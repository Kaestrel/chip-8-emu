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
  };

  struct DISPLAY {
    std::size_t height = 32;
    std::size_t width = 64;
    std::uint8_t screen[5] = {0};
    
    public void PRINT_NUMBER(char symbol) {
      switch (symbol) {
        case '0':
          printf("****\n*  *\n*  *\n*  *\n****");
          break;
        case '1':
          printf("  * \n ** \n  * \n  * \n ***");
          break;
        case '2':
          printf("****\n   *\n****\n*   \n****");
          break;
        case '3':
          printf("****\n   *\n****\n   *\n****");
          break;
        case '4':
          printf("*  *\n*  *\n****\n   *\n   *");
          break;
        case '5':
          printf("****\n*   \n****\n   *\n****");
          break;
        case '6':
          printf("****\n*   \n****\n*  *\n****");
          break;
        case '7':
          printf("****\n   *\n  * \n *  \n *  ");
          break;
        case '8':
          printf("****\n*  *\n****\n*  *\n****");
          break;
        case '9':
          printf("****\n*  *\n****\n   *\n****");
          break;
        case 'A':
          printf("****\n*  *\n****\n*  *\n*  *");
          break;
        case 'B':
          printf("*** \n*  *\n*** \n*  *\n*** ");
          break;
        case 'C':
          printf("****\n*   \n*   \n*   \n****");
          break;
        case 'D':
          printf("*** \n*  *\n*  *\n*  *\n*** ");
          break;
        case 'E':
          printf("****\n*   \n****\n*   \n****");
          break;
        case 'F':
          printf("****\n*   \n****\n*   \n*   ");
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

