all:
	g++ -std=c++11 -Wall -o hastable hastable.cpp

clean:
	rm -f *.o hastable