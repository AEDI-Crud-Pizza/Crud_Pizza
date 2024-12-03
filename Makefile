CC = gcc
CFLAGS = -Wall -g
TARGET = pizza

SRC = main.c pizza.c ingrediente.c
HEADERS = pizza.h ingrediente.h
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f $(OBJ) $(TARGET)
	