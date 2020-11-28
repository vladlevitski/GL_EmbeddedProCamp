#include "../headers/divider.h"

void divide(int divider)
{
    printf("Sequence of numbers divided by %d:\n", divider);
    for(int num = LOWER_LIMIT; num <= UPPER_LIMIT; ++num)
    {
        if (num % divider == 0)
        {
            printf("%d ", num);
        }
    }
    printf("\n");
}
