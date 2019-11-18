#include "../headers/rgb.h"

void convert_to_rgb565(uint32_t *x)
{
    *x = ((((*x) & 0xf80000) >> 8)
          | (((*x) & 0xfc00) >> 5)
          | (((*x) & 0xf8) >> 3));
}
