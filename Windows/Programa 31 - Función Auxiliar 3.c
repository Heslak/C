#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

float factorial (void);

main()
{
	float y;
	printf("\t\tPrograma 31:\"Funci\xA2n Auxiliar 3\"");
	system("color f9");
	y=factorial();
	printf("\n\t\tEl factorial es %g ",y);
	getch();
}

float factorial()
{
	float fact=1,c,x;
	printf("\n\n\t\tDame un valor para tu factorial: ");
	scanf("%f",&x);
	for(c=1;c<=x;c++)
		fact=fact*c;
	return(fact);	
}
