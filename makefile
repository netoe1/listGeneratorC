all:
	gcc -o ./obj/main ./src/main.c
run:
	./main

clean:
	rm -rf ./*.o
	rm -rf ./obj/*.o