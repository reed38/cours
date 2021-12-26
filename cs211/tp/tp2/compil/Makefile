prog: fonctions.o main.o
	gcc -g -Wall -o $@ $^

fonctions.o: fonctions.c
	gcc -g -c $<

main.o: main.c
	gcc -g -c $<


clean:
	rm -f *.o prog
