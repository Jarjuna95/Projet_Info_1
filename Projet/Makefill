all: exec

projet_main.o: projet_main.c projet.h
	gcc -c projet_main.c -o projet_main.o
        
projet_fonction.o: projet_fonction.c projet.h
	gcc -c projet_fonction.c -o  projet_fonction.o
        
exec: projet_main.o projet_fonction.o
	gcc projet_fonction.o projet_main.o -o exec  
