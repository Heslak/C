#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
	system("color f9");
	int a, reng, col,r,c;
	printf("Programa 25: \"Operaciones con Matrices\"");
	printf("\n\nMen\xA3");
	printf("\n\n1\xA7 Suma");
	printf("\n2\xA7 Resta");
	printf("\n3\xA7 Producto con un escalar");
	printf("\n4\xA7 Traza");
	printf("\n5\xA7 Determinante");
	printf("\n6\xA7 Transpuesta");
	printf("\n\nIngrese el n\xA3mero de la opci\xA2n que desea realizar: ");
	scanf("%i",&a);
	float A[10][10], B[10][10], C[10][10],escalar,traza=0;
	switch(a)
	{
		case 1:
			printf("\n\xFE\tSuma");
		    printf("\n\nElija el n\xA3mero de renglones ");
  			scanf("%i",&r);
		    printf("\nElija el n\xA3mero de columnas ");
		    scanf("%i",&c);
		    for(reng=0;reng<r;reng++)
			{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
    	    	    printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
    	    	    scanf("%f",&A[reng][col]);
    	    	}
   			}
		    for(reng=0;reng<r;reng++) 
    		{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
        		    printf("%10g ",A[reng][col]);
       			}
		    }
		    printf("\n");
		    for(reng=0;reng<r;reng++)
		    {
				printf("\n");
	        	for(col=0;col<c;col++)
	        	{
	        	    printf("Dame el valor de B[%i][%i]=",reng+1,col+1),
	        	    scanf("%f",&B[reng][col]);
	        	}
   			}
		    for(reng=0;reng<r;reng++) 
		    {
    		    printf("\n");
        		for(col=0;col<c;col++)
        		{
        	    printf("%10g ",B[reng][col]);
	        	}
		    }
		    for(reng=0;reng<r;reng++) 
		    {
		        for(col=0;col<c;col++)
    	   		{
    	        C[reng][col]=A[reng][col]+B[reng][col];
    	    	}
   			 }
 		   printf("\n\nEl esultado de la suma de las matrices A y B es:\n");
 	       for(reng=0;reng<r;reng++) 
 		   {
				printf("\n");
     		   for(col=0;col<c;col++)
     		   {
     		       printf("%10g ",C[reng][col]);
     		   }
    		}
    	break;
    	case 2:
    		printf("\n\xFE\tResta");
		    printf("\n\nElija el n\xA3mero de renglones ");
  			scanf("%i",&r);
		    printf("\nElija el n\xA3mero de columnas ");
		    scanf("%i",&c);
		    for(reng=0;reng<r;reng++)
			{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
    	    	    printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
    	    	    scanf("%f",&A[reng][col]);
    	    	}
   			}
		    for(reng=0;reng<r;reng++) 
    		{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
        		    printf("%10g ",A[reng][col]);
       			}
		    }
		    printf("\n");
		    for(reng=0;reng<r;reng++)
		    {
				printf("\n");
	        	for(col=0;col<c;col++)
	        	{
	        	    printf("Dame el valor de B[%i][%i]=",reng+1,col+1),
	        	    scanf("%f",&B[reng][col]);
	        	}
   			}
		    for(reng=0;reng<r;reng++) 
		    {
    		    printf("\n");
        		for(col=0;col<c;col++)
        		{
        	    printf("%10g ",B[reng][col]);
	        	}
		    }
		    for(reng=0;reng<r;reng++) 
		    {
		        for(col=0;col<c;col++)
    	   		{
    	        C[reng][col]=A[reng][col]-B[reng][col];
    	    	}
   			 }
 		   printf("\n\nEl esultado de la resta de las matrices A y B es:\n");
 	       for(reng=0;reng<r;reng++) 
 		   {
				printf("\n");
     		   for(col=0;col<c;col++)
     		   {
     		       printf("%10g ",C[reng][col]);
     		   }
    		}
    	break;
    	case 3:
    		printf("\n\xFE\tProducto con escalar");
		    printf("\n\nElija el n\xA3mero de renglones ");
  			scanf("%i",&r);
		    printf("\nElija el n\xA3mero de columnas ");
		    scanf("%i",&c);
		    for(reng=0;reng<r;reng++)
			{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
    	    	    printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
    	    	    scanf("%f",&A[reng][col]);
    	    	}
   			}
   			printf("\nIngrese el valor del escalar por el que desea multiplicar la matriz: ");
   			scanf("%f",&escalar);
	 		printf("\n\nEl esultado de la multiplicaci\xA2n del escalar por la matriz A es:\n");
  	        for(reng=0;reng<r;reng++) 
 		    {
		 		printf("\n");
     		   for(col=0;col<c;col++)
     		   {
				   A[reng][col]=escalar*A[reng][col];
     		       printf("%10g ",A[reng][col]);
     		   }
    	     }
   		break;
		case 4:
			printf("\n\xFE\tTraza");
		    printf("\n\nElija el n\xA3mero de renglones y columnas: ");
  			scanf("%i",&r);
			c=r;
		    for(reng=0;reng<r;reng++)
			{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
    	    	    printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
    	    	    scanf("%f",&A[reng][col]);
    	    	}
   			}
	 		printf("\n\nEl esultado de la resta de las matrices A y B es:\n");
  	        for(reng=0;reng<r;reng++) 
 		    {
     		   for(col=0;col<c;col++)
     		   {
					if(reng==col)
					{
						traza=traza+A[reng][col];
						printf("%g + ",A[reng][col]);
					}
				}
    	     }
    	     printf("\b\b= %g",traza);
   		break;
		case 6:
			printf("\n\xFE\tTranspuesta");
		    printf("\n\nElija el n\xA3mero de renglones ");
  			scanf("%i",&r);
		    printf("\nElija el n\xA3mero de columnas ");
		    scanf("%i",&c);
		    for(reng=0;reng<r;reng++)
			{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
    	    	    printf("Dame el valor de A[%i][%i]=",reng+1,col+1),
    	    	    scanf("%f",&A[reng][col]);
    	    	}
   			}
   			for(reng=0;reng<r;reng++) 
    		{
    		    printf("\n");
    		    for(col=0;col<c;col++)
    		    {
        		    printf("%10g ",A[reng][col]);
       			}
		    }
		    printf("\n\nLa matriz transpuesta de A es: ");
			for(col=0;col<c;col++)
   		 	{
    		    printf("\n");
    		    for(reng=0;reng<r;reng++) 
    		    {
    		        printf("%10g ",A[reng][col]);
    		    }
    		}
    	break;
	}
	getch();
}
