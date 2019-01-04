#include <stdio.h>
#include <string.h>
#include "../framework/cubtest.h"

void f(char* string){
	printf("%s", string);
}

int main(void) {

//handle to collect the results

	handle* handle_ = getEmptyHandle(&f);

	generateHeader(handle_);

//exceute some tests

	if(assert_IntEqual(42, 43, "F1: 42 != 43", handle_)){
		appendNote("Zusätzliche Debugginginformationen", handle_);
	}
	
	assert_IntNotEqual(42, 42, "F2: 42 == 42 !", handle_); 
	assert_IntGreater(42, 42, "F3: 42 > 43 !", handle_); 

	assert_IntSmaller(43, 43, "F4: 43 < 42 !", handle_); 
	assert_IntGreaterOrEqual(42, 43, "F5: 42 >= 43 !", handle_); 
	assert_IntSmallerOrEqual(43, 42, "F6: 43 <= 42 !", handle_); 

	
	int a[] = { 1, 2, 3 };
	int b[] = { 2, 3, 4 };

	assert_IntInRange(2,1,5,"Nicht im Bereich1.",handle_);
	assert_IntInRange(2,5,6,"Nicht im Bereich2.",handle_);

//See section about additional functions.

	appendNote("Einfache Meldung anzeigen.", handle_);
	appendNote("Ggf. um Programmverlauf zu folgen.", handle_);
	appendNoteAndMessage("Ausgabe eines Strings zusätzlich zur Notiz","Ich bin der Inhalt.", handle_);
	appendNoteAndInt("Ausgabe eines Ints",42, handle_);

//show results


	generateReport(handle_);

	return 0;

}
