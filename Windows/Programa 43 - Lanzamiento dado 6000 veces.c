#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dados(void);

main()
{
	char resp='s';
	srand(time(NULL));
	system("color f9");
	printf("Programa 41: \"Lanzamiento de dados 6000 veces\"");
	printf("\n\nPresione 's' para realizar otro volado o cualquier otra tecla para salir");
	while (resp=='s')
	{
		dados();
		resp=getch();
	}
}

void dados(void)
{
	float totalpor=0, unopor=0, dospor=0, trespor=0, cuatropor=0, cincopor=0, seispor=0,total=0, cont, uno=0, dos=0, tres=0, cuatro=0, cinco=0, seis=0;
	int num;
	for(cont=0;cont<6000;cont++)
	{
		num=1+rand()%6;
		if(num==1)
			uno++;
		if(num==2)
			dos++;
		if(num==3)
			tres++;
		if(num==4)
			cuatro++;
		if(num==5)
			cinco++;
		if(num==6)
			seis++;
	}
	total=uno+dos+tres+cuatro+cinco+seis;
	unopor=(uno*100)/total;
	dospor=(dos*100)/total;
	trespor=(tres*100)/total;
	cuatropor=(cuatro*100)/total;
	cincopor=(cinco*100)/total;
	seispor=(seis*100)/total;
	totalpor=unopor+dospor+trespor+cuatropor+cincopor+seispor;
	printf("Los dados cayeron:");
	printf("\n\nUno: \t%g \t%2.2f%c",uno,unopor,37);
	printf("\nDos: \t%g \t%2.2f%c" ,dos,dospor,37);
	printf("\nTres: \t%g \t%2.2f%c",tres,trespor,37);
	printf("\nCuatro: %g \t%2.2f%c",cuatro,cuatropor,37);
	printf("\nCinco: \t%g \t%2.2f%c",cinco,cincopor,37);
	printf("\nSeis: \t%g \t%2.2f%c",seis,seispor,37);
	printf("\n\nTotal: \t%g \t%g%c\n\n",total,totalpor,37);
}
