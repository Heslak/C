#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

main()
{
    system("color f9");
    int contb, suma=0;
    printf("Programa 5: \"Ciclo b\"\n\n");
    for (contb=100;contb>=1;contb=contb-1)
    {
        printf("El contador vale %i\n",contb);
        suma=suma+contb;
        if (contb%10==1)
        {
            printf("\n");
            system ("pause");
            printf("\n");
        }
    }
    printf("\n\nEl resultado de la suma es %i",suma);
    getch();
}
