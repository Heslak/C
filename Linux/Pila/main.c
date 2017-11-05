#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	PILA *pila1, *pila2;
	int i=0;
	char x, cadena[]="hola pedro";
	
	pila1=nuevaPila(10);
	pila2=nuevaPila(10);
	
	for(i=0; i<10;i++)
		push(pila1,cadena[i]);
	
	for(i=0; i<10;i++){
	
		x=pop(pila1);
		printf("%c",x);
		push(pila2,x);
	}
	
	for(i=9;i>=0;i--){
		x=pop(pila2);
		push(pila1,toupper(x));
	}
	
	printf("\n\nPila 1\n\n");
	dump (pila1);
	printf("\nPila 2\n\n");
	dump (pila2);
	
	return 0;
}
