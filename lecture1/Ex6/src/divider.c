#include "../headers/divider.h"

void divide(double divider)
{
    printf("Sequence of divided numbers:\n");
    for(double num = LOWER_LIMIT; num <= UPPER_LIMIT; ++num)
    {
        printf("%lf ", (num / divider));
    }
    printf("\n");
}
