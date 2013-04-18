P=main
CFLAGS = -Wall -Werror -std=c99 -D DEBUG
LDLIBS = -lSDL -lpthread
CC = gcc

#OBJECTS = TheDude.o
$(P): $(OBJECTS)


clean:
	rm -rf *.o *~ main

valgrind: $(P)
	valgrind -v --tool=memcheck --leak-check=full ./main