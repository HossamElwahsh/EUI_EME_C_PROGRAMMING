
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


/**
 * Call this from main.c to test all project modules
 */
void testAll()
{
    auto_test_palindrome();
}
