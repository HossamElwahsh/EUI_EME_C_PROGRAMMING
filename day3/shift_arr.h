//
// Created by hossam on 8/10/23.
//

#ifndef DAY2_SHIFT_ARR_H
#define DAY2_SHIFT_ARR_H

#include "std.h"
#include "test.h"
#include "swap_two_numbers.h"

/* Takes Modulus of x % y, and saves result in y */
#define MOD_SAVE(x,y) x %= y

/* Finds half of a number */
#define HALF_OF(x) (x/2)

#define MIN_ARR_SIZE 1

void shift_arr(int * arr, int n, int k);

#endif //DAY2_SHIFT_ARR_H
