/* File week5_endianness_test.c 
   Was covered in COMP 206 on Oct 5, 2015
   
   Explores the byte-ordering of integers 
   on the system it's run on. By using a shorter
   pointer than the target data-type, we can access
   the int it one byte at a time. Most Unix systems
   are "Little Endian".
 
   Author: David Meger
*/

//Output in 1 1 0 0, which suggests big endian

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a = 259; //2^8 + 1
	char *p = (char*)&(a);

	printf( "The value at p is %d.\n", *p );
	printf( "The value at p+1 is %d.\n", *(p+1) );
	printf( "The value at p+2 is %d.\n", *(p+2) );
	printf( "The value at p+3 is %d.\n", *(p+3) );
	
}

