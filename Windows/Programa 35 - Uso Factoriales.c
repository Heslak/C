#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int combina(int,int);
int factorial(int);
int permuta(int,int);

main()
{
	int a, c, n, r,cont1=0;
	char resp1='s';
	system("color f9");
	do
	{
		printf("Programa 35: \"Usos factoriales\"");
		printf("\n\nMen\xa3");
		printf("\n\n1\xA7 Factoriales");
		printf("\n2\xA7 Combinaciones");
		printf("\n3\xA7 Permutaci\xA2n");
		cont1=cont1+1;
		if(cont1>1)
		{	
			printf("\n\n\xF8 Si ya no desea realizar alguna otra operaci\xA2 \bn por favor presione 'ESC' , de lo contrario presione cualquier otra tecla ");
			resp1=getch();
			if(resp1=='\x1B') //Opción de salir que aparece al utilizar el prograama por por lo menos una vez
			{	
				printf("\n\n\xF8 Presione otra vez 'ESC' para confirmar ");//Confirmación para salir en caso de que el ususario se haya equivocado 
				resp1=getch();
				if(resp1=='\x1B')
					printf("\n\n\t\t\tGRACIAS POR UTILIZAR EL PROGRAMA");
			}
		}
		if(cont1==1 || resp1!='\x1B') 
		{
			printf("\n\nIngrese la opci\xA2n que desea realizar: ");
			scanf("%i",&a);
			switch (a)
			{	
				case 1:
					printf("\n\t\xFE \bFactoriales");
					printf("\n\n\xF8Ingrese el n\xA3mero del que quiere su factorial ");
					scanf("%i",&n);
					c=factorial(n);
					printf("\nEl factorial de %i es: %i",n,c);
					break;
				case 2:
					printf("\n\t\xFE \bCombinaciones");
					printf("\n\n\xF8Ingrese el n\xA3mero de elementos totales ");
					scanf("%i",&n);
					printf("\nIngrese el n\xA3mero de muestras ");
					scanf("%i",&r);
					c=combina(n,r);
					printf("\nLas combinaciones posibles son: %i",c);
					break;
				case 3:
					printf("\n\t\xFE \bPermutaci\xA2n");
					printf("\n\n\xF8Ingrese el n\xA3mero de elementos totales ");
					scanf("%i",&n);
					printf("\nIngrese el n\xA3mero de elementos de la permutaci\xA2n ");
					scanf("%i",&r);
					c=permuta(n,r);
					printf("\nLas combinaciones posibles son: %i",c);
					break;			
				default:
					printf("\n\xAD \bERROR! Ingrese una opci\xA2n que se encuentre en el men\xA3 (del 1 al 3)");
			}
		}
		printf("\n\n");
	} while(resp1!='\x1B');
}

int permuta(int n, int r)
{
	int c,d;
	d=n-r;
	c=factorial(n)/factorial(d);
	return (c);
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
