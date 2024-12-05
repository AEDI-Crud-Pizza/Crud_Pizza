#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingrediente.h"

void listarIngredientes() {
    FILE *arquivo = fopen("ingrediente.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    printf("\n--- Ingredientes ---\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (linha[0] == '\n') continue;

        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, ";");

        if (token) {
            Ingrediente ingrediente;
            ingrediente.id = atoi(token);

            token = strtok(NULL, ";");
            if (token) {
                strncpy(ingrediente.nome, token, sizeof(ingrediente.nome) - 1);
                ingrediente.nome[sizeof(ingrediente.nome) - 1] = '\0';

                token = strtok(NULL, ";");
                if (token) {
                    ingrediente.preco = atof(token);

                    printf("ID: %d, Nome: %s, Preco: %.2f\n", ingrediente.id, ingrediente.nome, ingrediente.preco);
                }
            }
        }
    }

    fclose(arquivo);
}

void adicionarIngrediente() {
    FILE *arquivo = fopen("ingrediente.txt", "a");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Ingrediente ingrediente;
    printf("ID do ingrediente: ");
    scanf("%d", &ingrediente.id);
    printf("Nome do ingrediente: ");
    scanf(" %[^\n]", ingrediente.nome);
    printf("Preco do ingrediente: ");
    scanf("%f", &ingrediente.preco);

    if (fprintf(arquivo, "%d;%s;%.2f\n", ingrediente.id, ingrediente.nome, ingrediente.preco) < 0) {
        printf("Erro ao adicionar o ingrediente no arquivo.\n");
    }

    fclose(arquivo);
    printf("Ingrediente adicionado com sucesso.\n");
}

void editarIngrediente() {
    FILE *arquivo = fopen("ingrediente.txt", "r+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    int id, encontrado = 0;
    printf("Digite o ID do ingrediente a ser editado: ");
    scanf("%d", &id);

    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Ingrediente ingrediente;
        if (sscanf(linha, "%d;%49[^\n];%f", &ingrediente.id, ingrediente.nome, &ingrediente.preco) == 3) {
            if (ingrediente.id == id) {
                encontrado = 1;
                printf("Ingrediente encontrado!\n");
                printf("Novo nome do ingrediente: ");
                scanf(" %[^\n]", ingrediente.nome);
                printf("Novo preco do ingrediente: ");
                scanf("%f", &ingrediente.preco);

                fseek(arquivo, -strlen(linha), SEEK_CUR); // Volta para a posição anterior no arquivo
                fprintf(arquivo, "%d;%s;%.2f\n", ingrediente.id, ingrediente.nome, ingrediente.preco);
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Ingrediente nao encontrado.\n");
    } else {
        printf("Ingrediente editado com sucesso.\n");
    }

    fclose(arquivo);
}

void removerIngrediente() {
    FILE *arquivo = fopen("ingrediente.txt", "r+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arquivo);
        return;
    }

    char linha[200];
    int id, encontrado = 0;
    printf("Digite o ID do ingrediente a ser removido: ");
    scanf("%d", &id);

    while (fgets(linha, sizeof(linha), arquivo)) {
        Ingrediente ingrediente;
        if (sscanf(linha, "%d;%49[^\n];%f", &ingrediente.id, ingrediente.nome, &ingrediente.preco) == 3) {
            if (ingrediente.id != id) {
                fprintf(temp, "%d;%s;%.2f\n", ingrediente.id, ingrediente.nome, ingrediente.preco);
            } else {
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Ingrediente nao encontrado.\n");
    } else {
        printf("Ingrediente removido com sucesso.\n");
    }

    fclose(arquivo);
    fclose(temp);

    remove("ingrediente.txt");
    rename("temp.txt", "ingrediente.txt");
}
