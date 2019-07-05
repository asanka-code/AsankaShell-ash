#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <string.h>

void main() 
{ 
	printf("Starting Asanka's Shell Program...\n"); 

	// char array to hold the command entered by the user
	char input[50];

	// a char array to hold the splitted words of the commmand (maximum 3 words each 10 chars long)
	char splitCommand[10][10];

	int j, count;

	while(1)
	{
		// Ask user to enter a command
		printf("asanka@AsankaBash>");

		// Read the user input using fgets (scanf does a poor job when reading strings with space)
		fgets(input, 50, stdin);
		//printf("Input length: %d \n", (int) strlen(input));

		// Splitting the command into pieces (We do it manually because 
		// strtok command seems not doing it the way we want)
    	j=0; count=0;
    	for(int i=0;i<=(strlen(input));i++)
    	{
        	// if space or NULL found, assign NULL into splitCommand[cnt]
			if(input[i]==' '|| input[i]=='\0' || input[i]=='\n')
        	{
            	splitCommand[count][j]='\0';
            	count++;  //for next word
            	j=0;    //for next word, init index to 0
        	}
        	else
        	{
           		splitCommand[count][j]=input[i];
            	j++;
        	}
    	}
		// Now, the 'count' variable contains how many words we produced after splitting
		//for(int i=0;i < count;i++)
        //	printf("word: %s length: %d\n",splitCommand[i], (int) strlen(splitCommand[i]));
		//printf("Number of words in the command: %d \n", count);
		
		// starting a new process
		int pid = fork(); 

		// if return value is 0, that's child. Parent gets the child's id.
		if(pid == 0)
		{
			// By default, we are passing all the three arguments. Some of them can be empty but it's OK.
			char *commandline_arguments[] = {splitCommand[0], splitCommand[1], splitCommand[2], NULL};
			execve(splitCommand[0], commandline_arguments, 0);
		} else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
} 