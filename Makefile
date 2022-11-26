PROGRAM = hangman
CC = clang
BIN = bin

SRC = src
OBJ = obj

CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(CFILES))

all: $(BIN)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -c $< -o $@

$(BIN):$(OBJS)
	$(CC) -o $@ $^

make exec:
	./$(BIN)

clean:
	rm $(BIN)
	rm -f *.o obj/*.o
