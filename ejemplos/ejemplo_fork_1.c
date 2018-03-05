/* ejemplo_fork_1.c
   Muestra el uso de fork()

------------------------------------------------------------
Para compilar:

    prompt$ gcc ejemplo_fork_1.c -o ejemplo_fork_1

Para ejecutar:

    prompt$ ./ejemplo_fork_1
------------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    /* Tipo de datos que representa un PID */
    pid_t pid;
    pid = fork();

    /* En caso de fallo, la llamada al sistema fork() retorna -1 */
    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){   /* Llamada al código del proceso hijo */
        printf("\nProceso hijo... Llama a ls\n");
        /* El espacio de memoria del proceso hijo se sobrescribe con el */
        /* código del programa 'bin/ls'                                 */
        execlp("/bin/ls", "ls", NULL);
    }
    else{
        /* Código del proceso padre                                   */
        /* wait() le indica al proceso padre que debe esperar a que   */
        /* reciba la señal de terminación del proceso hijo antes de   */
        /* continuar                                                  */
        wait(NULL);
        printf("\n\nYa el proceso hijo terminó. Este es el proceso PADRE\n");
    }

    return 0;
}
