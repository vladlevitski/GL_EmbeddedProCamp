#include "../headers/factorial.h"

int factorial(int num)
{
    int res = 1;
    if(num == 0 || num == 1)
    {
        return 1;
    }
    for(int i = 1; i <= num; ++i)
    {
        res *= i;
    }
    return res;
}
