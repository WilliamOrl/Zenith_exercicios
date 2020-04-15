#include<stdio.h>
#include<math.h>

float f_soma(float vet[], int freq){
	int i;
	float a;
	for(i=0;i!=freq;i++)
		a=a+vet[i];
	return a;	
}

float f_media(float total,int freq){
	int a;
	a = total / freq;
	return a;
}

float f_desvp(float vet[],float media, int freq){
		int i;
		float a;
		for(i=0;i!=freq;i++)
		a = a + pow(vet[i]-media,2);
		a = sqrt(a/freq);
		return a;
}

int main(void){
	int i,n;
	float media=0,desv_p=0,soma=0;
	
	printf("Digite um numero para os n numeros calculados:\n");
	scanf("%d",&n);

	float num[n];

	printf("Digite os %d numeros solicitados:\n",n);
	
	for(i=0;i!=n;i++){		
			scanf("%f",&num[i]);		
	}

	soma = f_soma(num,n);
	media = f_media(soma,n);
	desv_p = f_desvp(num,media,n);

	printf("Soma = %f \nMedia = %f \nDesvio Padrao = %f \n",soma,media,desv_p);
	
}
