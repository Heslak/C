//Directivas de preprocesacmiento
    #include<math.h>  
    #include<conio.h> 
    #include<stdio.h> 
    #include<stdlib.h>
   //Declaración de una variable global
    int x=3;
//Función principal 
main()
{
    system ("color f9");
//Declaración de variables locales
    int y=2,z;
//Cuerpo de la función
    printf ("Programa 2: \"Variables\"");
    printf("\n\ny=%i,  x=%i",y,x);
    z=pow(y,2);
    printf(", z=%i",z);    
    printf("\n\nDame valores para x=");
    scanf("%i",&x);
    printf("\nx=%i, y=%i, z=%i",x,y,z); 
    printf("\n\nDame otros valores para x,y,z");
    printf("\n\nDame valor de x=");
    scanf(" %i",&x);
    printf("\nDame valor de y=");
    scanf(" %i",&y);
    printf("\nDame valor de z=");
    scanf("%i",&z);
    printf("\n\nx+y+z=%i+%i+%i=%i",x,y,z,x+y+z);   
    getch();
}
