#include<stdio.h>

void main() {
	// used for the pages
	int logicalmemsize = 32, pagesize, physicalmemsize = 4, c[10], str = 4, a[logicalmemsize], b[35];
	// used for the for loops
	int i, j, k;
	
	// clear the CLI
	system("clear");
	// print what the addressing scheme is
	printf("\n The addressing scheme is a %d, and the address space is %d", logicalmemsize, physicalmemsize);
	// ask the user to enter the data that will be used to demonstrate how the addressing scheme works
	printf("\n Enter data:");
	for(i=0; i < logicalmemsize; i++)
		scanf("%d", &a[i]);
		
	// place the data properly in the memory
	for(i=0; i < logicalmemsize/physicalmemsize; i++) {
		c[i] = str/physicalmemsize;
		for(j=str, k=i*4; j<j+physicalmemsize, k<i*4+physicalmemsize; j++, k++)
			b[j] = a[k];
	}
	
	// print the tables and their frames
	printf("\n The page table is: \n Page \t\t Frame");
	
	for(i=0; i < logicalmemsize/physicalmemsize; i++)
		printf("\n %d\t\t %d", i, c[i]);
	
	// declare integers that we will be using to display the locations of the data in the memory
	int mappingaddress, page, frame, ab;
	
	// output where the requested data is
	printf("\n Enter for which data the mapping address is to be found:");
	scanf("%d", &mappingaddress);
	
	for(i=0; i<logicalmemsize; i++) {
		if(mappingaddress == a[i]) {
			page = i/physicalmemsize;
			frame=c[page];
			ab=(frame*physicalmemsize)+(i%physicalmemsize);
		}
	}
	
	printf("\n The physical address for %d is: %d", mappingaddress, ab);
}
