#include <stdio.h>
#include "../headers/find_biggest.h"

#define SIZE 10

int main()
{
    int arr[SIZE] = {1,7,5,3,9,11,4,6,0,8};

    printf("The biggest integer is: %d \n", find_biggest(arr, arr + SIZE));

    return 0;
}
