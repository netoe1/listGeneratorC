all:
	
	gcc -c ./module/itrargs/itrargs.c -o./obj/itrargs.o 
	gcc -o main.o ./src/main.c ./obj/itrargs.o
run:
	./main
clean:
	rm -rf ./*.o
	rm -rf ./obj/*.o