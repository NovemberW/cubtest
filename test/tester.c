#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(){

	handle base;

	handle* handle_ = &base;

	initHandle(handle_,&logPrint);

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

