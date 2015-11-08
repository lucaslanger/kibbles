#include<stdio.h>
#include<stdlib.h>
int main(){

	long c;
	for(c=1; c!=0;c=c<<1){
		printf("%d\n", c);
	} 
	printf("%d\n", sizeof(c));

	return EXIT_SUCCESS;
}
