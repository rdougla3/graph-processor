EXEC = proj2
CC = g++
CFLAGS = -c -Wall

$(EXEC)	:main.o	util.o	heap.o	graph.o
	$(CC) -o $(EXEC) main.o util.o heap.o graph.o

main.o	:main.cpp
	$(CC) $(CFLAGS) main.cpp

util.o	:util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o	:heap.cpp
	$(CC) $(CFLAGS) heap.cpp

graph.o	:graph.cpp
	$(CC) $(CFLAGS) graph.cpp

clean	:
	rm *.o	
