
all:PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o
	g++ -o PhotoMagic PhotoMagic.o FibLFSR.o -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic.o: PhotoMagic.cpp
	g++ -c PhotoMagic.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	g++ -c FibLFSR.cpp

clean:
	rm PhotoMagic.o FibLFSR.o PhotoMagic
