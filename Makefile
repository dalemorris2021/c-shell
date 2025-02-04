SRC = src
INC = include
BUILD = build
BIN = $(BUILD)/bin
OBJ = $(BUILD)/obj

OBJS = $(OBJ)/main.o $(OBJ)/shell.o

CC = clang
RM = rm -f

CPPFLAGS = -Iinclude
CFLAGS = -std=c99 -g -Wall -Wextra -Wpedantic -Werror

.PHONY: all clean

all: dirs $(BIN)/shell

dirs:
	mkdir -p $(INC) $(BUILD) $(OBJ) $(BIN)

$(BIN)/shell: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(BIN)/shell $(OBJS)

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/shell.o: $(SRC)/shell.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $(OBJ)/shell.o $(SRC)/shell.c

clean:
	$(RM) $(OBJ)/*
	$(RM) $(BIN)/*
