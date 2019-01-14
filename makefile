ROOT_DIR = .
SRC_DIR = $(ROOT_DIR)/src
LIB_DIR = $(ROOT_DIR)/lib
INC_DIR = $(ROOT_DIR)/include
OBJ_DIR = $(ROOT_DIR)/build
BIN_DIR = $(ROOT_DIR)/bin
TEST_DIR = $(ROOT_DIR)/test


CC = g++
FLAGS = -std=c++11 -o3 \
	-I $(ROOT_DIR) -I $(INC_DIR)

$(shell mkdir -p $(BIN_DIR) $(OBJ_DIR))

$(OBJ_DIR)/test.o: $(SRC_DIR)/test.cpp
	$(CC) $(FLAGS) $^ -c -o $@

$(BIN_DIR)/main.out : $(SRC_DIR)/main.cpp $(OBJ_DIR)/test.o
	$(CC) $(FLAGS) $^ -o $@

all: $(BIN_DIR)/main.out
	# make all finished

run: all
	./$(BIN_DIR)/main.out

clean:
	-rm -rf $(BIN_DIR)
	-rm -rf $(OBJ_DIR)
