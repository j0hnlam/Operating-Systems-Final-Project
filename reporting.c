#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

// define the variables we need, including the shell script that we'll be running for this demonstration

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
	// open the file that it will report to
	FILE *fp;
	
	fp = fopen("report.txt", "w");
	
	// check to make sure the reporting file opened properly
	if(fp == NULL) {
		fprintf(stderr, "Can't open report file.\n");
		exit(1);
	}
	
	// print that the interface is running
	fprintf(fp, "Running interface...");
	
	// declare the line that is read in from the stdin, and the way we are tracking how long it takes for the process to run
	char line[LINE_BUFFSIZE];
	clock_t t;

	// if system call to run the script works, while there is input check the time and write it to the reporting file
	if(system(SHELLSCRIPT) == 0) {
		while(fgets(line, LINE_BUFFSIZE, stdin) != NULL) {
			t = clock();
			fprintf(fp, "%f\n", t);
		}
	}
	else
		fprintf(fp, "Failed to run the script.\n");

	// close the file
	fclose(fp);
}
