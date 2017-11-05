


#include <stdio.h>
#include <stdlib.h>

int promedio(int A[]);
int minimo(int A[]);
int A[10];

int main(){
	int pidh1=0, pidh2=0, h1=0, i=0, min=0, prom=0, r1, r2;
	printf("\t\tPrograma de procesos\n\n");

	//Obtenemos 10 elementos para el arreglo

	for(i=0; i<10;i++){
		printf("Ingrese el termino %i: ",i+1);
		scanf("%i",&A[i]);
		
	}
	
	//Creamos un proceso

	pidh1=fork();
	
	//En caso de que el proceso sea el padre entra en la condición
	if(pidh1){
		
		//Creamos otro proceso hijo	
		pidh2=fork();
		
		//El proceso padre entra en la condición
		if(pidh2){
			
			//Obtenemos los resultados dados por los procesos hijos
			h1=wait(&r1);
			wait(&r2);

			//Recorremos 8 bits a la derecha la variable
			r1=r1>>8;
			r2=r2>>8;

			//Verificamos el Id de los procesos para saber cual es el proceso hijo 1 y cual es el proceso hijo 2
			if(h1==pidh1){
				printf("\nEl promedio es: %i",r1);
				printf("\nEl termino minimo es: %i\n", r2);
			
			}
			else{
				printf("\nEl promedio es: %i",r2);
				printf("\nEl termino minimo es: %i\n",r1);
			}
		
		}
		//El proceso hijo obtiene el elemento con menor valor del arreglo
		else{	
			min=minimo(A);
			exit(min);
		}	
	
	}
	//El proceso hijo obtiene el promedio y lo regresa 
	else{
		prom=promedio(A);
		exit(prom);
	}
	
	return 0;
}


//Función que obtiene el promedio de un arreglo

int promedio (int A[]){
	int i,prom=0;
	for(i=0;i<10;i++){
		prom+=A[i];				
	}
	prom=prom/10;
	return prom;
}


//Verificamos cual es el elemento con menor valor en el arreglo

int minimo (int A[]){
	int i,min=0;
	min=A[0];
	for(i=1;i<10;i++){
		if(min>A[i]){
		min=A[i];
		}					
	}	
	return min;
}

