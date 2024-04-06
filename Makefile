# Eduardo Stefanel Paludo - GRR20210581
# Fábio Naconeczny da Silva - GRR20211782

PROG = perfSL
CC = gcc
CFLAGS = -O0 -Wall
OBJS = main.o helpers.o methods.o utils.o

.PHONY: all debug clean purge

all: $(PROG)

helpers.o: helpers.c helpers.h
	$(CC) $(CFLAGS) -c helpers.c -o helpers.o

methods.o: methods.c methods.h
	$(CC) $(CFLAGS) -c methods.c -o methods.o

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c -o utils.o

main.o: main.c
	$(CC) $(CFLAGS) -DLIKWID_PERFMON -I${LIKWID_INCLUDE} -c main.c -o main.o

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS) -L${LIKWID_LIB} -llikwid

clean:
	@rm -f *~ *.bak *.tmp

purge: clean
	@rm -f  $(PROG) $(PROG_AUX) *.o $(OBJS) core a.out
	@rm -f *.png marker.out *.log
