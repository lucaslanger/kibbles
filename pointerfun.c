#include<stdio.h>

int main(){

	return 0;
}

void pointerfun(){
	int *p;
	int a = 256;
	p = &a;
	
	int b = *p;
	p = &b;
	*p = 13;

	printf("%d %d\n", a, b);
}

void arrayfun(){
	int a[3] = {1,2,3};
	int *p = a;
	a[1] == p[1]
	*(a+2) == *(p+2)

	special rule a == &(a[0])
	*(p+i) = p[i]
}



