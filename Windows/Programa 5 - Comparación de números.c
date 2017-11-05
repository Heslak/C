#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
	system("color f9");
	//Declaración de variables
	int a,b;
	//Título del programa y para que funciona
	printf("Programa 5: \"Programa para comparar 2 n%cmeros\"",163);
	printf("\n\nIngrese los valores que quiere comparar");
	printf("\n\nIngrese el valor de a=");
	scanf("%i",&a);
	printf("\nIngrese el valor de b=");
	scanf("%i",&b);
	//Condición para clasificar los números dados
	if(a==b)
	{
		printf("\n%i Es igual a %i",a,b);
	}
	else
	{
		//Concidión en otra condición para seguir con la clasificación de los números dados
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
