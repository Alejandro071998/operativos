#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int var_global;

void Collatz (int a){
	int resto,b,cont;

	do
	{
		resto=a%2;
		if (resto==0)
		{
			b=a/2;
		}

		else if (resto!=0)
		{
			b=(3*a)+1;
		}

		a=b;
		printf("%i\t",a); 
	} while (a!=1);
	printf("\n\n");

}



int main(int argc, char* arguv[]){

  char* in = arguv[1];
int input=atoi(in);
int dato=input;

      pid_t pid;

    pid = fork();

    if (pid < 0){
        perror("Error en la llamada a fork().");
        return -1;
    }
    else if (pid == 0){
      int a,b,res;

	printf("\t=============================== Conjetura de Collatz ===============================\n\n\t");
	printf("=============================== Christian Chacon Calvo ===============================\n\n\t");
	printf("Introduzca un numero: ");
	/*scanf("%i",&a);*/

	if (dato>0){

		Collatz(dato);

	}
	else if (dato<0){
		printf ("\t\nNo se puede calcular, introduzca un numero positivo\n\n");
}
    }
    else{
        wait(NULL);
     
    }

    return 0;
}
