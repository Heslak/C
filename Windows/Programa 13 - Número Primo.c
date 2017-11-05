#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
main ()
{
	system ("color f0");
	int a,c,cuenta=0;
	printf ("Programa 13:\"Programa para saber si un n\xA3 \bmero es primo");
	printf("\n\nIngres el n\xA3 \bmero que quiere saber si es primo ");
	scanf ("%i",&a);
	if (a<=1)
		printf("\n%i No es primo",a); 
	else
		for(c=2;c<=a/2;c++)
		{
			if (a%c==0)
			{ 
				if(cuenta==0)
					printf("\n Divisor(es): %i",c);
				else 
					printf(" %i",c);
					cuenta++; 
			}
		}
	if(cuenta==0 && a>1)
		printf("\n%i es primo",a);
	getch ();
}
