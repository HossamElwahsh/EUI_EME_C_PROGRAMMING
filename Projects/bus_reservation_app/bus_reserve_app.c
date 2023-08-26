#include "bus_reserve_app.h"
#include "std.h"
#include "string.h"

boolean bool_logged_in = FALSE;

static void reserve_new_ticket(int user_id)
{
    int bus_id = NOT_INIT;
    int seats = NOT_INIT;

    bus_show_buses();
    printf("\nSelect bus #: ");
    scanf("%d", &bus_id);

    printf("\nHow many seats would you like to reserve: ");
    scanf("%d", &seats);

    book_ticket(user_id, bus_id, seats, NULL_PTR);
}

static void cancel_existing_ticket(int user_id)
{
    int ticket_id = NOT_INIT;

    printf("\nEnter Ticket ID to cancel #: ");
    scanf("%d", &ticket_id);

    cancel_ticket(user_id, ticket_id);
}

void bus_reservation_program_start(void)
{
    /* init users */
    init_users();

    /* init buses */
    bus_init();

    /* init variables */
    char username[MAX_USERNAME_CHARS] = {0};
    char password[MAX_PWD_CHARS] = {0};
    int action = NOT_INIT;
    int current_user_id = NOT_INIT;

    while (TRUE)
    {
        while (bool_logged_in == FALSE)
        {
            /* init flags */
            bool_logged_in = FALSE;

            printf("\tWelcome to Bus Reservation System\n");

            /* Get username */
            printf("Enter username:\n\t");
            fgets(username, MAX_USERNAME_CHARS, stdin);
            /* remove new line char */
            username[strcspn(username, "\n")] = 0;

            /* Get password */
            printf("\nEnter password:\n\t");
            fgets(password, MAX_USERNAME_CHARS, stdin);
            password[strcspn(password, "\n")] = 0;

            if(USER_OK == login(username, password, &current_user_id))
            {
                bool_logged_in = TRUE;
            }
            else
            {
                printf("\n[INFO] Invalid username or password, try again.\n\n");
                continue;
            }
        }

        /* User is logged in */
        /* reset flags */
        action = NOT_INIT;

        /* Prompt for action */
        printf("\nSelect Action (1,2,3,4):\n\t1. Show Available Trips\n\t2. Reserve new ticket\n\t3. Cancel existing ticket\n\t4. Logout\nSelection:\t");
        scanf("%d", &action);

        switch (action) {
            case 1: /* show available trips */
            {
                bus_show_buses();
                break;
            }
            case 2: /* reserve ticket */
            {
                reserve_new_ticket(current_user_id);
                break;
            }
            case 3: /* cancel ticket */
            {
                cancel_existing_ticket(current_user_id);
                break;
            }
            case 4: /* logout */
            {
                printf("\n\n[INFO] Logging out...\n\n\n");
                fflush(stdin);
                bool_logged_in = FALSE;
                continue;
            }
            default:
            {
                printf("\n\n[ERROR] Invalid action, try again.\n");
                break;
            }
            
        }
    }
}