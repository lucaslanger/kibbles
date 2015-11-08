#include <stdlib.h>
#include <stdio.h>

int add3( int a ){

	return a+3;
}

int main()
{

	int (*fn)(int) = &add3;
	void *p = (void*)fn;
	int x = 1;

	if( fn(x) > 2 )
		printf( ">2\n");
	else
		printf( "<=2\n");

	printf( "Adding 3 to x gives: %d.\n", fn(x) );
        printf( "fn holds: %ld.\n", (long int)fn );
	printf( "fns value is: %ld.\n", (long int)*fn );
	printf( "double de-ref of fn is: %ld.\n", (long int)**fn );

	printf( "The value of printf is %ld.\n", (long int)printf );
	printf( "The function printf has address %ld.\n", (long int)&printf );

	printf( "The addres of x is: %ld.\n", (long int)&x );
        printf( "The address of fn is: %ld.\n", (long int)&fn );
    
}

