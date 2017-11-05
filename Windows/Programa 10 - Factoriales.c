#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
	system("color f9");
	int a,m=1,t;
	//Nombre del programa y su función
	printf("Programa 10: \"Programa para obtener el factorial de un n%cmero\"",163);
	printf("\n\nIngrese el n%cmero del que quiere obtener su factorial x=",163);
	scanf("%i",&a);
	//Se aplica un for el cual va multiplicando cada valor desde el 1 hasta el número dado
	for(t=1;t<=a;t++)
		m=t*m;
	printf("\nEl factorial de %i (%i!) es %i",a,a,m);
	getch();
}
