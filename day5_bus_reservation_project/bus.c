#include "bus.h"
#include "cqueue_interface.h"

/* Private vars */
static st_bus_t st_buses[MAX_BUSES];
int buses_count = ZERO;

void bus_init(void)
{
    st_bus_data_t st_bus_data =
            {
                    20,
                    "",
                    "Alexandria",
                    "Cairo",
                    "12/8/2023 1:00 PM",
                    3*60
            };

    bus_add(st_bus_data, NULL_PTR);

    st_bus_data.depart_station = "Cairo";
    st_bus_data.arrive_station = "Alexandria";
    st_bus_data.depart_datetime = "12/8/2023 4:00 PM";

    bus_add(st_bus_data, NULL_PTR);
}

/**
 * @brief                   :   Creates a new bus, returns bus ID
 *
 * @param st_a_bus_data     :   bus data
 * @param intptr_a_bus_id   :   created bus id
 *
 * @return  BUS_OK          :   Bus added successfully
 *          BUS_ERROR       :   No more slots available
 */
en_bus_status_t bus_add     (st_bus_data_t st_a_bus_data, int * intptr_a_bus_id)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;
    int bus_id = buses_count + 1;

    if(MAX_BUSES == buses_count)
    {
        en_bus_status_retval = BUS_ERROR;
        printf("\n\nNo more slots for extra buses.\n\n");
    }
    else
    {
        st_buses[buses_count].bus_id = bus_id;
        st_buses[buses_count].st_bus_data = st_a_bus_data;
        st_buses[buses_count].available_seats = st_a_bus_data.max_bus_seating;
        st_buses[buses_count].st_bus_data.max_bus_seating = st_a_bus_data.max_bus_seating;
    }

    /* Return Bus ID */
    if(NULL_PTR != intptr_a_bus_id)
    {
        *intptr_a_bus_id = bus_id;
    }

    /* Increment buses count */
    buses_count++;

    return en_bus_status_retval;
}

en_bus_status_t bus_delete  (int int_a_bus_id)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;
    int bus_index = int_a_bus_id - 1;

    /* Check if bus exists */
    if(bus_index < buses_count)
    {
        /* Delete bus then shift array */
        for (int i = bus_index; i < buses_count-1; ++i)
        {
            /* Shift array */
            st_buses[i] = st_buses[i+1];
            st_buses[i].bus_id--;
        }

        /* Decrement total buses count */
        buses_count--;
    }
    else
    {
        /* Bus doesn't exist */
        en_bus_status_retval = BUS_ERROR;
    }

    return en_bus_status_retval;
}

/**
 * @brief                   :   Reserves a seat in bus
 * @param   bus_id          :   Bus ID
 *
 * @return  BUS_OK          :   If Success
 *          BUS_NO_BUSES    :   If Bus doesn't exist
 *          BUS_INVALID_ARGS:   If Invalid args given
 *          BUS_ERROR       :   If failed, no seating available
 */
en_bus_status_t bus_reserve_seats(int bus_id, int seats_count)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;
    int bus_index = GET_BUS_INDEX_FROM_ID(bus_id);

    /* Arg check */
    if((BUS_OK == bus_check_id(bus_id, NULL_PTR)) && (seats_count > ZERO))
    {
        st_bus_t bus = st_buses[bus_index];
        if(bus.available_seats == ZERO)
        {
            printf("\n\t[INFO] Sorry, bus is fully booked.\n");
            en_bus_status_retval = BUS_NO_SPACE;
        }
        else if(bus.available_seats < seats_count)
        {
            printf("\n\t[INFO] Sorry, only %d seat(s) are available.\n", bus.available_seats);
            en_bus_status_retval = BUS_NO_SPACE;
        }
        else
        {
            /* reserve seats */
            st_buses[bus_index].available_seats -= seats_count;
#if DEBUG == TRUE
            printf("\n\n[DEBUG] %d seat(s) reserved successfully\n\n", seats_count);
#endif

        }
    }
    else
    {
        en_bus_status_retval = BUS_INVALID_ARGS;
    }

    return en_bus_status_retval;
}


en_bus_status_t bus_free_seats(int bus_id, int seats_count)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;
    int bus_index = GET_BUS_INDEX_FROM_ID(bus_id);

    /* Arg check */
    if((BUS_OK == bus_check_id(bus_id, NULL_PTR)) && (seats_count > ZERO))
    {
        st_buses[bus_index].available_seats = st_buses[bus_index].available_seats + seats_count;
    }
    else
    {
        en_bus_status_retval = BUS_INVALID_ARGS;
    }

    return en_bus_status_retval;
}

/**
 * @brief               :   Checks if bus exist
 * @param bus_id
 * @param ptr_st_bus
 * @return  BUS_OK      :   If Success
 *          BUS_NO_BUSES:   If Bus doesn't exist
 */
en_bus_status_t bus_check_id  (int bus_id, st_bus_t * ptr_st_bus)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;
    int bus_index = GET_BUS_INDEX_FROM_ID(bus_id);

    /* Arg check */
    if((bus_index < ZERO) || (buses_count < bus_index))
    {
        /* Wrong bus */
        en_bus_status_retval = BUS_NO_BUSES;
    }
    else
    {
        if(NULL_PTR != ptr_st_bus)
        {
            *ptr_st_bus = st_buses[bus_index];
        }
    }

    return en_bus_status_retval;
}

/**
 * @brief                   :   Prints all buses with free seats
 *
 * @return  BUS_OK          :   Bus added successfully
 *          BUS_NO_BUSES    :   No buses with empty seats available
 */
en_bus_status_t bus_show_buses  (void)
{
    en_bus_status_t en_bus_status_retval = BUS_OK;

    boolean is_av_buses_with_seats = FALSE;

    printf("\nAvailable Buses:\n\t");
    printf("Bus #\tseats\tdepart_time\t\tduration\ttrip\n\t");
    printf("------\t-----\t-----------------\t--------\t-------------------\n\t");

    /* Loop over buses */
    for (int i = 0; i < buses_count; ++i)
    {
        /* Check for available seating */
        if(
                st_buses[i].available_seats != ZERO)
        {
            is_av_buses_with_seats = TRUE;

            printf("%d\t%d\t%s\t%d mins\t%s -> %s\n\t",
                   st_buses[i].bus_id,
                   st_buses[i].available_seats,
                   st_buses[i].st_bus_data.depart_datetime,
                   st_buses[i].st_bus_data.trip_duration_min,
                   st_buses[i].st_bus_data.depart_station,
                   st_buses[i].st_bus_data.arrive_station
            );
        }
    }

    /* REQ-5 */
    if(
            (FALSE == is_av_buses_with_seats) ||
            (ZERO  == buses_count)
            )
    {
        printf("\t\tSorry, no buses available\n\t");
        en_bus_status_retval = BUS_NO_BUSES;
    }

//        printf("------\t-----\t12/8/2023 1:08 PM\t\t--------\tAlexandria -> Cairo\n");
    printf("------\t-----\t-----------------\t--------\t-------------------\n");

    return en_bus_status_retval;
}