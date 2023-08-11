
#include "test.h"

boolean match(char * str, char match)
{
    if(str[0] == match)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void auto_test_palindrome(void)
{
    char *test_cases_filename = CONCAT(TEST_DIR, "palindrome.csv");
    const char testCaseDelimiter[2] = ",";

    char testCase[256];

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\tis_palindrome()\n");
    printf("==================================\n");

    FILE *fp_test_cases;
    int i = 0;


    // redirect test case inputData to stdin
    fp_test_cases = fopen(test_cases_filename, "r");

    // read test case inputData
//        fgets(testCase, sizeof(testCase), fp_test_cases);
    while (fgets(testCase, sizeof(testCase), fp_test_cases)) {
        // split test case into tokens of input data & expected result (which was delimited by comma)

        FILE *fp_fake_stdin;
        char *inputData;
        char *expectedResult;
        int * arr = (int *) calloc(1, sizeof(int));
        int n = 0;

        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");

        inputData = strtok(testCase, testCaseDelimiter);

        arr[0] = atoi(inputData);
        n++;

        /* fetch array */
        while(TRUE)
        {
            inputData = strtok(NULL, testCaseDelimiter);

            if(NULL_PTR == inputData)
            {
                break;
            }
            arr = (int *) realloc(arr, (n+1) * sizeof (int));
            arr[n] = atoi(inputData);
            n++;
        }

        /* fetch expected result */
        fgets(testCase, sizeof(testCase), fp_test_cases);
        expectedResult = strtok(testCase, testCaseDelimiter);

        printf("Input Data:\n\t");
        for (int j = 0; j < n; ++j) {
            printf("%d\t", arr[j]);
        }
        printf("\nExpected:\t%s\n", expectedResult);

        printf("Actual Result:");

        /************* push input data to stdin ***************/
        fp_fake_stdin = freopen(CONCAT(TEST_DIR, "temp_stdin.txt"), "w+", stdin);
        fprintf(fp_fake_stdin, "%s\n", inputData);
        rewind(fp_fake_stdin);

        /************* Execute test case ***************/
        unsigned char ret = is_palindrome(arr, n);
        // turn on console logs

        printf("\n\nTest Result:\t");

        if(
                ((match(expectedResult, 'Y')) && (ret == TRUE)) ||
                ((match(expectedResult, 'N')) && (ret == FALSE))
        )
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }

        fclose(fp_fake_stdin);
        i++; // next test case

        free(arr);
    }

    fclose(fp_test_cases);
}


void auto_test_palindrome_digits(void)
{
    char *test_cases_filename = CONCAT(TEST_DIR, "palindrome_digits.csv");
    const char testCaseDelimiter[2] = ",";

    char testCase[256];

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\tis_palindrome_digits()\n");
    printf("==================================\n");

    FILE *fp_test_cases;
    int i = 0;


    // redirect test case inputData to stdin
    fp_test_cases = fopen(test_cases_filename, "r");

    // read test case inputData
//        fgets(testCase, sizeof(testCase), fp_test_cases);
    while (fgets(testCase, sizeof(testCase), fp_test_cases)) {
        // split test case into tokens of input data & expected result (which was delimited by comma)

        FILE *fp_fake_stdin;
        char *inputData;
        char *expectedResult;
        int number_to_test = 0;

        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");

        inputData = strtok(testCase, testCaseDelimiter);

        number_to_test = atoi(inputData);

        /* fetch expected result */
        fgets(testCase, sizeof(testCase), fp_test_cases);
        expectedResult = strtok(testCase, testCaseDelimiter);

        printf("Input Data:\n\t%d", number_to_test);
        printf("\nExpected:\t%s\n", expectedResult);

        printf("Actual Result:");

        /************* push input data to stdin ***************/
        fp_fake_stdin = freopen(CONCAT(TEST_DIR, "temp_stdin.txt"), "w+", stdin);
        fprintf(fp_fake_stdin, "%s\n", inputData);
        rewind(fp_fake_stdin);

        /************* Execute test case ***************/
        unsigned char ret = is_palindrome_digits(number_to_test);
        // turn on console logs

        printf("\n\nTest Result:\t");

        if(
                ((match(expectedResult, 'Y')) && (ret == TRUE)) ||
                ((match(expectedResult, 'N')) && (ret == FALSE))
        )
        {
            printf("OK\n");
        }
        else
        {
            printf("FAIL\n");
        }

        fclose(fp_fake_stdin);
        i++; // next test case

    }

    fclose(fp_test_cases);
}


