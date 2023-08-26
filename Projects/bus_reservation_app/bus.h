#ifndef DAY2_BUS_H
#define DAY2_BUS_H

#include "stdio.h"

#define MAX_BUSES 10
#define GET_BUS_INDEX_FROM_ID(x) (x-1)
#define DEBUG FALSE
typedef struct
{
    int max_bus_seating;
    char * line_desc;
    char * depart_station;
    char * arrive_station;
    char * depart_datetime;
    int trip_duration_min;
}st_bus_data_t;

typedef struct
{
    int bus_id;
    st_bus_data_t st_bus_data;
    int available_seats;
}st_bus_t;

typedef enum
{
    BUS_OK  =   0   ,
    BUS_NO_BUSES    ,
    BUS_NO_SPACE    ,
    BUS_ERROR       ,
    BUS_INVALID_ARGS,
    BUS_TOTAL
}en_bus_status_t;

void bus_init();
en_bus_status_t bus_add             (st_bus_data_t st_a_bus_data,   int * intptr_a_bus_id);
en_bus_status_t bus_delete          (int int_a_bus_id);
en_bus_status_t bus_reserve_seats   (int bus_id,                    int seats_count);
en_bus_status_t bus_free_seats      (int bus_id,                    int seats_count);
en_bus_status_t bus_check_id        (int bus_id,                    st_bus_t * ptr_st_bus);
en_bus_status_t bus_show_buses      (void);

#endif //DAY2_BUS_H
