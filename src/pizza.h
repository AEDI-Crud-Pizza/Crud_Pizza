#include <stdio.h>
#include <stdlib.h>
#include "ingrediente.h"

typedef struct {
    int id;
    char nome[50];
    char tamanho; // P, M, G
    float preco;
    Ingrediente ingredientes[3]; 
} Pizza;


typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

void adicionarPizza(Pizza* pizzas, int* numPizzas);
void removerPizza(Pizza* pizzas, int* numPizzas);
void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes);
