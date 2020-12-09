LDFLAGS = -framework SDL2  -I 
CFLAGS= -std=c++11

main=main.o
game=gameController.o gameView.o gameModel.o
zombie=zombieController.o zombieView.o zombieModel.o
character=characterController.o characterView.o characterModel.o
body=bodyView.o bodyModel.o
projectile=projectileView.o projectileModel.o
axe=axeController.o axeModel.o axeView.o
keyboard=sdl_keyboard_handler.o

all : main

main: $(main) $(game) $(axe) $(projectile) $(character) $(zombie) $(body) $(keyboard)
	g++ -o main $(main) $(game) $(axe) $(projectile) $(character) $(zombie) $(body) $(keyboard) -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11 -lpthread
main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

zombieController.o: zombieController.cpp zombieController.hpp
	g++ -c zombieController.cpp -ozombieController.o $(CFLAGS)

axeController.o: axeController.cpp axeController.hpp
	g++ -c axeController.cpp -oaxeController.o $(CFLAGS)
axeModel.o: axeModel.cpp axeModel.hpp
	g++ -c axeModel.cpp -oaxeModel.o $(CFLAGS)

axeView.o : axeView.cpp axeView.hpp
	g++ -c axeView.cpp -oaxeView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

projectileController.o: projectileController.cpp projectileController.hpp
	g++ -c projectileController.cpp -oprojectileController.o $(CFLAGS)

projectileModel.o: projectileModel.cpp projectileModel.hpp
	g++ -c projectileModel.cpp -oprojectileModel.o $(CFLAGS)

projectileView.o : projectileView.cpp projectileView.hpp
	g++ -c projectileView.cpp -oprojectileView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

characterController.o: characterController.cpp characterController.hpp
	g++ -c characterController.cpp -ocharacterController.o $(CFLAGS)
characterModel.o: characterModel.cpp characterModel.hpp
	g++ -c characterModel.cpp -ocharacterModel.o $(CFLAGS)
characterView.o : characterView.cpp characterView.hpp
	g++ -c characterView.cpp -ocharacterView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

bodyView.o: bodyView.cpp bodyView.hpp
	g++ -c bodyView.cpp -obodyView.o $(CFLAGS)
bodyModel.o: bodyModel.cpp bodyModel.hpp
	g++ -c bodyModel.cpp -obodyModel.o $(CFLAGS)

zombieModel.o: zombieModel.cpp zombieModel.hpp
	g++ -c zombieModel.cpp -ozombieModel.o $(CFLAGS)

zombieView.o : zombieView.cpp zombieView.hpp
	g++ -c zombieView.cpp -ozombieView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

sdl_keyboard_handler.o : sdl_keyboard_handler.cpp sdl_keyboard_handler.hpp
	g++ -c sdl_keyboard_handler.cpp -osdl_keyboard_handler.o $(CFLAGS) #-I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11


gameModel.o : gameModel.cpp gameModel.hpp
	g++ -c gameModel.cpp -ogameModel.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11

gameView.o : gameView.cpp gameView.hpp
	g++ -c gameView.cpp -ogameView.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11
gameController.o : gameController.cpp gameController.hpp
	g++ -c gameController.cpp -ogameController.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11

clean:
	rm *.o
	rm main
