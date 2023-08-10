//
// Created by hacke on 8/6/2023.
//

#ifndef DAY2_SECOND_BIGGEST_H
#define DAY2_SECOND_BIGGEST_H

/* Includes */
#include "stdio.h"

/* Helping macros */
#define TRUE            1
#define FALSE           0
#define MIN_ARR_COUNT   1
#define NULL            0
#define NULL_PTR        ((void *) NULL)
#define OPTIMIZED_FIND  TRUE

/* Config */
#define SORT_ASC        FALSE

/* Typdefs */
typedef unsigned char   boolean;

void print_arr  (int * int_arr, int n);
void sort_arr   (int * int_arr, int n);
int find_second_biggest(int * int_arr, int n);

#endif //DAY2_SECOND_BIGGEST_H
