#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

float raiz (float,float);

main()
{
	float X, A, B;
	system ("color f9");
	printf("Programa 33:\"Funci\xA2n Auxiliar 4");
	printf("\n\n\n\t\tPrograma que resuelve Ax+B=0"); 
	printf("\n\n\t\tDame A: ");
	scanf("%f",&A);
	printf("\n\t\tDame B: ");
	scanf("%f",&B);
	X=raiz(A,B); 
	printf("\n\t\tx=%g",X); 
	getch();
}

float raiz(float a,float b)
{
	float x;
	x= -b/a;
	return(x);
}
