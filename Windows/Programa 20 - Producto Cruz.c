#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	system("color f0");
	int cont;
	printf("Programa 20: \"Producto Cruz de vectores\"");
	printf("\n\nIngrese los valores de los escalares de los vectores\n");
	int A[3], B[3], C[3];
	for (cont=0;cont<3;cont++)	
	{
		printf("\nDame el valor de A[%i]=",cont+1);
		scanf("%i",&A[cont]);
	}
	printf("\nA[");
	for (cont=0;cont<3;cont++)
		printf("%i, ",A[cont]);
	printf("\b\b]\n");
	for (cont=0;cont<3;cont++)	
	{
		printf("\nDame el valor de B[%i]=",cont+1);
		scanf("%i",&B[cont]);
	}
		printf("\nB[");
	for (cont=0;cont<3;cont++)
		printf("%i, ",B[cont]);
	printf("\b\b]\n\n");
	C[0]=A[1]*B[2]-(A[2]*B[1]);
	C[1]=-(A[0]*B[2]-(A[2]*B[0]));
	C[2]=A[0]*B[1]-(A[1]*B[0]);
	printf("El resultado del producto cruz entre los vectores A y B es:\n\n");
	printf("[");
	for (cont=0;cont<3;cont++)
		printf("%i, ",B[cont]);
	printf("\b\b] X");
	printf("[");
	for (cont=0;cont<3;cont++)
		printf("%i, ",B[cont]);
	printf("\b\b] = ");
	printf("[");
	for (cont=0;cont<3;cont++)
		printf("%i, ",C[cont]);
	printf("\b\b]");
	getch();
}
