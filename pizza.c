#include "pizza.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPizza(Pizza* pizzas, int* numPizzas) {
    Pizza novaPizza;
    printf("Digite o nome da pizza: ");
    scanf("%s", novaPizza.nome);
    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza.preco);
    novaPizza.id = *numPizzas + 1; //Adiciona um ID automaticamente a medida que as pizzas são criadas
    novaPizza.nIngredientes = 0;
    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;  //Incrementa o número de pizzas na pizarria
}

void listarPizzas(Pizza* pizzas, int numPizzas) {
    for (int i = 0; i < numPizzas; i++) {
        printf("ID: %d | Nome: %s | Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
    }
}

void editarPizza(Pizza* pizzas, int numPizzas) {
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);
    for (int i = 0; i < numPizzas; i++) {
        if (pizzas[i].id == id) {
            printf("Digite o novo nome: ");
            scanf("%s", pizzas[i].nome);
            printf("Digite o novo preco: ");
            scanf("%f", &pizzas[i].preco);
            return;
        }
    }
    printf("Pizza nao encontrada!\n");
}

void removerPizza(Pizza* pizzas, int* numPizzas) {
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < *numPizzas; i++) {
        if (pizzas[i].id == id) {
            for (int j = i; j < *numPizzas - 1; j++) {
                pizzas[j] = pizzas[j + 1];
            }
            (*numPizzas)--;
            return;
        }
    }
    printf("Pizza nao encontrada!\n");
}

void venderPizza(Pizza *pizzas, int qtdPizzas, Ingrediente *ingredientes, int qtdIngredientes) {
    int idPizza, idIngrediente, adicionar;
    float precoFinal = 0;

    listarPizzas(pizzas, qtdPizzas);
    printf("Digite o ID da pizza que deseja vender: ");
    scanf("%d", &idPizza);
    for (int i = 0; i < qtdPizzas; i++) {
        if (pizzas[i].id == idPizza) {
            precoFinal = pizzas[i].preco;
            listarIngredientes(ingredientes, qtdIngredientes);
            printf("Deseja adicionar ingredientes extras? (1 - Sim, 0 - Nao): ");
            scanf("%d", &adicionar);
            while (adicionar) {
                printf("Digite o ID do ingrediente para adicionar: ");
                scanf("%d", &idIngrediente);
                for (int j = 0; j < qtdIngredientes; j++) {
                    if (ingredientes[j].id == idIngrediente) {
                        precoFinal += ingredientes[j].preco;
                        break;
                    }
                }
                printf("Deseja adicionar mais ingredientes? (1 - Sim, 0 - Nao): ");
                scanf("%d", &adicionar);
            }
            printf("Venda realizada! Preco final: %.2f\n", precoFinal);
            return;
        }
    }
    printf("Pizza nao encontrada!\n");
}