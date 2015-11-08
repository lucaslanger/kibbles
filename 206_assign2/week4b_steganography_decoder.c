/* The file week4b_steganography_decoder.c
   was demonstratd in COMP 206 on Sept 30th.
   
   At the time, we had not covered all of the functions here,
   so do not worry if you don't understand all the code yet.
   
   We will be working through what's needed to understand this by 
   the first week in October. For now, you can use it to get
   ahead.
   
   Build this file with: 
   gcc -o decoder week4b_steganography_decoder.c
   
   When both this, and the paired encoder are compiled, 
   then you can pass a message using a bmp file with these commands:
   
   $ ./encoder mario_16_bit.bmp mario_message.bmp Your Message Here.
   $ ./decoder mario_message.bmp
   
   Make sure to view the original mario bitmap and the 
   mario_message file to verify that you cannot visually detect the change.
   
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

	for( i=0; i < max_msg_size; i++ )
		msg[i] = 0;

	while( ( c = fgetc( img_in )) != EOF ){
		if( img_idx >= bmp_header_size ){
			char bit_mask = 0;
			if( ( c & 1 )  > 0 )
				bit_mask |= 1 << bit_idx;

			msg[msg_idx] |= bit_mask;

			bit_idx++;

			if( bit_idx >= 8 ){
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

