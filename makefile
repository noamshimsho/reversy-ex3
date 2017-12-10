a.out: compileAll
	g++ *.o -o player.out
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
