#include "chip.h"

Chip::Chip (std::size_t m) {
  memory = m;
  print_to_screen(fonts[0]);
  print_to_screen(fonts[1]);
  print_to_screen(fonts[2]);
  execute(0x00E0);
  print_to_screen(fonts[15]);
  execute(0xE19E);
}

//INTERPRETER
void Chip::set_v (std::uint8_t v, std::size_t i) {
  V[i] = v;
}

std::uint8_t Chip::get_v (std::size_t i) {
  return V[i];
}

void Chip::push_stack (std::uint16_t v) {
  if (*sp != 0xF) {
    *sp = v;
    sp -= 1;
  }
}

void Chip::pop_stack() {
  if (*sp != 0x0 && *sp != 0xF) --sp;
}

void Chip::rtn_from_subroutine() {
  pc_count = *sp;
  sp -= 1;
}

void Chip::jump_to (std::uint16_t loc) {
  pc_count = loc;
}

void Chip::call_subroutine() {
  sp += 1;
  *sp = pc_count;
  pc_count = addr;
}

void Chip::start_timer (std::uint8_t t) {
  while (t > 0) --t;
}

void Chip::print_to_screen(std::uint8_t a[5]) {
  for (int j = 0; j < 5; j++) {
    

      auto cursor = ((a[j] & 0xF0) >> 4);

      std::cout << '\n';
      for (int i = 3; i >= 0; i--) {
        bool on = (cursor >> i) & 1;
        std::cout << (on ? '*' : ' ');
      }
      std::cout << '\n';

  }
}

bool isKeyDown(KeySym ks) {
  Display *dpy = XOpenDisplay(":0");
  char keys_return[32];
  XQueryKeymap(dpy, keys_return);
  KeyCode kc2 = XKeysymToKeycode(dpy, ks);
  bool isPressed = !!(keys_return[kc2 >> 3] & (1 << (kc2 & 7)));
  XCloseDisplay(dpy);
  return isPressed;
}


void Chip::test() {
  std::ifstream file ("IBM.ch8", std::ios::binary | std::ios::ate);
    if (file.is_open()) {
      std::streampos size = file.tellg();
      char * memblock = new char [size];
      file.seekg (0, std::ios::beg);
      file.read (memblock, size);
      file.close();

      std::cout << memblock << size; 

      delete[] memblock;
    } else std::cout << "Unable to open file";
}

void Chip::execute (std::uint16_t instruction) {
  addr = instruction & 0xFFF;
  nibble = (instruction >> 12) & 0xF;
  y = (instruction >> 4) & 0xF;
  x = (instruction >> 8) & 0xF;
  kk = instruction & 0xFF;
  k = kk & 0xF;

  // DEBUG
  std::cout << std::hex << std::uppercase
            << "Address: " << addr
            << "\nnibble: " << +nibble
            << "\ny: " << +y
            << "\nx: " << +x
            << "\nkk: " << +kk
            << "\nk: " << +k;

    if (instruction == 0x00E0) {
        std::printf("\033[2J");
    } else if (instruction == 0x00EE) {
        rtn_from_subroutine();
    } else if (nibble == 1) {
        pc_count = addr;
    } else if (nibble == 2) {
        call_subroutine();
    } else if (nibble == 3) {
        if (V[x] == kk) pc_count += 2;
    } else if (nibble == 4) {
        if (V[x] != kk) pc_count += 2;
    } else if (nibble == 5) {
        if (V[x] == V[y]) pc_count += 2;
    } else if (nibble == 6) {
        V[x] = kk;
    } else if (nibble == 7) {
        V[x] += kk;
    } else if (nibble == 8 && k == 0) {
        V[x] = V[y];
    } else if (nibble == 8 && k == 1) {
        V[x] = V[x] | V[y];
    } else if (nibble == 8 && k == 2) {
        V[x] = V[x] & V[y];
    } else if (nibble == 8 && k == 3) {
        V[x] = V[x] ^ V[y];
    } else if (nibble == 8 && k == 4) {
        if (V[x] + V[y] > 255) V[0xF] = 1;
        else V[0xF] = 0;
        V[x] += V[y];
    } else if (nibble == 8 && k == 5) {
        if (V[x] > V[y]) V[0xF] = 1;
        else V[0xF] = 0;
        V[x] -= V[y];
    } else if (nibble == 8 && k == 6) {
        if (((V[x] >> 12) & 0xF) == 1) V[0xF] = 1;
        else V[0xF] = 0;
        V[x] /= 2;
    } else if (nibble == 8 && k == 7) {
        if (V[y] > V[x]) V[0xF] = 1;
        else V[0xF] = 0;
        V[x] = V[y] - V[x];
    } else if (nibble == 8 && k == 0xE) {
        if ((V[x] & 0xF) == 1) V[0xF] = 1;
        else V[0xF] = 0;
        V[x] *= 2;
    } else if (nibble == 0x9) {
        if (V[x] != V[y]) pc_count += 2;
    } else if (nibble == 0xA) {
        I = addr;
    } else if (nibble == 0xB) {
        pc_count = addr + V[0];
    } else if (nibble == 0xC) {
        srand(time(0));
        V[x] = (rand() % 256) & kk;
    } else if (nibble == 0xD) {
      print_to_screen(fonts[k]);
    } else if (nibble == 0xE && kk == 0x9E) {
      if (isKeyDown(keys[V[x] & 0xF])) pc_count += 2;
    } else if (nibble == 0xE && kk == 0xA1) {
      if (!isKeyDown(keys[V[x] & 0xF])) pc_count += 2;
    } 






  }

