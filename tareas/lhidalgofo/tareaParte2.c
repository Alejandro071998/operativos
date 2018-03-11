#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void childFunct(int i){
   printf("\nChild number: %i \nPID: %d \nPPID: %d \n", i, getpid(), getppid());
   
}
int main(int argc, char *argv[])
{
	int numberOfChilds = strtol(argv[1], NULL, 10);
	int i=1;

	pid_t pid;
	
	while(i<=numberOfChilds)
	{
	    pid = fork();

	        if(argc==1 || pid < 0 ) 
			return -1;

		else if(pid == 0)
		{
			childFunct(i);
			return 0;
		}
			
		else 
		{	
			wait(NULL);
		}

	    ++i;
	
	}

        return 0;
}
