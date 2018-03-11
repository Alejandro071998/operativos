#include<stdio.h> //Tarea 3 - Sistemas Operativos
#include<sys/types.h> //Ejercicio2
 //Brailan Moraga Moreno
 
int main()
{
	int num,error;
	//pid_t id;
	
	printf("Cantidad: ");
	scanf("%d",&num);
	
	int hijos,padre;
	hijos = num;
	padre = num;
	
    while(hijos>0)
    {
		//id= fork();
        if(fork() == 0)
        {
			int PID = getpid();
			int PPID = getppid();
            printf("Hijo #%d: PID = %d, PPID = %d\n",hijos,PID,PPID);
            exit(0);
        }
		hijos=hijos-1;
    }
    while(padre>0) {
		//wait(NULL);
		waitpid(NULL, &error, 0);
		padre=padre-1;
	}
	if (error == 0)  
	{
		printf("PROCESO SIN ERRORRES!!!\n");    
	}
	if (error == 1)      
	{
		printf("OOPS! ERRORRES!!!\n");    
	}
		
}
