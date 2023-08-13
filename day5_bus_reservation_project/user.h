//
// Created by hacke on 8/12/2023.
//

#ifndef DAY2_USER_H
#define DAY2_USER_H

#include "ticket.h"

/* REQ-10: User can only book a maximum of 2 tickets */
#define MAX_RESERVATIONS_PER_USER   2
#define MAX_USERS                   100
#define MAX_USERNAME_CHARS          20
#define MAX_PWD_CHARS               20

typedef struct
{
    int id;
    char * username;
    char * password;
    int reserved_tickets_count;
    /* REQ-10: User can only book a maximum of 2 tickets */
    st_ticket_t st_ticket_user_reservations[MAX_RESERVATIONS_PER_USER];
}st_user_t;

typedef enum
{
    USER_OK =   0       ,
    USER_INVALID_ARGS   ,
    USER_ERROR          ,
    USER_TOTAL
}en_user_status_t;

void init_users(void);

en_user_status_t login(char * username, char * password, int * ptr_usr_id);
en_user_status_t retrieve_user(int user_id, st_user_t ** ptr_ptr_st_user);
static en_user_status_t find_user(char * username, int * user_id);

#endif //DAY2_USER_H
