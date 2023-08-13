cmake_minimum_required(VERSION 3.25)
project(Day2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(day2)
include_directories(day3)
include_directories(day4)
include_directories(day5_bus_reservation_project)
include_directories(day5_bus_reservation_project/helpers)
include_directories(day5_bus_reservation_project/helpers/circular_queue)
include_directories(test)

add_executable(Day2
        main.c
        std.h

        day2/swap_two_numbers.c day2/febonanci.c
        day2/second_biggest.c
        day2/day_task.c
        day3/palindrome.c
        test/test.c
        test/test.h
        day3/shift_arr.h
        day3/shift_arr.c
        day3/largest_water_tank.c
        day4/calculator.c
        day4/calculator.h
        day4/stack.c
        day4/stack.h
        day5_bus_reservation_project/ticket.c
        day5_bus_reservation_project/ticket.h
        day5_bus_reservation_project/bus_reserve_app.c
        day5_bus_reservation_project/bus_reserve_app.h
        day5_bus_reservation_project/bus.c
        day5_bus_reservation_project/bus.h
        day5_bus_reservation_project/helpers/circular_queue/cqueue_program.c
        day5_bus_reservation_project/user.c
        day5_bus_reservation_project/user.h
        day5_bus_reservation_project/helpers/test.c
        day5_bus_reservation_project/helpers/test.h
)
