#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void collatz(int);

int main(int argc, char const *argv[]) {
  if(argc < 2 || argc > 2){
    perror("Error, entrada invalida");
  }else{
    int num = atoi(argv[1]);
    if(num==0){
      perror("Error, entrada invalida");
    }else{
      pid_t pid;
      pid = fork();
      if(pid < 0){
        perror("Error en la llamada a fork()");
        return -1;
      }else if(pid == 0){
        if(num == 1){
          printf("%d\n",1);
        }else{
          collatz(num);
        }
      }else{
        wait(NULL);
      }
    }
  }
  return 0;
}

void collatz(int num){
  printf("%d, ", num);
  while(num!=1){
    if(num%2 == 0){
      num = num/2;
      if(num == 1){
        printf("%d\n",num);
      }else{
        printf("%d, ",num);
      }
    }else{
      num = (num*3) +1;
      printf("%d, ",num);
    }
  }
}
