#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  if(argc < 2 || argc > 2){
    perror("Error, entrada invalida");
  }else{
    int num = atoi(argv[1]);
    if(num==0){
      perror("Error, entrada invalida");
    }else{
      pid_t pid;
      for(int i = 0;i<num; i++){
        pid = fork();
        if(pid < 0){
          perror("Error en la llamada a fork()");
          return -1;
        }else if(pid == 0){
          printf("Hijo #%d: PID = %d, PPID = %d\n",i+1,getpid(),getppid());
          exit(0);
        }else{
          wait(NULL);
        }
      }
    }
  }
  return 0;
}
