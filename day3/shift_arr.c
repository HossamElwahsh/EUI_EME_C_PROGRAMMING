//
// Created by Hossam Elwahsh on 10/8/23.
//

#include <stdio.h>
#include "shift_arr.h"

void shift_arr(int * arr, int n, int k)
{
    /* Arg check */
    if(
            (NULL_PTR != arr) &&
            (MIN_ARR_SIZE <= n)
    )
    {
        if(MIN_ARR_SIZE == n)
        {
            /* Shift won't make a difference */
        }
        else /* Can shift */
        {
            /* minimize number of loops if k is positive */
            if(k >= n) MOD_SAVE(k, n);

            /* Change shift left by shift right if k is negative */
            else if(k < ZERO)
            {
                k *= -1;

                /* minimize number of loops */
                if(k >= n) MOD_SAVE(k, n);

                /* Get k complement w.r.t array size if k not zero */
                if(k != ZERO) k = n - k;
            }

            /* print k for debugging */
            printf("\n\nk:\t%d\n\n", k);

            /* Rotate array elements */
            /* 0 <> 1 (1) */
            /* 1 <> 2 (1) */
            /* 2 <> 3 (1) */
            /* 3 <> 4 (1) */
            /* 4 <> 5 (1) */
            /* 5 <> 0 (1) */

            /* 5 <> 0 (2) */

            /* 0 <> 3 (3) */
            /* 1 <> 4 (3) */
            /* 2 <> 5 (3) */
            /* 3 <> 0 (3) */
            /* 4 <> 1 (3) */
            /* 5 <> 2 (3) */


            /* 0 <> 4 (4) */
            /* 1 <> 5 (4) */
            /* 2 <> 0 (4) */
            /* 3 <> 1 (4) */
            /* 4 <> 2 (4) */
            /* 5 <> 3 (4) */
            /*  */

            /* temp variable for swapping */
            int temp;

            /* no overlapping process from the end */
            if (k <= HALF_OF(n))
            {
                for (int i = n - 1; i > k - 1; i--)
                {
                    temp = arr[i];
                    arr[i] = arr[(i + k) % n];
                    arr[(i + k) % n] = temp;
                }
            }
            else
            {
                for (int i = 0; i < k; i++)
                {
                    temp = arr[i];
                    arr[i] = arr[(i + k) % n];
                    arr[(i + k) % n] = temp;
                }
            }


            /* Print array */
            printf("\n\nShifted Array:\n");

            for (int i = 0; i < n; ++i)
            {
                /* Print array element */
                printf("\t%d", arr[i]);
            }
        }
    }
    else
    {
        printf("\n=======\nInvalid array input\n=======\n");
    }
}








