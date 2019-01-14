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

test: compare run

$(BIN_DIR)/polymorphic.out : $(SRC_DIR)/*/polymorphic.cpp
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/polymorphic.tmp.out : $(SRC_DIR)/*/polymorphic.tmp.cpp
	$(CC) $(FLAGS) $^ -o $@

polymorphic.compare: $(BIN_DIR)/polymorphic.out $(BIN_DIR)/polymorphic.tmp.out
	# "polymorphic"
	time ./$(BIN_DIR)/polymorphic.out
	# "polymorphic with template meta programming"
	time ./$(BIN_DIR)/polymorphic.tmp.out

$(BIN_DIR)/vector.out : $(SRC_DIR)/*/vector.cpp
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/vector.tmp.out : $(SRC_DIR)/*/vector.tmp.cpp
	$(CC) $(FLAGS) $^ -o $@

vector.compare: $(BIN_DIR)/vector.out $(BIN_DIR)/vector.tmp.out
	# "vector"
	time ./$(BIN_DIR)/vector.out
	# "vector with template meta programming"
	time ./$(BIN_DIR)/vector.tmp.out

$(BIN_DIR)/factorial.out : $(SRC_DIR)/*/factorial.cpp
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/factorial.tmp.out: $(SRC_DIR)/*/factorial.tmp.cpp
	$(CC) $(FLAGS) $^ -o $@

factorial.compare: $(BIN_DIR)/factorial.out $(BIN_DIR)/factorial.tmp.out
	# "factorial"
	time ./$(BIN_DIR)/factorial.out
	# "factorial with template meta programming"
	time ./$(BIN_DIR)/factorial.tmp.out

compare: factorial.compare vector.compare polymorphic.compare
	# make all compare finished

clean:
	-rm -rf $(BIN_DIR)
	-rm -rf $(OBJ_DIR)
