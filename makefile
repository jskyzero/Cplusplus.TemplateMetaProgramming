CC=g++
FLAG= -std=c++98 -o3

vector.out : vector.cpp
	$(CC) $(FLAG) $^ -o $@

vector.tmp.out : vector.tmp.cpp
	$(CC) $(FLAG) $^ -o $@

vector.compare: vector.out vector.tmp.out
	# "vector"
	time ./vector.out
	# "vector with template meta programming"
	time ./vector.tmp.out

factorial.out : factorial.cpp
	$(CC) $(FLAG) $^ -o $@

factorial.tmp.out: factorial.tmp.cpp
	$(CC) $(FLAG) $^ -o $@

factorial.compare: factorial.out factorial.tmp.out
	# "factorial"
	time ./factorial.out
	# "factorial with template meta programming"
	time ./factorial.tmp.out

compare: factorial.compare vector.compare
	# make all compare finished

clean:
	rm *.out
