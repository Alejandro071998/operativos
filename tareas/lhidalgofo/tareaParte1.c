#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int collatz(int i)
{

	pid_t childPid, pid;
	int waiting = 0;

	if ((childPid = fork())==0)
    	{
		while(i != 1)
		{
		    printf("%d ", i);

		    if(i%2==0)
		        i/=2;

		    else
		        i = 3*i+1;
		}
	        printf("1\n");
		exit(1);
	}

	while((pid = wait(&waiting))>0)
        	printf("Child process ended\n");

    return 0;

}

int main(int argc, char *argv[])
{

    int arg = strtol(argv[1], NULL, 10);
    

	if(arg>0)
           collatz(arg);

	else
       	   printf("Please enter a valid number\n");


	return 0;
}
