prog: main.o fonctions.o
	gcc -Wall -g  -o $@ $^ -lm

main.o: main.c
	gcc -c $<

fonctions.o:fonctions.c
	gcc -c $<
clean:
	rm -rf *.o prog
