#include <stdio.h>
#include <string.h>
#include "../framework/cubtest.h"

void f(char* string){
	//printf("%s", string);
}



int_EQ_assert(){

	int a;
	int b;

	handle handle_;// = getEmptyHandle(&f);
	
	handle_.fails = 0;
	handle_.total = 0;
	handle_.messages = 0;
	handle_.pF = &f;
	
	__CPROVER_assume(a == b);
	
	char* s = "";

	__CPROVER_assume(strlen(s) == 0);
	
	int c = assert_IntEqual(a, b,s,&handle_);
	print("%s\n",c);
	//__CPROVER_assert(c != 0,"mist");
}

int main(void) {

	

//	generateHeader(handle_);



/*
	if(){
		appendNote("Zusätzliche Debugginginformationen", handle_);
	}
	assert_IntNotEqual(42, 42, "F2: 42 == 42 !", handle_); 
	assert_IntGreater(42, 42, "F3: 42 > 43 !", handle_); 

	assert_IntSmaller(43, 43, "F4: 43 < 42 !", handle_); 
	assert_IntGreaterOrEqual(42, 43, "F5: 42 >= 43 !", handle_); 
	assert_IntSmallerOrEqual(43, 42, "F6: 43 <= 42 !", handle_); 

	
	int a[] = { 1, 2, 3 };
	int b[] = { 2, 3, 4 };

	assert_IntArrayEqual(a,a,3,"Array should be equal ...", handle_);
	assert_IntArrayEqual(a,b,3,"Arrays should not be equal ...", handle_);

	assert_IntInRange(2,1,5,"Nicht im Bereich1.",handle_);
	assert_IntInRange(2,5,6,"Nicht im Bereich2.",handle_);

//See section about additional functions.

	appendNote("Einfache Meldung anzeigen.", handle_);
	appendNote("Ggf. um Programmverlauf zu folgen.", handle_);
	appendNoteAndMessage("Ausgabe eines Strings zusätzlich zur Notiz","Ich bin der Inhalt.", handle_);
	appendNoteAndInt("Ausgabe eines Ints in binär",142,BIN, handle_);
	appendNoteAndInt("Ausgabe eines Ints in oktal",142,OCT, handle_);
	appendNoteAndInt("Ausgabe eines Ints in dezimal",142,DEC, handle_);
	appendNoteAndInt("Ausgabe eines Ints in hexadezimal",142,HEX, handle_);
*/
//show results


	//generateReport(handle_);

	return 0;

}
