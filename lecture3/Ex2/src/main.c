#include <stdio.h>
#include "../headers/linkedstack.h"

int main()
{
    initList();
    
    if (push(5) == 0)
    {
        printf("Element %d pushed into stack\n", 5);
    }
    display();
    
    if (push(6) == 0)
    {
        printf("Element %d pushed into stack\n", 6);
    }
    display();
    
    if (push(7) == 0)
    {
        printf("Element %d pushed into stack\n", 7);
    }
    display();
    
    int element = 0;
    if (pop(&element) == 0)
    {
        printf("Element %d fetched from stack\n", element);
    }
    display();
    
    if (pop(&element) == 0)
    {
        printf("Element %d fetched from stack\n", element);
    }
    display();
    
    if (push(12) == 0)
    {
        printf("Element %d pushed into stack\n", 12);
    }
    display();
    
    element = 0;
    if (read(&element) == 0)
    {
        printf("Element %d read from stack\n", element);
    }
    display();

    return 0;
}
