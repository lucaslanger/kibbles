#include <stdlib.h>
#include <stdio.h>

int main() 
{
	const int SENTINEL = 0;
	int i;
	int maxi;
	printf("Enter integers, 0 to stop\n");

	if(fscanf(stdin, "%d", &maxi)!= 1 || maxi == SENTINEL){
		printf("No value read\n");
		return EXIT_SUCCESS;
 	}
	
	while(1) {
		if(scanf("%d", &i) != 1 || i == SENTINEL){
      			break;
      		}
   
		if(i > maxi) maxi = i;
 	};

	printf("The largest value: %d\n", maxi);
	return EXIT_SUCCESS;
}
