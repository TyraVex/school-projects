all: main

main : annuaire.o libannu.o
	gcc annuaire.o libannu.o -o annuaire.exe

libannu.o : libannu.c libannu.h
	gcc -c libannu.c

clean:
	rm -rf libannu.o *.gch

