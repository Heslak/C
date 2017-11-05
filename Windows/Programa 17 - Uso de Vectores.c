#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	system("color f0");
	int cont, n;
	printf("Programa 17: \"Uso de vectores\"");
	printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
	scanf("%i",&n);
	int A[n];
	for (cont=0;cont<n;cont++)	
	{
		printf("\nDame el valor de A[%i]=",cont+1);
		scanf("%i",&A[cont]);
	} 
	printf("\nA[");
	for (cont=0;cont<n;cont++)
		printf("%i, ",A[cont]);
	printf("\b\b] ");
	getch();
}
