#include "cola.h"
#include "pila.h"
COLA* pasar_posfija(char v[]);

COLA* posfija(char v[]);

int prioridad(char c);

void imprimeExpresion (COLA *posfija);

float evalua(COLA *posfija);

float operacion(float resultados,float b,char c);
