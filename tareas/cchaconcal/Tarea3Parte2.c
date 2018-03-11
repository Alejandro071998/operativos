#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

	char* in = argv[1];
	int input=atoi(in);
int dato=input;
	
 pid_t pid;
 int x;
 
 for(x=1;x<=dato;++x)
 {
  
  pid=fork(); 
  if(!pid)
  {
   printf("Hijo #  %d",x);
   printf("PID = %d",getpid());
   printf("PPID = %d\n",getppid());
   sleep(2);
   exit(0);
  }
else{
	wait(NULL);
	}  
 }
 return 0;
}

