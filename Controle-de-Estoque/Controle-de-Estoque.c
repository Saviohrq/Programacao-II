#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
	char descricao[100];
	float preco;
	int quantidade;
}Produto;

typedef struct {
	Produto produtos[100];
	int qtd; //Quantidade de produtos cadastrados
}Estoque;

void cadastrar(Estoque *estoque);
void listar(Estoque *estoque);
void excluir(Estoque *estoque);
char menu();

void main(){
    Estoque estoque;
    estoque.qtd = 0;

    while(1){
        fflush(stdin);
        char op = menu();
        if(op == '0'){
            break;
        }
        switch(op){
            case '1':
                cadastrar(&estoque);
                system("pause");
                break;
            case '2':
                listar(&estoque);
                system("pause");
                break;
            case '3':
                excluir(&estoque);
                system("pause");
                break;
            default:
                printf("\nOpcao Invalida\n");
                system("pause");
        }
    }//fim WHILE

}// Fim do MAIN

char menu(){
    system("cls");
    char op;
    printf("======= CONTROLE DE ESTOQUE =======\n\n");
    printf("1 - CADASTRAR\n");
    printf("2 - LISTAR\n");
    printf("3 - EXCLUIR\n");
    printf("0 - SAIR\n");
    printf(">>> ");
    scanf("%c", &op);
    return op;

}//fim MENU

void cadastrar(Estoque *estoque){
	system("cls");
	fflush(stdin);
	char descricao[100];
	float preco;
	int qtd;

	printf("======= CADASTRAR =======\n\n");
	printf("DESCRICAO: ");
	gets(descricao);
	printf("PRECO: R$ ");
	scanf("%f",&preco);
	printf("QUANTIDADE: ");
	scanf("%d",&qtd);

	int codigo;
	if(estoque->qtd == 0){
		codigo = 1;
	}else{
		codigo = estoque->produtos[estoque->qtd-1].codigo + 1;
	}

	estoque->produtos[estoque->qtd].preco = preco;
	estoque->produtos[estoque->qtd].quantidade = qtd;
	strcpy(estoque->produtos[estoque->qtd].descricao, descricao);
	estoque->produtos[estoque->qtd].codigo = codigo;
	estoque->qtd++;

	printf("\nProduto cadastrado com sucesso\n");

}//fim cadastrar

void listar(Estoque *estoque){
    system("cls");
    printf("======= LISTA DE PRODUTOS =======");
    int i;
    for(i=0; i<estoque->qtd;i++){
        printf("\nCODIGO: %d", estoque->produtos[i].codigo);
        printf("\nDESCRICAO: ");
        puts(estoque->produtos[i].descricao);
        printf("PRECO: R$ %.2f", estoque->produtos[i].preco);
        printf("\nQUANTIDADE: %d", estoque->produtos[i].quantidade);
        printf("\n--------------------------\n");
    }
}//fim listar

void excluir(Estoque *estoque){
    system("cls");
    printf("======= EXCLUIR =======");
    listar(estoque);
    int c;
    printf("Qual produto deseja excluir?: ");
    scanf("%d", &c);
    int ctz = 0;
    printf("Certeza que deseja exlcuir o produto %d (1 - SIM; 2 - NAO):", c);
    scanf("%d", &ctz);
    if(ctz == 1){
        int i, j, encontrado = 0;
        for(i = 0; i < estoque->qtd; i++){
            if(estoque->produtos[i].codigo == c){
                for(j = i; j < estoque->qtd - 1; j++){
                    estoque->produtos[j] = estoque->produtos[j + 1];
                }
                estoque->qtd--;
                encontrado = 1;
                break;
            }
        }
        if(encontrado == 0){
            printf("\nProduto não encontrado!");
        }else{
            printf("\nProduto exlcuido com sucesso!");
        }
        printf("\n");

    }//fim IF certeza
}//fim EXCLUIR
