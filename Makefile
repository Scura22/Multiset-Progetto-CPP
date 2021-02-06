main.exe: main.o
	g++ main.o -o main.exe -std=c++0x

main.o: main.cpp multiset.h element.h
	g++ -c main.cpp -o main.o -std=c++0x

clean:
	rm *.o *.exe
