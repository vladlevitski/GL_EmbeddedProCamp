#include <string.h>
#include <ctype.h>
#include "../headers/copydigits.h"

void copy_digits(char *input, char *target)
{
    int i, j = 0;
    int len = strlen(input);

    for (i = 0; i < len; ++i)
    {
        if ((isdigit(input[i])) || (input[i] = '\0'))
        {
            target[j] = input[i];
            ++j;
        }
    }
}
