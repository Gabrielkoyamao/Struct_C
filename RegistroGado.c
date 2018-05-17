#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void print();
void add();
void menu();
int totalLeite();
int totalLeiteAbate();
int totalAlimentoAbate();
int totalAlimento();
int totalAbate();

struct Data {
    int mes;
    int ano;
};

struct Dados {
    int codigo;
    int leite;
    int alim;
    struct Data nasc; 
    char abate[1];
} a[MAX];


int main(){

    int s;
    while(s != 8){
        menu();
        scanf("%d", &s);
        
        if(s == 1){
            add();
        }

        if(s == 2){
            print();
        }

        if(s == 3){
			printf("Total de Leite: %d", totalLeite());
        }

        if(s == 4){
            printf("Total de Alimento: %d", totalAlimento());
        }

        if(s == 5){
            printf("Total de Leite apos o Abate: %d", totalLeiteAbate());
        }

        if(s == 6){
            printf("Total de Alimento apos o Abate: %d", totalAlimentoAbate());
        }

        if(s == 7){
            printf("Total de Abates: %d", totalAbate());
        }

		if(s == 0){
			system("cls");
		}
    }
}

void print(){


    for(int i = 0; i<MAX; i++){

        if(a[i].codigo == 0){
            break;
        }
  
        printf("\n%d Dado: \n", i+1);

        printf("\n\tCodigo da Cabeca de Gado: ");       
        printf("%d", a[i].codigo);

        printf("\n\tLeite(numero de litros por semana): ");
        printf("%d", a[i].leite);
        
        printf("\n\tQuantidade de Alimento ingerido por semana: ");
        printf("%d", a[i].alim);
        
        printf("\n\tData de Nascimento(mes e ano): ");
        printf("(mes/ano): %d/%d", a[i].nasc.mes, a[i].nasc.ano);
        
        printf("\n\tAbate(s/n): ");
        printf("%s\n", a[i].abate);
    }
}

void add(){

    int n = 0;
    
	printf("\nDigite a quantidade de dados que ira informar\n");
    scanf("%d", &n);

    for(int i = 0 ; i < n; i++){

        for(int j = 0; j < MAX; j++){

            if(a[j].codigo == 0){
                printf("\n\tCodigo da Cabeca de Gado\n");
                scanf("%d", &a[j].codigo);

                printf("\n\tLeite(numero de litros por semana(Litros))\n");
                scanf("%d", &a[j].leite);
                
                printf("\n\tQuantidade de Alimento ingerido por semana(Kg)\n");
                scanf("%d", &a[j].alim);
                
                printf("\n\tData de Nascimento(mes e ano)\n");
                scanf("%d", &a[j].nasc.mes);
                scanf("%d", &a[j].nasc.ano);

                // 	tenha mais de 5 anos
                if( 2018 - a[j].nasc.ano <= 5){
                    strcpy(a[j].abate, "S");
                }
                // produza menos de 40 litros por semana
                else if( a[j].leite < 40){
                    strcpy(a[j].abate, "S");            
                }
                // produza entre 50 e 70 litros de leito por semana
                else if( 50 < a[j].leite < 70 ){
                    strcpy(a[j].abate, "S");
                }
                // ingerir mais de 50quilos de alimento
                else if(a[j].alim > 50){
                    strcpy(a[j].abate, "S");
                }
                else{
                    printf("\n\tAbate(s/n)\n");
                    scanf("%s", &a[j].abate);
                }

                break;
            }
        }
    }
}

void menu(){

    printf("\n\t0 - Limpar a tela\n");
    printf("\t1 - Adicionar\n");
    printf("\t2 - Mostrar Todos os Dados\n");
    printf("\t3 - Total de Leite Produzida p/ Semana\n");
    printf("\t4 - Total de Alimento produzido p/ Semana\n");
    printf("\t5 - Total de Leite produzido apos o abate\n");
    printf("\t6 - Total de Alimento produzido apos o abate\n");
    printf("\t7 - Total Numero de cabeca de gado q iram para o abate\n");
    printf("\t8 - Sair\n");
}

int totalLeite(){
    int soma = a[0].leite;
    for(int i = 1; i < MAX; i++){
        if(a[i].codigo == 0){
            break;
        }
        soma += a[i].leite;
    }
    return soma;
}

int totalLeiteAbate(){
    int soma = a[0].leite;
    for(int i = 1; i < MAX; i++){
        if(a[i].codigo == 0){
            break;
        }
        if(strcmp(a[i].abate, "S") == 0){
            soma += a[i].leite;
        }
    }
    return soma;
}

int totalAlimentoAbate(){
    int soma = a[0].alim;
    for(int i = 1; i < MAX; i++){
        if(a[i].codigo == 0){
            break;
        }
        if( strcmp(a[i].abate, "S") == 0 ){
            soma += a[i].alim;
        }
    }
    return soma;
}

int totalAlimento(){
    int soma = a[0].alim;
    for(int i = 1; i < MAX; i++){
        if(a[i].codigo == 0){
            break;
        }
        soma += a[i].alim;
    }
    return soma;
}

int totalAbate(){
    int cont = 0;
    for(int i = 0; i < MAX; i++){
        if(a[i].codigo == 0){
            break;
        }
        if ( strcmp(a[i].abate,"S") == 0 ){
            cont++;            
        }
    }
    return cont;
}