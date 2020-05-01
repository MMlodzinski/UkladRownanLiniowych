#
#  To sa opcje dla kompilacji
#
CXXFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan < rownanie_liniowe.dat

uklad_rownan: obj/main.o obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o

obj/main.o: src/main.cpp inc/SUkladRownanLiniowych.hh inc/SMacierz.hh inc/SWektor.hh\
        inc/rozmiar.h
	g++ ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CXXFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

clean:
	rm -f obj/*.o uklad_rownan

#CXXFLAGS= -c -g -std=c++11 -iquote inc -Wall -pedantic

#__start__: ./test_wektora
#	./test_wektora

#obj:
#	mkdir -p obj

#./test_wektora: obj obj/main.o obj/LZespolona.o
#	g++ -o ./test_wektora obj/main.o obj/LZespolona.o

#obj/main.o: src/main.cpp inc/SWektor.hh inc/LZespolona.hh inc/SMacierz.hh inc/SUkladRownanLiniowych.hh
#	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

#obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
#	g++ -c ${CXXFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

#clean:
#	rm -f obj/*.o ./test_wektora