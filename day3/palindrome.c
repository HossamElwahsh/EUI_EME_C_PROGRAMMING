//
// Created by Hossam Elwahsh on 8/10/23.
//

#include "palindrome.h"

boolean is_palindrome(int * int_a_arr, int n)
{
    boolean bool_l_palindrome_retval = TRUE;
    /* arg check */
    if(
            (NULL_PTR != int_a_arr) &&
            (n >= MIN_ARR_SIZE)
            )
    {
        if(MIN_ARR_SIZE < n)
        {
            for (int i = 0; i < n/2; ++i)
            {
                if(int_a_arr[i] != int_a_arr[n - 1 - i])
                {
                    bool_l_palindrome_retval = FALSE;
                    break;
                }
            }
        }
        else
        {
            /* Single number array is palindrome */
        }
    }
    else
    {
        printf("\n=======\nInvalid array input\n=======\n");
    }

    if(bool_l_palindrome_retval == TRUE)
    {
        printf("\n\nIs Palindrome\n\n");
    }
    else
    {
        printf("\n\nNOT Palindrome\n\n");
    }

    /* Print Reverse */
    printf("Reverse:\n\t");

    for (int i = n-1; i >= 0; i--)
    {
        printf("%d\t", int_a_arr[i]);
    }

    return bool_l_palindrome_retval;
}


boolean is_palindrome_digits(int number)
{
    boolean bool_l_palindrome_retval = TRUE;
    int digit = 0;
    int num_cpy = number;
    int reverse = 0;

    /* arg check */
    if((number / 10) != ZERO)
    {
        /* Number is not single digit */
        /* Process */
        do
        {
            digit = number % 10;
            reverse *= 10;
            reverse += digit;
        }while(number /= 10);

        if(reverse != num_cpy) bool_l_palindrome_retval = FALSE;
    }
    else
    {
        /* Single Digit is Palindrome */
        reverse = number;
    }

    if(bool_l_palindrome_retval == TRUE)
    {
        printf("\n\nIs Palindrome\n\n");
    }
    else
    {
        printf("\n\nNOT Palindrome\n\n");
    }

    /* Print Reverse */
    printf("Reverse:\n\t%d", reverse);


    return bool_l_palindrome_retval;
}