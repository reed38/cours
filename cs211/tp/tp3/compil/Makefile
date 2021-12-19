prog: main.o fat.o
	gcc -Wall -g  -o $@ $^

fat.o: fat.c
	gcc -Wall  -c  $<

main.o: main.c
	gcc -Wall  -c  $<


clean:
	rm *.o prog
