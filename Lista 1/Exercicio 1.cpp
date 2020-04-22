#include<stdio.h>
#include<math.h>
int main(){
	int i;
	float num[3],soma=0;
	float media=0,desv_p=0;
	
	
	printf("Digite os 3 numeros solicitados: ");
	
	for(i=0;i!=3;i++){
			
			scanf("%f",&num[i]);
			
			soma = soma + num[i];			
	}

	media = soma / 3;

	for(i=0;i!=3;i++)
		desv_p = desv_p + pow(num[i]-media,2);
	desv_p = sqrt(desv_p/3);
	
	printf("Soma = %f \nMedia = %f \nDesvio Padrao = %f \n",soma,media,desv_p);
	
}
