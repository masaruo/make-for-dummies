#include <stdio.h>
# define STR "hello world from #define"
const char	*str = "hello world from const";
int main(void)
{
	printf("%s\n", STR);
	printf("%s\n", str);
#ifdef DEBUG
	printf("this is debug\n");	
#endif
	return (0);
}