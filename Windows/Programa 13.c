#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
    int r,c,col,reng;
    system("color f9");
    printf("Programa 13: \"Matriz\"");
    printf("\n\nElija el n\xA3mero de renglones ");
    scanf("%i",&r);
    printf("\nElija el n\xA3mero de columnas ");
    scanf("%i",&c);
    float A[r][c], B[r][c], C[r][c];
    for(reng=0;reng<r;reng++)
    {
        printf("\n");
        for(col=0;col<c;col++)
        {
            printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
            scanf("%f",&A[reng][col]);
         }
    }
    for(reng=0;reng<r;reng++) 
    {
        printf("\n");
        for(col=0;col<c;col++)
        {
            printf("%10g ",A[reng][col]);
        }
    }
    printf("\n");
    for(reng=0;reng<r;reng++)
    {
        printf("\n");
        for(col=0;col<c;col++)
        {
            printf("Dame el valor de B[%i][%i]=",reng+1,col+1),
            scanf("%f",&B[reng][col]);
         }
    }
    for(reng=0;reng<r;reng++) 
    {
        printf("\n");
        for(col=0;col<c;col++)
        {
            printf("%10g ",B[reng][col]);
        }
    }
    for(reng=0;reng<r;reng++) 
    {
        for(col=0;col<c;col++)
        {
            C[reng][col]=A[reng][col]+B[reng][col];
        }
    }
    printf("\n\nEl esultado de la suma de las matrices A y B es:\n");
        for(reng=0;reng<r;reng++) 
    {
        printf("\n");
        for(col=0;col<c;col++)
        {
            printf("%10g ",C[reng][col]);
        }
    }
    getch();
}   
