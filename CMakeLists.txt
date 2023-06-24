cmake_minimum_required(VERSION 3.23)
project(system-programming C)

set(CMAKE_C_STANDARD 99)

add_executable(inline_asm ./windows/inline_asm1.c ./windows/inline_asm2.c)
add_executable(asm windows/asm1/main.c)
