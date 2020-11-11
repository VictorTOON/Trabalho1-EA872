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
	g++ -o main $(main) $(game) $(axe) $(projectile) $(character) $(zombie) $(body) $(keyboard) -I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11
main.o: main.cpp
	g++ -c main.cpp -o main.o $(CFLAGS)

zombieController.o: zombieController.cpp zombieController.h
	g++ -c zombieController.cpp -ozombieController.o $(CFLAGS)

axeController.o: axeController.cpp axeController.h
	g++ -c axeController.cpp -oaxeController.o $(CFLAGS)
axeModel.o: axeModel.cpp axeModel.h
	g++ -c axeModel.cpp -oaxeModel.o $(CFLAGS)

axeView.o : axeView.cpp axeView.h
	g++ -c axeView.cpp -oaxeView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

projectileController.o: projectileController.cpp projectileController.h
	g++ -c projectileController.cpp -oprojectileController.o $(CFLAGS)

projectileModel.o: projectileModel.cpp projectileModel.h
	g++ -c projectileModel.cpp -oprojectileModel.o $(CFLAGS)

projectileView.o : projectileView.cpp projectileView.h
	g++ -c projectileView.cpp -oprojectileView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

characterController.o: characterController.cpp characterController.h
	g++ -c characterController.cpp -ocharacterController.o $(CFLAGS)
characterModel.o: characterModel.cpp characterModel.h
	g++ -c characterModel.cpp -ocharacterModel.o $(CFLAGS)
characterView.o : characterView.cpp characterView.h
	g++ -c characterView.cpp -ocharacterView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

bodyView.o: bodyView.cpp bodyView.h
	g++ -c bodyView.cpp -obodyView.o $(CFLAGS)
bodyModel.o: bodyModel.cpp bodyModel.h
	g++ -c bodyModel.cpp -obodyModel.o $(CFLAGS)

zombieModel.o: zombieModel.cpp zombieModel.h
	g++ -c zombieModel.cpp -ozombieModel.o $(CFLAGS)

zombieView.o : zombieView.cpp zombieView.h
	g++ -c zombieView.cpp -ozombieView.o -I/usr/local/include $(CFLAGS) # -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11

sdl_keyboard_handler.o : sdl_keyboard_handler.cpp sdl_keyboard_handler.h
	g++ -c sdl_keyboard_handler.cpp -osdl_keyboard_handler.o $(CFLAGS) #-I/usr/local/include  -L/usr/local/lib -lSDL2 -lSDL2_image -std=c++11


gameModel.o : gameModel.cpp gameModel.h
	g++ -c gameModel.cpp -ogameModel.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11

gameView.o : gameView.cpp gameView.h
	g++ -c gameView.cpp -ogameView.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11
gameController.o : gameController.cpp gameController.h
	g++ -c gameController.cpp -ogameController.o $(CFLAGS) #-i/usr/local/include  -l/usr/local/lib -lsdl2 -lsdl2_image -std=c++11

clean:
	rm *.o
	rm main
