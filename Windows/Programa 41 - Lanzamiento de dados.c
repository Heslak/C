#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dados(void);

main()
{
	char resp='s';
	srand(srand(time(NULL));
	system("color f9");
	printf("Programa 41: \"Lanzamiento de dados\"");
	printf("\n\nPresione 's' para realizar otro volado o cualquier otra tecla para salir");
	printf("\n\nEl dado call\xA2:\n");
	while (resp=='s')
	{
		dados();
		resp=getch();
	}
}

void dados(void)
{
	int num;
	num=1+rand()%6;
	if(num==1)
		printf("\n1");
	if(num==2)
		printf("\n2");
	if(num==3)
		printf("\n3");
	if(num==4)
		printf("\n4");
	if(num==5)
		printf("\n5");
	if(num==6)
		printf("\n6");
}
