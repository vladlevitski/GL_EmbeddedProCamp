#include <stdio.h>
#include "arrayqueue.h"

int main()
{
    if (put(5) == 0)
    {
        printf("Element %d puts into queue\n", 5);
    }
    
    if (put(6) == 0)
    {
        printf("Element %d puts into queue\n", 6);
    }
    
    if (put(7) == 0)
    {
        printf("Element %d puts into queue\n", 7);
    }
    
    int element = 0;
    if (get(&element) == 0)
    {
        printf("Element %d fetched from queue\n", element);
    }
    
    if (get(&element) == 0)
    {
        printf("Element %d fetched from queue\n", element);
    }
    
    if (put(12) == 0)
    {
        printf("Element %d puts into queue\n", 12);
    }
    
    element = 0;
    if (read(&element) == 0)
    {
        printf("Element %d read from queue\n", element);
    }

    element = 0;
    if (read(&element) == 0)
    {
        printf("Element %d read from queue\n", element);
    }

    if (get(&element) == 0)
    {
        printf("Element %d fetched from queue\n", element);
    }

    element = 0;
    if (read(&element) == 0)
    {
        printf("Element %d read from queue\n", element);
    }

    return 0;
}
