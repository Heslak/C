    #include<math.h>  
    #include<conio.h> 
    #include<stdio.h> 
    #include<stdlib.h> 

//Función principal
main()
{
    system ("color f9");
//Variable local
    int a;
//Título del programa y su función    
    printf("Programa 3:\"Variables\"");
    printf("\n\nDame un valor de a=");
    scanf("%i",&a);
    printf("\n");
//Condición para realizar la clasificación de un número
    if(a<0)
    {
        printf("\n%i Es Negativo",a);
    }
    else
    {
        printf("%i Es positivo",a);
    }
    getch();
}
