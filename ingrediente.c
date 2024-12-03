#include "ingrediente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes) {
    Ingrediente novoIngrediente;
    printf("Digite o nome do ingrediente: ");
    scanf("%s", novoIngrediente.nome);
    printf("Digite o preço do ingrediente: ");
    scanf("%f", &novoIngrediente.preco);
    novoIngrediente.id = *numIngredientes + 1;  // ID baseado no número de ingredientes
    ingredientes[*numIngredientes] = novoIngrediente;
    (*numIngredientes)++;
}

void listarIngredientes(Ingrediente* ingredientes, int numIngredientes) {
    for (int i = 0; i < numIngredientes; i++) {
        printf("ID: %d | Nome: %s | Preço: %.2f\n", ingredientes[i].id, ingredientes[i].nome, ingredientes[i].preco);
    }
}

void editarIngrediente(Ingrediente* ingredientes, int numIngredientes) {
    int id;
    printf("Digite o ID do ingrediente que deseja editar: ");
    scanf("%d", &id);
    for (int i = 0; i < numIngredientes; i++) {
        if (ingredientes[i].id == id) {
            printf("Digite o novo nome: ");
            scanf("%s", ingredientes[i].nome);
            printf("Digite o novo preço: ");
            scanf("%f", &ingredientes[i].preco);
            return;
        }
    }
    printf("Ingrediente não encontrado!\n");
}

void removerIngrediente(Ingrediente* ingredientes, int* numIngredientes) {
    int id;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < *numIngredientes; i++) {
        if (ingredientes[i].id == id) {
            // Desloca os ingredientes para "remover" o ingrediente
            for (int j = i; j < *numIngredientes - 1; j++) {
                ingredientes[j] = ingredientes[j + 1];
            }
            (*numIngredientes)--;
            printf("Ingrediente removido com sucesso!\n");
            return;
        }
    }
    printf("Ingrediente não encontrado!\n");
}