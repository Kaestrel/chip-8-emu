#pragma once 
#ifndef _CHIP_H_
#define _CHIP_H_

#include <cstdint>
#include <cstdio>
#include <chrono>
#include <fstream>
#include <iostream>

using clock_type = std::chrono::steady_clock;

class Chip {
  public:

  Chip (std::size_t m);
  std::uint16_t memory;
  std::uint16_t memory_begin = 0x200;
  std::uint16_t memory_end = 0xFFF;
  std::uint16_t S[16] = {0};
  std::uint8_t V[16] = {0};
  std::uint16_t I[1] = {0};
  std::uint8_t sound = 0;
  std::uint8_t timer = 0;
  std::uint16_t pc_count = 0;
  std::uint16_t* sp = &S[0];

  //INTERPRETER 
  void set_v (std::uint8_t v, std::size_t i);
  std::uint8_t get_v (std::size_t i);
  void set_i (std::uint16_t v, std::size_t i);
  std::uint16_t get_i (std::size_t i);
  void push_stack (std::uint16_t v);
  void pop_stack();
  void rtn_from_subroutine();
  void jump_to (std::uint16_t loc);
  void call_subroutine (std::uint16_t loc);
  void skip_instruction (std::uint8_t i);
  void start_timer (std::uint8_t time);

  void test();

  static constexpr std::size_t height = 32;
  static constexpr std::size_t width = 64;
  std::uint8_t screen[height][width] = {{0}};
    
  std::uint16_t addr = 0x000;
  std::uint8_t nibble = 0x0;
  std::uint8_t x = 0x00;
  std::uint8_t y = 0x00;
  std::uint8_t kk = 0x00;


    void execute(std::uint16_t instruction) {
      //std::uint8_t mask = 1 << 0;
      nibble = (instruction);
      
      switch (instruction) {
        case 0x00E0:
          //for (int i = 0; i < 4; i++) DISPLAY.screen[i] = 0x00;
          break;
        case 0x00EE:

          break;
      }
    } 

};

#endif
