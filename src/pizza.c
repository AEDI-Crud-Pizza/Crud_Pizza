#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pizza.h"


void adicionarPizza(Pizza* pizzas, int* numPizzas) {
    Pizza novaPizza;
    printf("Digite o nome da pizza: ");
    scanf("%s", &novaPizza.nome);
    printf("Digite o tamanho (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho);
    printf("Digite o preço base: ");
    scanf("%f", &novaPizza.preco);
    novaPizza.id = *numPizzas + 1;  // ID baseado no número de pizzas
    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;

    FILE* arquivo = fopen("cardapio.txt", "a");

    fprintf(arquivo,"%s %c %.2f\n",novaPizza.nome, novaPizza.tamanho, novaPizza.preco);

    fclose(arquivo);
}

void listarPizzas(Pizza* pizzas, int numPizzas) {

    printf("Lista de Pizzas Cadastradas:\n");

    FILE* arquivo = fopen("cardapio.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    while(fscanf(arquivo,"%s %c %.2f\n",pizzas[numPizzas].nome, &pizzas[numPizzas].tamanho, &pizzas[numPizzas].preco) != EOF){
        numPizzas++;
        printf("ID: %d |Nome: %s | Tamanho: %c | Preço: %.2f\n",pizzas[numPizzas].id,pizzas[numPizzas].nome, pizzas[numPizzas].tamanho, pizzas[numPizzas].preco);
    }

    fclose(arquivo);
}

void editarPizza(Pizza* pizzas, int numPizzas) {
    int id;
    FILE* arquivo = fopen("cardapio.txt", "r+");
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);
    while (fscanf(arquivo,"%s %c %.2f\n",pizzas[numPizzas].nome, &pizzas[numPizzas].tamanho, &pizzas[numPizzas].preco) != EOF) {

        if (pizzas[numPizzas].id == id) {
            printf("Digite o novo nome da pizza: ");
            scanf("%s", &pizzas[numPizzas].nome);
            printf("Digite o novo tamanho (P, M, G): ");
            scanf(" %c", &pizzas[numPizzas].tamanho);
            printf("Digite o novo preço base: ");
            scanf("%f", &pizzas[numPizzas].preco);
            fseek(arquivo, -1, SEEK_CUR);
            fprintf(arquivo,"%s %c %.2f\n",pizzas[numPizzas].nome, pizzas[numPizzas].tamanho, pizzas[numPizzas].preco);
            fclose(arquivo);
            printf("Pizza editada com sucesso!\n");
            return;
        }

    }
    fclose(arquivo);
    printf("Pizza não encontrada!\n");
}

void removerPizza(Pizza* pizzas, int* numPizzas) {
    int id;
    FILE arquivo = fopen("cardapio.txt","r+");
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);
    while(fscanf(arquivo,"%s %c %.2f\n",pizzas[*numPizzas].nome, &pizzas[*numPizzas].tamanho, &pizzas[*numPizzas].preco) != EOF) {
        if (pizzas[*numPizzas].id == id) {
            fseek(arquivo, -1, SEEK_CUR);
            fprintf(arquivo,"%s %c %.2f\n",pizzas[*numPizzas].nome, pizzas[*numPizzas].tamanho, pizzas[*numPizzas].preco);
            fclose(arquivo);
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }
    printf("Pizza não encontrada!\n");
}

void venderPizza(int numPizzas, char* tamanho, char ingredientes[][20], int numIngredientes) {
    float precoP= 39.90;
    float precoM= 59.90;
    float precoG= 79.90;

printf("Digite a quantidade de pizzas que quer comprar: ");
scanf("%d", &numPizzas);

printf("Digite o tamanho da pizza: ");
scanf("%s", &tamanho);

printf("Digite a quantidade de ingredientes a adicionar: ");
scanf("%d", &numIngredientes);

printf("Digite os ingredientes que quer adicionar: ");


}

void visualizarIngrediente(Ingrediente* ingredientes, int numIngredientes) {
    printf("Lista de Ingredientes Cadastrados:\n");
    
    for (int i = 0; i < numIngredientes; i++) {
        printf("ID: %d\n", ingredientes[i].id);
        printf("Nome: %s\n", ingredientes[i].nome);
        printf("Preço: R$ %.2f\n", ingredientes[i].preco);
        printf("\n");
    }
}