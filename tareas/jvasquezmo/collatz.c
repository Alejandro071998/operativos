/* collatz.c
   Parte1.1

------------------------------------------------------------
Para compilar:

    prompt$ gcc collatz.c -o collatz

Para ejecutar:

    prompt$ ./collatz <numero>
------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void collatz(int n);

int main(int argc, char *argv[]) {
  int num, termino;
  if(argc != 2 || (num = atoi(argv[1])) <= 0){
    printf("Argumentos incorrectos.\n");
    return -1;
  }

  pid_t pid;
  pid = fork();

  if(pid < 0){
    perror("Error en la llamada a la funcion fork()...");
    return -1;
  } else if(pid == 0){
    collatz(num);
  } else{
    wait(NULL);
    printf("Conjetura de Collatz finalizada..\n");
  }
  return 0;
}
void collatz(int n){
  (n == 1)? printf("%i\n", n): printf("%i, ", n);
  if(n != 1){
    if((n%2) == 0)
      collatz(n/2);
    else
      collatz(n+n+n+1);
  }
}
