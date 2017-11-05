#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	system("color f9");
	int c,n,a=0,b=1,t;
	printf("Programa 11: \"Programa para ver la serie de Fibonacci hasta un termino n\"");
	printf("\n\n\xF8 Ingrese hasta que posici\xA2 \bn quiere la sucesi\xA2 \bn de Fibonacci ");
	scanf("%i",&n);	
	while(b<=0)
	{
		printf("\n\xAD \bERROR! Por favor introdusca un n\xA3 \bmero mayor que 0");
		printf("\n\n\xF8 Ingrese hasta que posici\xA2 \bn quiere la sucesi\xA2 \bn de Fibonacci ");
		scanf("%i",&n);
	}
	if(n==1)
		printf("\nLa serie hasta la posic\xA2 \bn %i es: 0",n);
	if(n==2)
		printf("\nLa serie hasta la posic\xA2 \bn %i es: 0, 1",n);
	if(n>=3)	
		printf("\nLa serie hasta la posic\xA2 \bn %i es: 0, 1",n);
	for(t=1;t<=n-2;t++)
	{
		c=a+b;
		a=b;
		b=c;
		printf(", %i",c);
	}
	getch();
}
