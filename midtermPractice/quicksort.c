#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_array_size(char *a){
	int elements =0;
	int i=0;
	int c;
	int streak=0;
	while( c=*(a+i) != '\0'){
		if(c!=','){
		
		}
		i++;
	}
	return elements
}

int main(int argc, char *argv){
	if(argc != 2){
		printf("User should pass one input, that is the array to sort\n")		
	}
	char *minspot;
	char *spot_to_sort = argv[1];
	find_minimum( &minspot); //this function call will modify the minspot pointer
	
}
