    #include<math.h>  
    #include<conio.h> 
    #include<stdio.h> 
    #include<stdlib.h> 

//Funci�n principal
main()
{
    system ("color f9");
//Variable local
    int a;
//T�tulo del programa y su funci�n    
    printf("Programa 3:\"Variables\"");
    printf("\n\nDame un valor de a=");
    scanf("%i",&a);
    printf("\n");
//Condici�n para realizar la clasificaci�n de un n�mero
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
