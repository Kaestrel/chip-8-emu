cmake_minimum_required(VERSION 3.20)

project(chip8 LANGUAGES CXX)

add_executable(chip8 src/main.cpp)
target_compile_features(chip8 PRIVATE cxx_std_17)

if (MSVC)
  target_compile_options(chip8 PRIVATE /W4 /WX)
else()
  target_compile_options(chip8 PRIVATE -Wall -Wextra -Wpedantic -Werror)
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(chip8 PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(chip8 PRIVATE -fsanitize=address,undefined)
  endif()
endif()

target_compile_definitions(chip8 PRIVATE CHIP8_DEBUG_TRACE=1)
