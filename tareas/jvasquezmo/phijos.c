/* phijos.c
   Parte1.2

------------------------------------------------------------
Para compilar:

    prompt$ gcc phijos.c -o phijos

Para ejecutar:

    prompt$ ./phijos <numero>
------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  int i = 0, num, ppid;
  if(argc != 2 || (num = atoi(argv[1])) <= 0){
    printf("Argumentos incorrectos.\n");
    return -1;
  }
  ppid = getpid();
  do{
    pid_t pid;
    pid = fork();
    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){
        printf("\nHijo #%i:   PID = %d, PPID = %d\n", ++i, getpid(), getppid());
    }
    else{
        wait(NULL);
        i++;
    }
  } while(i<num && getpid() == ppid);
  return 0;
}
