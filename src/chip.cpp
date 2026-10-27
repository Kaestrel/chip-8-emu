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

void Chip::call_subroutine (std::uint16_t i) {
  sp += 1;
  *sp = pc_count;
  pc_count = i;
}

void Chip::skip_instruction (std::uint8_t i) {
  if (V[i] == kk) pc_count += 2;
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
