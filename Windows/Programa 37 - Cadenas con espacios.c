#include<stdio.h>
#include<stdlib.h>
#include<string.h>

main()
{
	char cadena[50];
	int c, v=0;
	system("Color f9");
	printf("Programa 37: \"Leer cadenas con espacios\"");
	printf("\n\nIntroduzca una frase menor a 50 caracteres: ");
	gets(cadena);
	printf("\nLas vocales encontradas son: ");
	for(c=0;c<strlen(cadena);c++)
	{
		if(cadena[c]=='a' || cadena[c]=='e' ||cadena[c]=='i' ||cadena[c]=='o' ||
		cadena[c]=='u' ||cadena[c]=='A' || cadena[c]=='E' ||cadena[c]=='I' ||
		cadena[c]=='O' ||cadena[c]=='U')
		{
			v++;
			printf("%c ",cadena[c]); 
		}
	} 
	printf("\n\nEncontramos %i vocales\n\n\t\t",v); 
	system("pause");
}
