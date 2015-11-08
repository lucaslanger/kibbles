#include <stdio.h>
 
#define SIZE (1 << 2)

char getFrom2dCharArray(char *p, int w, int i, int j){
	return p[w*j+i];
}

void putTo2dCharArray(char *p, int w, int i, int j, char value){
	p[w*j+i] = value;
}

int rUD(int a, int d){
	return (a + (d-1))/d;
}

void fill_sierpinski(char *m, int w, int sx, int sy, int lx, int ly, int l ){
	if (l==0){
		//printf("Base case. sx:%d, sy:%d, lx:%d, ly:%d \n", sx, sy, lx, ly);	
		int j=0;
		while(j<ly){
			int i=0;
			int L=((lx+1)/2)-1-j;
			int stars=(2*j)+1;
			int tl=L+stars;
			///printf("%d,%d,%d\n",L,stars,tl);
			while(i<tl){
				if (i>=L){
					//printf("Filling:%d,%d\n",sx+i, sy+j);
					putTo2dCharArray(m, w, sx+i, sy+j, '*');		
				}
				i=i+1;			
			}
			j=j+1;
		}
	}
	else{		
		fill_sierpinski(m, w, sx+rUD(lx,4)  ,sy       ,(lx/2),(ly/2),l-1);
		fill_sierpinski(m, w, sx            ,sy+(ly/2),(lx/2),(ly/2),l-1);
		fill_sierpinski(m, w, sx+rUD(lx,2)  ,sy+(ly/2),(lx/2),(ly/2),l-1);

	}
}

void printMatrix(char *m, int h, int w){
	int j=0;
	while(j<h){
		char s[w+1];
		int i=0;
		while(i<w){
			s[i] = getFrom2dCharArray(m, w, i, j);
			i=i+1;
		}
		s[w] = '\0';
		printf("%s\n",s);
		j=j+1;
	}
}

void debug(){
	printf("debugSegFault\n");
	int t=0;
	scanf("%d",&t);
}

int print_sierpinksi(int h, int l){
	int w=2*(h-1)+1;
	char matrix[h*w];
	char *m = matrix;
	
	int j=0;

	while(j<h){
		int i=0;
		while(i<w){
			//debug();
			putTo2dCharArray(m,w,i,j,' ');
			i=i+1;		
		}	
		j=j+1;
	}

	fill_sierpinski(m, w, 0, 0, w, h, l);
	printMatrix(m, h, w);
	//What is the difference between using & on arrays and using pointers?
}

/*
int ipow(int a, int b){
	if (b==0){
		return 1;
	}
	else if(b%2==1){
		return a*ipow(a,b/2);
	}
	else{
		return ipow(a,b/2);
	}
}*/

int main(int argc, char *argv[])
{
	int height = atoi(argv[1]);
	int fractal_levels = atoi(argv[2]);

	if (height==0){
		printf("ERROR:Height must be a non-zero integer\n");
		return 0;
	}

	if (fractal_levels <0){
		printf("ERROR:Fractal Levels too small\n");
		return 0;	
	}

	if (height < 1){
		printf("ERROR: Height too small.\n");
		return 0;	
	}

	int bitsToCheck = (1 << fractal_levels)-1;
	int result = (bitsToCheck & height);

	//printf("%d,%d\n", bitsToCheck,height);
	if (result!=0){
		printf("ERROR:Height not divisible by 2^fractal_levels.\n");
		return 0;
	}
	
	print_sierpinksi(height, fractal_levels);

}


