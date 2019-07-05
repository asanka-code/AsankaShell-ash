#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char *argv[])
{	
	if(strcmp("name", argv[1]) == 0)
	{
		printf("Manual page of 'name' command. \n This command simply prints the full name of the programmer.\n");	
		printf("Run it by issueing: \n name \n");	
	} else if(strcmp("add", argv[1]) == 0)
	{
		printf("Manual page of 'add' command.\n This command take two integer values as arguents and prints the sum.\n");	
		printf("Run it by issueing: \n add number1 number2 \n");	
	} else
	{
		printf("No manual page for the given input\n");
	}
	
}
