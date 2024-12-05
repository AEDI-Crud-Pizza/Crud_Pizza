#ifndef PIZZA_H
#define PIZZA_H

typedef struct {
    int id;
    char nome[50];
    float preco;
} Pizza;

void carregarPizzas();
void salvarPizzas();
void listarPizzas();
void adicionarPizza();
void editarPizza();
void removerPizza();
void venderPizza();

#endif
