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

  std::uint8_t fonts[16][5] = {
    {0xF0, 0x90, 0x90, 0x90, 0xF0}, // 0
    {0x20, 0x60, 0x20, 0x20, 0x70}, // 1
    {0xF0, 0x10, 0xF0, 0x80, 0xF0}, // 2
    {0xF0, 0x10, 0xF0, 0x10, 0xF0}, // 3
    {0x90, 0x90, 0xF0, 0x10, 0x10}, // 4
    {0xF0, 0x80, 0xF0, 0x10, 0xF0}, // 5
    {0xF0, 0x80, 0xF0, 0x90, 0xF0}, // 6
    {0xF0, 0x10, 0x20, 0x40, 0x40}, // 7
    {0xF0, 0x90, 0xF0, 0x90, 0xF0}, // 8
    {0xF0, 0x90, 0xF0, 0x10, 0xF0}, // 9
    {0xF0, 0x90, 0xF0, 0x90, 0x90}, // A
    {0xE0, 0x90, 0xE0, 0x90, 0xE0}, // B
    {0xF0, 0x80, 0x80, 0x80, 0xF0}, // C
    {0xE0, 0x90, 0x90, 0x90, 0xE0}, // D
    {0xF0, 0x80, 0xF0, 0x80, 0xF0}, // E
    {0xF0, 0x80, 0xF0, 0x80, 0x80}  // F
  };

  //INTERPRETER 
  void set_v (std::uint8_t v, std::size_t i);
  std::uint8_t get_v (std::size_t i);
  void set_i (std::uint16_t v, std::size_t i);
  std::uint16_t get_i (std::size_t i);
  void push_stack (std::uint16_t v);
  void pop_stack();
  void rtn_from_subroutine();
  void jump_to (std::uint16_t loc);
  void call_subroutine();
  void start_timer (std::uint8_t time);

  void test();

  static constexpr std::size_t height = 32;
  static constexpr std::size_t width = 64;
  std::uint8_t screen[height][width] = {{0}};
    
  std::uint16_t addr = 0x0000;
  std::uint8_t nibble = 0x00;
  std::uint8_t n = 0x0;
  std::uint8_t x = 0x0;
  std::uint8_t y = 0x0;
  std::uint8_t kk = 0x00;
  std::uint8_t k = 0x0;
  
  void execute (std::uint16_t instruction);

};

#endif
