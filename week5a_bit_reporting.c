/* File week5_bit_reporting.c 
   Was covered in COMP 206 on Oct 5, 2015
   
   Uses the bit-wise operations left-shift and
   bitwise logical AND to sequentially check the
   bits within a single byte (character).

   Prints the results to screen and ensures
   the sum of the bitwise values adds up to the
   original number.
 
   Author: David Meger
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char c = 42;
	int bit_number;
	int bit_contribution;
	int total_value = 0;

	for( bit_number=0; bit_number<8; bit_number++ )
	{
		bit_contribution = c & (1<<bit_number );

		printf( "bit %d of c contributes %d.\n", bit_number, bit_contribution );

		total_value += bit_contribution;
	}

	printf( "The total value of c was %d\n.", total_value );

	return EXIT_SUCCESS;
}
