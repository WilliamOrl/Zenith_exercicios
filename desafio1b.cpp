#include<stdio.h>
#include<math.h>
int main(){
	int i,n;
	float media=0,desv_p=0,soma=0;
	
	printf("Digite um numero para os n numeros calculados:\n");
	scanf("%d",&n);

	float num[n];

	printf("Digite os %d numeros solicitados:\n",n);
	
	for(i=0;i!=n;i++){
			
			scanf("%f",&num[i]);
			
			soma = soma + num[i];			
	}

	media = soma / n;

	for(i=0;i!=n;i++)
		desv_p = desv_p + pow(num[i]-media,2);
	desv_p = sqrt(desv_p/n);
	
	printf("Soma = %f \nMedia = %f \nDesvio Padrao = %f \n",soma,media,desv_p);
	
}
