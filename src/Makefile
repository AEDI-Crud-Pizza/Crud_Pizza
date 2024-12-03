# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src
SRC_DIR = src
OBJ_DIR = obj
TARGET = programa

# Lista de arquivos fontes e objetos
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/pizza.c $(SRC_DIR)/ingrediente.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/pizza.o $(OBJ_DIR)/ingrediente.o

# Regra principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilação dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)

# Dependências
$(OBJ_DIR)/pizza.o: $(SRC_DIR)/pizza.h
$(OBJ_DIR)/ingrediente.o: $(SRC_DIR)/ingrediente.h
