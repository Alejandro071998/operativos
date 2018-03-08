#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int numProce = atoi(argv[1]);
	pid_t pid;
	
	for(int i = 0; i < numProce; i++)
	{
		pid = fork();

		if(pid < 0 || argc == 1) return -1;
		else if(pid == 0)
		{
			
		}
		else 
		{	
			printf("\nHijo %i \t PID: %d \tPPID: %d \t\n", i, getpid(), getppid());
			exit(0);
		}
	}

	return 0;
}
