// CS2211a 2023, Section 1
// Assignment 4
// Stephen Bian
// 251287906
// sbian23
// November 13th 2023
// ====== this is in bst.c
#include <stdio.h>

int main()
{
    // initializing variables
    double e = 1.0, epsilon, t = 1.0;
    long long fac = 1;
    int yesNo = 1;

    // while loop to repeat the process for the user
    while (yesNo == 1)
    {
        // takes in user input for epsilon
        printf("Enter a number for epsilon: ");
        scanf("%lf", &epsilon);

        // initialize integer
        int n = 1;
        // finding e
        while (t >= epsilon)
        {
            fac *= n;
            t = 1.0 / fac;
            e += t;
            n++;
        }
        // presenting the value of e
        printf("e: %.15lf\n", e);
        // asking the user if they want to continue
        printf("To enter another epsilon, enter 1, otherwise enter 0:");
        scanf("%d", &yesNo);
    }

    return 0;
}