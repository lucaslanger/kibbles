//Compute the highest Peak to the right for any index i.
//This is useful beiause it will tell you for any i will give you the peak index to the right. Then with the running_sums precomputed you can obtain the sum by taking the difference
//With this we will also need running_sums

//The tricky part is getting the biggest peak to the right, how do we do this without linear time? Well if we know the biggest peak to the right at the bottom of the hill, it will be the same until we pass that big hill

#include <stdio.h>

void computeRunningSum(int* A, int* R, int size_A){
    int i; 
    int prev = 0;   
    for (i=0; i<size_A; i+=1){
        R[i] = A[i] + prev;
        prev = R[i];
    } 
}

int max(int a, int b){
    if (a>=b){
        return a;
    }
    else{
        return b;    
    }
}

int arg_max(int a, int b, int i, int j){
    if ( max(a,b) == a ){
        return i;
    }
    else{
        return j;
    }
}

int get_rng_arg_max(int* A, int *R, int (*f)(int*,int,int), int start_index, int end_index){ 
    int argmax = 0;
    int max = 0;
    int v;
    int j;
    for(j=start_index; j<end_index; j+=1){   
        v = (*f)(R, start_index, j);
        argmax = arg_max(max, v, argmax, j);
        if (argmax==j){ max=v; } 
    }
    return argmax;
}

int get_intermediate_sum(int *R, int i, int j){ return R[j] - R[i]; }

int find_biggest_inner_sum(int* A, int size_A){
    int R[size_A];
    computeRunningSum(A, R, size_A);

    int best_peak_index = get_rng_arg_max(A, R, get_intermediate_sum, 0, size_A);
    int opt_sum = get_intermediate_sum(R, 0, best_peak_index);
    int i;
    for (i=1; i<size_A; i+=1){
        if (i >= best_peak_index){
            best_peak_index = get_rng_arg_max(A, R, get_intermediate_sum, i, size_A);
            opt_sum = max( opt_sum, get_intermediate_sum(R, i, best_peak_index) );
        }
    }
    return opt_sum;
}



int main(){
    printf("TO-fix: Make R have size_A+1 entries instead of A\n");
    int testArray[12] = {5,-1,7,-10,5,10,5,-3,-5,6,10,2};
    int opt = find_biggest_inner_sum(testArray, 12);
    printf("The optimal inner sum was: %d\n", opt);
}
