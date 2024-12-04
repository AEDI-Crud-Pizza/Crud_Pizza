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
    novaPizza.id = *numPizzas + 1;
    novaPizza.nIngredientes = 0;
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
            return;
        }
    }
    printf("Pizza nao encontrada!\n");
}

void venderPizza(Pizza* pizzas, int qtdPizzas, Ingrediente* ingredientes, int qtdIngredientes) {
    int idPizza, idIngrediente;
    float precoFinal;
    int adicionarIngredientes;
    Pizza pizzaEscolhida;
    int i, j;

    printf("Escolha a pizza do cardápio:\n");
    listarPizzas(pizzas, qtdPizzas);
    printf("Digite o ID da pizza: ");
    scanf("%d", &idPizza);

    for (i = 0; i < qtdPizzas; i++) {
        if (pizzas[i].id == idPizza) {
            pizzaEscolhida = pizzas[i];
            precoFinal = pizzaEscolhida.preco;
            break;
        }
    }

    if (i == qtdPizzas) {
        printf("Pizza nao encontrada!\n");
        return;
    }

    printf("Você escolheu a pizza: %s\n", pizzaEscolhida.nome);

    printf("Ingredientes padrao da pizza:\n");
    for (i = 0; i < pizzaEscolhida.nIngredientes; i++) {
        printf("%s\n", pizzaEscolhida.ingredientes[i].nome);
    }

    printf("Deseja adicionar ingredientes extras? (1 - Sim, 0 - Nao): ");
    scanf("%d", &adicionarIngredientes);

    while (adicionarIngredientes) {
        printf("Escolha um ingrediente adicional:\n");
        listarIngredientes(ingredientes, qtdIngredientes);
        printf("Digite o ID do ingrediente: ");
        scanf("%d", &idIngrediente);

        for (j = 0; j < qtdIngredientes; j++) {
            if (ingredientes[j].id == idIngrediente) {
                precoFinal += ingredientes[j].preco;
                printf("Ingrediente adicionado: %s\n", ingredientes[j].nome);
                break;
            }
        }

        if (j == qtdIngredientes) {
            printf("Ingrediente nao encontrado!\n");
        }

        printf("Deseja adicionar outro ingrediente? (1 - Sim, 0 - Nao): ");
        scanf("%d", &adicionarIngredientes);
    }

    printf("Preco final da pizza: %.2f\n", precoFinal);
}
