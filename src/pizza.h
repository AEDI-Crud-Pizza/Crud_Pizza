#include <stdio.h>
#include <stdlib.h>
#include "ingrediente.h"

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

typedef struct {
    int id;
    char nome[50];
    char tamanho; // P, M, G
    float preco;
    Ingrediente ingredientes[5]; 
} Pizza;

void adicionarPizza(Pizza* pizzas, int* numPizzas);
void removerPizza(Pizza* pizzas, int* numPizzas);
//void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes);
//void venderPizza(int numPizzas, char* tamanho, char ingredientes[][20], int numIngredientes)
//void visualizarIngrediente(Ingrediente* ingredientes, int numIngredientes);