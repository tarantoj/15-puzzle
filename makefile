CC = gcc
FLAGS = -O3 -Wall

ida: main.o ida.o action.o node.h heuristic.o
	$(CC) $(FLAGS) main.o ida.o action.o heuristic.o -o ida

wida: main.o wida.o action.o node.h heuristic.o
	$(CC) $(FLAGS) main.o wida.o action.o heuristic.o -o wida
	
main.o: main.c ida.h heuristic.h node.h
	$(CC) $(FLAGS) -c main.c

ida.o: ida.h ida.c action.h heuristic.h node.h
	$(CC) $(FLAGS) -c -D W=1 ida.c -o ida.o

wida.o: ida.h ida.c action.h heuristic.h node.h
	$(CC) $(FLAGS) -c -D W=1.5 ida.c -o wida.o

action.o: action.h action.c
	$(CC) $(FLAGS) -c action.c

heuristic.o: heuristic.h heuristic.c
	$(CC) $(FLAGS) -c heuristic.c

test: ida
	./ida 2.puzzle
clean:
	rm ida wida *.o
