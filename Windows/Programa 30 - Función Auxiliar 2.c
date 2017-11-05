#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void cuadrado(int);

main()
{
	int x;
	system ("color f9");
	printf("\t\tPrograma 30:\"Funci\xA2n Auxiliar 2\"");
	printf("\n\n\t\tDame un valor de x: ");
	scanf("%i",&x);
	cuadrado(x);
	getch();
}

void cuadrado (int x)
{
	x=x*x;
	printf("\n\t\tEl cuadrado de x es: %i",x);
}
