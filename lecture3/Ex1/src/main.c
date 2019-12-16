#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "../headers/copystring.h"

int main()
{
	char str1[] = {"Hello world"};
	char str2[] = "\0";

	str_copy(str1, str2);
	puts(str2);
	return 0;
}