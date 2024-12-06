#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;


void listarIngredientes();
void adicionarIngrediente();
void editarIngrediente();
void removerIngrediente();

#endif
