#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void saludo(void);

main()
{
	printf("Programa 29:\"Funci\xA2n Auxiliar");
	saludo();
	system("color b0");
	printf("\n\nSaludos desde la funci\xA2n pprincipal");
	getch();
}

void saludo(void)
{
	system("color 02");
	printf("\n\nSaludos desde la funci\xA2n auxiliar");
	getch();
}
