//
// Created by hacke on 8/12/2023.
//

#include "user.h"

/* Private includes */
#include "std.h"
#include "string.h"

/* Private Macros */
#define PREDEFINED_USERS_SIZE 2

/* Private Variable */
static st_user_t    st_users[MAX_USERS];
static int          users_count = PREDEFINED_USERS_SIZE;

void init_users(void)
{
    st_users[0].id = 0;
    st_users[0].username = "hossam";
    st_users[0].password = "123";
    st_users[0].reserved_tickets_count = ZERO;

    st_users[1].id = 1;
    st_users[1].username = "ahmed";
    st_users[1].password = "987";
    st_users[1].reserved_tickets_count = ZERO;
}

/**
 * @brief                               :   Tries to login with given username and password
 * @param[in]       username            :   char pointer to username
 * @param[in]       password            :   char pointer to user password
 *
 * @return          USER_OK             :   If success
 *                  USER_INVALID_ARGS   :   Invalid arguments given
 *                  USER_ERROR          :   If failed, username or password is incorrect
 */
en_user_status_t login(char * username, char * password, int * ptr_usr_id)
{
    en_user_status_t en_user_status_retval = USER_OK;
    int user_id = NOT_INIT;

    /* arg check */
    if((NULL_PTR != username) && (NULL_PTR != password))
    {
        /* find user in db */
        if(USER_OK == find_user(username, &user_id))
        {
            /* User found, check password */

            if(ZERO == strcmp(password, st_users[user_id].password)) // password OK/MATCH
            {
                /* Passwords match, allow login */

                /* return user id */
                if(NULL_PTR != ptr_usr_id)
                {
                    *ptr_usr_id = user_id;
                }
            }
            else
            {
                en_user_status_retval = USER_ERROR;
            }
        }
        else
        {
            /* Not found */
            en_user_status_retval = USER_ERROR;
        }
    }
    else
    {
        /* Invalid args */
        en_user_status_retval = USER_INVALID_ARGS;
    }

    return en_user_status_retval;

}

/**
 * @brief                               :   Searches for a user id in the database
 * @param[in]       username            :   char pointer for username to find
 * @param[in,out]   user_id             :   pointer to store found user id
 *
 * @return          USER_OK             :   If success
 *                  USER_INVALID_ARGS   :   Invalid arguments given
 *                  USER_ERROR          :   If failed, user not found
 */
static en_user_status_t find_user(char * username, int * user_id)
{
    en_user_status_t en_user_status_retval = USER_OK;
    boolean user_exists = FALSE;

    if((NULL_PTR == username) || (ZERO > user_id))
    {
        /* Invalid arguments */
        en_user_status_retval = USER_INVALID_ARGS;
    }
    else
    {
        /* Search db for username */
        for (int i = 0; i < users_count; ++i)
        {
            if(ZERO == strcmp(st_users[i].username, username)) // match
            {
                *user_id = i;
                user_exists = TRUE;
                break;
            }
            else
            {
                /* check next */
                continue;
            }
        }

        /* if user not found, update return value */
        if(FALSE == user_exists)
        {
            en_user_status_retval = USER_ERROR;
        }
    }

    return en_user_status_retval;
}

/**
 * @brief                               :   Searches for a user id in the database
 * @param[in]       username            :   char pointer for username to find
 * @param[in,out]   ptr_ptr_st_user         :   pointer to store user data
 *
 * @return          USER_OK             :   If success
 *                  USER_INVALID_ARGS   :   Invalid arguments given
 *                  USER_ERROR          :   If failed, user not found
 */
en_user_status_t retrieve_user(int user_id, st_user_t ** ptr_ptr_st_user)
{
    en_user_status_t en_user_status_retval = USER_OK;
    boolean user_exists = FALSE;
    int user_index = user_id - 1;


    if((NULL_PTR == ptr_ptr_st_user) || (ZERO > user_id))
    {
        /* Invalid arguments */
        en_user_status_retval = USER_INVALID_ARGS;
    }
    else
    {
        /* Valid user id/index */
        if(user_index < users_count)
        {
            /* update flag */
            user_exists = TRUE;

            /* return user */
            *ptr_ptr_st_user = &st_users[user_index];
        }
        else
        {
            en_user_status_retval = USER_ERROR;
        }

        /* if user not found, update return value */
        if(FALSE == user_exists)
        {
            en_user_status_retval = USER_ERROR;
        }
    }

    return en_user_status_retval;
}