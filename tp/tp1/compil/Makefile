prog: main.o fonctions.o
	gcc -o prog main.o fonctions.o

main.o: main.c
	gcc -c -Wall main.c


fonction.o: fonctions.c
	gcc -c -Wall  fonctions.c


clean:

	rm -fr *.o
