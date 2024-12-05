#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

void menuPizzas() {
    int opcao;
    do {
        printf("\n--- Menu Pizzas ---\n");
        printf("1. Listar Pizzas\n");
        printf("2. Adicionar Pizza\n");
        printf("3. Editar Pizza\n");
        printf("4. Remover Pizza\n");
        printf("5. Vender Pizza\n");
        printf("6. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: listarPizzas(); break;
            case 2: adicionarPizza(); break;
            case 3: editarPizza(); break;
            case 4: removerPizza(); break;
            case 5: venderPizza(); break;
        }
    } while (opcao != 6);
}

void menuIngredientes() {
    int opcao;
    do {
        printf("\n--- Menu Ingredientes ---\n");
        printf("1. Listar Ingredientes\n");
        printf("2. Adicionar Ingrediente\n");
        printf("3. Editar Ingrediente\n");
        printf("4. Remover Ingrediente\n");
        printf("5. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: listarIngredientes(); break;
            case 2: adicionarIngrediente(); break;
            case 3: editarIngrediente(); break;
            case 4: removerIngrediente(); break;
        }
    } while (opcao != 5);
}

int main() {
    int opcao;
    do {
        printf("\n--- Sistema da Pizzaria ---\n");
        printf("1. Gerenciar Pizzas\n");
        printf("2. Gerenciar Ingredientes\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menuPizzas(); break;
            case 2: menuIngredientes(); break;
        }
    } while (opcao != 3);

    printf("Terminado\n");
    return 0;
}
