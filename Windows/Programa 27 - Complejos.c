#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

main()
{
	int selec;
	float a, b,e ,f , c, d;
	system("color f9");
	printf("Programa 27: Operaciones con número complejos");
	printf("\n\nMen\xA3");
	printf("\n\n1\xA7 Suma");
	printf("\n2\xA7 Resta");
	printf("\n3\xA7 Multiplicaci\xA2n");
	printf("\n4\xA7 Divisi\xA2n");
	printf("\n\n\xF8Seleccione que operaci\xA2n desea realizar: ");
	scanf("%i",&selec);
	switch(selec)
	{
		case 1:
			printf("\n\t\xFE Suma");
			printf("\n\nIngrese el primer n\xA3mero complejo que quiere sumar a+bi: ");
			scanf("%f %fi",&a,&b);
			printf("\nIngrese el segundo n\xA3mero complejo que quiere sumar a+bi: ");
			scanf("%f %fi",&c,&d);
			a=a+c;
			b=b+d;
			if(b<0)
				printf("\nEl resultado es %g%gi",a,b);
			if(b>=0)
				printf("\nEl resultado es %g+%gi",a,b);
			break;
		case 2:	
			printf("\n\t\xFE Resta");
			printf("\n\nIngrese el primer n\xA3mero complejo a+bi: ");
			scanf("%f %fi",&a,&b);
			printf("\nIngrese el segundo n\xA3mero complejo que quiere restar a+bi: ");
			scanf("%f %fi",&c,&d);
			a=a-c;
			b=b-d;
			if(b<0)
				printf("\nEl resultado es %g%gi",a,b);
			if(b>=0)
				printf("\nEl resultado es %g+%gi",a,b);
			break;
		case 3:
			printf("\n\t\xFE Multipliaci\xA2n");
			printf("\n\nIngrese el primer n\xA3mero complejo a+bi: ");
			scanf("%f %fi",&a,&b);
			printf("\nIngrese el segundo n\xA3mero complejo que quiere multiplicar a+bi: ");
			scanf("%f %fi",&c,&d);
			e=a;
			f=b;
			a=e*c-d*f;
			b=f*c+e*d;
			if(b<0)
				printf("\nEl resultado es %g%gi",a,b);
			if(b>=0)
				printf("\nEl resultado es %g+%gi",a,b);
			break;
		case 4:
			printf("\n\t\xFE Divisi\xA2n");
			printf("\n\nIngrese el primer número complejo a+bi: ");
			scanf("%f %fi",&a,&b);
			printf("\nIngrese el segundo n\xA3mero complejo que quiere dividir a+bi: ");
			scanf("%f %fi",&c,&d);
			e=(a*c+d*b)/(c*c+d*d);
			f=(b*c-d*a)/(c*c+d*d);
			if(f<0)
				printf("\nEl resultado es %g%gi",e,f);
			if(f>=0)
				printf("\nEl resultado es %g+%gi",e,f);
			break;
			
	}
	getch();
}
