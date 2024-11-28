#include <stdio.h>
#include "pizza.h"


void adicionarPizza(Pizza* pizzas, int* numPizzas) {
    Pizza novaPizza;
    printf("Digite o nome da pizza: ");
    scanf("%s", novaPizza.nome);
    printf("Digite o tamanho (P, M, G): ");
    scanf(" %c", &novaPizza.tamanho);
    printf("Digite o preço base: ");
    scanf("%f", &novaPizza.preco);
    novaPizza.id = *numPizzas + 1;  // ID baseado no número de pizzas
    pizzas[*numPizzas] = novaPizza;
    (*numPizzas)++;
}

void listarPizzas(Pizza* pizzas, int numPizzas) {
    for (int i = 0; i < numPizzas; i++) {
        printf("ID: %d | Nome: %s | Tamanho: %c | Preço: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].tamanho, pizzas[i].preco);
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
            printf("Digite o novo tamanho (P, M, G): ");
            scanf(" %c", &pizzas[i].tamanho);
            printf("Digite o novo preço: ");
            scanf("%f", &pizzas[i].preco);
            return;
        }
    }
    printf("Pizza não encontrada!\n");
}

void removerPizza(Pizza* pizzas, int* numPizzas) {
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < *numPizzas; i++) {
        if (pizzas[i].id == id) {
            // Desloca as pizzas para "remover" a pizza
            for (int j = i; j < *numPizzas - 1; j++) {
                pizzas[j] = pizzas[j + 1];
            }
            (*numPizzas)--;
            printf("Pizza removida com sucesso!\n");
            return;
        }
    }
    printf("Pizza não encontrada!\n");
}
