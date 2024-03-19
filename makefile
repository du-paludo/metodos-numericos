PROG = perfSL
CC = gcc
CFLAGS = -Wall
OBJS = main.o functions.o

.PHONY: all debug clean purge

all: $(PROG)

functions.o: functions.c functions.h
	$(CC)  $(CFLAGS) -c functions.c -o functions.o

main.o: main.c
	$(CC)  $(CFLAGS) -c main.c -o main.o

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	@rm -f *~ *.bak *.tmp

purge: clean
	@rm -f  $(PROG) $(PROG_AUX) *.o $(OBJS) core a.out
	@rm -f *.png marker.out *.log