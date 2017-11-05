#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char cadena[50];
	int v=0,c=0;
	system("color f9");
	printf("Programa 36:\"Buscador Vocales");
	printf("\n\nIntroduzca una cadena de menos de 50 caracteres, no se permiten espacios "),
	scanf("%s",&cadena[c]);
	printf("Las vocales que se encontraron son: ");
	for(c=0;c<strlen(cadena);c++)
	{
		if(cadena[c]=='a' || cadena[c]=='e' ||cadena[c]=='i' ||cadena[c]=='o' ||
		cadena[c]=='u' ||cadena[c]=='A' || cadena[c]=='E' ||cadena[c]=='I' ||
		cadena[c]=='O' ||cadena[c]=='U')
		{
			v++;
			printf("%c",cadena[c]); 
		}
	}
	printf("\n\nEncontramos %i vocales\n\n\t\t",v); 
	system("pause");
}
