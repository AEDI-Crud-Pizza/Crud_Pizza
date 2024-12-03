
#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

typedef struct {
    int id;
    char nome[50];
    char tamanho; // P, M, G
    float preco;
    Ingrediente ingredientes[5]; 
} Pizza;

void adicionarPizza(Pizza* pizzas, int* numPizzas);
void removerPizza(Pizza* pizzas, int* numPizzas);
void listarPizzas(Pizza* pizzas, int numPizzas);
void editarPizza(Pizza* pizzas, int numPizzas);
//void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes);
//void venderPizza(int numPizzas, char* tamanho, char ingredientes[][20], int numIngredientes)
//void visualizarIngrediente(Ingrediente* ingredientes, int numIngredientes);

#endif