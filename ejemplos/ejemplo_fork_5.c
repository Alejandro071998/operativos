/* ejemplo_fork_5.c
   Muestra el uso de fork() - Utiliza la función wait() para obtener el
   código de retorno que devuelve el proceso hijo al terminar ejecución

   Nota: Revise las páginas del manual de exit() para saber por qué status
         imprime un valor diferente del número que retornó la función

         prompt$ man exit

------------------------------------------------------------
Para compilar:

    prompt$ gcc ejemplo_fork_5.c -o ejemplo_fork_5

Para ejecutar:

    prompt$ ./ejemplo_fork_5
------------------------------------------------------------*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototipo de función */
int funcion();

int main(){

    /* Tipo de datos que representa un PID */
    pid_t pid;

    /* Variable que se utiliza para indicarle al padre el código de     */
    /* retorno del hijo: cuando el hijo termina la ejecución le retorna */
    /* al proceso padre un código de estado. El código de retorno se    */
    /* en esta variable                                                 */
    int status;

    int num;

    pid = fork();

    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){
        /* Función que ejecuta el proceso hijo. Retorna un número aleatorio */
        /* del 1 al 10 que se usa como un código de retorno. Éste código    */
        /* se envía por parámetro a la función exit(), que a su vez se      */
        /* envía al proceso padre cuando el hijo termina de ejecutarla      */
        num = funcion();

        printf("La funcion en el proceso hijo retorna: %d", num);
        exit(num);
    }
    else{
        /* Acá el proceso padre guarda en 'pid' el PID del proceso hijo que */
        /* terminó la ejecución. La variable 'status' obtiene el código de  */
        /* retorno del hijo                                                 */
        pid = wait(&status);
        /* Imprime el PID del proceso hijo junto con su código de retorno   */
        /* al terminar la ejecución                                         */
        printf("\nProceso hijo con PID %d, retorna el status %d\n", pid, status);
    }

    return 0;
}

/* Función que genera un número aleatorio del 1 al 10 y lo retorna */
int funcion(){
    int n;

    /* Obtiene la semilla para generar números aleatorios utilizados por */
    /* rand()                                                            */
    srand(time(NULL));

    n = rand() % 10 + 1;
    return n;
}
