#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int (*f)(int);

int increment(int a)
{
    puts("Call increment");
    return a = a + 1;
}

int decrement(int a)
{
    puts("Call decrement");
    return a = a - 1;
}

int func(int (*function))
{
    return function;
}


int main ()
{
    f = &decrement;
    printf("a = 2 -> call func() -> a = %d\n", func(f(2)));
    
    f = &increment;
    printf("a = 2 -> call func() -> a = %d\n", func(f(2)));
    
    return 0;
}