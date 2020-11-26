main.exe: main.o binarytree.o
	gcc -o main.exe main.o binarytree.o
main.o: main.c binarytree.h
	gcc -c main.c
binarytree.o: binarytree.c binarytree.h
	gcc -c binarytree.c
remove:
	rm main.exe main.o binarytree.o
