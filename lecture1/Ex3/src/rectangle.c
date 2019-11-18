#include "../headers/rectangle.h"

double perimeter(double h, double w)
{
    return (2*(h + w)) / INCH;
}

double area(double h, double w)
{
    return (h / INCH) * (w / INCH);
}
