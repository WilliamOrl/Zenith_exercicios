#include<stdio.h>
#include<math.h>
#define N 4
int main(){
	int i;
	float num[N],soma=0;
	float media=0,desv_p=0;
	
	
	printf("Digite os %d numeros solicitados:\n",N);
	
	for(i=0;i!=N;i++){
			
			scanf("%f",&num[i]);
			
			soma = soma + num[i];			
	}

	media = soma / N;

	for(i=0;i!=N;i++)
		desv_p = desv_p + pow(num[i]-media,2);
	desv_p = sqrt(desv_p/N);
	
	printf("Soma = %f \nMedia = %f \nDesvio Padrao = %f \n",soma,media,desv_p);
	
}
