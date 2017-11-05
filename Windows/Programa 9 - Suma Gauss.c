#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
	system("color f9");
	int a,b,s=0,t;
	//Descripción del programa y la función de este
	printf("Programa 9: \"Programa para hacer una suma de Gauss en un intervalo [a,b]\"",162);
	printf("\n\nIngrese los límites de la suma");
	printf("\n\nDame el valor del extremo inferior a=");
	scanf("%i",&a);
	printf("\nDame el valor del extremo superior b=");
	scanf("%i",&b);
	//Si los valores estan mal dados se corrigen con un if, el cual reasigna los valores
	if(a>b)
	{
		t=a;
		a=b;
		b=t;
	}
	//Teniendo los valores correctamente se hace un for, el cual va sumando todos los valores del intervalor dado
	for (t=a;t<=b;t=t+1)
		s=s+t;
	//Se da el resultado y se muestra como deben de darse los valores la próxima ocación
	printf("\nLa suma en el intervalo [%i,%i] es %i",a,b,s);
	getch();
}
