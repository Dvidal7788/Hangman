PROGRAM = hangman
CC = gcc
BIN = bin

SRC = src
OBJ = obj
INCDIRS = . ./include/

DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

CFILES = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(CFILES))
DEPFILES = $(patsubst $(SRC)/%.c,$(OBJ)/%.d,$(CFILES))

DATE = $(shell date +%F)
TIMESTAMP = $(shell date +%r)

all: $(BIN)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):$(OBJS)
	$(CC) -o $@ $^

make run:
	@./$(BIN)

dist:
	tar -czvf $(PROGRAM)$(DATE).tgz *
	echo "* $(PROGRAM)$(DATE).tgz successfully created *"

clean:
	rm -f $(BIN)
	rm -rf *.o obj/*.o

rmtar:
	rm -f *.tgz *tar.gz

rmd:
	rm -rf *.d obj/*.d

-include $(DEPFILES)
