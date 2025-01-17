#include "common.h"
#include "hoge.h"
#include "piyo.h"
#include "fake.h"
#include <stdlib.h>

int	main(void)
{
	// int num = 0;
	int *arr = malloc(1 * sizeof(int));
	arr[1] = 42;
	print("this is mandatory\n");
	func();
	piyo();
	hoge();
	return (0);
}
