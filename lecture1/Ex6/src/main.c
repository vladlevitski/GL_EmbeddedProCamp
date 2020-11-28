#include <stdio.h>
#include "../headers/divider.h"

int main()
{  
    int n = 0;
    printf("Range: from %u up to %u\n", LOWER_LIMIT, UPPER_LIMIT);
    printf("Enter non zero integer number: ");

    while (1 == scanf("%d", &n) && n > 0)
    {
        divide(n);
        printf("\nEnter non zero integer number: ");
    }
    printf("Entered invalid number.");

    return 0;
}
