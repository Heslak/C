#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quitando_vocal(char *cadena, int v){
	
	int i=0,r=0;
	char cadena2[1000];
	
	while(cadena[i]!='\0'){
	
		if (i==v){
			i+=1;
			continue;
		}
		
		cadena2[r]=cadena[i];
		r+=1;
		i+=1;
	
	}
	cadena2[r]='\0';
	strncpy(cadena,cadena2,1000);
}

void quitando_siete(char *cadena){
	
	int i=0,r=0;
	char cadena2[1000];
	
	while(cadena[i]!='\0'){
	
		if (i%7==0){
			i+=1;
			continue;
		}
		
		cadena2[r]=cadena[i];
		r+=1;
		i+=1;
	
	}
	cadena2[r]='\0';
	strncpy(cadena,cadena2,1000);
	
	
}

void det_primo(char *cadena){
	
	int longi=0,i=0,r=0,x=0,y=0,pol;
	char cadena2[100];
	
	while(cadena[i]!='\0'){
		if (ispunct(cadena[i])==0 && isdigit (cadena[i])==0 && isspace(cadena[i])==0 && cadena[i]!='\xEF' && cadena[i]!='\xF9' && cadena[i]!='^' && cadena[i]!='?' && cadena[i]!='\xA8' && cadena[i]!='\xAD' && cadena[i]!='\xF8' && cadena[i]!='\xAA'){
			longi+=1;
		}
		i+=1;		
	}
	
	if (longi==1 || longi ==0){
	r=12;	
	}
	else{
		for(i=2; i<longi; i++){
		
			if(longi%i==0){
				r=12;
				break;
			
			}
		
		}	
	}
	
	if(r==0){
		
		pol=strlen(cadena)-1;
		if (ispunct(cadena[pol])!=0 || cadena[pol]=='\xEF' || cadena[pol]=='\xF9' || cadena[pol]=='^' || cadena[pol]=='\x3F' || cadena[pol]=='\xA8' || cadena[pol]=='\xAD' || cadena[pol]=='\xF8' || cadena[pol]=='\xAA'){
			
			while(cadena[y]!='\0'){
	
				if (y==strlen(cadena)-1){
					cadena2[y-1]!='\0';
					break;
				}
		
				cadena2[y]=cadena[y];
				y+=1;
	
			}
			printf("\n   \xF8%s",cadena2);
		}
		
		else{
			
			printf("\n   \xF8%s",cadena);
		}
		
	}
}

void contar_letras(char *cadena){
	int i=0, cont_letras=0;
	
	while(cadena[i]!='\0'){
		if (ispunct(cadena[i])==0 && isdigit (cadena[i])==0 && isspace(cadena[i])==0 && cadena[i]!='\xEF' && cadena[i]!='\xF9' && cadena[i]!='^' && cadena[i]!='?' && cadena[i]!='\xA8' && cadena[i]!='\xAD' && cadena[i]!='\xF8' && cadena[i]!='\xAA'){
			cont_letras+=1;
		}
		i+=1;		
	}
	if (cont_letras==0){
		printf("\n*La cadena no tiene letras");
	}
	if(cont_letras==1){
		printf("\n*La cadena tiene 1 letra");
	}
	if(cont_letras>1){
		printf("\n*La cadena tiene %i letras",cont_letras);
	}
	
}


void contar_primos(char *cadena){
	
	int i=0, cont_letras=0, confirmacion=0,iaux=0,num;
	char aux[100];
	
	printf("\n\n*Las palabras que contienen un n\xA3mero de letras primo son:\n");
	
	num=strlen(cadena);
	
	for(i=0;i<num;i++){
		
		
		
		if(isspace(cadena[i])!=0 || cadena[i+1]=='\0'){
			if (cadena[i+1]=='\0'){
				aux[iaux]=cadena[i];
				iaux+=1;
			}
			aux[iaux]='\0';
			
			det_primo(aux);
			
			confirmacion=0;
		}
		
		if (ispunct(cadena[i])==0 && isdigit (cadena[i])==0 && isspace(cadena[i])==0 && cadena[i]!='\xEF' && cadena[i]!='\xF9' && cadena[i]!='^' && cadena[i]!='?' && cadena[i]!='\xA8' && cadena[i]!='\xAD' && cadena[i]!='\xF8' && cadena[i]!='\xAA'){
		
			if (confirmacion==0){	
				cont_letras=0;
				iaux=0;
			}
			
			confirmacion=1;
			cont_letras+=1;
			
		}
		
		aux[iaux]=cadena[i];
		iaux+=1;
				
	}
	
}

void quitar(char *cadena){
	
	int i=0,v=0, vocales[]={65,69,73,79,85,97,101,105,111,117,-127,-126,-125,-124,-123,-132,-120,-119,-118,-117,-116,-115,-114,-113,-112,-109,-108,-107,-106,-105,-103,-102,-96,-95,-94,-93,-75,-74,-73,-58,-57,-46,-45,-44,-42,-41,-40,-31,-30,-29,-28,-27,-23,-22,-21};
	printf("\n\n*La cadena sin vocales y sin las posiciones multiplos de 7 es:");
	while(cadena[i]!='\0'){
		
		for(v=0;v<55;v++){
		
			
			if(cadena[i]==vocales[v]){
				quitando_vocal(cadena,i);
				i-=1;
			}
		}
		
		i+=1;		
	}
	
	quitando_siete(cadena);
	printf("\n\t%s\n\n",cadena);
	
}
