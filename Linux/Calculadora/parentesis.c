#include<stdlib.h>
#include "pila.h"
#include<string.h>
#include<stdio.h>


void verif(PILA *pilaCompa,char v[]){
	if (!evaluar_parentesis(v,pilaCompa)){
		printf("Error en los parentesis\n\n");
		dump(pilaCompa);
		exit (0);
	}
}


int evaluar_parentesis(char v[], PILA *pilaCompa){
	int k=0;
	INFO carac;
	
		
	while(v[k]!='\0')
	{
		if (v[k]=='(' || v[k]=='[' )
			push(pilaCompa,(INFO)v[k]);


		if (v[k]==')' || v[k]==']'){
			
			carac=pop(pilaCompa);
			
			if ((carac.c=='[' && v[k]==')') || (carac.c=='(' && v[k]==']')){
				printf("Error en los parentesis\n\n");
				dump(pilaCompa);
				exit (0);
			}
				
		}
		
		k+=1;
	}
		
	return pilaVacia(pilaCompa);	
}
