#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "../framework/cubtest.h"

#define BUFFER_SIZE 1024

char* logger[BUFFER_SIZE];

int head = 0;

void logPrint(char* content){

	if(head >= BUFFER_SIZE){
		printf("Out of log-space for: %s\n",content);
		exit(-1);
	}


	char* helper = (char*) malloc(strlen(content));
	strcpy(helper,content);
	logger[head] = helper;
	head++;
}

bool contains(char* searchString){
	int i;
	
	for(i = 0;i < head;i++)
		if(strstr(logger[i],searchString) != NULL){	
			return true;
		}

	return false;
}

int main(){

	handle base;

	handle* handle_ = &base;

	initHandle(handle_,&logPrint);

	assert(handle_->total == 0);
	assert(handle_->fails == 0);
	assert(handle_->messages == 0);
	assert(handle_->pF == &logPrint);

	generateHeader(handle_);


	assert_IntEqual(0, 0, "Corr. IntEqual", handle_);

	int e = 42;
	int delta;	
	//for(delta = 0;base + delta < 2000;base += 10){}		
		
	assert_IntEqual(e , e  + 1, "Err IntEqual", handle_);

	assert_IntNotEqual(0, 1, "Corr. IntNotEqual", handle_);
	assert_IntNotEqual(4, 4, "Err IntNotEqual", handle_);


	assert_IntSmaller(1, 2, "Corr. IntSmaller", handle_);
    assert_IntSmaller(4, 4, "Err IntSmaller", handle_);


	assert_IntSmallerOrEqual(0, 0, "Corr. IntSmallerOrEqual", handle_);
    assert_IntSmallerOrEqual(4, 5, "Err IntSmallerorEqual", handle_);


    assert_IntGreater(2, 1, "Corr. IntGreater", handle_);
    assert_IntGreater(4, 4, "Err IntGreater", handle_);


	assert_IntGreaterOrEqual(0, 0, "Corr. IntGreaterOrEqual", handle_);
    assert_IntGreaterOrEqual(5, 4, "Err IntGreaterorEqual", handle_);

    generateReport(handle_);

	assert(handle_->total = 11);
	assert(handle_->fails = 4);
	assert(handle_->messages == 0);

	
	appendNote("Dummy note", handle_);
	appendNoteAndInt("Dummy int note b",42, BIN, handle_);
	appendNoteAndInt("Dummy int note o",42, OCT, handle_);
	appendNoteAndInt("Dummy int note d",42, DEC, handle_);
	appendNoteAndInt("Dummy int note h",42, HEX, handle_);
	appendNoteAndMessage("Dummy message note","Second one" , handle_);

	assert(contains("Dummy note"));
	assert(contains("Dummy int note b"));
	assert(contains("Dummy int note o"));
	assert(contains("Dummy int note d"));
	assert(contains("Dummy int note h"));
	assert(contains("Dummy note"));
	assert(contains("Second one"));



	assert(handle_->total = 11);
	assert(handle_->fails = 4);
	assert(handle_->messages == 6);

	int i = 0;
	for(;i < head;i++)
		printf("%s",logger[i]);

	printf("HEAD: %d\n",head);

	int errorCount = 0;
	int j = 0;
	for(;j < head;j++){
		if(strstr(logger[j],"Corr") != NULL){		
			printf("%d: %s",j,logger[j]);
			errorCount++;
		}
	}

	if(errorCount != 0){
		printf("\n%d Errors found.\n",errorCount);
	}else{
		printf("\nNo errors found.\n");
	}	

	return 0;
}

