CC = clang

CFLAGS  = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -I/opt/homebrew/Cellar/glfw/3.4/include
CFLAGS += -I/opt/homebrew/Cellar/glew/2.2.0_1/include
CFLAGS += -I/opt/homebrew/Cellar/cglm/0.9.4/include

LDFLAGS  = -lGLEW -lglfw -lcglm -framework OpenGL
LDFLAGS += -L/opt/homebrew/Cellar/glew/2.2.0_1/lib
LDFLAGS += -L/opt/homebrew/Cellar/glfw/3.4/lib
LDFLAGS += -L/opt/homebrew/Cellar/cglm/0.9.4/lib

SRC = $(wildcard common/*.c) $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c)) $(patsubst common/%.c,obj/%.o,$(wildcard common/*.c))
BIN = bin

.PHONY: all clean dirs run game

all: dirs game

allclean: clean all

dirs:
#mkdir -p ./$(BIN) ./obj
#find src common -type d | sed 's/^/obj\//' | xargs mkdir -p
	mkdir ./obj/common
	mkdir ./obj/src
	mkdir ./obj/src/math

run: all
	$(BIN)/game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

obj/%.o: common/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

obj/%.o: src/math/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj/*
	rm -rf bin/*



#CC = clang
#
#CFLAGS  = -std=c11 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
#CFLAGS += -I/opt/homebrew/Cellar/glfw/3.4/include
#CFLAGS += -I/opt/homebrew/Cellar/glew/2.2.0_1/include
#CFLAGS += -I/opt/homebrew/Cellar/cglm/0.9.4/include
#
#LDFLAGS  = -lGLEW -lglfw -lcglm -framework OpenGL
#LDFLAGS += -L/opt/homebrew/Cellar/glew/2.2.0_1/lib
#LDFLAGS += -L/opt/homebrew/Cellar/glfw/3.4/lib
#LDFLAGS += -L/opt/homebrew/Cellar/cglm/0.9.4/lib
#
#SRC = $(wildcard common/*.c) $(wildcard src/**/*.c) $(wildcard src/*.c)
#OBJ = $(patsubst src/%.c,obj/%.o,$(wildcard src/**/*.c src/*.c)) $(patsubst common/%.c,obj/%.o,$(wildcard common/*.c))
#BIN = bin
#
#.PHONY: all clean dirs run game
#
#all: dirs game
#
#allclean: clean all
#
#dirs:
#	mkdir -p ./$(BIN) ./obj
##mkdir -p ./$(BIN)
##find src common -type d | sed 's/^/obj\//' | xargs mkdir -p
#
#run: all
#	$(BIN)/game
#
#game: $(OBJ)
#	$(CC) -o $(BIN)/game $^ $(LDFLAGS)
#
#obj/%.o: src/%.c
#	$(CC) -o $@ -c $< $(CFLAGS)
#
#obj/%.o: common/%.c
#	$(CC) -o $@ -c $< $(CFLAGS)
#
#obj/%.o: src/math/%.c
#	$(CC) -o $@ -c $< $(CFLAGS)
#
#clean:
#	rm -f obj/*.o
#	rm -f bin/*