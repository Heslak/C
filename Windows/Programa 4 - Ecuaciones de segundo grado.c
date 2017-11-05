    #include<math.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<conio.h>
    
main()
{
     //Cambiamos de color la ventana de ejecución
	 system("color f0");
	 //Se declaran las variables
     int a, b, c, X1, X2;
    printf("Programa 4 : \"Programa para ecuaciones de segundo grado\"");
    printf("\n\nIngrese los valores de a, b y c\n");
    //Se piden los datos
    printf("\nDame el valor de a=");
    scanf( "%i", &a);
    printf("\nDame el valor de b=");
	scanf( "%i", &b);
	printf("\nDame el valor de c=");
	scanf( "%i", &c);
    printf( "\n %ix^2 + (%ix) + (%i)" ,a,b,c);
    //Se hace la fórmula general de segundo grado para obetener los valores de X
    X1=(-b+sqrt((b*b)-4*a*c))/(2*a);
    X2=(-b-sqrt((b*b)-4*a*c))/(2*a);
    //Se imprimen los valores de X1 y X2 obtenidos con la ecuación general de segundo grado
    printf("\n\nEl valor de X1=%i \n\nEl valor de X2=%i", X1,X2);
    getch();	
}
