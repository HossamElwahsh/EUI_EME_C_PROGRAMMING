//
// Created by Hossam Elwahsh on 8/6/2023.
//

#include "second_biggest.h"
#include "swap_two_numbers.h"

/* Private Functions' Prototypes */
static int find_second_biggest_with_sort(int * int_arr, int n);
static int find_second_biggest_no_sort(int * int_arr, int n);

/**
 * @brief               :   Find second biggest element in array
 *
 * @param[in] int_arr   :   Ptr to array of integers
 * @param[in] n         :   Array items count
 *
 * @return    integer   :   Second largest number
 */
int find_second_biggest(int * int_arr, int n)
{
#if OPTIMIZED_FIND == TRUE
    return find_second_biggest_no_sort(int_arr, n);
#else
    return find_second_biggest_with_sort(int_arr, n);
#endif
}

static int find_second_biggest_with_sort(int * int_arr, int n)
{
    int int_l_second_biggest_retval = -1;

    /* Arg Check */
    if(
            (MIN_ARR_COUNT <= n) &&
            (int_arr != NULL_PTR)
            )
    {
        /* Sort Array */
        sort_arr(int_arr, n);

        if(n == 1)
        {
            int_l_second_biggest_retval = int_arr[0];
        }
        else
        {
#if SORT_ASC == TRUE
            int_l_second_biggest_retval = int_arr[n-2];
#else
            int_l_second_biggest_retval = int_arr[1];
#endif
        }
    }
    else
    {
        printf("Invalid array\n");
    }

    return int_l_second_biggest_retval;
}

/**
 * @brief               :   Sorts an array of integers
 * @param[in] int_arr   :   int array ptr
 * @param[in] n         :   array count
 */
static int find_second_biggest_no_sort  (int * int_arr, int n)
{
    int int_l_second_biggest_retval = -1;
    int int_l_biggest = -1;

    /* Arg Check */
    if(
            (MIN_ARR_COUNT <= n) &&
            (int_arr != NULL_PTR)
            )
    {
        if(n == 1)
        {
            int_l_second_biggest_retval = int_arr[0];
        }
        else
        {
            int_l_second_biggest_retval = int_arr[0];
            int_l_biggest = int_arr[0];

            /* Loop over array elements */
            for (int i = 1; i < n; ++i) {
                if(int_arr[i] > int_l_biggest)
                {
                    /* swap biggest <> second biggest */
                    swap1(&int_l_biggest, &int_l_second_biggest_retval);

                    /* update new biggest */
                    int_l_biggest = int_arr[i];
                }
                else if(int_arr[i] > int_l_second_biggest_retval)
                {
                    int_l_second_biggest_retval = int_arr[i];
                }
            }
        }
    }
    else
    {
        printf("Invalid array\n");
    }

    return int_l_second_biggest_retval;
}

/**
 * @brief               :   Sorts an array of integers
 * @param[in] int_arr   :   int array ptr
 * @param[in] n         :   array count
 */
void sort_arr(int * int_arr, int n)
{
    /* arg check */
    if(
            (MIN_ARR_COUNT <= n) &&
            (int_arr != NULL_PTR)
            )
    {

        boolean swapped = FALSE;

        /* Bubble Sort */
        for (int i = 0; i < n-1; ++i) {
            swapped = FALSE;

            /* loop over remaining unsorted numbers */
            for (int j = 0; j < n-1-i; ++j) {
#if SORT_ASC == TRUE
                if(int_arr[j] > int_arr[j+1])
                {
                    swap1(&int_arr[j], &int_arr[j+1]);
                    swapped = TRUE;
                }
#else
                if(int_arr[j] < int_arr[j+1])
            {
                swap1(&int_arr[j], &int_arr[j+1]);
                swapped = TRUE;
            }
#endif
            }

            if(swapped == FALSE)
            {
                /* No more sorting, bubble sort optimization */
                break;
            }

        }
    }
    else
    {
        printf("Invalid array\n");
    }


}

/**
 * @brief               :   Prints an array of integers
 * @param[in] int_arr   :   int array ptr
 */
void print_arr(int * int_arr, int n)
{
    /* arg check */
    if(
            (MIN_ARR_COUNT <= n) &&
            (int_arr != NULL_PTR)
        )
    {
        printf("\nArray:\n");

        /* Loop over array items */
        for (int i = 0; i < n; ++i)
        {

            /* Print array element */
            printf("\t%d", int_arr[i]);
        }
    }
    else
    {
        printf("Invalid array\n");
    }
}
