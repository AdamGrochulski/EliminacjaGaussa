all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test1: all
	bin/gauss dane/A_1 dane/b_1
test1: all
	bin/gauss dane/A_2 dane/b_2
test2: all
	bin/gauss dane/A_3 dane/b_3
