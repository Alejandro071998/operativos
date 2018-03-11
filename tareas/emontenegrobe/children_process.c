#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int num, char* argc[]){

  if(argc[1] != NULL){
    num = atoi(argc[1]);
    pid_t pids[num];
    int status;
    pid_t pid;

    for(int i = 1; i <= num; i++) {

      if( (pids[i] = fork()) < 0 ){
        perror("Error en la llamada a fork().");
        return -1;
      }

      else if (pids[i] == 0) {
        printf("Hijo #%d: PID = %d, PPID = %d\n", i, getpid(), getppid());
        exit(0);
      }
    }

    while ( num > 0) {
      pid = wait(&status);
      printf("\n\nYa el proceso hijo terminó. Este es el proceso PADRE\n");
      --num;
    }
  }
  else{
    printf("Any argment was passed when the program was called");
  }
  return 0;
}
