#include <stdio.h>
#include <stdlib.h>
//#include "pila.h"
#include "fposfija.h"
//#include "cola.h"
#include <string.h>

int main(int argc, char *argv[]) {
	char v[81];
	COLA *expresionPosfija;
	float r;

	do {
		printf(">> ");
		gets(v);
		if (strcmp(v,"exit")==0)
			break;
		fflush(stdin);
		expresionPosfija=posfija(v);
		imprimeExpresion(expresionPosfija);
		r = evalua(expresionPosfija);
		//printf(">> %s = %lf\n",v, r);
		printf(">> %s = %f\n",v, r);
	} while (1);
	printf("Gracias por usar la calculadora!\n");
	
	getchar();
	return 0;
}
