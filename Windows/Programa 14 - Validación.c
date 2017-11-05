#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
main ()
{
	system("color f9");
	char a='s';
	printf("Programa 14:\"Validaci\xA2 \bn\"");
	while(a!='x')
	{
		printf("\n\nIngrese una x ");
		a=getche();
	}
	printf("\n\nLa letra que ingresaste es %c",a);
	getch();
}
