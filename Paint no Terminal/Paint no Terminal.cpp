//	Programa realizado durante o treinamento do Zenith 
//	Hands-on Project 1 - Paint no Terminal
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>  
#include <math.h>

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
void Circle(int *dados, Imagem *pixels);				//Cria uma Circulo
void Disk(int *dados, Imagem *pixels);					//Cria um Disco
void Rect(int *dados, Imagem *pixels);					//Cria um Retangulo

int main(void){
	Imagem pixels;
	int cmdint[30];
	char cmdchar[30];
	int aux;
	
	while(1){
		aux = Comandos(cmdint,cmdchar);
		switch(aux){
			
			case 1:						//CREATE
				Create(cmdint,&pixels);
				break;
			
			
			case 2:						//EXPORT
				Export(cmdchar,&pixels);
				break;
			
			
			case 3:						//LINE
				Line(cmdint,&pixels);
				break;
			
			
			case 4:						//CIRCLE
				Circle(cmdint, &pixels);
				break;
			
			
			case 5:						//DISK
				Disk(cmdint, &pixels);
				break;
			
			case 6:						//RECT
				Rect(cmdint, &pixels);
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
		return 4;
	}
	
	if(cmd[0] == 'D' && cmd[1] == 'I' && cmd[2] == 'S' && cmd[3] == 'K'){		//DISK
		
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
		return 5;
	}
	
	if(cmd[0] == 'R' && cmd[1] == 'E' && cmd[2] == 'C' && cmd[3] == 'T'){		//RECT
		
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


//=========================================================================
//								LINE
//=========================================================================

void Line(int *dados, Imagem *pixels){
	
	float x1,x2,y1,y2;
	int color;
	float  m;				// Coeficiente da reta;
	float c;	    			// Termo independente
	int x,y; 
	
	x1 = dados[0];
	y1 = dados[1];
	x2 = dados[2];
	y2 = dados[3];	
	color = dados[4];
	
	printf("Desenhando a Linha...\n");
	
	if( (color>=0 && color<=255) && (x1>=0 && x1<=pixels->width) && (x2>=0 && x2<=pixels->width) && (y1>=0 && y1<=pixels->heigth) && (y2>=0 && y2<=pixels->heigth) && (x1 != x2)){
	
	m  = (y2-y1)/(x2-x1);
	c  = y1 - m*x1; 
	
	 /*
	for(i=0;i!=30;i++)
		printf("vet[%d] = %d\n",i,dados[i]);
	*/
	
//	printf("x1 = %f\ny1 = %f\nx2 = %f\ny2 = %f\ncolor = %d\n",x1,y1,x2,y2,color);
//	printf("coeficiente = %f\ntermo independente = %f\n",m,c);
	
	
	for(y=0;y!=pixels->heigth;y++){
		//y = m*x + c;
		x = (y-c)/m;
		if(x>=0 && x<=pixels->width){
			pixels->imagem[y][x] = color;
			}
	}
	
	return;	
	}else 
		printf("ERRO!\n");
		return;
	
	
}


//=========================================================================
//								CIRCLE
//=========================================================================
void Circle(int *dados, Imagem *pixels){
	
	float x1,y1,radius;
	int color;
	
	int x,y;
	float r2,x2,y2,aux;
	
	x1 = dados[0];
	y1 = dados[1];
	radius = dados[2];	
	color = dados[3];
	
	/*
	for(i=0;i!=30;i++)
		printf("vet[%d] = %d\n",i,dados[i]);
	*/
	
	printf("Desenhando o Circulo...\n");
	
	
	if( (color>=0 && color<=255) && (x1>=0 && x1<=pixels->width) && (y1>=0 && y1<=pixels->heigth) ){
		
		for(x=x1-radius;x<=x1+radius;x++){
			
			x2=  pow(x-x1,2);
			r2 = radius*radius;
			y2 = y1*y1;
	
			aux = sqrt(r2-x2);
			y= y1 + aux;
			
			if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;
			}
			
			aux = sqrt(r2-x2);
			y = y1 - aux;
			if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;		
			}
		
		}
	return;
	}else 
		printf("ERRO!\n");
		return;	
}

//=========================================================================
//								DISK
//=========================================================================
void Disk(int *dados, Imagem *pixels){
		
	float x1,y1,radius;
	int color;
	
	int x,y,x_cont,ysec,y_cont;
	float r2,x2,y2,aux;
	
	x1 = dados[0];
	y1 = dados[1];
	radius = dados[2];	
	color = dados[3];
	
	printf("Desenhando o Disco...\n");
	
	if( (color>=0 && color<=255) && (x1>=0 && x1<=pixels->width) && (y1>=0 && y1<=pixels->heigth) ){
		for(x=x1-radius;x<=x1+radius;x++){
			
			x2=  pow(x-x1,2);
			r2 = radius*radius;
			y2 = y1*y1;
	
			
			if(x<x1){
			
				aux = sqrt(r2-x2);
				y= y1 + aux;
				
				for(x_cont=x;x_cont<=x1;x_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[y][x_cont] = color;
					}
				
				aux = sqrt(r2-x2);
				ysec = y1 - aux;
				
				for(x_cont=x;x_cont<=x1;x_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[ysec][x_cont] = color;
					}	
				
			
				for(y_cont=ysec;y_cont<=y;y_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[y_cont][x] = color;
					}
			}
			
			if(x>=x1){
				aux = sqrt(r2-x2);
				y= y1 + aux;
	
				for(x_cont=x1;x_cont<=x;x_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[y][x_cont] = color;
					}
				
				aux = sqrt(r2-x2);
				ysec = y1 - aux;
				
				for(x_cont=x1;x_cont<=x;x_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[ysec][x_cont] = color;
					}
			
				for(y_cont=ysec;y_cont<=y;y_cont++)
					if(x_cont>=0 && x_cont<=pixels->width && y>=0 && y<=pixels->heigth){
						pixels->imagem[y_cont][x] = color;
					}	
			}
		}
	return;
	}else 
		printf("ERRO!\n");
		return;		
}



//=========================================================================
//								RECT
//=========================================================================

void Rect(int *dados, Imagem *pixels){
	
	int x1,y1,width,heigth,color;
	int aux,aux2;
	int x,y;
	
	x1 = dados[0];
	y1 = dados[1];
	width = dados[2];	
	heigth = dados[3];
	color = dados[4];
	
	printf("Desenhando o Retangulo...\n");
	
	if( (color>=0 && color<=255) && (x1>=0 && x1<=pixels->width) && (y1>=0 && y1<=pixels->heigth) ){
	aux = heigth/2;
	aux2 = width/2;
	
	y = y1-aux;
	x = x1-aux2;
	for(;x!=x1+aux;x++)
		if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;		
		}
	
	y = y1+aux;
	x = x1-aux2;	
	for(;x!=x1+aux;x++)
		if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;		
		}
	
	y = y1-aux;
	x = x1-aux2;
	for(;y!=y1+aux;y++)
		if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;		
		}
	
	y = y1-aux;
	x = x1+aux2;
	for(;y!=y1+aux;y++)
		if(x>=0 && x<=pixels->width && y>=0 && y<=pixels->heigth){
				pixels->imagem[y][x] = color;		
		}
	return;
	}else 
		printf("ERRO!\n");
		return;
}

