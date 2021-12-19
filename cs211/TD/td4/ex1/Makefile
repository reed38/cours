prog: application.o mymath.o
	gcc -o $@ -Wall  $^
application.o:application.c
	gcc -Wall -c 	$<
mymath.o: mymath.c
	gcc -Wall -c $<

clean:
	rm -rf *.o prog
