/* ejemplo_fork_4.c
   Muestra el uso de fork() - Utiliza la función getpid() para obtener el PID
   asignado por el sistema operativo para cada uno de los procesos

------------------------------------------------------------
Para compilar:

    prompt$ gcc ejemplo_fork_4.c -o ejemplo_fork_4

Para ejecutar:

    prompt$ ./ejemplo_fork_4
------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    /* Tipo de datos que representa un PID */
    pid_t pid;

    pid = fork();

    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){
        /* Imprime el PID del proceso hijo junto con el PID del padre */
        printf("\nProceso HIJO\n\t PID: %d\n\tPPID: %d\n\t", getpid(), getppid());
    }
    else{
        wait(NULL);
        /* Imprime el PID del proceso hijo junto con el PID del padre */
        printf("\nProceso PADRE\n\t PID: %d\n\tPPID: %d\n", getpid(), getppid());
    }

    return 0;
}
