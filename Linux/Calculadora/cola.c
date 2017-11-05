#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

COLA *nuevaCola() {
    COLA *p;
    p = malloc(sizeof(COLA));
    p->h = p->t = NULL;
    return p;
}


NODO *nuevoNodo() {
    NODO *p;
    p = malloc(sizeof(NODO));
    p->sig = NULL;
    return p;
}

int colaEstaVacia(COLA *cola) {
    return cola->h == NULL;
}

void colaAgregar(COLA *cola,NODO *nodo) {
    if (colaEstaVacia(cola)) {
       cola->h = cola->t = nodo;
    } else {
        (cola->t)->sig = nodo;
        cola->t = nodo;
    }
}

NODO *colaRetirar(COLA *cola) {
    NODO *p;
    if (colaEstaVacia(cola))
        return NULL;
    p = cola->h;
    cola->h = (cola->h)->sig;
    if (colaEstaVacia(cola))
        cola->t = NULL;
    p->sig = NULL;
    return p;
}

void colaIterar(COLA *cola, ITERADOR_COLA miFuncion) {
    NODO *p;
    if (colaEstaVacia(cola)) {
        return;
    }
    p = cola->h;
    while (p!=NULL) {
        miFuncion(p);
        p=p->sig;
    }
}

void presentaInfoNODO(NODO *n){
	printf("[%c],",n->info);
}

