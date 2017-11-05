#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int combina(int,int);
int factorial(int);
main()
{
	int c, n, r;
	system("color f9");
	printf("Programa 34: \"Calcular combinaciones\"");
	printf("\n\nIngrese el n\xA3mero de elementor totales ");
	scanf("%i",&n);
	printf("\nIngrese el n\xA3mero de muestras ");
	scanf("%i",&r);
	c=combina(n,r);
	printf("\n\nLas combinaciones posibles son: %i",c);
	getch();	
}

int combina(int n,int r)
{
	int c,d;
	d=n-r;
	c=factorial(n)/(factorial(r)*factorial(d));
	return(c);
}

int factorial(int m)
{
	int c,fact=1;
	for(c=1;c<=m;c++)
		fact=fact*c;
	return(fact);
}
