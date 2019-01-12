ROOT_DIR = .
SRC_DIR = $(ROOT_DIR)/src
LIB_DIR = $(ROOT_DIR)/lib
INC_DIR = $(ROOT_DIR)/include
OBJ_DIR = $(ROOT_DIR)/build
BIN_DIR = $(ROOT_DIR)/bin
TEST_DIR = $(ROOT_DIR)/test


CC = g++
FLAGS = -std=c++98 -o3 \
				-I $(ROOT_DIR) -I $(INC_DIR)

$(shell mkdir -p $(BIN_DIR) $(OBJ_DIR))

$(BIN_DIR)/vector.out : $(SRC_DIR)/vector.cpp
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/vector.tmp.out : $(SRC_DIR)/vector.tmp.cpp
	$(CC) $(FLAGS) $^ -o $@

vector.compare: $(BIN_DIR)/vector.out $(BIN_DIR)/vector.tmp.out
	# "vector"
	time ./$(BIN_DIR)/vector.out
	# "vector with template meta programming"
	time ./$(BIN_DIR)/vector.tmp.out

$(BIN_DIR)/factorial.out : $(SRC_DIR)/factorial.cpp
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/factorial.tmp.out: $(SRC_DIR)/factorial.tmp.cpp
	$(CC) $(FLAGS) $^ -o $@

factorial.compare: $(BIN_DIR)/factorial.out $(BIN_DIR)/factorial.tmp.out
	# "factorial"
	time ./$(BIN_DIR)/factorial.out
	# "factorial with template meta programming"
	time ./$(BIN_DIR)/factorial.tmp.out

compare: factorial.compare vector.compare
	# make all compare finished

clean:
	-rm -rf $(BIN_DIR)
	-rm -rf $(OBJ_DIR)
