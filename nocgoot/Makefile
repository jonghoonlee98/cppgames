CXX = clang++ -std=c++11 
CXXFLAGS = -g3
LDFLAGS = -g3 -lsfml-window -lsfml-graphics -lsfml-system

nocgoot: main.o player.o ball.o ghost.o star.o
	${CXX} ${LDFLAGS} -o nocgoot main.o player.o ball.o ghost.o star.o

main.o:	main.cpp player.h ball.h

player.o: player.cpp player.h

ball.o: ball.cpp ball.h

ghost.o: ghost.cpp ghost.h

star.o: star.cpp star.h

clean:
	-rm -rf nocgoot *.dSYM *.o