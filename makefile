CC=g++

factorial.out : factorial.cpp
	$(CC) $^ -o $@

factorial.tmp.out: factorial.tmp.cpp
	$(CC) $^ -o $@

factorial.compare: factorial.out factorial.tmp.out
	# "factorial"
	time ./factorial.out
	# "factorial with template meta programming"
	time ./factorial.tmp.out

compare: factorial.compare
	# make all compare finished

clean:
	rm *.out