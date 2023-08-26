//
// Created by hossam on 8/11/23.
//

#ifndef DAY2_CALCULATOR_H
#define DAY2_CALCULATOR_H

#include "std.h"

typedef enum
{
    CALC_OK     =   0,
    CALC_ERROR  =   1
}en_calc_error_t;

typedef enum
{
    CALC_ADD    =    0  ,
    CALC_SUB            ,
    CALC_MUL            ,
    CALC_DIV            ,
    CALC_POW            ,
    CALC_TOTAL
}en_calc_types_t;

static en_calc_error_t add         (double f64_a_x, double f64_a_y, double * ptr_f64_a_result);
static en_calc_error_t sub         (double f64_a_x, double f64_a_y, double * ptr_f64_a_result);
static en_calc_error_t multiply    (double f64_a_x, double f64_a_y, double * ptr_f64_a_result);
static en_calc_error_t divide      (double f64_a_x, double f64_a_y, double * ptr_f64_a_result);
static en_calc_error_t power       (double f64_a_x, double f64_a_y, double * ptr_f64_a_result);
static en_calc_error_t factorial   (double f64_a_number, double * ptr_f64_a_result);

/* function pointer type for calculator APIs */
typedef en_calc_error_t (*calc_fun)  (double,   double,      double *   );

/* Helping macro to use calculator APIs */
#define CALC(en_calc_types_t,x,y,res) (* (calc_fun)calculator_arr[en_calc_types_t])(x, y, &result)

/* calculator functions array */
extern calc_fun calculator_arr[];

/* Calculator main program */
void calculator_program();

#endif //DAY2_CALCULATOR_H
