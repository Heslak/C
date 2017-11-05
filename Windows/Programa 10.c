#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
    int t=0,cont,A[t];
    system("color f9");
    printf("Elija el n\xA3mero de elementos ");
    scanf("%i",&t);
    for (cont=0;cont<t;cont++)
    {
        printf("Dame el valor de A[%i]",cont+1);
        scanf("%i",&A[cont]);
    }
    for(cont=0;cont<t;cont++)
    {
        printf("%i ",A[cont]);
    }
    getch();
}
