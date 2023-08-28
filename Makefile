cc = gcc
CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LIBS = $(shell pkg-config --libs gtk+-3.0)
obj= automata.o initWidgets.o
.PHONY = clean all

all: automata
	./$<

automata: automata.o
	$(cc) -o automata automata.o $(CFLAGS) $(LIBS)
	
initWidgets.o: initWidgets.c widgets.h
	$(cc) -c initWidgets.c -o initWidgets.o $(CFLAGS) $(LIBS)
	
automata.o: automata.c widgets.h
	$(cc) -c automata.c $(CFLAGS) $(LIBS)


	
	

clean:
	rm -f *.o automata