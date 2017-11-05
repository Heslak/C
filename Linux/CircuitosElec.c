#include<stdlib.h>
#include<stdio.h>

#Programa personalizado para calculos de Voltajes y Corrientes de un circuito por leyes Kirchhoff

int main(){
	float G1,G2,G3,G4, IR1,IR2,IR3,IR4,Va,Vb,Vc,Vd,If;
	
	G1=5.4;
	G2=0.017;
	G3=13.57;
	G4=27.0873;
	
	If=14.7;
	
	Va=-If/(((G1*G1)/(G3+G1))+((G2*G2)/(G2+G4))-(G1+G2));
	
	Vc=Va*(G2/(G2+G4));
	
	Vb=Va*(G1/(G1+G3));
	
	Vd=0;
	
	IR1=(Va-Vb)*G1;
	IR2=(Va-Vc)*G2;
	IR3=(Vb-Vd)*G3;
	IR4=(Vc-Vd)*G4;
	
	printf("El valor de Va=%g",Va);
	printf("\nEl valor de Vb=%g",Vb);
	printf("\nEl valor de Vc=%g",Vc);
	printf("\nEl valor de Vd=%g",Vd);
	printf("\nEl valor de IR1=%g",IR1);
	printf("\nEl valor de IR2=%g",IR2);
	printf("\nEl valor de IR3=%g",IR3);
	printf("\nEl valor de IR4=%g\n",IR4);
	
	return 0;
}
