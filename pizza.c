#include "pizza.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarPizza(Pizza* pizzas, int* numPizzas) {
    Pizza novaPizza;
    printf("Digite o ID da pizza: ");
    scanf("%d", &novaPizza.id);
    printf("Digite o nome da pizza: ");
    scanf("%s", novaPizza.nome);
    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza.preco);
    novaPizza.id = *numPizzas + 1;
    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
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
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }
    printf("Pizza nao encontrada!\n");
}
