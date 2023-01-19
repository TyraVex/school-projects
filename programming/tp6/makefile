all: main

main : annuaire.o libannu.o debogage.o
	gcc annuaire.o libannu.o -o annuaire.exe
	gcc debogage.o libannu.o -o debogage.exe

libannu.o : libannu.c libannu.h
	gcc -c libannu.c

debogage.o : debogage.c libannu.h
	gcc -c debogage.c

clean:
	rm -rf libannu.o debogage.o *.gch

