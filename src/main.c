int main() {
    int opcao;

    do {
        printf("1. Gerenciar Ingredientes\n");
        printf("2. Gerenciar Pizzas\n");
        printf("3. Registrar Venda\n");
        printf("4. Salvar/Carregar Dados\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: /* Funções de ingredientes */ break;
            case 2: /* Funções de pizzas */ break;
            case 3: /* Função de venda */ break;
            case 4: /* Exportar/Importar dados */ break;
        }

    } while (opcao != 0);

    
    return 0;
}
