#include <stdio.h>
#include "pizza.h"
#include "ingrediente.h"

int main() {
    Pizza pizzas[100];
    Ingrediente ingredientes[100];
    int numPizzas = 0, numIngredientes = 0;

    int opcao = -1;

    while (opcao != 9) {
        printf("1. Adicionar pizza\n");
        printf("2. Listar pizzas\n");
        printf("3. Editar pizza\n");
        printf("4. Remover pizza\n");
        printf("5. Adicionar ingrediente\n");
        printf("6. Listar ingredientes\n");
        printf("7. Editar ingrediente\n");
        printf("8. Remover ingrediente\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPizza(pizzas, &numPizzas);
                break;
            case 2:
                listarPizzas(pizzas, numPizzas);
                break;
            case 3:
                editarPizza(pizzas, numPizzas);
                break;
            case 4:
                removerPizza(pizzas, &numPizzas);
                break;
            case 5:
                adicionarIngrediente(ingredientes, &numIngredientes);
                break;
            case 6:
                listarIngredientes(ingredientes, numIngredientes);
                break;
            case 7:
                editarIngrediente(ingredientes, numIngredientes);
                break;
            case 8:
                removerIngrediente(ingredientes, &numIngredientes);
                break;
            case 9:
                printf("Saindo...\n");
                opcao = 9;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
