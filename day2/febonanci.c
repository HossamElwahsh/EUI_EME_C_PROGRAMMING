//
// Created by Hossam Elwahsh on 8/6/2023.
//

#include "febonanci.h"

/**
 * @brief                 :   Prints feb series till int_a_count count
 * @param int_a_count     :   Count of feb numbers to print (Positive numbers)
 *
 * @return                :   Void
 */
void print_feb(int int_a_count)
{
    unsigned int next = 0;
    unsigned int prev = 0;
    unsigned int current = 1;

    /* invalid input, less than one */
    if(MIN_ALLOWED_NUMBER > int_a_count)
    {
        printf("\nInvalid input\n");
        return;
    }

    /* Print initial Zero */
    printf("%d\n", prev);

    while(int_a_count - PREDEFINED_NUMBERS_COUNT > 0)
    {
        /* Print current feb series number */
        printf("%d\n", current);

        next = prev + current;
        prev = current;
        current = next;

        if(next < prev)
        {
            printf("\n===overflow detected, stopping===\n");
            break;
        }

        /* Decrement counter */
        int_a_count--;
    }
}