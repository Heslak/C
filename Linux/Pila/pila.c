#include <stdlib.h>
#include <stdio.h>
#include "pila.h"


PILA *nuevaPila(int n) {
    PILA *pila;
    pila = (PILA *)malloc(sizeof(PILA));
    pila->top = -1; // pila vacia
    pila->p = (char *)malloc(sizeof(char)*n);
    pila->max = n;
    return pila;
}

void dump(PILA *pila) {
    int k;
    printf("Tope del stack = %d    Capacidad del stack = %d\n",pila->top,pila->max);
    for (k=0;k<=pila->top;k++)
        printf("[%d]=%c\n",k,pila->p[k]);
}

int pilaVacia(PILA *pila) {
    return pila->top== -1;
}

void push(PILA *pila, char c) {
    if (pila->top<pila->max) {
		pila->top+=1;
		pila->p[pila->top]=c;	
    } else {
        printf("ERROR(push): Pila llena!\n");
        dump(pila);
        exit(0);
    }
}

char pop(PILA *pila) {
    char c;
    if (pila->top==-1) {
        printf("ERROR (pop): Pila vacia!");
        exit(0);
    } else{
    c=pila->p[pila->top];
	pila->top-=1;
	}
    return c;
}

char tope(PILA *pila) {
    if (pila->top == -1) {
        printf("ERROR (tope): Pila vacia!");
        exit(0);
    }
    return pila->p[pila->top];
}
