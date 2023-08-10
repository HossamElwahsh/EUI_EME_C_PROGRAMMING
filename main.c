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

int main(void)
{
//    testPalindrome();
    auto_test_palindrome();

//    testMaxProfit();
    //    secondBiggestTest();
    return 0;
}

