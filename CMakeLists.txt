cmake_minimum_required(VERSION 3.23)
project(system-programming C)

set(CMAKE_C_STANDARD 99)

add_executable(gcc_inline_asm1 assembly/gcc/inline_asm1.c)
add_executable(gcc_inline_asm2 assembly/gcc/inline_asm2.c)
add_executable(vcpp_inline_asm1 assembly/vcpp/inline_asm1.c)
add_executable(vcpp_inline_asm2 assembly/vcpp/inline_asm2.c)
