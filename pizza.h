#ifndef PIZZA_H
#define PIZZA_H

typedef struct {
    int id;
    char nome[50];
    float preco;
} Pizza;

void adicionarPizza(Pizza* pizzas, int* numPizzas);
void listarPizzas(Pizza* pizzas, int numPizzas);
void editarPizza(Pizza* pizzas, int numPizzas);
void removerPizza(Pizza* pizzas, int* numPizzas);

#endif
