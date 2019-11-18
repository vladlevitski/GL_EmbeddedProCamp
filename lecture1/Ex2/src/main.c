#include <stdio.h>
#include "../headers/rgb.h"

int main()
{
    uint32_t rgb = 0x00AABBCC;
    printf("RGB888: %X\n", rgb);
    convert_to_rgb565(&rgb);
    printf("RGB565: %X\n", rgb);

    return 0;
}
