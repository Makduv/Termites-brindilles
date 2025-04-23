all: projet testcoord

projet: main.cpp coord.cpp grille.cpp termite.cpp
	 g++ -o projet main.cpp coord.cpp grille.cpp termite.cpp

testcoord: testcoord.cpp coord.cpp
	 g++ -o testcoord testcoord.cpp coord.cpp

clean:
	rm -f *.o projet testcoord
