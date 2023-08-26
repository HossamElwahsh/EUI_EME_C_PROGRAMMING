# EUI / EME - Egypt Make Electronics
## Hossam Elwahsh - CLASS 3 - SEITECH
### C Programming

> This repository contains multiple tasks and projects completed during EME program in EUI.

#### Projects
- **Bus Reservation System**
  - valid login data (username, password):
    - `hossam:123`
    - `ahmed:987`
- **Mini-console calculator**
  - Supported operations:
    - (+) addition
    - (-) subtraction
    - (*) multiplication
    - (/) division
    - (^) power
    - (!) factorial

#### Mini Tasks
- Febonanci series
- Max stock trade profit finder
- Second biggest number finder (optimized)
- Swap 2 numbers in 4 different ways
- Palindrome checker
- Array shifter
- Stack Implementation

### How to use
> - Clone repo locally
> - In [main.c](main.c) file, uncomment required program to run
> - Build and run

### Video 👉 [showcase_video.mp4](Docs/showcase_video.mp4)

### Testing
> - Multiple auto-testing APIs are also available in main.c to test every task in this repository
> - You may also add extra test cases to the required module (test cases .csv) file found inside the directory [test/Testcases](test/TestCases)

Sample testing output
<details>
<summary>test output</summary>
==================================<br/>
Tester Name:    Hossam Elwahsh<br/>
Function Name:  is_palindrome()<br/>
==================================<br/>

-----------------------
Test Case 1
-----------------------
Input Data:
1       2       3       4       5
Expected:       N

Actual Result:

NOT Palindrome

Reverse:
5       4       3       2       1

Test Result:    OK

-----------------------
Test Case 2
-----------------------
Input Data:
4       5       1
Expected:       N

Actual Result:

NOT Palindrome

Reverse:
1       5       4

Test Result:    OK

-----------------------
Test Case 3
-----------------------
Input Data:
1       2       3       2       1
Expected:       Y

Actual Result:

Is Palindrome

Reverse:
1       2       3       2       1

Test Result:    OK

-----------------------
Test Case 4
-----------------------
Input Data:
1
Expected:       Y

Actual Result:

Is Palindrome

Reverse:
1

Test Result:    OK

-----------------------
Test Case 5
-----------------------
Input Data:
1       2
Expected:       N
Actual Result:

NOT Palindrome

Reverse:
2       1

Test Result:    OK
==================================<br/>
Tester Name:    Hossam Elwahsh<br/>
Function Name:  is_palindrome_digits()<br/>
==================================<br/>

-----------------------
Test Case 1
-----------------------
Input Data:
12345
Expected:       N

Actual Result:

NOT Palindrome

Reverse:
54321

Test Result:    OK
</details>