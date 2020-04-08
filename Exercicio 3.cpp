#include<stdio.h>
#include<stdlib.h>

void lerArquivo(int *vet);

int main(){
	int vet[4];
	char num[4];
		
	lerArquivo(vet);
	
	printf("Arquivo lido com Sucesso\n");
	
	system("PAUSE");
	return 0;
}


void lerArquivo(int *vet){
	
	char i=0;
	FILE *arquivo;
	
	arquivo = fopen("C:\\Users\\User\\Desktop\\USP\\Zenith\\Treinamento_Programacao_C-master\\Lista01\\dados1.csv","r");
	
	for(i=0;i<10;i++)
		fscanf(arquivo,"%d,%d,%d\n",&vet[i],&vet[i+1],&vet[i+2]);
	
	arquivo = fopen("dadoscopia1.csv","w");
	
		for(i=0;i!=10;i++)
			fprintf(arquivo,"%d, %d, %d\n",vet[i],vet[i+1],vet[i+2]);
	
	fclose(arquivo);
	
	
}
