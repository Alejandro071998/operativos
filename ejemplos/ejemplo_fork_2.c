/* ejemplo_fork_2.c
   Muestra el uso de fork() - Imprime el PID correspondiente a la llamada
   fork()

------------------------------------------------------------
Para compilar:

    prompt$ gcc ejemplo_fork_2.c -o ejemplo_fork_2

Para ejecutar:

    prompt$ ./ejemplo_fork_2
------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t pid;
    pid = fork();

    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0)
        printf("\nEste es el PID del proceso HIJO: %d\n", pid);
    else{
        printf("\nEste es el PID del proceso PADRE: %d\n", pid);
    }

    return 0;
}
