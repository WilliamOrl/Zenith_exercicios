#include<stdio.h>
#define SUCESSO 0
#define ERRO -1

int div(float *result, int n1,int n2, int divisor);

int main(){
	
	int n1,n2,divisor,aux;
	float result[2];
	
	printf("digite o primeiro numero: ");
	scanf("%d",&n1);
	printf("\ndigite o segundo numero: ");
	scanf("%d",&n2);
	printf("\ndigite o divisor: ");
	scanf("%d",&divisor);
	
	aux = div(result,n1,n2,divisor);	
	
	if (aux == SUCESSO)
	printf("\ndivisao de %d por %d = %f\ndivisao de %d por %d = %f",n1,divisor,result[0],n2,divisor,result[1]);

	else 
	printf("\nErro!");
	
}

int div(float*result,int n1,int n2,int divisor){
	
	if(divisor==0)
	return ERRO;
		
	result[0] = n1/divisor;
	result[1] = n2/divisor;	
	
	return SUCESSO;
}
