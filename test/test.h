#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"
#include "shift_arr.h"
#include "largest_water_tank.h"
#include "string.h"

#define TEST_DIR "../test/TestCases/"
#define CONCAT(STR1, STR2) STR1 STR2

 /** Test function for @see ../Card/card.c:getCardPan() */
void auto_test_palindrome(void);
void auto_test_palindrome_digits(void);
void auto_test_shift_arr();
void auto_test_largest_area(void);

void testAll();

#endif //TEST_H