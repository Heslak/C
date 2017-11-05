#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void calc_lugares(int jugadores);

void verif (int **A,int i, int j, int **B);

//int contar_rep(int **A, int jugadores, int conda);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int k=0,jugadores,i=0,j=0,c,ronda=0,cont=0,cero=0,uno=0,dos=0,tres=0,conda, **A;
	char x[10];
	system("color f9");
	printf("*************************Bienvenido a The Falling Ball**************************");
	while (1){
	
		while(1){
			ronda=0;
			printf("\nIngrese el n\xA3mero de jugadores (de 2 a 4): ");
			scanf("%i",&jugadores);
			if (jugadores <=4 && jugadores>1){
				break;
			}
		}	
	
		while (1){
		
			printf("\n\n");
		
			printf("\t\tRonda %i\n\n",ronda+1);
			srand (time(NULL)); 
			rand();
			calc_lugares(jugadores);
			
			
			printf("\n\nPresione cualquier tecla si quiere otra ronda, en caso de que quiera salir escriba exit o si quiere desea que el n\xA3mero de jugadores sea otro escriba cambiar: ");
			fflush(stdin);
			gets(x);
			ronda+=1;
			if (strcmp(x,"exit")==0 || strcmp(x,"cambiar")==0 ){
				break;
			}
		}
		
		if (strcmp(x,"exit")==0 ){
				break;
			}
	}
	printf("\t\t\t*Gracias por jugar*");
	return 0;
}



void calc_lugares(int jugadores){
	int i=0,j=0;
	int c,n=0,**B,**A, cont=0, conda=0;
	rand();
	A=(int **)calloc(7*jugadores,sizeof(int *));
	if(A==NULL){
		printf("Memoria insuficiente");
		exit(0);
	}
	for(i=0;i<7*jugadores;i++){
		A[i]=(int*)calloc(2,sizeof(int));
	}
	
	B=(int **)calloc(7*jugadores,sizeof(int *));
	
	if(B==NULL){
		printf("Memoria insuficiente");
		exit(0);
	}
	for(i=0;i<7*jugadores;i++){
		B[i]=(int*)calloc(2,sizeof(int));
	}
	
	for(i=0;i<7*jugadores;i++){
		for(j=0;j<2;j++){
			
			B[i][j]=A[i][j]=(rand()%6)+1;
				
		}
	verif(A,i,2,B);
		
	}
	
	//conda=contar_rep(A, jugadores,conda);
	//printf("%i", conda);
	printf("\t\tDados\n\n");

	for(i=0;i<7*jugadores;i++){
			if ( cont==jugadores){
			
				printf("\n");
				cont=0;
			}
			printf("[");
			for(j=0;j<2;j++){
			
				printf("%i,",A[i][j]);
				
			}
		cont+=1;
		printf("\b]\t\t");
		
	}
		
}
	
void verif (int **A,int i, int j, int **B){
	int xi, xj,yi,yj;
	for (yi=0;yi<=i;yi++){
			for (xi=0;xi<=i;xi++){
				if ((A[yi][0]==B[xi][0]) && (A[yi][1]==B[xi][1]) && yi!=xi){
					B[yi][0]=A[yi][0]=(rand()%6)+1;
					B[yi][1]=A[yi][1]=(rand()%6)+1;
					verif(A,i,2,B);
			}
		}
	}
}

/*int contar_rep(int **A, int jugadores, int conda){
	
	int i,j;
	
	
	for(i=0;i<7*jugadores;i++){
			
			if ((A[i][0]==3 &&  A[i][1]==4) || (A[i][0]==2 &&  A[i][1]==5)){
				conda+=1;
				printf("[%i,%i]",A[i][0],A[i][1]);
			
		}
	
	}
	return conda;
	
	
}*/
