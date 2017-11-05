#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
	system("color f0");
	int a, cont, cont1=0, n=0, A[n], B[n],C[n], b=1;
	float c=0;
	char resp='s', resp1='s';
	do
	{
		printf("Programa 21: \"Operaciones con vectores\"\n");
		printf("\n\xF8 De las siguientes opciones escoja  la que quiera realizar"); 
		printf("\n\n\xFE Men\xA3"); //Menú del programa
		printf("\n\n1\xA7 Suma de vectores");
		printf("\n2\xA7 Resta de vectores");
		printf("\n3\xA7 Producto punto de vectores");
		printf("\n4\xA7 Producto cruz de vectores");
		printf("\n5\xA7 Modulo de vectores");
		printf("\n6\xA7 Escalar por un vector");
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
		if(cont==1 || resp1!='\x1B') 
		{
			printf("\n\nIngrese el n\xA3mero de la opci\xA2n que desea realizar: "); //Petición para que el usuario ingrese la ipción que desea realizar
			scanf("%i",&a);
			switch(a) //aplicación de switch
			{
				case 1:
					do
					{
						resp='s';
					 	printf("\n\xFE\t\"Suma de vectores\"");
						printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector="); //Se piden en esta opción el número de elementos que quiere el usuario que tenga el vector 
		 				scanf("%i",&n);
	   	 				for (cont=0;cont<n;cont++)	
	 					{
							printf("\nDame el valor de A[%i]=",cont+1); //Se piden valores de A
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]\n");
						for (cont=0;cont<n;cont++)	
						{
							printf("\nDame el valor de B[%i]=",cont+1); //Se piden valores de B
							scanf("%i",&B[cont]);
						}
						printf("\nB[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b]\n\n");
						printf("El resultado de la suma de los vectores A y B es:\n"); //Se hace la operación dentro de un for, para que cada 
						for (cont=0;cont<n;cont++)
							C[cont]=A[cont]+B[cont];
						printf("\n[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b] + ");
						printf("[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b] = ");
						printf("[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",C[cont]);
						printf("\b\b]");
						printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla "); //Se le pregunta al ususario que es lo que desea realizar
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');
					break;
				case 2:
					do
					{
						resp='s';
					 	printf("\n\xFE\t\"Resta de vectores\""); //Se realiza lo mismo que en el caso anterior, pero cambiando un signo en la operación
						printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
						scanf("%i",&n);
						for (cont=0;cont<n;cont++)
						{
							printf("\nDame el valor de A[%i]=",cont+1);
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]\n");
						for (cont=0;cont<n;cont++)	
						{
							printf("\nDame el valor de B[%i]=",cont+1);
							scanf("%i",&B[cont]);
						}
						printf("\nB[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b]\n\n");
						printf("El resultado de la resta de los vectores A y B es:\n");
						for (cont=0;cont<n;cont++)
							C[cont]=A[cont]-B[cont];
						printf("\n[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b] - ");
						printf("[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b] = ");
						printf("[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",C[cont]);
						printf("\b\b]");
						printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla ");
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');
						break;
				case 3:
					do
					{
						resp='s';
						printf("\n\xFE\t\"Producto punto de vectores\""); //Tercer programa producto punto entre vectores
						printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
						scanf("%i",&n);
						for (cont=0;cont<n;cont++)// Se piden el número de elemntos de los vectores y sus valores
						{
							printf("\nDame el valor de A[%i]=",cont+1);
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]\n");
						for (cont=0;cont<n;cont++)	
						{
							printf("\nDame el valor de B[%i]=",cont+1);
							scanf("%i",&B[cont]);
						}
						printf("\nB[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b]\n\n");
						for (cont=0;cont<n;cont++) //Se realiza la operación en la cual se multipliacan los lementos de los vectores y al final se suman para obtener un escalar
							b=b+A[cont]*B[cont];
						printf("El resultado del producto punto de los vectores A y B es:\n"); //Se imprime la operación y al final el resultado
						printf("\n[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b] ");
						printf("* [");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b] = %i",b);
						printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla ");
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');
					break;
				case 4:
					do
					{
						resp='s';
						printf("\n\xFE\t\"Producto Cruz de vectores\"");
						printf("\n\nIngrese los valores de los escalares de los vectores\n"); //Se piden directamente los valores de los vectores, ya que esta operación solo se puede realiar con vectores de 3 elementos
						n=3;
						for (cont=0;cont<3;cont++)	
						{
							printf("\nDame el valor de A[%i]=",cont+1);
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<3;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]\n");
						for (cont=0;cont<3;cont++)	
						{
							printf("\nDame el valor de B[%i]=",cont+1);
							scanf("%i",&B[cont]);
						}
						printf("\nB[");
						for (cont=0;cont<3;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b]\n\n");
						C[0]=A[1]*B[2]-(A[2]*B[1]); //las operaciones se ponen directamente, ya que no hay manera de hacerlas de otra forma
						C[1]=-(A[0]*B[2]-(A[2]*B[0]));
						C[2]=A[0]*B[1]-(A[1]*B[0]);
						printf("El resultado del producto cruz entre los vectores A y B es:\n\n"); //Se imprimen ambos vectores y el nuevo vector que dio como resultado
						printf("[");
						for (cont=0;cont<3;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b] X");
						printf("[");
						for (cont=0;cont<3;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b] = ");
						printf("[");
						for (cont=0;cont<3;cont++)
							printf("%i, ",C[cont]);
						printf("\b\b]");
						printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla ");
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');			
						break;
				case 5:
					do
					{
						resp='s';
						printf("\n\xFE\t\"M\xA3 \bdulo de un vector");
						printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
						scanf("%i",&n);
						for (cont=0;cont<n;cont++)	//Se piden el número de elementos del vector
						{
							printf("\nDame el valor de A[%i]=",cont+1);
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]");
						for (cont=0;cont<n;cont++) //Se hace la operación para cada elemento del vector y al final todos los elementos se suman para sacarle la raíx cuadrada a esa suma
							c=c+pow(A[cont],2);//se usan variables flotantes, debido aque el resultado no puede ser siempre una raíz exacta
						c=sqrt(c);
						printf("\n\nEl m\xA2 \bdulo del vector A es: %g",c); //Se imprime el modulo, ya siendo un escalar
						printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla ");
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');
					break;
				case 6:
					do
					{
						resp='s';
						printf("\n\xFE\t\"Escalar por un vector"); //Sexto programa
						printf("\n\nIngrese el n\xA3 \bmero de elementos que quiere que tenga su vector=");
						scanf("%i",&n);
						for (cont=0;cont<n;cont++)	
						{
							printf("\nDame el valor de A[%i]=",cont+1);
							scanf("%i",&A[cont]);
						}
						printf("\nA[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b]\n");
						printf("\nIngrese el escalar por el que quiere multiplicar su vector="); //Se pide el escalar por el cual se va a multiplicar todo el vector
						scanf("%f",&c);
						for (cont=0;cont<n;cont++) //Se hace la multiplicación del escalar por cada uno de los elementos del vector ya obtenidos
							B[cont]=A[cont]*c;
						printf("\nEl resultado de la multiplicaci\xA2n del vector A por el escalar %g es:",c); //Se imprime el vector, el escalar y el nuevo vector obtenido de la operación
						printf("\n\n%g * [");
						for (cont=0;cont<n;cont++)
							printf("%i, ",A[cont]);
						printf("\b\b] = ");
						printf("[");
						for (cont=0;cont<n;cont++)
							printf("%i, ",B[cont]);
						printf("\b\b]");
							printf("\n\n\xF8 Si desea regresar al men\xA3 principal presione 'ESC', de lo contrario presione cualquier otra tecla ");
						resp=getch();
						printf("\n");
					}while(resp!='\x1B');
					break;
				default:
					printf("\n\xAD \bERROR! Por favor introdusca un n\xA3mero que este en la opciones (del 1 al 6)\n\n");
			}
		}
	printf("\n");
	} while(resp1!='\x1B');
}
