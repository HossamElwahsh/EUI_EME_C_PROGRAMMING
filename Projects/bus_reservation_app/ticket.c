#include "ticket.h"

/* Private includes */
#include "user.h"
#include "std.h"
#include "bus.h"

/**
 * @brief
 * @param[in]   customer_id       : Customer ID
 * @param[in]   bus_id            : Bus to reserve
 * @param[in]   ticket_seats      : how many seats to reserve
 * @param[out]  ticket_id         : pointer to store ticket id
 *
 * @return      TICKET_OK         : If success
 *              TICKET_ERROR      : If failed
 *              _TOO_MANY_RESERV  : If user exceeded allowed reservations
 */
en_ticket_status_t book_ticket(int customer_id, int bus_id, int ticket_seats, int * ticket_id)
{
    en_ticket_status_t en_ticket_status_retval = TICKET_OK;
    st_user_t * st_user = NULL_PTR;

    if(USER_OK == retrieve_user(customer_id, &st_user))
    {
        /* REQ-10: User can only book a maximum of 2 tickets */
        if(MAX_RESERVATIONS_PER_USER <= st_user->reserved_tickets_count)
        {
            en_ticket_status_retval = TICKET_TOO_MANY_RESERVATIONS;
            printf("\n\t[INFO] Sorry, our policy only allows 2 tickets per user.\n");
        }
        else
        {
            /* User can book */

            /* Check bus availability */
            if(BUS_OK == bus_reserve_seats(bus_id, ticket_seats))
            {
                /* Seats reserved successfully, complete booking */
                /* Create ticket */
                int ticket_index = st_user->reserved_tickets_count;

                st_user->st_ticket_user_reservations[ticket_index].bus_id = bus_id;
                st_user->st_ticket_user_reservations[ticket_index].ticket_seats = ticket_seats;
                st_user->st_ticket_user_reservations[ticket_index].customer_id = customer_id;
                st_user->st_ticket_user_reservations[ticket_index].ticket_id = GET_TICKET_ID_FROM_INDEX(ticket_index);

                /* Increment user tickets count */
                st_user->reserved_tickets_count++;

                /* Save ticket id */
                if(NULL_PTR != ticket_id)
                {
                    *ticket_id = GET_TICKET_ID_FROM_INDEX(ticket_index);
                }

                /* Print ticket */
                printf("\n\nYour Reservation Info:\n");
                printf("\tTicket ID: #%d\n", GET_TICKET_ID_FROM_INDEX(ticket_index));
                printf("\tSeats:%d\n", ticket_seats);
                printf("---------------------------");
            }
            else
            {
                /* Bus not available */
                printf("\n[ERROR] Bus # not available, please try again\n");
                en_ticket_status_retval = TICKET_ERROR;
            }

        }
    }
    else
    {
        /* User not found */
#if DEBUG == TRUE
        printf("\n\n[DEBUG] User ID %d not found\n", customer_id);
#endif

        en_ticket_status_retval = TICKET_ERROR;
    }

    return en_ticket_status_retval;
}

en_ticket_status_t cancel_ticket(int customer_id, int ticket_id)
{
    en_ticket_status_t en_ticket_status_retval = TICKET_OK;
    int ticket_index = GET_BUS_INDEX_FROM_ID(ticket_id);

    st_user_t * ptr_st_user = NULL_PTR;
    if(USER_OK == retrieve_user(customer_id, &ptr_st_user))
    {
        /* validate ticket id */
        if(ticket_index < ptr_st_user->reserved_tickets_count)
        {
            /* free bus seats */
            bus_free_seats(ptr_st_user->st_ticket_user_reservations[ticket_index].bus_id,
                           ptr_st_user->st_ticket_user_reservations[ticket_index].ticket_seats
                           );

            printf("\n\n[INFO] Ticket ID# %d has been cancelled.\n\n", GET_TICKET_ID_FROM_INDEX(ticket_index));

            /* shift array back to delete ticket */
            for (int i = ticket_index; i < ptr_st_user->reserved_tickets_count - 1; ++i)
            {
                ptr_st_user->st_ticket_user_reservations[i] = ptr_st_user->st_ticket_user_reservations[i+1];
            }

            /* Decrement user reservations count */
            ptr_st_user->reserved_tickets_count--;
        }
        else
        {
            /* reservation not found or invalid */
            printf("\n\n[ERROR] Ticket not found.\n\n");
            en_ticket_status_retval = TICKET_ERROR;
        }
    }
    else
    {
        /* user not found */
        en_ticket_status_retval = TICKET_ERROR;
    }

    return en_ticket_status_retval;
}