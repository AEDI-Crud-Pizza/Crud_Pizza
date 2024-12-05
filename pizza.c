#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pizza.h"

#define MAX_PIZZAS 100

Pizza pizzas[MAX_PIZZAS];
int total_pizzas = 0;

void carregarPizzas() {
    FILE *arquivo = fopen("cardapio.txt", "r");
    if (arquivo == NULL) {
        return;
    }
    total_pizzas = 0;
    while (fscanf(arquivo, "%d;%[^;];%f\n", &pizzas[total_pizzas].id, pizzas[total_pizzas].nome, &pizzas[total_pizzas].preco) == 3) {
        total_pizzas++;
    }
    fclose(arquivo);
}

void salvarPizzas() {
    FILE *arquivo = fopen("cardapio.txt", "w");
    if (arquivo == NULL) {
        return;
    }
    for (int i = 0; i < total_pizzas; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
    }
    fclose(arquivo);
}

void listarPizzas() {
    if (total_pizzas == 0) {
        printf("Nenhuma pizza cadastrada\n");
        return;
    }
    for (int i = 0; i < total_pizzas; i++) {
        printf("ID: %d Nome: %s Preco: %.2f\n", pizzas[i].id, pizzas[i].nome, pizzas[i].preco);
    }
}

void adicionarPizza() {
    if (total_pizzas >= MAX_PIZZAS) {
        printf("Limite de pizzas atingido\n");
        return;
    }
    Pizza nova;
    nova.id = total_pizzas + 1;
    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", nova.nome);
    printf("Digite o preco da pizza: ");
    scanf("%f", &nova.preco);
    pizzas[total_pizzas] = nova;
    total_pizzas++;
    salvarPizzas();
    printf("Pizza adicionada com sucesso\n");
}

void editarPizza() {
    int id;
    printf("Digite o ID da pizza que deseja editar: ");
    scanf("%d", &id);
    for (int i = 0; i < total_pizzas; i++) {
        if (pizzas[i].id == id) {
            printf("Digite o novo nome da pizza: ");
            scanf(" %[^\n]", pizzas[i].nome);
            printf("Digite o novo preco da pizza: ");
            scanf("%f", &pizzas[i].preco);
            salvarPizzas();
            printf("Pizza editada com sucesso\n");
            return;
        }
    }
    printf("Pizza nao encontrada\n");
}

void removerPizza() {
    int id;
    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < total_pizzas; i++) {
        if (pizzas[i].id == id) {
            for (int j = i; j < total_pizzas - 1; j++) {
                pizzas[j] = pizzas[j + 1];
            }
            total_pizzas--;
            salvarPizzas();
            printf("Pizza removida com sucesso\n");
            return;
        }
    }
    printf("Pizza nao encontrada\n");
}

void venderPizza() {
    int id;
    printf("Digite o ID da pizza que deseja vender: ");
    scanf("%d", &id);
    for (int i = 0; i < total_pizzas; i++) {
        if (pizzas[i].id == id) {
            printf("Pizza vendida: %s Preco: %.2f\n", pizzas[i].nome, pizzas[i].preco);
            return;
        }
    }
    printf("Pizza nao encontrada\n");
}
