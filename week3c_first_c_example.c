/* File week3c_first_c_example.c 
   Was covered in COMP 206 on Sept 25, 2015
   
   This file just shows a very basic C program,
   but does illustrate how to interact with arguments
   and to print to the screen.
   
   Author: David Meger
*/

#include <stdio.h>

int main(int argc, char *argv[] ){
	printf( "Hello world.\n" );
	printf( "Thank you for providing me with %d arguments.\n", argc );
	printf( "My favorite is argument is the last one: %s.\n", argv[argc-1] );
	return 0;
}

/*
#include <stdio.h>

int main(int argc, char *argv[] )
{
	printf( "Hello world.\n" );
  printf( "Thank you for providing me with %d arguments.\n", argc );
  printf( "My favorite is argument %s.\n", argv[argc-1] );
  
	return 0;
}
*/
