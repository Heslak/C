/*
 * Dekker.c
 * Este programa genera un arreglo de 1000 datos enteros, los cuales se generarán de forma aleatoria (0 – 255).
 * Proceso 1: Todos los primos los convierte a cero.
 * Proceso 2: A todos los números les suma 1.
 * 
 * Acosta Vega Sergio
 * Flores López Edgar Gerardo
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>												//biblioteca que contiene pipe()
#include <time.h>												//Biblioteca que contiene time()
#define TAM 1000*sizeof(int)									//Definimos esta constante para ahorrar tiempo en modificaciones futuras

void proc1(int pipefd[], int pipefd2[]);						//Funciones que usaremos en el programa
void proc2(int pipefd2[], int pipefd[]);
void aleatorios(void);
void primos(int **cp);
int suma_uno(void);

int num[1000];													//Se crea un arreglo de 1000 enteros

int main()
{
	
	int pipefd[2], pipefd2[2];
		
	pipe(pipefd);												// Empezamos abriendo 2 canales de comunicación
	pipe(pipefd2);
	
	if(fork())													//Creamos al proceso hijo
	{													
		proc1(pipefd,pipefd2);
	}
	else
	{
		aleatorios();											//En el proceso hijo se obtienen los números aleatorios, ya que si se pone afuera los obtiene 2 veces
		close(pipefd2[0]);										//Cerramos el canal de lectura del pipe 2
		write(pipefd2[1],num, TAM);								//Escribimos la cadena en el archivo del pipe2
		proc2(pipefd2,pipefd);
	}	
	return 0;
}

void proc1(int pipefd[], int pipefd2 [])						//Proceso 1
{
	
	int i=0,j, **cp;
	
	close(pipefd2[1]);											//Cerramos el canal de escritura del pipe 2
	close(pipefd[0]);											//Cerramos el canal de lectura del pipe 1
	
	cp=(int **)calloc(2,sizeof(int*));
	
	cp[0]=(int *)calloc(1000,sizeof(int));
	cp[1]=(int *)calloc(1000,sizeof(int));
	
	for (i=0;i<10;i++)
	{
		read(pipefd2[0],num, TAM);								//Leemos el contenido del archivo del pipe 2 y lo guardamos en el arreglo num
		
		primos(cp);												//Mandamos a llamar a la función primos

		write(pipefd[1],num, TAM);								//Escribimos el arreglo ya modificado en el archivo del pipe 1
		
		for(j=0; j<1000;j++){
			
			
			if(cp[0][j]==-1){
				break;
			}
			
			printf(" El numero primo %i se repite %i vez/veces\n",cp[0][j],cp[1][j]);		//Imprimimos el elemento primo y cuantas veces se repite
			fflush(stdout);
		}
		
		
		
		fflush(stdout);
	}
	
}

void proc2(int pipefd2[], int pipefd[])							//Proceso 2
{
	int i, resultado;
	
	close(pipefd[1]);											//Cerramos el canal de escriura del pipe 1
	close(pipefd2[0]);											//cerramos el canal de lectura del pipe 2
	for (i=0;i<10;i++)
	{
		read(pipefd[0],num, TAM);								//Leemos el contenido del archivo del pipe 1 y lo guardamos en el arreglo num
		
		resultado=suma_uno();												//Mandamos llamar a la función suma que modifica el arreglo num
		
		write(pipefd2[1],num, TAM);								//Escribimos el arreglo ya modificado en el archivo del pipe 2
		
		printf("El resultado de la suma de los elementos del arreglo es: %i\n", resultado);	//Se imprime la supa de los elementos del arreglo
		fflush(stdout);
	}
}

void aleatorios()												//Función que da número aleatorios en un arreglo
{
	int i;
	srand(time(NULL));											//Semilla para lla aletoriedad
	for(i=0;i<10;i++)
	{
		num[i]=rand()%255;										//Se da un número entre el 0 y el 255
	}
}

void primos(int **cp)											//Función que obtiene los números primos
{
	
	int i, j, k,contador=0,z,x;
	
	
	
	for(i=0;i<1000;i++)
	{
		x=0;
		k=0;
		if(num[i]==0 || num[i]==1)												//El numero 0 y el 1 no son primos
		{
			continue;	
		}
		if(num[i]==2)													//El número 2 es primo
		{
			for(z=0;z<1000;z++){										//Se captura en un arreglo el número primo y cuantas veces se repite
				if(num[i]==cp[0][z]){
					cp[1][z]=cp[1][z]+1;								
					x=1;
					break;
				}
			}
			if (x==0){
				cp[0][contador]=num[i];
				cp[1][contador]=1;
				contador=contador+1;
			}
			num[i]=0;
			continue;
		}
		for(j=2;j<num[i];j++)									//Se verifica que el número no sea primo
		{
			if(num[i]%j==0)
			{
				k=1;
				break;
			}
		}
		if(k==0)												//Se captura en un arreglo el número primo y cuantas veces se repite
		{
			for(z=0;z<1000;z++){
				if(num[i]==cp[0][z]){
					cp[1][z]=cp[1][z]+1;
					x=1;
					break;
				}
			}
			if(x==0){
				cp[0][contador]=num[i];
				cp[1][contador]=1;
				contador=contador+1;
			}
			num[i]=0;
		}
	}
	cp[0][contador]=-1;
	cp[1][contador]=-1;
}

int suma_uno()												//Se suman cada uno de los elementos del arreglo
{
	int i, resultado=0;
	for(i=0;i<1000;i++)
	{
		num[i]+=1;
		resultado+=num[i];
		
	}
	
	return resultado;
}
