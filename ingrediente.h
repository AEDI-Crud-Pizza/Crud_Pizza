#ifndef INGREDIENTE_H
#define INGREDIENTE_H


typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes);
void listarIngredientes(Ingrediente* ingredientes, int numIngredientes);
void editarIngrediente(Ingrediente* ingredientes, int numIngredientes);
void removerIngrediente(Ingrediente* ingredientes, int* numIngredientes);

#endif