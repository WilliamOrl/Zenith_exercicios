//	Programa realizado durante o treinamento do Zenith 
//	Hands-on Project 1 - Paint no Terminal
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  


typedef struct{						//Elementos nescessarios para a criação de uma imagem tipo PGM
	char magic_number[3];
	int heigth;
	int width;
	int color;
	int **imagem;
}Imagem;


int Comandos(int *retorno,char *nome);					//Le os comandos digitados
void Create(int *dimensoes,Imagem *pixels);				//Cria a imagem PGM
void Export(char *nome, Imagem *pixels);				//Salva a imagem
void Line(int *dados, Imagem *pixels);					//Cria uma linha

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
			Line(cmdint,&pixels);
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

//=========================================================================
//								COMANDOS
//=========================================================================


int Comandos(int *retorno,char *nome){  //Seleciona o comando
	
	int i,j,aux=0;
	char cmd[30];
	int caracter;
	
	for(i=0;i!=30;i++){
		cmd[i] = ' ';
		retorno[i] = 0;  
	}
		
	printf("Digite o Comando: ");
	scanf("%[^\n]s",&cmd);
	setbuf(stdin, NULL);

		

	if(cmd[0] == 'C' && cmd[1] == 'R' && cmd[2] == 'E' && cmd[3] == 'A' && cmd[4] == 'T' && cmd[5] == 'E'){		//CREATE
		
		for(i=7,j=0;i!=30;i++){
			if(cmd[i]>=48 && cmd[i]<=57 || cmd[i] == ' ' ){					//48 e 57 são os estremos de 0 a 9 na tabala ASCII
				if(cmd[i] == ' '){
					j++;
				}
				else{
					aux = cmd[i] - 48;
					retorno[j] = retorno[j]*10;	
					retorno[j] = retorno[j] + aux;
				}
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
		
		for(i=5,j=0;i!=30;i++){
			if(cmd[i]>=48 && cmd[i]<=57 || cmd[i] == ' ' ){					//48 e 57 são os estremos de 0 a 9 na tabala ASCII
				if(cmd[i] == ' '){
					j++;
				}
				else{
					aux = cmd[i] - 48;
					retorno[j] = retorno[j]*10;	
					retorno[j] = retorno[j] + aux;
				}
			}
		}
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


//=========================================================================
//								CREATE
//=========================================================================

void Create(int *dimensoes,Imagem *pixels){		//Cria a imagem PGM
	
	int i,j,aux;
	int width=0,heigth=0;
	
	printf("Criando Imagem...\n");
	
	width = dimensoes[0];
	heigth = dimensoes[1];
		
	if(heigth>width || heigth == 0 || width == 0 || heigth > 2000 || width > 2000 ){
		printf("ERRO!\n");
		return;
	}
	
	
	pixels->magic_number[0] = 'P';
	pixels->magic_number[1] = '2';
	pixels->magic_number[2] = '\0';
	
	pixels->color = 255;

	pixels->width = width;
	pixels->heigth = heigth;

	pixels->imagem = (int **) calloc (width, sizeof(int *));
        for (int i = 0; i < heigth; i++){
            pixels->imagem[i] = (int *) calloc (width, sizeof(int));
        }
	
	return;
}


//=========================================================================
//								EXPORT
//=========================================================================

void Export(char *nome, Imagem *pixels){

	int i,j;
	
	if(pixels->heigth == 0 || pixels->width == 0){
		printf("ERRO!\n");
		return;
	}
	
	printf("Salvando Imagem...\n");
	strcat (nome, ".pgm");
	
	FILE *arquivo = fopen (nome,"w");

	fprintf(arquivo,"%s\n",pixels->magic_number);
    fprintf(arquivo, "%d %d\n",pixels->width,pixels->heigth);
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

void Line(int *dados, Imagem *pixels){
	
	int x1,x2,y1,y2,color;
	int m;			// Coeficiente da reta;
	int c;			// Termo independente
	int i;
	
	x1 = dados[0];
	y1 = dados[1];
	x2 = dados[2];
	y2 = dados[3];	
	color = dados[4];
	
	m = (y2-y1)/(x2-x1);
	c = y1 - m*x1; 
	 /*
	for(i=0;i!=30;i++)
		printf("vet[%d] = %d\n",i,dados[i]);
	*/
	printf("x1 = %d\ny1 = %d\nx2 = %d\ny2 = %d\ncolor = %d\n",x1,y1,x2,y2,color);
	
	printf("coeficiente = %d\ntermo independente = %d\n",m,c);
	return;
}
