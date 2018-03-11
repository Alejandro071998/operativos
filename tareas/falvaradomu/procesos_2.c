#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

void createProcess(pid_t pid, int pi){
	pid_t pid1= fork();
	if(pid1==0){
		printf("Hijo #: %d PID: %d PPID: %d\n", pi, getpid(), pid);
		exit(0);
	}
}

int main(int argc, char** argv){
	pid_t pid, pid1;
  int num, i=1, status;
	//verificacion de dato valido en el parametro
  if(argc<=1 || isdigit(*argv[1])==0){
    printf("El valor digitado no es correcto, no se puede ejecutar el programa\n");
    exit(-1);
  }
  num = *argv[1]-'0';

	pid1=getpid(); //PID del padre
	pid=fork();
	  if(pid==0){
		printf("Hijo #: %d PID: %d PPID: %d\n", i, getpid(), pid1);
		return 0;
  }else{
		while(i<num){
			createProcess(pid1,++i);
			wait(NULL);
		}
		wait(NULL);
  }

  return 0;
}
