//	Programa realizado durante o treinamento do Zenith 
//	Hands-on Project 1 - Paint no Terminal
#include<stdio.h>
#include<string.h>
#define SUCESSO 1
#define ERRO -1

int Comandos(int *retorno,char *nome, int *info);					//Le o comando digitado
void Create(int *dimensoes,char *nome, int *info);			//Cria a imagem PBM


int main(void){
	int cmdint[30];
	char cmdchar[30];
	int aux,info;
	info = 0;
	
	while(1){
		aux = Comandos(cmdint,cmdchar,&info);
		switch(aux){
			
			case 1:
			Create(cmdint,cmdchar,&info);
				break;
			
			
			case 2:
				
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


int Comandos(int *retorno,char *nome, int *info){  //Seleciona o comando
	
	int i,j,aux;
	char cmd[30];
	int caracter;
	
	
	for(i=0;i!=30;i++)
		cmd[i] = ' ';
	
	
	printf("Digite o Comando: ");
	scanf("%[^\n]s",&cmd);
	setbuf(stdin, NULL);
	//printf("\n");
		

	if(cmd[0] == 'C' && cmd[1] == 'R' && cmd[2] == 'E' && cmd[3] == 'A' && cmd[4] == 'T' && cmd[5] == 'E'){		//CREATE
		
		for(i=0,j=0;i!=30;i++){
			if(cmd[i]>=48 && cmd[i]<=57){	//48 e 57 s�o os estremos de 0 a 9 na tabala ASCII
				retorno[j] = cmd[i] - 48;
				j++;
			}
		}
		*info = 1;
		return 1;
	}
	
	if(cmd[0] == 'E' && cmd[1] == 'X' && cmd[2] == 'P' && cmd[3] == 'O' && cmd[4] == 'R' && cmd[5] == 'T'){		//EXPORT

		
	
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

void Create(int *dimensoes,char *nome, int *info){		//Cria a imagem PGM
	
	int aux,i,j,branco = 255;
	int width=0,heigth=0;
	
	if(*info == 1){
		printf("A Imagem ainda esta sem Nome: ");
		scanf("%s",&nome);
	}
	
	for(i=0,aux=100;i!=3;i++){
		width = width + dimensoes[i]*aux;
		aux = aux/10;
	}
	
	for(i=3,aux=100;i!=6;i++){
		heigth = heigth + dimensoes[i]*aux;
		aux = aux/10;
	}
	
	strcat (nome, ".pgm");
	FILE *arquivo = fopen (nome,"w");
	
	fprintf(arquivo, "P2\n");
    fprintf(arquivo, "%d %d\n",width, heigth);
    fprintf(arquivo, "255\n");
	
	for(i=0;i!=width;i++){
		for(j=0;j!=heigth;j++){
			fprintf(arquivo,"255");
		}
		fprintf(arquivo,"\n");
	}
	
	fclose(arquivo);
	
	printf("width = %d\nheigth = %d\n",width,heigth);
	return;
}
