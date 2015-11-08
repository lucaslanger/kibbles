#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
	if( argc != 2 ){
		printf( "Usage: %s <string_to_sort>\n", argv[0] );
		return EXIT_FAILURE;
	}
	
	// Move through the string, sorting one character at a time
	char *next_spot_to_sort_ptr = argv[1];
	while( *next_spot_to_sort_ptr ){

		// Find the minimum character that we haven't yet sorted
		unsigned char min_val = 255;
		char *minimum_spot_ptr = NULL;
		char *candidate_minimum_ptr = next_spot_to_sort_ptr;
		while( *candidate_minimum_ptr != '\0' ){
			if( *candidate_minimum_ptr <= min_val ){
				min_val = *candidate_minimum_ptr;
				minimum_spot_ptr = candidate_minimum_ptr;
			}

			candidate_minimum_ptr++;
		}
		
		// Swap that character to the end of our sorted data
		char temp = *next_spot_to_sort_ptr;
		*next_spot_to_sort_ptr = *minimum_spot_ptr;
		*minimum_spot_ptr = temp;

		next_spot_to_sort_ptr++;		
	}

	printf( "The sorted version is %s.\n", argv[1] );
	return EXIT_SUCCESS;
}
