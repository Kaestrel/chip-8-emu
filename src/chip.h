#pragma once 
#include <cstdint>
#include <cstdio>

class CHIP {

  std::uint8_t MEMORY[4096] = {0};

  struct INTERPRETER {
    std::uint16_t MEM_BEGIN = 0x000;
    std::uint16_t MEM_END = 0x1FF;

    std::uint8_t GEN_REG[16] = {{0}};
    std::uint16_t I_REG[2] = {0};
    std::uint8_t SOUND_REG = 0;
    std::uint8_t TIMER_REG = 0;
    std::uint16_t PC_COUNT_REG = 0;
    std::uint8_t sp = 0;
    std::uint16_t STACK[16] = {0};

    public void SET_GEN(std::uint8_t v, std::size_t i) GEN_REG[i] = v;
    public std::uint8_t GET_GEN(std::size_t i) return GEN_REG[i];
    public void SET_I_REG(std::uint16_t v, std::size_t i) I_REG[i] = v;
    public std::uint16_t GET_I_REG(std::size_t i) return I_REG[i];
    public void PUSH_STACK(std::uint16_t v) {
      STACK[sp] = v;
      ++sp;
    }

  };

  struct DISPLAY {
    std::size_t height = 32;
    std::size_t width = 64;
    std::uint8_t screen[5] = {0};
    
    public void PRINT_NUMBER(char symbol) {
      switch (symbol) {
        case '0':
          screen[0] = 0xF0;
          screen[1] = 0x90;
          screen[2] = 0x90;
          screen[3] = 0x90;
          screen[4] = 0xF0;
          break;
        case '1':
          screen[0] = 0x20;
          screen[1] = 0x60;
          screen[2] = 0x20;
          screen[3] = 0x20;
          screen[4] = 0x70;
          break;
        case '2':
          screen[0] = 0xF0;
          screen[1] = 0x10;
          screen[2] = 0xF0;
          screen[3] = 0x80;
          screen[4] = 0xF0;
          break;
        case '3':
          screen[0] = 0xF0;
          screen[1] = 0x10;
          screen[2] = 0xF0;
          screen[3] = 0x10;
          screen[4] = 0xF0;
          break;
        case '4':
          screen[0] = 0x90;
          screen[1] = 0x90;
          screen[2] = 0xF0;
          screen[3] = 0x10;
          screen[4] = 0x10;
          break;
        case '5':
          screen[0] = 0xF0;
          screen[1] = 0x80;
          screen[2] = 0xF0;
          screen[3] = 0x10;
          screen[4] = 0xF0;
          break;
        case '6':
          screen[0] = 0xF0;
          screen[1] = 0x80;
          screen[2] = 0xF0;
          screen[3] = 0x90;
          screen[4] = 0xF0;
          break;
        case '7':
          screen[0] = 0xF0;
          screen[1] = 0x10;
          screen[2] = 0x20;
          screen[3] = 0x40;
          screen[4] = 0x40;
          break;
        case '8':
          screen[0] = 0xF0;
          screen[1] = 0x90;
          screen[2] = 0xF0;
          screen[3] = 0x90;
          screen[4] = 0xF0;
          break;
        case '9':
          screen[0] = 0xF0;
          screen[1] = 0x90;
          screen[2] = 0x90;
          screen[3] = 0x10;
          screen[4] = 0xF0;
          break;
        case 'A':
          screen[0] = 0xF0;
          screen[1] = 0x90;
          screen[2] = 0xF0;
          screen[3] = 0x90;
          screen[4] = 0x90;
          break;
        case 'B':
          screen[0] = 0xE0;
          screen[1] = 0x90;
          screen[2] = 0xE0;
          screen[3] = 0x90;
          screen[4] = 0xE0;
          break;
        case 'C':
          screen[0] = 0xF0;
          screen[1] = 0x80;
          screen[2] = 0x80;
          screen[3] = 0x80;
          screen[4] = 0xF0;
          break;
        case 'D':
          screen[0] = 0xE0;
          screen[1] = 0x90;
          screen[2] = 0x90;
          screen[3] = 0x90;
          screen[4] = 0xE0;
          break;
        case 'E':
          screen[0] = 0xF0;
          screen[1] = 0x80;
          screen[2] = 0xF0;
          screen[3] = 0x80;
          screen[4] = 0xF0;
          break;
        case 'F':
          screen[0] = 0xF0;
          screen[1] = 0x80;
          screen[2] = 0xF0;
          screen[3] = 0x80;
          screen[4] = 0x80;
          break;

      }
    }
  };
  
  struct PROGRAM {
    std::uint16_t MEM_BEGIN = 0x200;
    std::uint16_t MEM_END = 0xFFF;
  };

  struct INSTRUCTION {
    std::uint16_t addr;
    std::uint8_t nibble;
    std::uint8_t x;
    std::uint8_t y;
    std::uint8_t kk;

    public void execute(std::uint16_t instruction) {
      switch (instruction) {
        case 0x00E0:
          //system("clear");
          break;
        case 0x00EE:
          //RETURN FROM A SUBROUTINE
          break;
      }
    } 
  };

};

