#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

void collatz(int num);

int main(int argc, char** argv){
	pid_t pid;
  int num;

  if(argc<=1 || isdigit(*argv[1])==0){
    printf("El valor digitado no es correcto, no se puede ejecutar el programa\n");
    exit(-1);
  }
  num = *argv[1]-'0';
  pid=fork();

  if(pid==0){
    printf("se calculara el numero %d\n", num);
    collatz(num);
  }else{
    wait(NULL);

  }
  return 0;
}

void collatz(int num){
  printf("%d, ", num);
  if(num!=1)
    num%2==0?collatz(num/2):collatz((3*num)+1);
}
