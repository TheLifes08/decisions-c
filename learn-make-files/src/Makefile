objects = main.o menu.o index_first_negative.o index_last_negative.o sum_between_negative.o sum_before_and_after_negative.o
compile_flags = -c -std=c99

all: build clean

build: $(objects)
	gcc $(objects) -o menu

sum_before_and_after_negative.o:
	gcc $(compile_flags) sum_before_and_after_negative.c

sum_between_negative.o: sum_between_negative.c
	gcc $(compile_flags) sum_between_negative.c

index_last_negative.o: index_last_negative.c
	gcc $(compile_flags) index_last_negative.c

index_first_negative.o: index_first_negative.c
	gcc $(compile_flags) index_first_negative.c

menu.o: menu.c
	gcc $(compile_flags) menu.c

main.o: main.c
	gcc $(compile_flags) main.c

clean:
	rm -rf *.o