void auto_test_shift_arr(void)
{
    char *test_cases_filename = CONCAT(TEST_DIR, "shift.csv");
    const char testCaseDelimiter[2] = ",";

    char testCase[256];

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\tshift_arr()\n");
    printf("==================================\n");

    FILE *fp_test_cases;
    int i = 0;


    // redirect test case inputData to stdin
    fp_test_cases = fopen(test_cases_filename, "r");

    // read test case inputData
//        fgets(testCase, sizeof(testCase), fp_test_cases);
    while (fgets(testCase, sizeof(testCase), fp_test_cases)) {
        // split test case into tokens of input data & expected result (which was delimited by comma)

        FILE *fp_fake_stdin;
        char *inputData;
        int number_to_test = 0;
        int shift_by = 0;
        int expectedResult = 0;
        int * arr = calloc(1, sizeof(int));
        int * exp_arr = NULL_PTR;
        int arr_size = 0;

        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");

        /* fetch input number */
        inputData = strtok(testCase, testCaseDelimiter);
        number_to_test = atoi(inputData);

        /* parse number to array */

        arr[0] = atoi(inputData);
        arr_size++;

        while(TRUE)
        {
            inputData = strtok(NULL, testCaseDelimiter);

            if(NULL_PTR == inputData)
            {
                break;
            }
            arr = (int *) realloc(arr, (arr_size+1) * sizeof (int));
            arr[arr_size] = atoi(inputData);
            arr_size++;
        }


        /* fetch shift by */
        fgets(testCase, sizeof(testCase), fp_test_cases);
        inputData = strtok(testCase, testCaseDelimiter);
        shift_by = atoi(inputData);


        /* fetch expected result */
        fgets(testCase, sizeof(testCase), fp_test_cases);
        inputData = strtok(testCase, testCaseDelimiter);
        exp_arr = calloc(arr_size, sizeof(int));
        exp_arr[0] = atoi(inputData);

        for (int j = 1; j < arr_size; ++j)
        {
            inputData = strtok(NULL, testCaseDelimiter);
            exp_arr[j] = atoi(inputData);
        }

        /* ---------------------- */

        printf("Input Data:\n");
        
        /* print input array */
        for (int j = 0; j < arr_size; ++j) {
            printf("\t%d", arr[j]);
        }

        printf("\n\nshift by:\n\t%d\n", shift_by);
        
        printf("\n\nExpected Result:\n");

        /* print expected array */
        for (int j = 0; j < arr_size; ++j) {
            printf("\t%d", exp_arr[j]);
        }

        printf("\n\nActual:");

        /************* push input data to stdin ***************/
        fp_fake_stdin = freopen(CONCAT(TEST_DIR, "temp_stdin.txt"), "w+", stdin);
        fprintf(fp_fake_stdin, "%s\n", inputData);
        rewind(fp_fake_stdin);

        /************* Execute test case ***************/
        shift_arr(arr, arr_size, shift_by);
        
        printf("\n\nTest Result:\t");

        boolean test_pass = TRUE;
        for (int j = 0; j < arr_size; ++j)
        {
            if(arr[j] != exp_arr[j])
            {
                test_pass = FALSE;
                break;
            }
        }

        switch (test_pass) {
            case TRUE:
                printf("Passed!\n---------------\n");
                break;
            case FALSE:
            default:
                printf("Failed!\n---------------\n");
        }

        fclose(fp_fake_stdin);
        i++; // next test case

    }

    fclose(fp_test_cases);
}

void auto_test_largest_area(void)
{
    char *test_cases_filename = CONCAT(TEST_DIR, "largest_area.csv");
    const char testCaseDelimiter[2] = ",";

    char testCase[256];

    printf("==================================\n");
    printf("Tester Name:\tHossam Elwahsh\n");
    printf("Function Name:\tfind_largest_area()\n");
    printf("==================================\n");

    FILE *fp_test_cases;
    int i = 0;


    // redirect test case inputData to stdin
    fp_test_cases = fopen(test_cases_filename, "r");

    // read test case inputData
//        fgets(testCase, sizeof(testCase), fp_test_cases);
    while (fgets(testCase, sizeof(testCase), fp_test_cases)) {
        // split test case into tokens of input data & expected result (which was delimited by comma)

        FILE *fp_fake_stdin;
        char *inputData;
        int expected = 0;
        int * arr = calloc(1, sizeof(int));
        int * exp_arr = NULL_PTR;
        int arr_size = 0;

        printf("\n-----------------------\n");
        printf("Test Case %d\n", i + 1);
        printf("-----------------------\n");


        /* parse number to array */
        inputData = strtok(testCase, testCaseDelimiter);
        arr[0] = atoi(inputData);
        arr_size++;

        while(TRUE)
        {
            inputData = strtok(NULL, testCaseDelimiter);

            if(NULL_PTR == inputData)
            {
                break;
            }
            arr = (int *) realloc(arr, (arr_size+1) * sizeof (int));
            arr[arr_size] = atoi(inputData);
            arr_size++;
        }


        /* fetch shift by */
        fgets(testCase, sizeof(testCase), fp_test_cases);
        inputData = strtok(testCase, testCaseDelimiter);
        expected = atoi(inputData);

        /* ---------------------- */

        printf("Input Data:\n");

        /* print input array */
        for (int j = 0; j < arr_size; ++j) {
            printf("\t%d", arr[j]);
        }

        printf("\n\nExpected Result:\n\t%d\n", expected);

        printf("\n\nActual:");

        /************* push input data to stdin ***************/
        fp_fake_stdin = freopen(CONCAT(TEST_DIR, "temp_stdin.txt"), "w+", stdin);
        fprintf(fp_fake_stdin, "%s\n", inputData);
        rewind(fp_fake_stdin);

        /************* Execute test case ***************/
        int result = find_largest_area(arr, arr_size);

        printf("\n\t%d", result);

        printf("\n\nTest Result:\t");

        if(result == expected)
        {
            printf("Passed!\n---------------\n");
        }
        else
        {
            printf("Failed!\n---------------\n");
        }

        fclose(fp_fake_stdin);
        i++; // next test case

    }

    fclose(fp_test_cases);
}


/**
 * Call this from main.c to test all project modules
 */
void testAll()
{
    auto_test_palindrome();
}
