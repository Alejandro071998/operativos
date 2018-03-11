
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){ 
    
	pid_t pid;
	pid = fork();
	
	if (pid < 0){
		perror("No se pudo iniciar el proceso.");
		return -1;
	}
	else {
		if (pid == 0){ 
			if(argv[1] != NULL){
				int valor = atoi(argv[1]);
				if(valor != 0){
					printf("%s ", argv[1]);
					while (valor != 1) {
						if (valor % 2 == 0) { //Es par
							valor = valor / 2;
						}
						else {
							valor = (3 * valor) + 1;
						}
						printf("%d ", valor);
					}
				}
				else{
					printf("El valor digitado es 0, por lo tanto, la conjetura no se puede realizar.");
				}
			}
			else{
				printf("No hay argumentos.");
			}
			getchar();
			return 0;
		}
		else{                                        
			wait(NULL);
		}
	}
}
