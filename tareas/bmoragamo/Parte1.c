#include <stdio.h> //Tarea 3 - Sistemas Operativos
#include <signal.h> // Ejercicio 1
#include <sys/types.h> //Brailan Moraga Moreno
#include <sys/wait.h>
#include <stdlib.h> 

void collatz (int a){
	while(a!=1){
		printf("%d ,",a);
		if(a%2==0){
			a = (a/2);
		}else{
			a = (3*a)+1;
		}
	}
	printf("%d \n",a);
}

void llamada_fork(){

	int num, error; 
	printf ("Numero: "); 
	scanf("%d", &num);
		
	pid_t id = fork();
	if( id == 0 ){ //hijo
		if(num>0)
			collatz(num);
		exit(0);
	}else{
		waitpid(id, &error, 0);
		//resultado = WEXITSTATUS(recibido);
		if (error == 0) 
		{
			printf("PROCESO SIN ERRORRES!!!\n");    
		}

		if (error == 1)      
		{
			printf("OOPS! ERRORRES!!!\n");    
		}
	}
	
}

int main(){
	llamada_fork();

	return 0;
}
