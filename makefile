PROG = perfSL
CC = gcc
CFLAGS = -Wall
OBJS = main.o helpers.o methods.o

.PHONY: all debug clean purge

all: $(PROG)

helpers.o: helpers.c helpers.h
	$(CC)  $(CFLAGS) -c helpers.c -o helpers.o

methods.o: methods.c methods.h
	$(CC)  $(CFLAGS) -c methods.c -o methods.o

main.o: main.c
	$(CC)  $(CFLAGS) -c main.c -o main.o

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@rm -f *~ *.bak *.tmp

purge: clean
	@rm -f  $(PROG) $(PROG_AUX) *.o $(OBJS) core a.out
	@rm -f *.png marker.out *.log