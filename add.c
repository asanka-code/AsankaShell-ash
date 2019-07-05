#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	//printf("Hello World Program! \n");

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int sum = a + b;
	printf("Sum: %d \n", sum);
}
