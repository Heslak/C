#include <stdlib.h>
#include "fposfija.h"
#include "parentesis.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>




COLA* posfija(char v[]){
	COLA *expresion;
	PILA *pilaCompa;
	
	pilaCompa=nuevaPila(strlen(v));
	verif(pilaCompa,v);
	expresion=pasar_posfija(v);
	return expresion;
	
}

COLA* pasar_posfija(char v[]){
	PILA *signos;
	COLA *posfija;
	NODO *nodito;
	INFO carac;
	signos=nuevaPila(strlen(v));
	posfija=nuevaCola();
	char c,r;
	int i=0;
	int x=-2,y=0;
	
	for (i=0; i<strlen(v); i++){
	
		if (isdigit(v[i])!=0){
			nodito=nuevoNodo();
			colaAgregar(posfija,nodito);
			(posfija->t)->info = v[i];
			//printf("[%c] popop,",(posfija->t)->info);
		}
		
		else{
			if (prioridad(v[i])>x || v[i]==']' || v[i]==')' || v[i]=='[' || v[i]=='('){
				x=prioridad(v[i]);
				if (v[i]=='[' || v[i]=='('){
					push(signos,(INFO)v[i]);
					continue;
				}
				
				if (v[i]==']' || v[i]==')'){
					carac.c='0';
					while (1){
						if (v[i]==']'){
							
							if (carac.c!='['){
								
								carac=pop(signos);
								if (carac.c=='[')
									break;
								nodito=nuevoNodo();
								colaAgregar(posfija,nodito);
								(posfija->t)->info=carac.c;
								//imprimeExpresion (posfija);
							}
						
							
						}
						if (v[i]==')'){
							if (carac.c!='('){
							carac=pop(signos);
							if (carac.c=='(')
								break;
							nodito=nuevoNodo();
								colaAgregar(posfija,nodito);
							//printf("%c,",carac.c);
							(posfija->t)->info=carac.c;
							}
							
						}
					}
					continue;
				}
			push(signos,(INFO)v[i]);
			continue;		
				
			}
			if(prioridad(v[i]) <= x){
				carac=pop(signos);
				nodito=nuevoNodo();
				colaAgregar(posfija,nodito);	
				//printf("%c,",carac.c);
				(posfija->t)->info=carac.c;
				x=prioridad(v[i]);
				while(1){
			
					if (pilaVacia(signos)){
						push(signos,(INFO)v[i]);
						x=-2;
						break;
					}
					y=x;
					carac=pop(signos);
					x=prioridad(carac.c);
					push(signos,carac);
					if (x<y || x==-1){
						push(signos,(INFO)v[i]);
						break;
					}
					carac=pop(signos);
					nodito=nuevoNodo();
					colaAgregar(posfija,nodito);		
					//printf("%c,",carac.c);
					(posfija->t)->info=carac.c;
				}
				continue;
			
			}
		}
	}

	while(1){
		if (pilaVacia(signos)){
			break;
		}

		nodito=nuevoNodo();
		colaAgregar(posfija,nodito);
		carac=pop(signos);		
		//printf("%c,",carac.c);
		(posfija->t)->info=carac.c;
		
	}
	
	return posfija;

}

int prioridad (char c){
	if (c=='^'){
		return 10;
	}
	
	if (c=='*' || c=='/'){
		return 9;
	}
	if (c=='+' || c=='-'){
		return 8;
	}
	return -1;
}

void imprimeExpresion (COLA *posfija){
	colaIterar(posfija,&presentaInfoNODO);
}

float evalua (COLA *posfija){
	PILA *numeros;
	NODO *quitando;
	INFO a,b;
	char c;
	int veces=0;
	float resultado=0;
	numeros=nuevaPila(100);
	resultado=0;
	while (1){
		if(colaEstaVacia(posfija)){
			break;
			
		}
		c=(posfija->h)->info;
		if (isdigit(c)!=0){
			push(numeros,(INFO)c);
			}
		else{
			if (veces==0){
				a=pop(numeros);
				b=pop(numeros);
				a.c=a.c-48;
				b.c=b.c-48;
				resultado=operacion((int)b.c,(int)a.c,c);
				veces=1;
			}
			else{
				b=pop(numeros);
				b.c=b.c-48;
				resultado=operacion(resultado,(int)b.c,c);
			}
			
		}
		quitando=colaRetirar(posfija);
		
	}
	return resultado;
}

float operacion(float resultados,float b,char c){
	if (c=='+'){
		return resultados+b;
	}
	if (c=='-'){
		return resultados-b;
	}
	
	if (c=='*'){
		return resultados*b;
	}
	if (c=='/'){
		return resultados/b;
	}
	if (c=='^'){
		return pow(resultados,b);
	}
	
	printf("\n\nError en los operandos");
	exit(0);
}


