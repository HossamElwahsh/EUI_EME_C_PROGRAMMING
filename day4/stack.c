//
// Created by hossam on 8/11/23.
//

#include "stack.h"

/**
 * Creates and returns a new stack
 * @param ptr_st_a_stack    : stack pointer
 * @param size              : size of stack
 * @return
 */
st_stack_t * stack_create(int size)
{
    st_stack_t * ptr_st_stack = calloc(1, sizeof (st_stack_t));

    /* initialize stack */
    ptr_st_stack->top = -1;
    ptr_st_stack->size = size;
    ptr_st_stack->int_stack_arr = (int *) calloc(size, sizeof(int));

    return ptr_st_stack;
}

/**
 * Pushes a number to stack
 * @param ptr_st_a_stack    :   Stack pointer
 * @param int_a_number      :   Number to push
 */
en_stack_status_t stack_push(st_stack_t * ptr_st_a_stack, int int_a_number)
{
    en_stack_status_t en_stack_status_retval = STACK_OK;

    if(NULL_PTR != ptr_st_a_stack)
    {
        if(STACK_FULL == stack_is_full(ptr_st_a_stack))
        {
            printf("\n\nError Stack Full\n\n");
            en_stack_status_retval = STACK_FULL;
        }
        else
        {
            /* Stack not full, push number into stack */
            INCREMENT(ptr_st_a_stack->top);
            ptr_st_a_stack->int_stack_arr[ptr_st_a_stack->top] = int_a_number;
            printf("\n[Stack]: pushed\t%d\tin pos:\t%d\n", int_a_number, ptr_st_a_stack->top);
        }
    }
    else
    {
        printf("\n\nInvalid stack given\n\n");
        en_stack_status_retval = STACK_ARG_ERROR;
    }
}

/**
 * @brief pops a number from stack
 *
 * @param[out] ptr_st_a_stack   :   Stack pointer
 * @param int_ptr_a_number      :   Pointer to int to pop into
 * @return  STACK_OK            :   If success
 *          STACK_EMPTY         :   If stack is empty
 */
en_stack_status_t stack_pop(st_stack_t * ptr_st_a_stack, int * int_ptr_a_number)
{
    en_stack_status_t en_stack_status_retval = STACK_OK;

    if(NULL_PTR != ptr_st_a_stack)
    {
        if(STACK_EMPTY == stack_is_empty(ptr_st_a_stack))
        {
            printf("\n\nError Stack Empty\n\n");
            en_stack_status_retval = STACK_EMPTY;
        }
        else
        {
            /* Stack not empty, pop number from stack */
            *int_ptr_a_number = ptr_st_a_stack->int_stack_arr[ptr_st_a_stack->top];
            printf("\n[Stack]: popped\t%d\tfrom pos:\t%d\n", *int_ptr_a_number, ptr_st_a_stack->top);
            DECREMENT(ptr_st_a_stack->top);
        }
    }
    else
    {
        printf("\n\nInvalid stack given\n\n");
        en_stack_status_retval = STACK_ARG_ERROR;
    }

    return en_stack_status_retval;
}

/**
 * Checks if stack is empty or not
 * @param ptr_st_a_stack    : Stack to check
 */
en_stack_status_t stack_is_empty(st_stack_t * ptr_st_a_stack)
{
    en_stack_status_t en_stack_status_retval = STACK_OK;

    if(NULL_PTR != ptr_st_a_stack)
    {
        /* check if stack is empty == top is -1 */
        if(-1 == ptr_st_a_stack->top)
        {
            en_stack_status_retval = STACK_EMPTY;
        }
    }
    else
    {
        printf("\n\nInvalid stack given\n\n");
        en_stack_status_retval = STACK_ARG_ERROR;
    }

    return en_stack_status_retval;

}

/**
 * Checks if stack is full or not
 * @param ptr_st_a_stack    : Stack to check
 */
en_stack_status_t stack_is_full(st_stack_t * ptr_st_a_stack)
{
    en_stack_status_t en_stack_status_retval = STACK_OK;

    if(NULL_PTR != ptr_st_a_stack)
    {
        /* check if stack is empty == top is -1 */
        if((ptr_st_a_stack->size-1) == ptr_st_a_stack->top)
        {
            en_stack_status_retval = STACK_FULL;
        }
    }
    else
    {
        printf("\n\nInvalid stack given\n\n");
        en_stack_status_retval = STACK_ARG_ERROR;
    }

    return en_stack_status_retval;
}

en_stack_status_t stack_print(st_stack_t * ptr_st_a_stack)
{
    en_stack_status_t en_stack_status_retval = STACK_OK;

    int number_buffer = 0;

    /* arg check */
    if(NULL_PTR != ptr_st_a_stack)
    {
        /* Check if stack is empty */
        if(STACK_EMPTY == stack_is_empty(ptr_st_a_stack))
        {
            printf("\n\nStack is empty.\n\n");
        }
        else
        {
            printf("\n\nStack:\n");
            while(STACK_OK == stack_pop(ptr_st_a_stack, &number_buffer))
            {
                printf("\t%d", number_buffer);
            }
        }
    }
    else
    {
        printf("\n\nInvalid stack given\n\n");
        en_stack_status_retval = STACK_ARG_ERROR;
    }

    return en_stack_status_retval;
}