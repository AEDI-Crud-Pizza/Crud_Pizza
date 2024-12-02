#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Ingrediente;

void adicionarIngrediente(Ingrediente* ingredientes, int* numIngredientes);