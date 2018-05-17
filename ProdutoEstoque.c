#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


void add();
void show();
void showSetor();
float totalProduto();
void menu();


struct produto {
	char nome[15];
	char setor[MAX];
	int quant;
	float preco;
} estoque[MAX];


int main(void){

	int c;

	while(c != 5){
		menu();
		scanf("%d", &c);

		if(c == 1){
			add();
		}
		else if(c == 2){
			show();
		}
		else if(c == 0){
			system("cls");
		}
		else if(c == 3){
			showSetor();
		}
		else if(c == 4){
			printf("\n\tTotal de Capital investido em Produtos: %.2f\n", totalProduto());
		}
	}
}

float totalProduto(){

	float soma;

	soma = estoque[0].preco;

	for(int i = 1; i < MAX; i++){

		if(!*estoque[i].nome){
			break;
		}
		soma += estoque[i].preco;
	}

	return soma;

}

void showSetor(){

	char nomeSetor[15];
	int flag = 0;

	printf("Qual setor vc deseja vizualizar?:");
	scanf("%s", nomeSetor);

	printf("\nNome do setor escolhido: %s \n", nomeSetor);

	for(int i = 0; i < MAX; i++){

		if(!*estoque[i].nome){
			if(flag == 0){
				printf("\nNao ha produtos ou o setor nao existe\n");
				printf(":/\n");
			}
			break;
		}
		if(strcmp(nomeSetor,estoque[i].setor) == 0){
			printf("\n\tNome do Produto: %s", estoque[i].nome);
			flag = 1;
		}
	}

	printf("\n");

}


void menu(){

	printf("\n\t0 - clear");
	printf("\n\t1 - add");
	printf("\n\t2 - show");
	printf("\n\t3 - show setor");
	printf("\n\t4 - show total capital");
	printf("\n\t5 - exit\n");

}

void add(){
	
	int n;

	printf("\nDigite a quantidade de dados que ira informar: ");
	scanf("%d", &n);

    for(int i = 0 ; i < n; i++){
        
		for(int j = 0; j < MAX; j++){

			if(!*estoque[j].nome){

				printf("\n\tNome do produto: ");
				scanf("%s", &estoque[j].nome);

				printf("\n\tNome do setor: ");
				scanf("%s", &estoque[j].setor);

				printf("\n\tQuantidade: ");
				scanf("%d", &estoque[j].quant);

				printf("\n\tValor do Produto: ");
				scanf("%f", &estoque[j].preco);
				
				break;
			}

		}
    
	}

}

void show(){

	for(int i = 0; i < MAX; i++){
		
		if(!*estoque[i].nome){
			break;
		}

		printf("\n%d Dado: \n", i+1);
		printf("\n\tNome do produto: %s", estoque[i].nome);
		printf("\n\tNome do setor: %s", estoque[i].setor);
		printf("\n\tQuantidade: %d", estoque[i].quant);
		printf("\n\tValor do Produto: %.2f\n", estoque[i].preco);

	}

}


