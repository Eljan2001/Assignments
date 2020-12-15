main.exe: task.o 
	gcc -o main.exe task.o
task.o: task.c task.h
	gcc -c task.c
close:
	rm main.exe task.o
