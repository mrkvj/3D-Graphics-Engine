CC = clang

CFLAGS  = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -I/opt/homebrew/Cellar/glfw/3.4/include
CFLAGS += -I/opt/homebrew/Cellar/glew/2.2.0_1/include
CFLAGS += -I/opt/homebrew/Cellar/cglm/0.9.4/include

LDFLAGS  = -lGLEW -lglfw -lcglm -framework OpenGL
LDFLAGS += -L/opt/homebrew/Cellar/glew/2.2.0_1/lib
LDFLAGS += -L/opt/homebrew/Cellar/glfw/3.4/lib
LDFLAGS += -L/opt/homebrew/Cellar/cglm/0.9.4/lib

SRC=$(wildcard common/*.c) \
	$(wildcard src/**/*.c) \
	$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,obj/src/%.o,$(wildcard src/*.c)) \
	$(patsubst src/math/%.c,obj/src/math/%.o,$(wildcard src/math/*.c)) \
	$(patsubst common/%.c,obj/common/%.o,$(wildcard common/*.c))
BIN=bin

.PHONY: all clean dirs run game

all: dirs game

allclean: clean all

dirs:
	mkdir -p ./obj/common
	mkdir -p ./obj/src
	mkdir -p ./obj/src/math
	mkdir -p ./bin

run: all
	$(BIN)/game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

obj/src/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

obj/common/%.o: common/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

obj/src/math/%.o: src/math/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj/*
	rm -rf bin/*


