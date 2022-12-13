hw1 : main.o
	gcc -o hw1_201720736.exe main.o

main.o : main.c
	gcc -c -o main.o main.c

test: input.txt
	./hw1_201720736.exe < input.txt
clean:
	rm *.o hw1_201720736.exe
