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
