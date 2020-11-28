#include <stdio.h>
#include <stdint.h>
#include "../headers/circle.h"

int main()
{
    uint32_t radius = 6;
    printf("Radius size is %d meters.\n", radius);
    printf("Area of circle: %f\n", area(radius));
    printf("Perimeter of circle: %f\n", perimeter(radius));

    return 0;
}
