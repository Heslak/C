#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void CURP(char** nombre, char fecha[], char sexo);																								//Declaración de la función que va a conseguir el CURP

char CURPI[18], **situacion, RFC[10], estado[2], INI[18],n_estado[2];																										//Variable global donde se va a guardar el CURP

char** reservar_memoria(char** nombre);

char** obtener_nombres(char** nombre);

void obtener_fecha(char fecha[], char* sexo);

void obtener_estado();

void INE(char** nombre, char fecha[], char sexo);	


int main(){
	
	char **nombre, fecha[10], sexo; 																								//Cadena de caraceres que van a albergar el nombre
	system("color f9");																												//Cambiamos el fondo y las letras de color
	srand(time(NULL));
	printf("********************************************************************************");
	printf("\n \t\t\tPrograma para sacar CURP, RFC y Clave Electoral");
	printf("\n Integrantes: \n Acosta Vega Sergio \n Fabian Fabian Oscar Daniel \n Hern\xA0ndez Ira\xA1s \n P\x82rez Carlos");
	
	nombre=reservar_memoria(nombre);	
	obtener_fecha(fecha, &sexo);
	obtener_estado();
	CURP(nombre, fecha, sexo);																											//Mandamos llamar a la función que obtendra el CURP
	INE(nombre, fecha, sexo);
	getchar();
	return 0;	
}

char** reservar_memoria(char** nombre){																								//Función para reservar memoria
	
	int i=0;
	situacion=(char **)calloc(4,sizeof(char*));
	nombre=(char **)calloc(4,sizeof(char*));																						//Reservamos memoria para hacer la lista de cadenas
		
	for(i=0;i<4;i++){
		nombre[i]=(char*)calloc(50,sizeof(char));																					//Reservamos memoria para cada elemento de la lista
		situacion[i]=(char*)calloc(50,sizeof(char));
	}
	
	situacion[0]="primer nombre";
	situacion[1]="segundo nombre";
	situacion[2]="apellido paterno";
	situacion[3]="apellido materno";
	
	return (obtener_nombres(nombre));																								//Regresamos la dirección del apuntador
}

char** obtener_nombres(char** nombre){																								//Función para obtener datos
	
	int i=0, j=0;
	
	for(i=0;i<4;i++){																												//For con el que obtenemos nombres y apellidos
		switch(i){
			case 0:
				printf("\n\nPor favor, ingrese su primer nombre: ");
			break;
			case 1:
				printf("Por favor, ingrese su segundo nombre (en caso de no tenerlo presionar enter): ");								
			break;
			case 2:
				printf("Por favor, ingrese su apellido paterno: ");
			break;
			case 3:
				printf("Por favor, ingrese su apellido materno: ");
			break;			
		}
		gets(nombre[i]);																												//Obtenemos el apellido materno
		strupr(nombre[i]);																												
		fflush(stdin);
		
		while(nombre[i][0]=='\0' && i!=1){
			printf("Por favor, ingrese bien su %s: ", situacion[i]);
			gets(nombre[i]);	
			strupr(nombre[i]);																									//Obtenemos la fecha de nacimiento
			fflush(stdin);	
		}
		
		while(nombre[i][j]!='\0'){
			
			if(nombre[i][j]>90 || nombre[i][j]<65){																							//Verificamos que se hayan ingresado solo números para la fecha
				printf("Por favor, ingrese bien su %s: ", situacion[i]);
				gets(nombre[i]);	
				strupr(nombre[i]);																									//Obtenemos la fecha de nacimiento
				fflush(stdin);
				j=-1;
				
				while(nombre[i][0]=='\0' && i!=1){
					printf("Por favor, ingrese bien su %s: ", situacion[i]);
					gets(nombre[i]);	
					strupr(nombre[i]);																									//Obtenemos la fecha de nacimiento
					fflush(stdin);	
				}
			}
			
			j++;			
		}
		
		j=0;
		
	}
		
	return nombre;
	
}

void obtener_fecha(char fecha[], char* sexo){
	
	int i=0;
	
	printf("Por favor, ingrese su fecha de nacimiento (dd/mm/aaaa): ");
	gets(fecha);																													//Obtenemos la fecha de nacimiento
	fflush(stdin);
	
	for(i=0; i<10; i++){

		if(i==2 || i==5){
			if (fecha[i]!='/'){																										//Verificamos que las diagonales se encuentren en el lugar correcto
				printf("Por favor, ingrese bien su fecha de nacimiento (dd/mm/aaaa): ");
				gets(fecha);																										//Obtenemos la fecha de nacimiento
				fflush(stdin);
				i=0;
			}
			
		}else{
				
			if(fecha[i]>57 || fecha[i]<48){																							//Verificamos que se hayan ingresado solo números para la fecha
				printf("Por favor, ingrese bien su fecha de nacimiento (dd/mm/aaaa): ");
				gets(fecha);																										//Obtenemos la fecha de nacimiento
				fflush(stdin);
				i=0;
			}else{	
					if(fecha[0]>51 || fecha[3]>49 || (fecha[3]==49 && fecha[4]>50) || (fecha[0]==51 && fecha[1]>49) || (fecha[0]==51 && fecha[3]==48 && fecha[4]==50)){																							//Verificamos que se hayan ingresado solo números para la fecha
						printf("Por favor, ingrese bien su fecha de nacimiento (dd/mm/aaaa): ");
						gets(fecha);																										//Obtenemos la fecha de nacimiento
						fflush(stdin);
						i=0;
				}
			
			}
			
		}	
		
	}
	
	printf("Por favor, ingrese su sexo (M o H): ");
	scanf("%c",sexo);
	if(*sexo==104 || *sexo==109){
		*sexo=*sexo-32;
	}
	fflush(stdin);

	while( (*sexo)!='M' && (*sexo)!='H'){
		
		printf("Por favor, ingrese bien su sexo (M o H): ");
		scanf("%c",sexo);
		if(*sexo==104 || *sexo==109){
			*sexo=*sexo-32;
		}
		fflush(stdin);
	}

}

