all: simul.exe


afnd.o : afnd.c afnd.h
	clang -g -Wall -c afnd.c

simul.o: simul.c
	clang -g -Wall -c simul.c

simul.exe: simul.o afnd.o
	clang -g -Wall afnd.o simul.o -o simul.exe
