#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
{
    system("color f9");
    char resp='s';
    int a, b=1,t,c=0;
    printf("Program 8: Ciclo (While-2)");
    while(resp=='s')
    {
    b=1;
    c=0;
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
    printf("\n\nEscribe s para repetir, otro caracter para salir");
    resp=getche();
    }
}
