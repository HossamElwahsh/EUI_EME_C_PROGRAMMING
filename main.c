/**
 * @brief   :   Swap two numbers with 4 different ways,
 *              print feb series,
 *              print second biggest number in array.
 *
 * @author  :   Hossam Elwahsh
 * @date    :   8-6-2023
 * @class   :   EME - C Programming - Day 2
 */

#include "stdio.h"
#include "swap_two_numbers.h"
#include "febonanci.h"
#include "second_biggest.h"
#include "day_task.h"
#include "test/test.h"
#include "palindrome.h"
#include "shift_arr.h"
#include "calculator.h"
#include "stack.h"
#include "bus_reserve_app.h"

void swapTest()
{
    int a,b;
    a = 5;
    b = 8;

    printf("a: %d\tb: %d\n", a, b);

    swap4(&a, &b);

    printf("a: %d\tb: %d", a, b);

}

void secondBiggestTest()
{
    int second_biggest = -1;
    int n = 8;
    int arr[] = {5,8,2,1, -5,9,60,4};
//    int arr[] = {3, 3, 3};
//    int arr[] = {1, 3, 2};
    print_arr(arr, n);

    second_biggest = find_second_biggest(arr, n);

    if(-1 == second_biggest)
    {
        printf("\n\nSecond biggest not found.\n");
    }
    else
    {
        printf("\n\nSecond biggest number is %d\n", second_biggest);
    }
}

void testMaxProfit()
{
    int max_profit = 0;
    int n = 6;
    int arr[] = {7,1,5,3,6,4};

    int n2 = 5;
    int arr2[] = {7,6,4,3,1};
//    int arr2[] = {2,6,1,4,3};

    max_profit = find_max_profit(arr, n);

    printf("Max profit: %d\n", max_profit);

    max_profit = find_max_profit(arr2, n2);

    printf("Max profit: %d\n", max_profit);
}

void testPalindrome()
{
    int arr[] = {1,2,2,1};
    int n = 4;

    is_palindrome(arr, n);
}

void testShiftArray()
{
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    shift_arr(arr, n, 3);
}

void getInput(boolean two_numbers, double * x, double * y)
{
    if(two_numbers)
    {
        printf("Enter operands separated with space (x y):\n\t");
        scanf("%lf %lf", x, y);
    }
    else
    {
        printf("Enter operand:\n\t");
        scanf("%lf", x);
    }
}

void testCalculator()
{
    char operator = ' ';
    double x,y, result;
    en_calc_error_t en_l_calc_error = CALC_OK;

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

void test_stack()
{
    st_stack_t * my_stack = NULL_PTR;
    int number = 0;

    my_stack = stack_create(STACK_SIZE);

//    stack_print(my_stack);
    stack_pop(my_stack, &number);
    stack_push(my_stack, 1);
    stack_push(my_stack, 2);
    stack_push(my_stack, 3);
    stack_pop(my_stack, &number);

    stack_push(my_stack, 3);
    stack_push(my_stack, 4);
    stack_push(my_stack, 5);
    stack_push(my_stack, 6);
    stack_print(my_stack);
//    stack_print(my_stack);
    stack_pop(my_stack, &number);

    /* free pointer */
    free(my_stack);
}

void testBuses()
{
    /* init users */
    init_users();

    st_bus_data_t st_bus_data =
            {
                    20,
                    "",
                    "Alexandria",
                    "Cairo",
                    "12/8/2023 1:00 PM",
                    3*60
            };

    bus_show_buses();

    bus_add(st_bus_data, NULL_PTR);

    st_bus_data.depart_station = "Cairo";
    st_bus_data.arrive_station = "Alexandria";
    st_bus_data.depart_datetime = "12/8/2023 4:00 PM";

    bus_add(st_bus_data, NULL_PTR);

    bus_show_buses();

//    bus_delete(1);

//    bus_add(st_bus_data, NULL_PTR);

//    bus_show_buses();

    en_ticket_status_t en_ticket_status = book_ticket(1, 1, 2, NULL_PTR);
    en_ticket_status = book_ticket(1, 1, 2, NULL_PTR);
    en_ticket_status = book_ticket(1, 1, 2, NULL_PTR);

    boolean test = TRUE;
}

int main(void)
{
//    testPalindrome();
//    auto_test_palindrome();
//    auto_test_palindrome_digits();
//    auto_test_shift_arr();
//    auto_test_largest_area();
//    testCalculator();
//    testCalculator();
//    test();

//testBuses();

//    bus_program_start();

    test_bus_all();

//    test_stack();

//    testMaxProfit();
    //    secondBiggestTest();
    return 0;
}

