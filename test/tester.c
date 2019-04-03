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


	assert_IntEqual(4,5,"Err 1",handle_);	

	int i = 0;
	for(;i < head;i++)
		printf("%s\n",logger[i]);

	return 0;
}
