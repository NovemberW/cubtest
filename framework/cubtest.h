#ifndef CUBTEST_H
#define CUBTEST_H

#define _bool int

typedef void (*printFunc)(char* string);

typedef enum format {BIN = 2, OCT = 8, DEC = 10, HEX = 16} format;

typedef struct {
	int total;
	int fails;
	int messages;
	printFunc pF;

} handle;
//handle;

int itoaB(int value, char *sp, int radix);

void initHandle(handle* handle_, printFunc pF);

char* strcopyto(char* dest, char* src, int begin, int length);

void generateHeader(handle* handle_);

void generateReport(handle* handle_);

char** getMessages(handle* handle_);

void appendNote(char* note, handle* handle_);

void appendNoteAndInt(char* note, int i, format format_, handle* handle_);

void appendNoteAndMessage(char* note, char* message, handle* handle_);

_bool assert_IntEqual(int actual, int expected, char *message, handle* handle_);

_bool assert_IntNotEqual(int actual, int expected, char *message,
		handle* handle_);

_bool assert_IntGreater(int actual, int expected, char *message,
		handle* handle_);

_bool assert_IntGreaterOrEqual(int actual, int expected, char *message,
		handle* handle_);

_bool assert_IntSmaller(int actual, int expected, char *message,
		handle* handle_);

_bool assert_IntSmallerOrEqual(int actual, int expected, char *message,
		handle* handle_);

_bool assert_IntArrayEqual(int* actual, int* expected, int length,
		char *message, handle* handle_);

_bool assert_IntInRange(int actual, int lowerBound, int higherBound,
		char *message, handle* handle_);

_bool assert_IntNotInRange(int actual, int lowerBound, int higherBound,
		char *message, handle* handle_);

_bool assert_FloatEqual(float actual, float expected, float delte,
		char *message, handle* handle_);

_bool assert_FloatNotEqual(float actual, float expected, float delta,
		char *message, handle* handle_);

//add needed functions above this comment 

_bool noteMe(int _bool_, char *message, handle *handle_);


#endif
