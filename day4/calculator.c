//
// Created by hossam on 8/11/23.
//

#include "calculator.h"

calc_fun calculator_arr[] = {
        add         ,
        sub         ,
        multiply    ,
        divide      ,
        power
//        factorial
};

en_calc_error_t calc_init()
{
    /* Todo */
    return CALC_OK;
}


void test()
{
    double result = 0;
    void * test = calculator_arr[0];

    result = CALC(CALC_ADD, result, result, &result);

    (* (calc_fun)test)(5,3, &result);


    boolean deb = TRUE;
}



en_calc_error_t add(double x, double y, double * result)
{
    int error_retval = CALC_OK;
    double sum = 0;
    long double temp = 0;

    sum = x + y;
    temp = x + y;

    /* check for overflow */
    if(sum != temp)
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        *result = sum;
    }

    return error_retval;
}

en_calc_error_t sub(double x, double y, double * result)
{
    int error_retval = CALC_OK;
    double diff = 0;
    long double temp = 0;

    diff = x - y;
    temp = x - y;

    /* check for overflow */
    if(diff != temp)
    {
        /* over flow */
        error_retval = CALC_ERROR;
    }
    else
    {
        *result = diff;
    }

    return error_retval;
}
en_calc_error_t multiply(double x, double y, double * result)
{
    int error_retval = CALC_OK;
    double mult = 0;

    mult = x * y;

    /* check for overflow */
    if (x != 0 && ((mult / x) != y))
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        *result = mult;
    }

    return error_retval;
}

en_calc_error_t divide(double x, double y, double * result)
{
    int error_retval = CALC_OK;

    if(y == ZERO)
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        /* Calculate division */
        *result = x / y;
    }


    return error_retval;
}

en_calc_error_t power(double x, double y, double * result)
{
    int error_retval = CALC_OK;
    double temp_result = ZERO;

    /* flag for negative power */
    boolean neg = FALSE;

    if(y < ZERO)
    {
        neg = TRUE;
        y *= -1;
    }

    /* Handle power of zero */
    if(y == ZERO)
    {
        /* power of zero is always 1 */
        *result = 1;
        return error_retval;
    }

    /* simplify power of 2 with bit shifting */
    if(x == 2)
    {
        temp_result = 1 << (int)y;

        /* check overflow */
        if(temp_result < x)
        {
            /* overflow */
            error_retval = CALC_ERROR;
        }

        *result = temp_result;
    }
    else
    {
        /* Calculate power */
        for (int i = 0; i < y; ++i)
        {
            temp_result = x * x;

            /* check for overflow */
            if(temp_result < x)
            {
                error_retval = CALC_ERROR;
                break;
            }

            /* no overflow, save value */
            *result = temp_result;
        }
    }

    /* handle negative power */
    if(TRUE == neg)
    {
        *result = 1.0 / *result;
    }

    return error_retval;
}

en_calc_error_t factorial(double x, double * result)
{
    int error_retval = CALC_OK;
    int current_val = 1;
    int prev_val = 1;

    /* calculate factorial of x = x! */
    for (int i = (int)x; i > 0; i--)
    {
        current_val *= i;

        if(current_val < prev_val)
        {
            /* overflow */
            error_retval = CALC_ERROR;
            break;
        }
    }

    *result = current_val;

    return error_retval;
}