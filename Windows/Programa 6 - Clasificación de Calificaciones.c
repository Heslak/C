#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

main()
{
	system("color f9");
	//Se decalaran variables de tipo flotante (con decimales)
	float a,b,c,d;
	//Título del programa y para que funciona
	printf("Programa 6: \"Programa clasificaci%cn de calificaciones\"",162);
	//Se piden los valores para obtener su promedio
	printf("\n\nIngrese las 3 calificaciones que desea primediar");
	printf("\n\nIngrese la primera calificaci%cn a=",162);
	scanf("%f",&a);
	printf("\n\nIngrese la segunda calificaci%cn b=",162);
	scanf("%f",&b);
	printf("\n\nIngrese la tercera calificaci%cn c=",162);
	scanf("%f",&c);
	//Se realiza la siguiente operación para obtener el promedio de los número obtenidos
	d=(a+b+c)/3;
	//Condición para clasificar el promedio
	if (d>=8)
	{
		printf("\n El primedio es %f, por lo cual el alumno aprueba",d);
	}
	else
	{
		if(d>=6)
		//Concidicón en otra condición que continua con la clasificación del promedio
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
