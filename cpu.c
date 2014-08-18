#include<stdio.h>

void main() {
	// used for the pages
	int logicalmemsize = 32, pagesize, physicalmemsize = 4, c[10], str = 4, a[logicalmemsize], b[35];
	// used for the for loops
	int i, j, k;
	
	system("clear");
	printf("\n The addressing scheme is a %d, and the address space is %d", logicalmemsize, physicalmemsize);
	printf("\n Enter data:");
	for(i=0; i < logicalmemsize; i++)
		scanf("%d", &a[i]);
	for(i=0; i < logicalmemsize/physicalmemsize; i++) {
		c[i] = str/physicalmemsize;
		for(j=str, k=i*4; j<j+physicalmemsize, k<i*4+physicalmemsize; j++, k++)
			b[j] = a[k];
	}
	
	printf("\n The page table is: \n Page \t\t Frame");
	
	for(i=0; i < logicalmemsize/physicalmemsize; i++)
		printf("\n %d\t\t %d", i, c[i]);
	
	int mappingaddress, page, frame, abs;
	
	printf("\n Enter for which data the mapping address is to be found:");
	scanf("%d", &mappingaddress);
	
	for(i=0; i<logicalmemsize; i++) {
		if(mappingaddress == a[i]) {
			page = i/physicalmemsize;
			frame=c[page];
			abs=(frame*physicalmemsize)+(i%physicalmemsize);
		}
	}
	
	printf("\n The physical address for %d is: %d", mappingaddress, abs);
}
