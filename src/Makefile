LDFLAGS = -framework SDL2  -I 

all : main

main: main.o characterModel.o characterView.o
	g++ -o main main.o characterModel.o characterView.o -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++11

characterModel.o: characterModel.cpp characterModel.h
	g++ -c characterModel.cpp -ocharacterModel.o 

characterView.o : characterView.cpp characterView.h
	g++ -c characterView.cpp -ocharacterView.o -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
clean:
	rm *.o
	rm main
