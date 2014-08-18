#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#define LINE_BUFFSIZE 128

#define SHELLSCRIPT "\
#!/bin/bash \n\
if ($# == 0); then \n\
	echo "Please enter a command." \n\
else \n\
	echo $1 \n\
fi \n\
"

void main(int argc, char *argv[]) {
	FILE *fp;
	
	fp = fopen("report.txt", "w");
	
	if(fp == NULL) {
		fprintf(stderr, "Can't open report file.\n");
		exit(1);
	}
	
	fprintf(fp, "Running interface...");
	
	char line[LINE_BUFFSIZE];
	clock_t t;

	if(system(SHELLSCRIPT) == 0) {
		while(fgets(line, LINE_BUFFSIZE, stdin) != NULL) {
			t = clock();
			fprintf(fp, "%f\n", t);
		}
	}

	fclose(fp);
}
