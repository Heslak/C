#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int volado(void);
int apuesta(int,int);
void cuenta(int,int,int,int);

int cont2=0;
int A[0];

main()
{	
	char resp='s',resp2='s';
	int vol, mon,apu, ban=20,cont=-1,A[cont],b=0,res;
	srand(time(NULL));
	system("color f9");
	printf("Programa 38:\"Apuestas\"");
	do
	{
	cont=cont+1;
	printf("\n\n\t\t\tMen\xA3");
	printf("\n\n1\xA7 \b\xB5guila");
	printf("\n2\xA7 \bSol");
	printf("\n\nBanco: $%i",ban);
	if(cont>=1)
	{
		cuenta(cont,res,ban,mon);
	}
	printf("\n\n\xF8 \bElija a que le quiere apostar: ");
	scanf("%i",&mon);
	while(mon!=1 && mon!=2)
	{
		printf("\n\xF8Por favor ingrese una de las 2 opciones anteriores: ");
		scanf("%i",&mon);
	}
	printf("\n\xF8Ingresa cuanto quiere apostar: ");
	scanf("%i",&apu);
	while(apu>ban)
		{
			printf("\nNo puedes apostar m\xA1s de lo que tienes ingresa una cantidad menor o igual a la \nque tienes en el banco: ");
			scanf("%i",&apu);
		}
	printf("\n\n\t\t\tLa moneda call\xA2:\n");
	res=ban;
	ban=ban+apuesta(apu,mon);
	printf("\n\n\nAhora tienes en tu Banco: $%i",ban);
		if(ban==0)
	{
	printf("\n\n\t\t\tGAME OVER");
	resp2='\x1B';
	}
	else
	{
	printf("\n\nPara seguir realizando apuestas presione cualquier tecla, para salir \npresione 'ESC'");
	resp2=getch();
	}
	}while(resp2!='\x1B');
	getch();
}

int volado()
{
	int res;
	res=1+rand()%2;
	if(res==1)
	{
		printf("\n\t\t\t\xB5guila");
		return(1);
	}
	if(res==2)
	{
		printf("\n\t\t\tSol");
		return(2);
	}
}

int apuesta(int apu, int mon)
{
	int res;
	res=volado();
	if (res==mon)
		printf("\n\n\t\t\t\xAD \bFelicidades Ganaste!");
	if (res!=mon)
	{
		printf("\n\n\t\t\t\xADL\xA0stima perdiste!");
		apu=-1*apu;
	}
	return(apu);
}

void cuenta(int cont,int res, int ban, int mon)
{
		printf("\n\n\t\t\t\xE9ltimos 6 resultados:\n\n");
		int b,a;
		if(res<ban && mon==1)
			b=1;
		if( res>ban && mon==2)
			b=1;
		if(res<ban && mon==2)
			b=2;
		if( res>ban && mon==1)
			b=2;
		if(cont<=6)
			a=0;
		if(cont>6)
			a=cont-6;
		for(cont2=cont-1;cont2<=cont+1;cont2++)
			A[cont2]=b;
		for(cont2=a;cont2<cont;cont2++)
		{
			if(cont2==cont-1)
				printf("\n\t\t\t\xE9ltimo resultado: ");
			else
				printf("\t\t\t");
			if(A[cont2]==1)
				printf("\xB5guila\n");
			if(A[cont2]==2)
				printf("Sol\n");
		}
}
