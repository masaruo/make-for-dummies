#include "main.h"
#include "common.h"
#include "hoge.h"
#include "piyo.h"

int	main(void)
{
	int *arr = malloc(1 * sizeof(int));
	arr[1] = 42;
	printf("this is mandatory\n");
	func();
	piyo();
	hoge();
	return (0);
}
