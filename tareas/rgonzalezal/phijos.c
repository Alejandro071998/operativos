#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, char* argv[]){ 
	if(argv[1] != NULL){
		int argumento = atoi(argv[1]);
		if(argumento == 0){
			printf("El argumento es 0, por lo tano, no se crearon procesos hijos.");
		}
		else{
			padreConVariosHijos(argumento, 1);
		}
	}
	else{
		printf("No hay argumentos.");
	}
}

void padreConVariosHijos(int cantidadDeHijos, int contadorDeHijos){
	pid_t pid;
	if(cantidadDeHijos > 0){
		pid = fork();
		if (pid < 0){
			perror("No se pudo crear el proceso hijo.");
		}
		else if (pid == 0){
			printf("Hijo #%d, PID: %d, ", contadorDeHijos, getpid());
		}
		else if(pid > 0){
			wait(NULL);
			printf("PIDD: %d\n", getpid());
			contadorDeHijos += 1;
			padreConVariosHijos(cantidadDeHijos - 1, contadorDeHijos);
		}
	}
}
