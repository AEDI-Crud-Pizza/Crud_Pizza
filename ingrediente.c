#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingrediente.h"

#define MAX_INGREDIENTES 100

Ingrediente ingredientes[MAX_INGREDIENTES];
int total_ingredientes = 0;

void carregarIngredientes() {
    FILE *arquivo = fopen("ingrediente.txt", "r");
    if (arquivo == NULL) {
        return;
    }
    total_ingredientes = 0;
    while (fscanf(arquivo, "%d;%[^;];%f\n", &ingredientes[total_ingredientes].id, ingredientes[total_ingredientes].nome, &ingredientes[total_ingredientes].preco) == 3) {
        total_ingredientes++;
    }
    fclose(arquivo);
}

void salvarIngredientes() {
    FILE *arquivo = fopen("ingrediente.txt", "w");
    if (arquivo == NULL) {
        return;
    }
    for (int i = 0; i < total_ingredientes; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
    fclose(arquivo);
}

void listarIngredientes() {
    if (total_ingredientes == 0) {
        printf("Nenhum ingrediente cadastrado\n");
        return;
    }
    for (int i = 0; i < total_ingredientes; i++) {
        printf("ID: %d Nome: %s Preco: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void adicionarIngrediente() {
    if (total_ingredientes >= MAX_INGREDIENTES) {
        printf("Limite de ingredientes atingido\n");
        return;
    }
    Ingrediente novo;
    novo.id = total_ingredientes + 1;
    printf("Digite o nome do ingrediente: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &novo.preco);
    ingredientes[total_ingredientes] = novo;
    total_ingredientes++;
    salvarIngredientes();
    printf("Ingrediente adicionado com sucesso\n");
}

void editarIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);
    for (int i = 0; i < total_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            printf("Digite o novo nome do ingrediente: ");
            scanf(" %[^\n]", ingredientes[i].nome);
            printf("Digite o novo preco do ingrediente: ");
            scanf("%f", &ingredientes[i].preco);
            salvarIngredientes();
            printf("Ingrediente editado com sucesso\n");
            return;
        }
    }
    printf("Ingrediente nao encontrado\n");
}

void removerIngrediente() {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < total_ingredientes; i++) {
        if (ingredientes[i].id == id) {
            for (int j = i; j < total_ingredientes - 1; j++) {
                ingredientes[j] = ingredientes[j + 1];
            }
            total_ingredientes--;
            salvarIngredientes();
            printf("Ingrediente removido com sucesso\n");
            return;
        }
    }
    printf("Ingrediente nao encontrado\n");
}
