P=main
CFLAGS = -Wall -Werror -std=c99 -D DEBUG
LDLIBS = -lSDL -lpthread
CC = gcc

OBJECTS = Control.o Player.o
$(P): $(OBJECTS)


clean:
	rm -rf *.o main ../*/*~ ../guilt.tar

tarball: clean
	tar -cvf ../guilt.tar ..
	
pushgit: clean
	git add ..
	git commit -m "make commit"
	git push origin master
	
valgrind: $(P)
	valgrind -v --tool=memcheck ./main
