#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
    int t=0,cont,A[t],B[t],punto=0;
    system("color f9");
    printf("Programa 11: \"Producto punto entre vectores\"");
    printf("\n\nElija el n\xA3mero de elementos ");
    scanf("%i",&t);
    printf("\n");
    for (cont=0;cont<t;cont++)
    {
        printf("Dame el valor de A[%i]=",cont+1);
        scanf("%i",&A[cont]);
    }
    printf("\nSu vector A es:[");
    for (cont=0;cont<t;cont++)
        printf("%i, ",A[cont]);
    printf("\b\b]");
    printf("\n\n");
     for (cont=0;cont<t;cont++)
    {
        printf("Dame el valor de B[%i]=",cont+1);
        scanf("%i",&B[cont]);
    }
        printf("\nSu vector B es:[");
    for (cont=0;cont<t;cont++)
        printf("%i, ",B[cont]);
    printf("\b\b]");
    for (cont=0;cont<t;cont++)
    {
        punto=punto+(A[cont]*B[cont]);
    }
    printf("\n\nSu producto punto es: ");
    printf("[");
    for (cont=0;cont<t;cont++)
        printf("%i, ",A[cont]);
    printf("\b\b]*");
    printf("[");
    for (cont=0;cont<t;cont++)
        printf("%i, ",B[cont]);
    printf("\b\b]=");
    printf("%i",punto);
    getch();
}
