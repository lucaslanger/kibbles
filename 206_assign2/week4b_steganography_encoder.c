/* The file week4b_steganography_encoder.c
   was demonstratd in COMP 206 on Sept 30th.
   
   At the time, we had not covered all of the functions here,
   so do not worry if you don't understand all the code yet.
   
   We will be working through what's needed to understand this by 
   the first week in October. For now, you can use it to get
   ahead.
   
   Build this file with: 
   gcc -o encoder week4b_steganography_encoder.c
   
   When both this, and the paired decoder are compiled, 
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
	int curr_message_position=0;
	int read_code;
	int msg_idx = 0;
	int img_idx = 0;
	int bit_idx = 0;
	char c;
	char msg[max_msg_size];
	FILE *img_in = NULL;
	FILE *img_out = NULL;

	if( argc < 3 ){
		printf( "Usage: %s source_bmp output_bmp message.\n", argv[0] );
		return 1;
	}
	
	img_in = fopen( argv[1], "rb" );
	if( img_in == NULL ){
		printf( "Could not open the input image file.\n" );
		return 1;
	}

	img_out = fopen( argv[2], "wb" );
	if( img_out == NULL ){
		printf( "Could not open the output file.\n" );
		return 1;
	}	

	for( i=3; i<argc; i++ ){
		strcpy( msg+curr_message_position, argv[i] );
		curr_message_position += strlen(argv[i]);

		if( i<argc-1 )
			msg[curr_message_position] = ' ';
			curr_message_position++;
	}
	msg[curr_message_position] = '\0';

	while( ( read_code = fgetc( img_in )) != EOF ){
		c = (char)read_code;

		if( img_idx >= bmp_header_size && msg_idx <= strlen( msg ) ){
			char bit_mask = 1 << bit_idx;
			
			if( ( msg[msg_idx] & bit_mask) > 0 )
				c |= 1;
			else
				c &= 254;

			bit_idx++;

			if( bit_idx >= 8 ){
				bit_idx = 0;
				msg_idx++;
			}			
		}

		fputc( c, img_out );
		img_idx++;
	}

	printf( "I have hidden the secret within an image of %d bytes.\n", img_idx );

	fclose(img_in);
	fclose(img_out);

	return 0;
}

