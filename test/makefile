all: tester.o cubtest.o 
	gcc -o tester tester.o cubtest.o
	./tester

tester.o: tester.c
	gcc -c $?

cubtest.o: ../framework/cubtest.c
	gcc -c $?

cleanup: 
	rm cubtest.o
	rm tester.o
	rm tester
