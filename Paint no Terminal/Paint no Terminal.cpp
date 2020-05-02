//	Programa realizado durante o treinamento do Zenith 
//	Hands-on Project 1 - Paint no Terminal
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  


typedef struct{
	char magic_number[3];
	int heigth;
	int width;
	int color;
	int **imagem;
}Imagem;


int Comandos(int *retorno,char *nome);					//Le o comando digitado
void Create(int *dimensoes,Imagem *pixels);				//Cria a imagem PBM
void Export(char *nome, Imagem *pixels);				//Salva a imagem

int main(void){
	Imagem pixels;
	int cmdint[30];
	char cmdchar[30];
	int aux;
	
	while(1){
		aux = Comandos(cmdint,cmdchar);
		switch(aux){
			
			case 1:
			Create(cmdint,&pixels);
				break;
			
			
			case 2:
			Export(cmdchar,&pixels);
				break;
			
			
			case 3:
				
				break;
			
			
			case 4:
				
				break;
			
			
			case 5:
				
				break;
			
			case 6:
				
				break;
			
		}	
	}
}


int Comandos(int *retorno,char *nome){  //Seleciona o comando
	
	int i,j,aux;
	char cmd[30];
	int caracter;
	
		
	printf("Digite o Comando: ");
	scanf("%[^\n]s",&cmd);
	setbuf(stdin, NULL);

		

	if(cmd[0] == 'C' && cmd[1] == 'R' && cmd[2] == 'E' && cmd[3] == 'A' && cmd[4] == 'T' && cmd[5] == 'E'){		//CREATE
		
		for(i=0,j=0;i!=30;i++){
			if(cmd[i]>=48 && cmd[i]<=57){	//48 e 57 são os estremos de 0 a 9 na tabala ASCII
				retorno[j] = cmd[i] - 48;
				j++;
			}
		}
		return 1;
	}
	
	if(cmd[0] == 'E' && cmd[1] == 'X' && cmd[2] == 'P' && cmd[3] == 'O' && cmd[4] == 'R' && cmd[5] == 'T'){		//EXPORT

		for(i=7,j=0;i!=30;i++,j++){
			nome[j] = cmd[i]; 
		}
		
		return 2;
	}
	
	if(cmd[0] == 'L' && cmd[1] == 'I' && cmd[2] == 'N' && cmd[3] == 'E'){		//LINE
		
		for(i=4,j=0;i=30;i++,j++)
		
			cmd[i]= retorno[j];
			
		return 3;
	}
	
	if(cmd[0] == 'C' && cmd[1] == 'I' && cmd[2] == 'R' && cmd[3] == 'C' && cmd[4] == 'L' && cmd[5] == 'E'){		//CIRCLE
		
		for(i=6,j=0;i=30;i++,j++)
			cmd[i]= retorno[j];
		
		return 4;
	}
	
	if(cmd[0] == 'D' && cmd[1] == 'I' && cmd[2] == 'S' && cmd[3] == 'K'){		//DISK
		
		for(i=4,j=0;i=30;i++,j++)
			cmd[i]= retorno[j];
		
		return 5;
	}
	
	if(cmd[0] == 'R' && cmd[1] == 'E' && cmd[2] == 'C' && cmd[3] == 'T'){		//RECT
		
		for(i=4,j=0;i=30;i++,j++)
			cmd[i]= retorno[j];
		
		return 6;
	}
}

void Create(int *dimensoes,Imagem *pixels){		//Cria a imagem PGM
	
	int i,j,aux;
	int width=0,heigth=0;
	
	printf("Criando Imagem...\n");
	
	for(i=0,aux=100;i!=3;i++){
		width = width + dimensoes[i]*aux;
		aux = aux/10;
	}
	
	for(i=3,aux=100;i!=6;i++){
		heigth = heigth + dimensoes[i]*aux;
		aux = aux/10;
	}
	
	
	if(heigth>width){
		printf("ERRO!\n");
		return;
	}
	
	
	pixels->magic_number[0] = 'P';
	pixels->magic_number[1] = '2';
	pixels->magic_number[2] = '\0';

	pixels->width = width;
	pixels->heigth = heigth;

	pixels->imagem = (int **) calloc (width, sizeof(int *));
        for (int i = 0; i < heigth; i++){
            pixels->imagem[i] = (int *) calloc (width, sizeof(int));
        }
		

	return;
}

void Export(char *nome, Imagem *pixels){

	int i,j;
	
	strcat (nome, ".pgm");
	
	FILE *arquivo = fopen (nome,"w");

	fprintf(arquivo,"%s\n",pixels->magic_number);
    fprintf(arquivo, "%d %d\n",pixels->heigth,pixels->width);
	fprintf(arquivo, "%d\n",pixels->color);
	
	for(i=0;i!=pixels->heigth;i++){
		for(j=0;j!=pixels->width;j++){
			fprintf(arquivo,"%d",pixels->imagem[i][j]);
		}
		fprintf(arquivo,"\n");
	}

	fclose(arquivo);
	return;
}

