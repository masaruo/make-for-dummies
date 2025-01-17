#include <unistd.h>
#include <string.h>

void	print(char *str)
{
	int len = strlen(str);
	write(1, str, len);
}
