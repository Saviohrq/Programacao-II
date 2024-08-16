#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10

char descricao[N][100];
float preco[N];
int qtd[N];
int id[N];
int cont = 0;

void cadastrar();
void listar();

void main(){
	int menu;
	do{
		system("cls");
		
		printf("==== ESTOQUE FELIZ ====\n");
		printf("\n1 - Cadastrar\n");
		printf("2 - Listar\n");
		printf("0 - Sair\n");
		printf(">>> ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				cadastrar();
				break;
			case 2:
				listar();
				break;
			default:
				break;
				
		}
		
	}while(menu != 0);
}

void cadastrar(){
	fflush(stdin); // resolver bug de buffer do teclado na linguagem c
	printf("---- CADASTRO DE PRODUTOS ----\n");
	if(cont < N){
		char d[100];
		float p;
		int q;
		printf("\nDESCRICAO: ");
		gets(d);
		printf("PRECO: ");
		scanf("%f", &p);
		printf("QUANTIDADE: ");
		scanf("%d", &q);
		
		preco[cont] = p;
		qtd[cont] = q;
		strcpy(descricao[cont], d);
		id[cont] = cont + 1;
		cont++;
		printf("\nCadastrado com sucesso.\n");
		
	}else{
		printf("Memoria cheia");
	}
	system("pause");
	
}// fim cadastrar

void listar(){
	system("cls");
	int i;
	printf("---- LISTAGEM DE PRODUTOS ----\n");
	for(i=0;i<cont;i++){
		printf("ID: %d\n", id[i]);
		printf("DESCRICAO: %s\n", descricao[i]);
		printf("PRECO: R$%.2f\n", preco[i]);
		printf("QUANTIDADE: %d\n", qtd[i]);
		printf("------------------------------------\n");
	}
	system("pause");
}// fim listar