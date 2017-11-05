#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
	system("color f9");
	printf("Programa 8: \"Programa para cuenta regresiva\"");
	int a,b,c;
	//Se aplica un for para pober obtener una cuenta regresiva del 1 al 10
	for (a=10;a>=1;a=a-1)
	{
		printf("\n\nEl contador va en %i",a);
		//Se aplica un for para que entre un número y otro haya un intervalo de tiempo y que la cuenta sea más tardada
		for (b=1;b<=100000000;b=b+1);
			//Se aplica otro for para que la cuenta sea aún más tardada
			for(c=1;c<=500000;c=c+1);
	}	
	//Un pequeño detalle para adornar la cuenta regresiva, incluyendo un sonido al final
	printf("\n\nBOOM!\a");
	getch();
}
