#include <stdio.h>
#include "../headers/swap.h"

int main()
{
    uint16_t u16_number = 0xAABB;
    printf("Swapping bytes uint16_t %X\n", u16_number);
    swap16(&u16_number);
    printf("After swapping uint16_t %X\n\n", u16_number);

    uint32_t u32_number = 0xAABBCCDD;
    printf("Swapping bytes uint32_t %X\n", u32_number);
    swap32(&u32_number);
    printf("After swapping uint32_t %X\n\n", u32_number);

    uint64_t u64_number = 0xAABBCCDDEEFF1122;
    printf("Swapping bytes uint64_t %lX\n", u64_number);
    swap64(&u64_number);
    printf("After swapping uint64_t %lX\n\n", u64_number);

    return 0;
}
