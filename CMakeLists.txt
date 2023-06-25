cmake_minimum_required(VERSION 3.23)
project(system-programming C)

set(CMAKE_C_STANDARD 99)

enable_language(ASM_NASM)
if(APPLE)
    #Add leading underscore when building macho64 object files
    string(APPEND CMAKE_ASM_NASM_FLAGS "--prefix _")
endif(APPLE)
if(WIN32)
    string(APPEND CMAKE_ASM_NASM_FLAGS "-dWIN32=1")
endif(WIN32)

add_executable(inline_asm ./windows/inline_asm1.c ./windows/inline_asm2.c)
