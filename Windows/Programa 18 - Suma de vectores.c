#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	system("color f0");
	int cont, n;
	printf("Programa 18: \"Suma de vectores\"");
	printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
	scanf("%i",&n);
	int A[n], B[n],C[n];
	for (cont=0;cont<n;cont++)	
	{
		printf("\nDame el valor de A[%i]=",cont+1);
		scanf("%i",&A[cont]);
	}
	printf("\nA[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",A[cont]);
	printf("\b\b]\n");
	for (cont=0;cont<n;cont++)	
	{
		printf("\nDame el valor de B[%i]=",cont+1);
		scanf("%i",&B[cont]);
	}
		printf("\nB[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",B[cont]);
	printf("\b\b]\n\n");
	printf("El resultado de la suma de los vectores A y B es:\n");
	for (cont=0;cont<n;cont++)
		C[cont]=A[cont]+B[cont];
	printf("\n[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",A[cont]);
	printf("\b\b] + ");
	printf("[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",B[cont]);
	printf("\b\b] = ");
		printf("[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",C[cont]);
	printf("\b\b]");
	getch();
}
