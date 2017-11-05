#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "cadenas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	char cadena[1000];
	
	while(1){
		printf("********************************************************************************\n");
		printf("\t\t\t\tPrograma de Prueba");
		printf("\n\n Al ingresar una cadena de texto este programa regresar\xA0:\n");
		printf("\n\t\xFE N\xA3mero total de letras");
		printf("\n\t\xFE Las palabras que contengan un n\xA3mero de letras primo");
		printf("\n\t\xFE La cadena sin vocales y sin las posiciones que sean m\xA3ltiplos de siete\n");
		printf("\t*En caso de querer salir del programa increse 'salir'\n\n");
		printf("Ingrese la cadena: ");
	
		gets(cadena);
		fflush(stdin);
		
		if (strcmp(cadena,"salir")==0){
			break;
		}
	
		contar_letras(cadena);
		contar_primos(cadena);
		quitar(cadena);
		
	}
	
	printf("\n\t\t\t*Gracias por utilizar el programa*");
	getchar();
	return 0;
}
