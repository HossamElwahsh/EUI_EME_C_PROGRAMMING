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

en_calc_error_t add         (double x, double y, double * result);
en_calc_error_t sub         (double x, double y, double * result);
en_calc_error_t multiply    (double x, double y, double * result);
en_calc_error_t divide      (double x, double y, double * result);
en_calc_error_t power       (double x, double y, double * result);
en_calc_error_t factorial   (double x, double * result);

typedef en_calc_error_t (*calc_fun)  (double,   double,      double *   ); // function pointer type for addition

#define CALC(en_calc_types_t,x,y,res) (* (calc_fun)calculator_arr[en_calc_types_t])(x, y, &result)

extern calc_fun calculator_arr[];

#endif //DAY2_CALCULATOR_H
