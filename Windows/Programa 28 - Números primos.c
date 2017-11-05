#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	system("color f9");
	int cont,cont2,a,b,c;
	printf("Porgrama 26: \"Obtenci\xA2n de n\xA3meros primos en un intervalo\"");
	printf("\n\nIngrese el intervalo [a,b] en donde quiere encontrar los n\xA3meros primos ");
	printf("\n\nIngrese a=");
	scanf("%i",&a);
	printf("\n\nIngrese b="),
	scanf("%i",&b);
	if(b<a)
	{
		cont=a;
		a=b;
		b=cont;
	}
	printf("\nLos n\xA3meros primos encontrados en el intervalor [%i,%i] son:\n\n",a,b);
	for(cont=a;cont<=b;cont++)
	{
		for(cont2=2;cont2<cont;cont2++)
		{
			c=cont%cont2;
			if(c==0)
				cont2=cont+1;
		}
		if(c!=0 && cont!=1 && cont!=0)
			printf("%i ",cont);
	}
	getch();
}