void obtener_estado(){
	int i=0, j=1;
	
	printf("\n\t\t\tEstados");
	printf("\n\n1\xA7\t Aguascalientes");
	printf("\n2\xA7\t Baja California");
	printf("\n3\xA7\t Baja California Sur");
	printf("\n4\xA7\t Campeche");
	printf("\n5\xA7\t Coahuila");
	printf("\n6\xA7\t Colima");
	printf("\n7\xA7\t Chiapas");
	printf("\n8\xA7\t Chihuahua");
	printf("\n9\xA7\t Ciudad de M\x82xico");
	printf("\n10\xA7\t Durango");
	printf("\n11\xA7\t Guanajuato");
	printf("\n12\xA7\t Guerrero");
	printf("\n13\xA7\t Hidalgo");
	printf("\n14\xA7\t Jalisco");
	printf("\n15\xA7\t Estado de M\x82xico");
	printf("\n16\xA7\t Michoac\xA0n");
	printf("\n17\xA7\t Morelos");
	printf("\n18\xA7\t Nayarit");
	printf("\n19\xA7\t Nuevo Le\xA2n");
	printf("\n20\xA7\t Oaxaca");
	printf("\n21\xA7\t Puebla");
	printf("\n22\xA7\t Quer\x82taro");
	printf("\n23\xA7\t Quintana Roo");
	printf("\n24\xA7\t San Luis Potos\xA1");
	printf("\n25\xA7\t Sinaloa");
	printf("\n26\xA7\t Sonora");
	printf("\n27\xA7\t Tabasco");
	printf("\n28\xA7\t Tamaulipas");
	printf("\n29\xA7\t Tlaxcala");
	printf("\n30\xA7\t Veracruz");
	printf("\n31\xA7\t Yucat\xA0n");
	printf("\n32\xA7\t Zacatecas");
	
	while(j){
	printf("\n\nPor favor, ingrese el n\xA3mero nombre de su estado de nacimiento: ");
	scanf("%i", &i);
	j=0;
	switch(i){
			case 1:
				strncpy(estado,"AS",2);
				strncpy(n_estado,"01",2);			
			break;
			case 2:
				strncpy(estado,"BN",2);
				strncpy(n_estado,"02",2);
			break;
			case 3:
				strncpy(estado,"BR",2);	
				strncpy(n_estado,"03",2);
			break;
			case 4:
				strncpy(estado,"CC",2);	
				strncpy(n_estado,"04",2);
			break;
			case 5:
				strncpy(estado,"CL",2);	
				strncpy(n_estado,"05",2);
			break;
			case 6:
				strncpy(estado,"CM",2);	
				strncpy(n_estado,"06",2);
			break;
			case 7:
				strncpy(estado,"CS",2);	
				strncpy(n_estado,"07",2);
			break;
			case 8:
				strncpy(estado,"CH",2);	
				strncpy(n_estado,"08",2);
			break;
			case 9:
				strncpy(estado,"CX",2);	
				strncpy(n_estado,"09",2);
			break;
			case 10:
				strncpy(estado,"DG",2);	
				strncpy(n_estado,"10",2);
			break;
			case 11:
				strncpy(estado,"GT",2);	
				strncpy(n_estado,"11",2);
			break;
			case 12:
				strncpy(estado,"GR",2);	
				strncpy(n_estado,"12",2);
			break;
			case 13:
				strncpy(estado,"HG",2);	
				strncpy(n_estado,"13",2);
			break;
			case 14:
				strncpy(estado,"JC",2);	
				strncpy(n_estado,"14",2);
			break;
			case 15:
				strncpy(estado,"MC",2);	
				strncpy(n_estado,"15",2);
			break;
			case 16:
				strncpy(estado,"MN",2);	
				strncpy(n_estado,"16",2);
			break;
			case 17:
				strncpy(estado,"MS",2);
				strncpy(n_estado,"17",2);
			break;
			case 18:
				strncpy(estado,"NT",2);
				strncpy(n_estado,"18",2);
			break;
			case 19:
				strncpy(estado,"NN",2);
				strncpy(n_estado,"19",2);
			break;
			case 20:
				strncpy(estado,"OC",2);
				strncpy(n_estado,"20",2);
			break;
			case 21:
				strncpy(estado,"PL",2);
				strncpy(n_estado,"21",2);
			break;
			case 22:
				strncpy(estado,"QT",2);
				strncpy(n_estado,"22",2);
			break;
			case 23:
				strncpy(estado,"QR",2);
				strncpy(n_estado,"23",2);
			break;
			case 24:
				strncpy(estado,"SS",2);
				strncpy(n_estado,"24",2);
			break;
			case 25:
				strncpy(estado,"SL",2);
				strncpy(n_estado,"25",2);
			break;
			case 26:
				strncpy(estado,"SR",2);
				strncpy(n_estado,"26",2);
			break;
			case 27:
				strncpy(estado,"TC",2);
				strncpy(n_estado,"27",2);
			break;
			case 28:
				strncpy(estado,"TP",2);
				strncpy(n_estado,"28",2);
			break;
			case 29:
				strncpy(estado,"TL",2);
				strncpy(n_estado,"29",2);
			break;
			case 30:
				strncpy(estado,"VZ",2);
				strncpy(n_estado,"30",2);
			break;
			case 31:
				strncpy(estado,"YN",2);
				strncpy(n_estado,"31",2);
			break;
			case 32:
				strncpy(estado,"ZS",2);
				strncpy(n_estado,"32",2);
			break;
			default:
				j=1;
			break;
		}
	}
	
	
}

