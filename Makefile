CPPFLAGS = -I/usr/include/irrlicht
CXXFLAGS = -Wall -Wextra -O2 -g -std=c++11 -Wno-unused-parameter

irrlicht-projet: main.o player.o events.o
	g++ $^ -o $@ -lIrrlicht

main.o player.o events.o: player.h events.h
clean:
	@rm -f irrlicht-projet *.o
