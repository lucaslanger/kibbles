/* The file steganography_decoder_commented.c
   is a modified version of the original file
   with verbose comments to help with Assignment 2.
      
   Author: David Meger
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[] )
{
	const int bmp_header_size = 54;
	const int max_msg_size = 1000;

	int i;
	int c;
	int img_idx = 0;
	int msg_idx = 0;
	int bit_idx = 0;

	char msg[max_msg_size];
	FILE *img_in = NULL;
	
	img_in = fopen( argv[1], "rb" );

	if( img_in == NULL ){
		printf( "Could not open the input image file.\n" );
		return 1;
	}

  // This for loop sets the character string initially to all 0's
  // This is to save us some trouble in having to explicitly zero-out
  // bits when we're decoding. Since all bits are set to 0 at first, we
  // now will only need to flip some of them to 1's as needed
	for( i=0; i < max_msg_size; i++ )
		msg[i] = 0;

  // This while loop is the main decoding action. We loop through the image
  // and extract the lowest-order bits from each byte into msg
	while( ( c = fgetc( img_in )) != EOF ){
	
	  // The encoder did not touch the BMP header, so we also have to skip 
	  // those bytes here
		if( img_idx >= bmp_header_size ){
		
		  // This is how to check the lowest-order bit (from class-notes)
			if( ( c & 1 )  > 0 )
			  // If it was 1, use OR to set msg where we next need to write 
			  // into msg to be 1 (OR does not change any of its other bits)
				msg[msg_idx] |= 1 << bit_idx;
		  // Note that no else was needed because msg starts as 0's

      // Move on to the next bit
			bit_idx++;

      // When we're done all 8 bits in a byte, move on to the next byte
			if( bit_idx >= 8 ){
			  // However, we know we're done reading the message when we see the
        // null character '\0'
				if( msg[msg_idx] == '\0' )
					break;
				bit_idx = 0;
				msg_idx++;
			}			
		}
		
		img_idx++;
	}

	printf( "Processed %d bytes.\n", img_idx );
	printf( "The secret message is: %s\n", msg );

	fclose(img_in);

	return 0;
}

