#include <stdlib.h>
#include <stdio.h>
#include "pila.h"


PILA *nuevaPila(int n) {
    PILA *pila;
    pila = (PILA *)malloc(sizeof(PILA));
    pila->top = -1; // pila vacia
    pila->p = (INFO *)malloc(sizeof(INFO)*n);
    pila->max = n;
    return pila;
}


int pilaVacia(PILA *pila) {
    return pila->top== -1;
}

void dump(PILA *pila) {
    int k;
    printf("Tope del stack = %d    Capacidad del stack = %d\n",pila->top,pila->max);
    for (k=0;k<=pila->top;k++)
        printf("[%d]=%c\n",k,pila->p[k].c);
}

void push(PILA *pila, INFO s) {
    if ((pila->top+1) < pila->max) {
        pila->top++;
        pila->p[pila->top] =s;
    } else {
        printf("ERROR(push): pila llena!\n");
        dump(pila);
        exit(0);
    }
}

INFO pop(PILA *pila) {
    INFO c;
    if (pilaVacia(pila)) {
        printf("ERROR (pop): Pila vacia!");
        exit(0);
    }
    c = pila->p[pila->top];
    pila->top--;
    return c;
}

INFO tope(PILA *pila) {
    if (pila->top == -1) {
        printf("ERROR (tope): Pila vacia!");
        exit(0);
    }
    return pila->p[pila->top];
}
