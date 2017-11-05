

#include <stdio.h>
#include <stdlib.h>

int pantalla(int Xp, int Yp);
int lineas();
int Xizq=0,Yinf=0,Xder=10,Ysup=10;

int main()
{
    printf("\t\t\t\tCohen-Sutherland\n\n");
    printf("Ingrese los l\xA1mites de la ventana:\n\n");
    printf("X izquierda: ");
    scanf("%i",&Xizq);
    printf("Y inferior: ");
    scanf("%i",&Yinf);
    printf("X derecha: ");
    scanf("%i",&Xder);
    printf("Y superior: ");
    scanf("%i",&Ysup);
    lineas();
    printf("\n\n");
    getchar();
    return 0;
}


int pantalla (int Xp,int Yp){
    int p=0;

    if(Xp>Xder){                                                                        //Comparamos con el límite derecho de la pantalla
        p=4;

        if(Yp>Ysup){                                                                    //Comparamos con el límite superior de la pantalla
            p+=2;
        }else{
            if(Yp<Yinf){                                                                //Comparamos con el límite inferior de la pantalla
                p+=1;
            }
        }
    }else{
        if(Xp<Xizq){
            p=8;
            if(Yp>Ysup){
                p+=2;
            }else{
                if(Yp<Yinf){
                    p+=1;
                }
            }
        }else{
            if(Yp>Ysup){
                p+=2;
            }else{
                if(Yp<Yinf){
                    p+=1;
                }
            }
        }
    }
    return p;

}


int lineas(){
    int x=0,y=0,x1,y1,i,f;
    FILE *archivo;
    if(!(archivo=fopen("input.txt","r"))){
        printf("No existe el archivo");
        exit(1);
    }

    while(!(feof(archivo))){
        fscanf(archivo,"%i %i",&x,&y);
            i=pantalla(x,y);
        fscanf(archivo,"%i %i",&x1,&y1);
            f=pantalla(x1,y1);
        if((i|f)==0){
            printf("\n\nLa linea con coordenadas [%i,%i] y [%i,%i] se dibuja",x,y,x1,y1);
        }else{
            if((i&f)==0){
                printf("\n\nLa linea con coordenadas [%i,%i] y [%i,%i] se recorta",x,y,x1,y1);
            }else{
                printf("\n\nLa linea con coordenadas [%i,%i] y [%i,%i] se descarta",x,y,x1,y1);
            }
        }
    }
    fclose(archivo);
    return 0;
}
