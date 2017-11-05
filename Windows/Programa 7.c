#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
{
    system("color f9");
    char resp='s';
    printf("Program 7: Ciclo (While)");
    while(resp=='s')
    {
        printf("\n\nSaludos");
        printf("\nEscribe s para repetir, otro caracter para salir\n\n");
        resp=getche();
    }
}
