/*
Name: John Lam
Student ID: 103603126
Course: 60-330
Date: August 11, 2014
Final Project: Simulation of single process execution
*/

#include <stdio.h>

/*Function Prototypes */
void simpsonRule ();

int main (void){

	simpsonRule(); // function call

	return 0;

}

//Evaluates Simpson's Rule for the given parameters
void simpsonRule (){
	double answer =0.0;
	double h = 1.0/32000.0; 
	double subanswer =0.0;
	double x = h;

	for (int i = 1; i <= 100000; i++){ // loops the calculation 100000 times
			x =h;
			subanswer =0; 
		for (int j = 0 ;j < 16000; j++){ // calculates 16000 pieces with simpson's rule
			subanswer +=  (4*(4/(1+(x*x))));
			x += h;
			subanswer += (2 * (4/(1+(x*x))));
			x+= h;	
		}
		subanswer += 4;
		subanswer+= 4/(1 + x*x);
		answer = ((h/3) * subanswer);
	}
	printf ("h= %lf\t x= %lf\n", h, x);
	printf ("Sigma : %lf\n", answer); // prints the answer
}