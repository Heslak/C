#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
{
    system("color f9");
    int a, b=1,t,c=0;
    printf("Programa 6: \"Programa para factoriales\"");
    printf("\n\nIngrese el n%cmero del que quiere saber su factorial: ",163);
    scanf("%i",&a);
    if (a<0)
    {
        a=a*-1;
        c=1+2;
    }
    for(t=1;t<=a;t=t+1)
    {
        b=b*t;
    }
    if(c==0)
    {
        printf("\nEl factorial de %i (%i!) es: %i",a,a,b);
    }
    else
    {
        printf("\nEl factorial de -%i (-%i!) es: -%i",a,a,b);
    }
    getch();
}

