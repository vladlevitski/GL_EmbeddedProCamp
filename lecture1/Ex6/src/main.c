#include <stdio.h>
#include "../headers/divider.h"

int main()
{  
    double n = 0;
    printf("Range: from %u up to %u\n", LOWER_LIMIT, UPPER_LIMIT);
    printf("Enter non zero and non negative number from the range: ");

    while (1 == scanf("%lf", &n) && n > 0)
    {
        if((n >= LOWER_LIMIT) && (n <= UPPER_LIMIT))
        {
            divide(n);
        }
        else
        {
            printf("Entered number out of range.");
        }
        printf("Enter non zero and non negative number from the range: ");
    }

    return 0;
}
