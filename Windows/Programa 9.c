#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
{
    system("color f9");
    int a, res=0, b=0;
    printf("Programa 9: While/If\n\n");
    printf("Introdusca un n\xA3mero ");
    scanf("%i",&a);
    while(a>1)
    {
        res=a%2;
        if(res==0)
        {
            b=a/2;
            printf("\n%i",b);
        }
        else
        {
            b=(a+1)/2;
            printf("\n%i",b);
        }
        a=b;
    }
    getch();
}
