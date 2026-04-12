# Makefile - Compilation du compilateur LGLo

CC      = gcc
CFLAGS  = -Wall -Wextra -g -I./include -I./src/parser
LDFLAGS =

# repertoires
SRC     = src
BUILD   = build

# fichiers sources C
SRCS    = $(SRC)/main.c          \
          $(SRC)/ast/ast.c       \
          $(SRC)/semantic/semantic.c \
          $(SRC)/utils/error.c   \
          $(BUILD)/lexer.c       \
          $(BUILD)/parser.tab.c

# executable final
TARGET  = $(BUILD)/lglo_compiler


.PHONY: all clean debug


# -- Cible principale --

all: $(BUILD) $(TARGET)


# -- Creation du repertoire build --

$(BUILD):
	mkdir -p $(BUILD)


# -- Generation du parser (Bison) --

$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(SRC)/parser/parser.y
	bison -d -o $(BUILD)/parser.tab.c $(SRC)/parser/parser.y


# -- Generation du lexer (Flex) --

$(BUILD)/lexer.c: $(SRC)/lexer/lexer.l $(BUILD)/parser.tab.h
	flex -o $(BUILD)/lexer.c $(SRC)/lexer/lexer.l


# -- Compilation et edition des liens --

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


# -- Compilation en mode debug (affiche l'AST) --

debug: CFLAGS += -DDEBUG
debug: all


# -- Nettoyage --

clean:
	rm -rf $(BUILD)