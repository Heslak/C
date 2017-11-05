#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
    int r,c,col,reng;
    
    system("color f9");
    printf("Programa 12: \"Matriz\"");
    printf("\n\nElija el n\xA3mero de renglones ");
    scanf("%i",&r);
    printf("\nElija el n\xA3mero de columnas ");
    scanf("%i",&c);
    float A[r][c];
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
    getch();
}   
