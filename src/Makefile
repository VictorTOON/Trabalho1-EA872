LDFLAGS = -framework SDL2  -I 

all : main

main: main.o gameController.o zombieView.o zombieModel.o characterModel.o characterView.o gameView.o sdl_keyboard_handler.o
	g++ -o main main.o gameController.o zombieView.o zombieModel.o characterModel.o gameView.o characterView.o sdl_keyboard_handler.o -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++11

characterModel.o: characterModel.cpp characterModel.h
	g++ -c characterModel.cpp -ocharacterModel.o 

characterView.o : characterView.cpp characterView.h
	g++ -c characterView.cpp -ocharacterView.o -I/usr/local/include # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

zombieModel.o: zombieModel.cpp zombieModel.h
	g++ -c zombieModel.cpp -ozombieModel.o 

zombieView.o : zombieView.cpp zombieView.h
	g++ -c zombieView.cpp -ozombieView.o -I/usr/local/include # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

sdl_keyboard_handler.o : sdl_keyboard_handler.cpp sdl_keyboard_handler.h
	g++ -c sdl_keyboard_handler.cpp -osdl_keyboard_handler.o #-I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11


gameView.o : gameView.cpp gameView.h
	g++ -c gameView.cpp -ogameView.o #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11
gameController.o : gameController.cpp gameController.h
	g++ -c gameController.cpp -ogameController.o #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11

clean:
	rm *.o
	rm main
