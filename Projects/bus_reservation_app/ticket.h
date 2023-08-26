//
// Created by Hossam Elwahsh on 8/12/2023.
//

#ifndef DAY2_TICKET_H
#define DAY2_TICKET_H

#define DEBUG FALSE
#define GET_TICKET_INDEX_FROM_ID(x) (x-1)
#define GET_TICKET_ID_FROM_INDEX(x) (x+1)

typedef struct
{
    int ticket_id;
    int customer_id;
    int bus_id;
    int ticket_seats;
}st_ticket_t;

typedef enum
{
    TICKET_OK   =   0               ,
    TICKET_ERROR                    ,
    TICKET_TOO_MANY_RESERVATIONS    ,
    TICKET_STATUS_TOTAL
}en_ticket_status_t;

en_ticket_status_t book_ticket(int customer_id, int bus_id, int ticket_seats, int * ticket_id);
en_ticket_status_t cancel_ticket(int customer_id, int ticket_id);

#endif //DAY2_TICKET_H
