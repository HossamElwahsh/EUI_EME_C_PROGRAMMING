#include "test.h"
#include "bus_reserve_app.h"
#include "std.h"

void init_bus_tests()
{
    bus_init();
    init_users();
}

void test_bus_login()
{
    int int_l_test_cases = 4;

    init_bus_tests();

    char input_data[4][2][10] = {
            {
                "hossam",
                "123"
            },
            {
                "hossam",
                "wrong"
            },
            {
                "wrong",
                "123"
            },
            {
                "super",
                "mario"
            },
    };

    en_user_status_t expected_results[4] = {
            USER_OK,
            USER_ERROR,
            USER_ERROR,
            USER_ERROR,
    };

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\ttest_bus_login()\n");
    printf("==================================\n");

    for (int i = 0; i < int_l_test_cases; ++i)
    {
        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");

        printf("Input Data:\n\tUsername:\t %s\n\tPassword:\t %s\n",input_data[i][0], input_data[i][1]);

        en_user_status_t en_user_status = login(input_data[i][0], input_data[i][1], (void *) 0);

        printf("\nExpected:\n\t%s\n", expected_results[i] == USER_OK ? "login success" : "login fail");

        printf("\nActual Result:\n\t%s\n", en_user_status == USER_OK ? "login success" : "login failed");

        printf("\n\nTest Result:\n\t%s\n", en_user_status == expected_results[i] ? "PASS" : "FAIL");
    }

}

void test_user_retrieve_user()
{
    int int_l_test_cases = 2;

    /* init environment */
    init_bus_tests();

    char input_data[2] = {1,5};

    en_user_status_t expected_results[2] = {
            USER_OK,
            USER_ERROR
    };

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\tretrieve_user()\n");
    printf("==================================\n");

    for (int i = 0; i < int_l_test_cases; ++i)
    {
        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");

        printf("Input Data:\n\tUser ID:\t %d\n",input_data[i]);

        st_user_t * st_user;

        en_user_status_t en_user_status = retrieve_user(input_data[i], &st_user);

        printf("\nExpected:\n\t%s\n", expected_results[i] == USER_OK ? "User exist" : "User doesn't exist");

        printf("\nActual Result:\n\t%s\n", en_user_status == USER_OK ? "User exist" : "User doesn't exist");

        printf("\n\nTest Result:\n\t%s\n", en_user_status == expected_results[i] ? "PASS" : "FAIL");
    }

}

void test_bus_all()
{
    test_bus_login();
    test_user_retrieve_user();
}