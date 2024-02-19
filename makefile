CC=gcc
CFLAGS=-Wall -g -std=c99
CCLINK=$(CC)
OBJS=stack.o student.o main.o
EXEC=prog.exe
RM=rm -f *.o *.exe

$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC) 

stack.o: stack.h stack.c common.h
	$(CC) $(CFLAGS) -c stack.c
student.o: stack.h student.h student.c
	$(CC) $(CFLAGS) -c student.c
main.o: main.c stack.h student.h common.h
	$(CC) $(CFLAGS) -c main.c
clean:
	rm -f *.o *.exe
