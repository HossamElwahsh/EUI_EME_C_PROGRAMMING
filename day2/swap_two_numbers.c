//
// Created by hacke on 8/6/2023.
//

#include "swap_two_numbers.h"
/**
 * @brief               :   Takes two numbers and swaps them together using temp variable
 * @param intptr_a_num1 :   Ptr to Number 1
 * @param intptr_a_num2 :   Ptr to Number 2
 */
void swap1(int * intptr_a_num1, int * intptr_a_num2)
{
    int temp;

    /* Swap numbers */
    temp = *intptr_a_num1;
    *intptr_a_num1 = *intptr_a_num2;
    *intptr_a_num2 = temp;
}

/**
 * @brief               :   Takes two numbers and swaps them together using xor
 * @param intptr_a_num1 :   Ptr to Number 1
 * @param intptr_a_num2 :   Ptr to Number 2
 */
void swap2(int * intptr_a_num1, int * intptr_a_num2)
{
    *intptr_a_num1 ^= *intptr_a_num2 ^= *intptr_a_num1 ^= *intptr_a_num2;
}

/**
 * @brief               :   Takes two numbers and swaps them together using summation
 * @param intptr_a_num1 :   Ptr to Number 1
 * @param intptr_a_num2 :   Ptr to Number 2
 */
void swap3(int * intptr_a_num1, int * intptr_a_num2)
{
    // a = 5, b = 8
    // a = 13
    // b = 13 - 8
    // a = 13 - b(5) = 8

    *intptr_a_num1 += *intptr_a_num2;
    *intptr_a_num2 = *intptr_a_num1 - *intptr_a_num2;
    *intptr_a_num1 -= *intptr_a_num2;

}

void swap4(int * intptr_a_num1, int * intptr_a_num2)
{
    // a = 5, b = 8;
    // a = 5 * 8 = 40
    // b = tot / 8 = 5
    // a = tot

    *intptr_a_num1 *= *intptr_a_num2;
    *intptr_a_num2 = *intptr_a_num1 / *intptr_a_num2;
    *intptr_a_num1 /= *intptr_a_num2;
}