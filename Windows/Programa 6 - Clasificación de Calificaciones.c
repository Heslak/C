#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

main()
{
	system("color f9");
	//Se decalaran variables de tipo flotante (con decimales)
	float a,b,c,d;
	//T�tulo del programa y para que funciona
	printf("Programa 6: \"Programa clasificaci%cn de calificaciones\"",162);
	//Se piden los valores para obtener su promedio
	printf("\n\nIngrese las 3 calificaciones que desea primediar");
	printf("\n\nIngrese la primera calificaci%cn a=",162);
	scanf("%f",&a);
	printf("\n\nIngrese la segunda calificaci%cn b=",162);
	scanf("%f",&b);
	printf("\n\nIngrese la tercera calificaci%cn c=",162);
	scanf("%f",&c);
	//Se realiza la siguiente operaci�n para obtener el promedio de los n�mero obtenidos
	d=(a+b+c)/3;
	//Condici�n para clasificar el promedio
	if (d>=8)
	{
		printf("\n El primedio es %f, por lo cual el alumno aprueba",d);
	}
	else
	{
		if(d>=6)
		//Concidic�n en otra condici�n que continua con la clasificaci�n del promedio
		{
			printf("\n El promedio es %f, por lo cual es alumno se va a final",d);
		}
		else
		{
			printf("\n El promedio es %f, por lo cual es alumno esta reprobado",d);
		}
	}
	getch();
}
