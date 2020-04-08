#include<stdio.h>
#include<stdlib.h>

void lerArquivo(int *vet);

int main(){
	int vet[4];
	char num[4];
		
	lerArquivo(vet);
	
	printf("Arquivo lido com Sucesso");
	
	system("PAUSE");
	return 0;
}


void lerArquivo(int *vet){
	
	char i=0;
	FILE *arquivo;
	
	arquivo = fopen("C:\\Users\\User\\Desktop\\USP\\Zenith\\Treinamento_Programacao_C-master\\Lista01\\dados1.csv","r");
	
	for(i=0;i<4;i++)
		fscanf(arquivo,"%d",&vet[i]);
	
	arquivo = fopen("dadoscopia.csv","w");
	
		for(i=0;i!=4;i++)
			fprintf(arquivo,"%d", vet[i]);
	
	fclose(arquivo);
	
	
}
