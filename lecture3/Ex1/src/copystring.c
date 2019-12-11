#include <string.h>
#include "../headers/copystring.h"


void str_copy(char *input, char *target)
{
	for (int i = 0; i < strlen(input); ++i)
	{	
		target[i] = input[i];	
	}
}