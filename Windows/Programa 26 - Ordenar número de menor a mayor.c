#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	system("color f9");
	int n,cont,a,b,t;
	printf("Porgrama 26: \"Programa para ordenar n\xA3meros\"");
	printf("\n\nIngrese el n\xA3mero de elementos que quiere ordenar ");
	scanf("%i",&n);
	int A[n];
	printf("\n");
	for(cont=0;cont<n;cont++)
	{
		printf("Ingrese el valor A[%i]=",cont+1);
		scanf("%i",&A[cont]);
	}
	printf("\n");
	printf("Los n\xA3meros que ingreso son:\n\n");
	for(cont=0;cont<n;cont++)
		printf("%i ",A[cont]);
	printf("\n\n");
	for(t=0;t<=n;t++)
	{
		for(cont=0;cont<n-1;cont++)
		{
			a=A[cont];
			b=A[cont+1];
			if(b<a)
			{
				A[cont+1]=a;
				A[cont]=b;			
			}
		}
	}
	printf("Los n\xA3meros en orden del menor al mayor son:\n\n");
	for(cont=0;cont<n;cont++)
		printf(" %i",A[cont]);
}
