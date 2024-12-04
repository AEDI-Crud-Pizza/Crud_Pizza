#ifndef PIZZA_H
#define PIZZA_H
#include "ingrediente.h"

typedef struct {
    int id;
    char nome[50];
    float preco;
    Ingrediente ingredientes[5];
    int nIngredientes;
} Pizza;

void adicionarPizza(Pizza* pizzas, int* numPizzas);
void listarPizzas(Pizza* pizzas, int numPizzas);
void editarPizza(Pizza* pizzas, int numPizzas);
void removerPizza(Pizza* pizzas, int* numPizzas);
void venderPizza(Pizza *pizzas, int qtdPizzas, Ingrediente *ingredientes, int qtdIngredientes);

#endif
