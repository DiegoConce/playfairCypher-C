cmake_minimum_required(VERSION 3.14)
project(DiegoConcetti104936 C)

set(CMAKE_C_STANDARD 99)


add_executable(playfair  main.c utils.c utils.h driver.c driver.h playfair_encode.c playfair_encode.h rules_decode.c rules_decode.h file_manager.c file_manager.h playfair_decode.c playfair_decode.h matrix_utils.c matrix_utils.h rules_encode.c rules_encode.h validate.c validate.h)
