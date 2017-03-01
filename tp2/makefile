all: simul.exe


afnd.o : afnd.c
	gcc -g -Wall -c afnd.c

simul.o: simul.c
	gcc -g -Wall -c simul.c

simul.exe: simul.o afnd.o
	gcc -g -Wall afnd.o simul.o -o simul.exe
