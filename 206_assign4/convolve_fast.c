#include <stdio.h>
#include <stdlib.h>
#include "fast_filter.h"

float* seperated_str_to_float_array(char* argv[], int start, int W){
    int sep = 0;
    int size = W*W;
    float* fa = (float*) malloc(sizeof(float)*size);
    for(int i=0;i<size;i+=1){
        fa[i] = atof(argv[start+i]);
    }
    /*for(int i=0;*s!='\0';i+=1){
        if (!sep){
            fa[i] = atof(s); //Careful that it doesnt try converting all at once
        }
        sep = 1 - sep;
        s = s + 1;
    }*/
    return fa;
}

int get_byte_size_of_file(FILE* f){
    int number_of_bytes;
    int read_code;
    while( (read_code = fgetc(f) ) != EOF){
        number_of_bytes += 1;
        printf("%c\n", (char) read_code);
    }
}

char* read_char_array_from_file(FILE* f){
    
}

int main(int argc, char* argv[]){      
    if (argc < 5){ printf("Not enough argumentsi, at least 4 must be provided (input_image, output_image, filter_width, filter_eights)"); }
    FILE* input_image = fopen(argv[1],"rb");
    int nbi = get_byte_size_of_file(input_image);  
    //char* input_chars = read_char_array_from_file(input_image);    
    FILE* output_image = fopen(argv[2], "rb");
    int filter_width = atoi(argv[3]);
    float* filter_weight = seperated_str_to_float_array(argv, 4, filter_width); 

    doFiltering( input_image, filter_width, filter_weight, output_image);

    free(filter_weight);
    fclose(input_image);
    fclose(output_image);
    return 0;
}