void CURP(char** nombre, char fecha[],char sexo){																								//Función que obtiene el CURP
		int i=0,j=0;
		CURPI[0]=nombre[2][0];																										//Usamos la primer letra el apellido
		i=1;
		while(nombre[2][i]!='A' && nombre[2][i]!='E' && nombre[2][i]!='I' && nombre[2][i]!='O' && nombre[2][i]!='U'){
			i++;
		}
		CURPI[1]=nombre[2][i];
		CURPI[2]=nombre[3][0];
		CURPI[3]=nombre[0][0];
		
		CURPI[4]=fecha[8];
		CURPI[5]=fecha[9];
		
		CURPI[6]=fecha[3];
		CURPI[7]=fecha[4];
		
		CURPI[8]=fecha[0];
		CURPI[9]=fecha[1];
		strncpy(RFC,CURPI,10);
		CURPI[10]=sexo;
		CURPI[11]=estado[0];
		CURPI[12]=estado[1];
		
		for(j=0;j<4;j++){
			
			if(j==1){
				continue;
			}
			
			i=1;
			while(nombre[j][i]=='A' || nombre[j][i]=='E' || nombre[j][i]=='I' || nombre[j][i]=='O' || nombre[j][i]=='U'){
				i++;
			}
			
			if(j==0){
				CURPI[15]=nombre[j][i];
			}
			if(j==2){
				CURPI[13]=nombre[j][i];
			}
			if(j==3){
				CURPI[14]=nombre[j][i];
			}
			
			
		}
		if(fecha[6]=='2'){
			CURPI[16]=65+rand()%26;
		}else{
			CURPI[16]=48+rand()%10;
		}
		
		
		CURPI[17]=48+rand()%10;

		printf("%s", CURPI);
	
}

void INE(char** nombre, char fecha[], char sexo){
	
	int j=0, i=0;
	char ulimo[3]="000";
	
	for(j=0;j<4;j++){
			
		if(j==1){
			continue;
		}
	
		i=1;
		while(nombre[j][i]=='A' || nombre[j][i]=='E' || nombre[j][i]=='I' || nombre[j][i]=='O' || nombre[j][i]=='U'){
			i++;
		}
		
		if(j==0){
			INI[4]=nombre[j][0];
			INI[5]=nombre[j][i];
		}
		if(j==2){
			INI[0]=nombre[j][0];
			INI[1]=nombre[j][i];
		}
		if(j==3){
			INI[2]=nombre[j][0];
			INI[3]=nombre[j][i];
		}
				
	}
	
	INI[6]=fecha[8];
	INI[7]=fecha[9];
		
	INI[8]=fecha[3];
	INI[9]=fecha[4];
		
	INI[10]=fecha[0];
	INI[11]=fecha[1];
	
	INI[12]=n_estado[0];
	INI[13]=n_estado[1];
	
	INI[14]=sexo;
	
	if(sexo=='H'){
		i=atoi(n_estado)*10;
	}else{
		i=atoi(n_estado)*20;
	}
	
	sprintf(ulimo,"%i",i);
	
	if(i<100){
		INI[15]='0';
		INI[16]=ulimo[0];
		INI[17]=ulimo[1];
	}else{
		
		INI[15]=ulimo[0];
		INI[16]=ulimo[1];
		INI[17]=ulimo[2];
	}
	
	printf("\n%s", INI);
	
	
}
