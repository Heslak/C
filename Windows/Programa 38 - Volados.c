#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void volado(void);

main()
{	
	char resp='s';
	srand(time(NULL));
	system("color f9");
	printf("Programa 38:\"Volado\"");
	printf("\n\nPresione 's' para realizar otro volado o cualquier otra tecla para salir");
	printf("\n\nLa moneda call\xA2:\n");
	while (resp=='s')
	{
		volado();
		resp=getch();
	}
}

void volado()
{
	int res;
	res=rand()%2;
	if(res==0)
		printf("\nAgulia");
	if(res==1)
		printf("\nSol");
}
