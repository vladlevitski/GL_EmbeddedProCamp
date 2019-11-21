#include <stdio.h>
#include "../headers/factorial.h"

int main()
{
    int n = 0;
    printf("Enter non negative integer number: ");

    while(1 == scanf("%u", &n) && n >= 0)
    {
        printf("Factorial: %u\n", factorial(n));
        printf("Enter non negative integer number: ");
    }

    return 0;
}
