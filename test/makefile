all: tester.o cubtest.o
	gcc -o tester tester.o cubtest.o

tester.o: tester.c
	gcc -c $?

cubtest.o: ../framework/cubtest.c
	gcc -c $?
