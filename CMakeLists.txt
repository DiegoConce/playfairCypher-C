cmake_minimum_required(VERSION 3.14)
project(DiegoConcetti104936 C)

set(CMAKE_C_STANDARD 99)


add_executable(playfair  main.c utils.c utils.h driver.c driver.h playfair.c playfair.h rules.c rules.h file_manager.c file_manager.h)
