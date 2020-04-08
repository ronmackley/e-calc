#include <math.h>
#include <stdio.h>

/***************************************************************
	e.c - calculate the value of e to the precision available 
	in a long double.
	   
	    inf.
	   -----| 
	   \     1
	    -   ---
	e= /     n!
	   -----|	
		n=0

     this program holds the current value of the denominator
     in a variable so that it factorials do not need to be 
     recalculated with each iteration. That makes this run in 
     linear time.
     
 ***************************************************************/
 
int main()
{
	long double e = 0.0;
	long double prior_e = 0.0;
	long long denom = 1;
	long long n = 0;	

	do
	{
		prior_e = e;
		// calculate the current value of the summation
		e = e + 1/(double)denom;
		
		printf("e = %30.30Lf\n", e );
		// increment the summation step
		n++;
		// compute the next factorial value
		denom = denom * n;

	// Continue while prior and currentvalues are unequal. After that 
	// point no subsequent calculations will change the answer we get.
	
	} while(e != prior_e);
	
	printf("precision limit for e reached at e = %30.30Lf\n", e );	
}

