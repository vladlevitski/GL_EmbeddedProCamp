#include <stdio.h>
#include "../headers/rectangle.h"

int main()
{
    double height = 0;
    puts("Height in meters:");
    if(scanf("%lf", &height) != 1 || height < 0)
    {
        goto err1;
    }

    double width = 0;
    puts("Width in meters:");
    if(scanf("%lf", &width) != 1 || width < 0)
    {
        goto err1;
    }

    printf("Rectangle perimeter is %lf in\n",
           perimeter(height, width));
    printf("Rectangle area is %lf sq in\n",
           area(height, width));

    return 0;

err1:
    puts("Entered wrong value.\nExit with error.");
    return -1;

}
