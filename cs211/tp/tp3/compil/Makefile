prog: fonctions.o main.o
	gcc -Wall -g -o $@ $^

fonctions.o: fonctions.c
	gcc -c $<

main.o: main.c
	gcc -c $<


clean:
	rm -fr *.o prog
