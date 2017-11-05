#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
	system("color f9");
	int a;
	printf("Programa 12:\"Programa para saber sin un n\xA3 \bmero es par o no");
	printf("\n\nIngrese eln\xA3 \bmero que quiere saber si es par ");
	scanf("%i",&a);
	if(a%2==0)
		printf("\n%i Es un n\xA3 \bmero par",a);
	else
		printf("\n%i No es un n\xA3 \bmero par",a);
	getch();
}
