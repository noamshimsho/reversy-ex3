a.out: compileAll
	g++ *.o -pthread -o server.out
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp -pthread
