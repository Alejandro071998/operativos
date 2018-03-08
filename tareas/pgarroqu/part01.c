#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cCollatz(int var)
{
	if(var <= 1) printf(".\n");

	else if(var % 2 == 0)
	{
		var = var/2;
		printf("%i ", var);
		cCollatz(var);
	}

	else
	{
		var = (3 * var) + 1;
		printf("%i ", var);
		cCollatz(var);
	}
}

int main(int argc, char *argv[])
{
	int var = 10;
	pid_t pid;
	pid = fork();
	
	if(pid < 0 || argc == 1)
	{
		printf("ERROR TENEDOR().\n");
		return -1;
	}
	else if(pid == 0)
	{
		var = atoi(argv[1]);
		cCollatz(var);
	}
	else
	{
		wait(NULL);
		printf("\nProceso terminado\n");
	}

	return 0;
}
