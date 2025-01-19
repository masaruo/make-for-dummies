#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	fakeft_print(char *str)
{
	int len = strlen(str);
	write(1, str, len);
}
