#include<stdio.h>

int Comandos(char *retorno);		//Le o comando digitado

int main(void){
	char cmd[30];
	int aux;
	
	aux = Comandos(cmd);
	switch(aux){
		
		case 1:
			
			break;
		
		
		case 2:
			
			break;
		
		
		case 3:
			
			break;
		
		
		case 4:
			
			break;
		
		
		case 5:
			
			break;
		
	}
	
	
	
}


int Comandos(char *retorno){
	
	char cmd[30];
	scanf("%s",cmd);
	
	if(cmd[0] == 'C' && cmd[1] == 'R' && cmd[2] == 'E' && cmd[3] == 'A' && cmd[4] == 'T' && cmd[5] == 'E'){		//CREATE
		return 0;
		
	}
	
	if(cmd[0] == 'E' && cmd[1] == 'X' && cmd[2] == 'P' && cmd[3] == 'O' && cmd[4] == 'R' && cmd[5] == 'T'){		//EXPORT
		return 1;
	}
	
	if(cmd[0] == 'L' && cmd[1] == 'I' && cmd[2] == 'N' && cmd[3] == 'E'){		//LINE
		return 2;
	}
	
	if(cmd[0] == 'C' && cmd[1] == 'I' && cmd[2] == 'R' && cmd[3] == 'C' && cmd[4] == 'L' && cmd[5] == 'E'){		//CIRCLE
		return 3;
	}
	
	if(cmd[0] == 'D' && cmd[1] == 'I' && cmd[2] == 'S' && cmd[3] == 'K'){		//DISK
		return 4;
	}
	
	if(cmd[0] == 'R' && cmd[1] == 'E' && cmd[2] == 'C' && cmd[3] == 'T'){		//RECT
		return 5;
	}
}
