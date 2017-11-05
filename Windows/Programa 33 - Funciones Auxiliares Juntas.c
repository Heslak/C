#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void saludo(void);
void cuadrado(int);
float factorial (void);
float raiz (float,float);

main()
{
	int x;
	float X, y, A, B;
	printf("\t\tPrograma 33:\"Funci\xA2n auxiliares juntas");
	saludo();
	system("color f9");
	printf("\n\n\t\tSaludos desde la funci\xA2n principal");
	printf("\n\n\t\tDame un valor de x: ");
	scanf("%i",&x);
	cuadrado(x);
	printf("\n\n\t\tx En la funci\xA2n principal es: %i",x);
	y=factorial();
	printf("\n\t\tEl factorial es %g ",y);
	printf("\n\n\n\t\tPrograma que resuelve Ax+B=0"); 
	printf("\n\n\t\tDame A: ");
	scanf("%f",&A);
	printf("\n\t\tDame B:");
	scanf("%f",&B);
	X=raiz(A,B); 
	printf("\n\t\tx=%g",X); 
	getch();
}

void saludo(void)
{
	system("color 02");
	printf("\n\n\t\tSaludos desde la funci\xA2n auxiliar");
	getch();
}

void cuadrado (int x)
{
	x=x*x;
	printf("\n\t\tEl cuadrado de x es: %i",x);
}

float factorial()
{
	float fact=1,c,x;
	printf("\n\n\t\tDame un valor para tu factorial: ");
	scanf("%f",&x);
	for(c=1;c<=x;c++)
		fact=fact*c;
	return(fact);	
}

float raiz(float a,float b)
{
	float x;
	x= -b/a;
	return(x);
}
