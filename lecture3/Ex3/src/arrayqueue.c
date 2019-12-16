#include "arrayqueue.h"

int put(int element)
{
    if (quantity < MAX_SIZE)
    { 
        if (rear == MAX_SIZE - 1)
        {
            rear = -1;
        }
        arrayqueue[++rear] = element;
        ++quantity;
    }
    else
    {
        printf("<Error> No free memory\n");
        return 1;
    }
    return 0;
}

int get(int *element)
{
    if (quantity > 0)
    {
        if (front == MAX_SIZE)
        { 
            front = 0;
        }
        *element = arrayqueue[front++];
        --quantity;
    }
    else
    {
        printf("<Error> Queue is empty\n");
        return 1;
    }
    return 0;
}

int read(int *element)
{
    if (quantity > 0)
    {
        *element = arrayqueue[front];
    }
    else
    {
        printf("<Error> Queue is empty\n");
        return 1;
    }
    return 0;
}
