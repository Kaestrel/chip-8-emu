#pragma once 
#ifndef _CHIP_H_
#define _CHIP_H_

#include <cstdint>
#include <cstdio>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <bitset>
#include <X11/Xlib.h>
#include "X11/keysym.h"

using clock_type = std::chrono::steady_clock;

class Chip {
  public:

  Chip (std::size_t m);
  std::uint16_t memory;
  std::uint16_t memory_begin = 0x200;
  std::uint16_t memory_end = 0xFFF;
  std::uint16_t S[16] = {0};
  std::uint8_t V[16] = {0};
  std::uint16_t I = 0;
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

  std::uint8_t keys[16] = {
    0x78,// Host X, CHIP 0
    0x31,// Host 1, CHIP 1
    0x32,// Host 2, CHIP 2
    0x33,// Host 3, CHIP 3
    0x71,// Host Q, CHIP 4 
    0x77,// Host W, CHIP 5 
    0x65,// Host E, CHIP 6 
    0x61,// Host A, CHIP 7 
    0x73,// Host S, CHIP 8 
    0x64,// Host D, CHIP 9
    0x7A,// Host Z, CHIP A
    0x63,// Host C, CHIP B
    0x34,// Host 4, CHIP C
    0x72,// Host R, CHIP D
    0x66,// Host F, CHIP E
    0x76// Host V, CHIP F
  };

  //INTERPRETER 
  void set_v (std::uint8_t v, std::size_t i);
  std::uint8_t get_v (std::size_t i);
  void push_stack (std::uint16_t v);
  void pop_stack();
  void rtn_from_subroutine();
  void jump_to (std::uint16_t loc);
  void call_subroutine();
  void start_timer (std::uint8_t time);
  void print_to_screen(std::uint8_t a[5]);

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
