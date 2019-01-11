CC=g++
FLAG= -std=c++98

vector.out : vector.cpp
	$(CC) $(FLAG) $^ -o $@

factorial.out : factorial.cpp
	$(CC) $(FLAG) $^ -o $@

factorial.tmp.out: factorial.tmp.cpp
	$(CC) $(FLAG) $^ -o $@

factorial.compare: factorial.out factorial.tmp.out
	# "factorial"
	time ./factorial.out
	# "factorial with template meta programming"
	time ./factorial.tmp.out

compare: factorial.compare
	# make all compare finished

clean:
	rm *.out
