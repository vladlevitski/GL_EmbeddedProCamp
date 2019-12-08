#include <stdio.h>
#include "../headers/copydigits.h"

#define MAX_SIZE 101

int main()
{

    char in_str[MAX_SIZE] = "\0";
    char out_str[MAX_SIZE] = "\0";

    printf("Please enter a string of %d characters or shorter: ", MAX_SIZE - 1);
    fgets(in_str, MAX_SIZE, stdin);

    copy_digits(in_str, out_str);

    printf("Digits from provided string: ");
    puts(out_str);

    return 0;
}
