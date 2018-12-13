#include <stdio.h>
#include <string.h>
#include "../cubtest.c"

int main(void) {

//handle für das sammeln der Testergebnisse

	handle* handle_ = getEmptyHandle();

//die tests durchführen

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

	int f = assert_IntArrayEqual(a, b, 3, "F7: Arrays auf dem bereich [0..3] nicht gleich!", handle_);//1

	assert_IntInRange(2,1,5,"Nicht im Bereich.",handle_);
	assert_IntInRange(2,5,6,"Nicht im Bereich.",handle_);

	printf("%d\n",f);
//Siehe Abschnitt über Weitere Features.

	appendNote("Einfache Meldung anzeigen.", handle_);
	appendNote("Ggf. um Programmverlauf zu folgen.", handle_);
	appendNoteAndMessage("Ausgabe eines Strings zusätzlich zur Notiz","Ich bin der Inhalt.", handle_);
	appendNoteAndInt("Ausgabe eines Ints",42, handle_);
//Ausgabe erzeugen

	generateHeader(handle_);
	generateReport(handle_);
	char** noteList = getMessages(handle_);

//Ausgabe

	printf("%s\n", handle_->header);

	int i = 0;
	while (i < handle_->messages) {
		printf("%s\n", noteList[i]);
		i++;
	}

	printf("%s\n", handle_->report);

//Speicherplatz freigeben

	deleteHandle(handle_);


	return 0;

}
