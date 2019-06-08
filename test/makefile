.PHONY : core run all cleanup

core: tester.o cubtest.o 
	gcc -o tester tester.o cubtest.o

run: core
	./tester

all: core cleanup run

tester.o: tester.c
	gcc -c $?

cubtest.o: ../framework/cubtest.c
	gcc -c $?

cleanup: 
	rm cubtest.o
	rm tester.o
