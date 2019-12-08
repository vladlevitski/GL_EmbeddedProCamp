#include "../headers/find_biggest.h"

int find_biggest(int* begin, int* end)
{
    int biggest = *begin;
    ++begin;
    while (begin < end)
    {
        if (*begin > biggest)
        {
            biggest = *begin;
        }
        ++begin;
    }
    return biggest;
}
