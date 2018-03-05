/* ejemplo_fork_3.c
   Muestra el uso de fork() - Utiliza variables globales y locales
   para demostrar la independencia de ambos tipos de variables
   entre el proceso padre y el proceso hijo, ya que los procesos no comparten
   espacio de direcciones de memoria

------------------------------------------------------------
Para compilar:

    prompt$ gcc ejemplo_fork_3.c -o ejemplo_fork_3

Para ejecutar:

    prompt$ ./ejemplo_fork_3
------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Declaración de una variable global tipo int */
int var_global;

int main(){

    /* Variable local tipo int */
    int var_local = 10;

    var_global = 50;

    /* Tipo de datos que representa un PID */
    pid_t pid;

    pid = fork();

    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){
        /* Eñ proceso hijo incrementa el valor de ambas variables */
        var_global++;
        var_local++;
        printf("\nProceso HIJO PID %d: var_global=%d. var_local=%d\n", pid, var_global, var_local);
    }
    else{
        wait(NULL);
        printf("\nProceso PADRE PID %d: var_global=%d. var_local=%d\n", pid, var_global, var_local);
    }

    return 0;
}
