#include <stdio.h>
#include <stdlib.h>

void imprime(int k, int V[]){
	
	if (k==-1){
		return;
	}
	printf("%d\n",V[k]);
	imprime(k-1,V);
	
}
