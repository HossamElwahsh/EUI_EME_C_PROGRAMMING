#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"
#include "string.h"

#define TEST_DIR "../test/TestCases/"
#define CONCAT(STR1, STR2) STR1 STR2

 /** Test function for @see ../Card/card.c:getCardPan() */
void auto_test_palindrome(void);


void testAll();

#endif //TEST_H