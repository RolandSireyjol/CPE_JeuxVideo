CPPFLAGS = -I/usr/include/irrlicht
CXXFLAGS = -Wall -Wextra -O2 -g -std=c++11 -Wno-unused-parameter

irrlicht-projet: main.o player.o events.o game.o sceneManager.o tir.o collidable.o
	g++ $^ -o $@ -lIrrlicht

main.o player.o events.o game.o sceneManager.o tir.o collidable.o: player.h events.h game.h sceneManager.h tir.h collidable.h
clean:
	@rm -f irrlicht-projet *.o
