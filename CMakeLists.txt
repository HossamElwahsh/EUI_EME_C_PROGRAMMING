cmake_minimum_required(VERSION 3.25)
project(Day2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(day2)
include_directories(day3)

add_executable(Day2
        main.c
        std.h

        day2/swap_two_numbers.c day2/febonanci.c
        day2/second_biggest.c
        day2/day_task.c
        day3/palindrome.c
        test/test.c)
