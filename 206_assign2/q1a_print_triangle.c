#include<stdio.h>

void printTriangle(int n){
	if (n<1){
		printf("Height is too small!");	
	}

	int i=0;
	while(i<n){
		int l = (2*n)+1;
		char line[l];
		int j=0;
		int L=n-1-i;
		int stars=2*i+1;
		while(j<L+stars){
			if (j<L){
				line[j]=' ';
			}
			else{
				line[j]='*';			
			}
			j=j+1;		
		}
		line[l-1]='\0';
		printf("%s\n",line);
		i=i+1;	
	}
}

int main(int argc, char *argv[]){

	int n = atoi(argv[1]);
	if (n==0){
		printf("ERROR:Height must be a non-zero integer");
		return 0;
	}
	//printf("%d\n",n);
	printTriangle(n);
	return 0;
}

