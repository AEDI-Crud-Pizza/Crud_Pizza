#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int IdP;
    char NomeP[50];
    char Tamanho;
    float Preço;
    Ingredientes lista_ingredientes[];
} Pizza;

typedef struct {
    int Id;
    char Nome[30];
    float Preço;
} Ingredientes;