//
// Created by hossam on 8/11/23.
//

#ifndef DAY2_STACK_H
#define DAY2_STACK_H

#include "stdio.h"
#include "stdlib.h"
#include "std.h"

#define STACK_SIZE 5

typedef struct
{
    int top;
    int size;
    int * int_stack_arr;
}st_stack_t;

typedef enum
{
    STACK_DEINIT = 0    ,
    STACK_INIT          ,
    STACK_OK            ,
    STACK_ERROR         ,
    STACK_ARG_ERROR     ,
    STACK_FULL          ,
    STACK_EMPTY         ,
    STACK_TOTAL
}en_stack_status_t;

st_stack_t *        stack_create    (int size);
en_stack_status_t   stack_push      (st_stack_t * ptr_st_a_stack, int   int_a_number    );
en_stack_status_t   stack_pop       (st_stack_t * ptr_st_a_stack, int * int_ptr_a_number);
en_stack_status_t   stack_print     (st_stack_t * ptr_st_a_stack);
en_stack_status_t   stack_is_empty  (st_stack_t * ptr_st_a_stack);
en_stack_status_t   stack_is_full   (st_stack_t * ptr_st_a_stack);

#endif //DAY2_STACK_H
