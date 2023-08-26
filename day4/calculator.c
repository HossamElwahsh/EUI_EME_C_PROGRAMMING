//
// Created by Hossam Elwahsh on 8/11/23.
//

#include "calculator.h"
#include "stdio.h"

calc_fun calculator_arr[] = {
        add         ,
        sub         ,
        multiply    ,
        divide      ,
        power
//        factorial
};


/**
 * Adds two numbers together
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t add(double f64_a_x, double f64_a_y, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;
    double sum = 0;
    long double temp = 0;

    sum = f64_a_x + f64_a_y;
    temp = f64_a_x + f64_a_y;

    /* check for overflow */
    if(sum != temp)
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        *ptr_f64_a_result = sum;
    }

    return error_retval;
}


/**
 * Subtracts two numbers
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t sub(double f64_a_x, double f64_a_y, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;
    double diff = 0;
    long double temp = 0;

    diff = f64_a_x - f64_a_y;
    temp = f64_a_x - f64_a_y;

    /* check for overflow */
    if(diff != temp)
    {
        /* over flow */
        error_retval = CALC_ERROR;
    }
    else
    {
        *ptr_f64_a_result = diff;
    }

    return error_retval;
}


/**
 * Multiplies two numbers together
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t multiply(double f64_a_x, double f64_a_y, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;
    double mult = 0;

    mult = f64_a_x * f64_a_y;

    /* check for overflow */
    if (f64_a_x != 0 && ((mult / f64_a_x) != f64_a_y))
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        *ptr_f64_a_result = mult;
    }

    return error_retval;
}


/**
 * Divides two numbers together
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t divide(double f64_a_x, double f64_a_y, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;

    if(f64_a_y == ZERO)
    {
        error_retval = CALC_ERROR;
    }
    else
    {
        /* Calculate division */
        *ptr_f64_a_result = f64_a_x / f64_a_y;
    }


    return error_retval;
}

/**
 * Raises number (f64_a_x) to the power of (f64_a_y)
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t power(double f64_a_x, double f64_a_y, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;
    double temp_result = ZERO;

    /* flag for negative power */
    boolean neg = FALSE;

    if(f64_a_y < ZERO)
    {
        neg = TRUE;
        f64_a_y *= -1;
    }

    /* Handle power of zero */
    if(f64_a_y == ZERO)
    {
        /* power of zero is always 1 */
        *ptr_f64_a_result = 1;
        return error_retval;
    }

    /* simplify power of 2 with bit shifting */
    if(f64_a_x == 2)
    {
        temp_result = 1 << (int)f64_a_y;

        /* check overflow */
        if(temp_result < f64_a_x)
        {
            /* overflow */
            error_retval = CALC_ERROR;
        }

        *ptr_f64_a_result = temp_result;
    }
    else
    {
        /* Calculate power */
        for (int i = 0; i < f64_a_y; ++i)
        {
            temp_result = f64_a_x * f64_a_x;

            /* check for overflow */
            if(temp_result < f64_a_x)
            {
                error_retval = CALC_ERROR;
                break;
            }

            /* no overflow, save value */
            *ptr_f64_a_result = temp_result;
        }
    }

    /* handle negative power */
    if(TRUE == neg)
    {
        *ptr_f64_a_result = 1.0 / *ptr_f64_a_result;
    }

    return error_retval;
}

/**
 * Calculates factorial of a number
 * @param   f64_a_x             :   operand 1
 * @param   f64_a_y             :   operand 2
 * @param   ptr_f64_a_result    :   pointer to store result
 *
 * @return  CALC_OK             :   If successful
 *          CALC_ERROR          :   If failed
 */
static en_calc_error_t factorial(double f64_a_number, double * ptr_f64_a_result)
{
    int error_retval = CALC_OK;
    int current_val = 1;
    int prev_val = 1;

    /* calculate factorial of f64_a_number = f64_a_number! */
    for (int i = (int)f64_a_number; i > 0; i--)
    {
        current_val *= i;

        if(current_val < prev_val)
        {
            /* overflow */
            error_retval = CALC_ERROR;
            break;
        }
    }

    *ptr_f64_a_result = current_val;

    return error_retval;
}

/**
 * [Private] Requests input from user
 * @param two_numbers   Request one or two numbers
 * @param ptr_f64_x             ptr to store first inserted number
 * @param ptr_f64_y             ptr to store second inserted number
 */
static void getInput(boolean two_numbers, double * ptr_f64_x, double * ptr_f64_y)
{
    if(two_numbers)
    {
        printf("Enter operands separated with space (x y):\n\t");
        scanf("%lf %lf", ptr_f64_x, ptr_f64_y);
    }
    else
    {
        printf("Enter operand:\n\t");
        scanf("%lf", ptr_f64_x);
    }
}

/**
 * Calculator Program
 */
void calculator_program()
{
    char operator = ' ';
    double x,y, result;
    en_calc_error_t en_l_calc_error = CALC_OK;

    /* Super Loop */
    while(TRUE)
    {
        /* reset error flag */
        en_l_calc_error = CALC_OK;

        printf("\n------------\n\nChoose operation (+,-,*,/,^,!):\t");
        scanf("\n%c", &operator);

        /* Process user input */
        switch (operator)
        {
            case '+':
            {
                /* get user input */
                getInput(TRUE, &x, &y);
                en_l_calc_error = CALC(CALC_ADD, x, y, &result);
                break;
            }
            case '-':
            {
                /* get user input */
                getInput(TRUE, &x, &y);
                en_l_calc_error = CALC(CALC_SUB, x, y, &result);
                break;
            }
            case '*':
            {
                /* get user input */
                getInput(TRUE, &x, &y);
                en_l_calc_error = CALC(CALC_MUL,x, y, &result);
                break;
            }
            case '/':
            {
                /* get user input */
                getInput(TRUE, &x, &y);
                en_l_calc_error = CALC(CALC_DIV, x, y, &dec_result);
                break;
            }
            case '^':
            {
                /* get user input */
                getInput(TRUE, &x, &y);
                en_l_calc_error = CALC(CALC_POW, x, y, &dec_result);
                break;
            }
            case '!':
            {
                /* get user input */
                getInput(FALSE, &x, NULL_PTR);
                en_l_calc_error = factorial(x, &result);
                break;
            }
            default:
            {
                /* Wrong user input */
                printf("\nWrong input! \n\n");
                continue;
            }
        }

        /* Print result */
        if(CALC_ERROR == en_l_calc_error)
        {
            printf("\nResult:\n\tError occurred.\n");
        }
        else
        {
            printf("\nResult:\n\t%lf\n", result);
        }

        fflush(stdin);

    } /* end while */
}
