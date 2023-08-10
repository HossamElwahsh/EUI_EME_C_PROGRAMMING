//
// Created by hacke on 8/6/2023.
//

#include "day_task.h"

static int find_max_profit_one_sell(int * arr, int n);
static int find_max_profit_multi_sells(int *arr, int n);

int find_max_profit(int * arr, int n)
{
#if GOD_MODE == TRUE
    return find_max_profit_multi_sells(arr, n);
#else
    return find_max_profit_one_sell(arr, n);
#endif
}


int find_max_profit_one_sell(int * arr, int n)
{
    int int_l_max_profit_retval = 0;
    int max_price = -1;
    int min_price = -1;

    /* Arg Check */
    if((NULL_PTR != arr) && (MIN_REQ_DAYS > n))
    {
        /* Invalid Arguments */
    }
    else
    {
        /* Args valid */
        max_price = -1;
        min_price = arr[0];

        /* Loop over days */
        for (int i = 1; i < n; ++i)
        {
            if(arr[i] < min_price)
            {
                /* update min price */
                min_price = arr[i];
                continue;
            }
            if(arr[i] > max_price)
            {
                max_price = arr[i];
                int_l_max_profit_retval = max_price - min_price;
            }
        }
    }

    return int_l_max_profit_retval;
}

int find_max_profit_multi_sells(int * arr, int n)
{
    int int_l_max_profit_retval = 0;
    int max_price = -1;
    int min_price = -1;
    int last = -1;

    /* Arg Check */
    if((NULL_PTR != arr) && (MIN_REQ_DAYS > n))
    {
        /* Invalid Arguments */
    }
    else
    {
        /* Args valid */
        max_price = -1;
        min_price = arr[0];
        last = arr[0];
        boolean can_sell = FALSE;

        /* Loop over days */
        for (int i = 1; i < n; ++i)
        {
            if(FALSE == can_sell)
            {
                /* Must buy first */
                if(arr[i] > last)
                {
                    /* buy last now */
                    can_sell = TRUE;
                    min_price = last;
                }
            }
            else
            {
                /* Must sell first */
                if(arr[i] < last)
                {
                    /* sell last now */
                    can_sell = FALSE;
                    max_price = last;

                    /* calc profit */
                    int_l_max_profit_retval += max_price - min_price;

                    /* reset prices */
                    max_price = -1;
                    min_price = arr[0];
                }
            }

            /* Update last element */
            last = arr[i];
        }
    }

    return int_l_max_profit_retval;
}
