//
// Created by Hossam Elwahsh on 8/6/2023.
//

#ifndef DAY2_MAX_PROFIT_FINDER_H
#define DAY2_MAX_PROFIT_FINDER_H

#include "std.h"

/* Helping macros */
#define MIN_REQ_DAYS    2

/* If set to TRUE, finds maximum profit from multiple buy & sells transactions
 * If set to FALSE, finds maximum profit from a single buy & sell transaction
 * */
#define GOD_MODE        TRUE

//typedef unsigned char boolean;

int find_max_profit(int * arr, int n);

#endif //DAY2_MAX_PROFIT_FINDER_H
