factorial.out : factorial.cpp
	g++ factorial.cpp -o factorial.out

factorial.tmp.out: factorial.tmp.cpp
	g++ factorial.tmp.cpp -o factorial.tmp.out

factorial.compare: factorial.out factorial.tmp.out
	# "factorial"
	time ./factorial.out
	# "factorial with template meta programming"
	time ./factorial.tmp.out


clean:
	rm *.out