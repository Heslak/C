#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
	system("color f9");
	//Declaraci�n de variables
	int a,b;
	//T�tulo del programa y para que funciona
	printf("Programa 5: \"Programa para comparar 2 n%cmeros\"",163);
	printf("\n\nIngrese los valores que quiere comparar");
	printf("\n\nIngrese el valor de a=");
	scanf("%i",&a);
	printf("\nIngrese el valor de b=");
	scanf("%i",&b);
	//Condici�n para clasificar los n�meros dados
	if(a==b)
	{
		printf("\n%i Es igual a %i",a,b);
	}
	else
	{
		//Concidi�n en otra condici�n para seguir con la clasificaci�n de los n�meros dados
		if(a<b)
		{
			printf("\n%i Es menor que %i",a,b);
		}
		else
		{
			printf("\n%i Es mayor que %i",a,b);
		}
	}
	getch();
	
}
