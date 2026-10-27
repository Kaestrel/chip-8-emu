#include "chip.h"

Chip::Chip (std::size_t m) {
  memory = m;
}

//INTERPRETER
void Chip::set_v (std::uint8_t v, std::size_t i) {
  V[i] = v;
}

std::uint8_t Chip::get_v (std::size_t i) {
  return V[i];
}

void Chip::set_i (std::uint16_t v, std::size_t i) {
  I[i] = v;
}

std::uint16_t Chip::get_i (std::size_t i) {
  return I[i];
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
      //CLEAR SCREEN
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
        V[x] -= V[y];
        if (V[x] > V[y]) V[0xF] = 1;
        else V[0xF] = 0;
    } else if (nibble == 8 && k == 6) {
        
    } else if (nibble == 8 && k == 7) {

    } else if (nibble == 8 && k == 0xE) {

    }






  }

