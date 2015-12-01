#include <stdio.h>
#include <stdlib.h>
#include "fast_filter.h"

void debug(char* s);

void seperated_str_to_float_array(char* argv[], float* f_array, int start, int W){
    int sep = 0;
    int size = W*W;
    for(int i=0;i<size;i+=1){
        f_array[i] = atof(argv[start+i]);
    }
}

int get_byte_size_of_file(FILE* f){
    int read_code;
    int nob=0;
    while( (read_code = fgetc(f) ) != EOF ){
        //printf("%ld\n", (long int) &f );
        nob+=1;
    }
    return nob;
}

void read_char_array_from_file(FILE* f, int size, char* chars){
    int i;    
    for (i=0; i<size; i+=1){
        chars[i] = fgetc(f);
    }
}

void debug(char* s){
    int d;
    printf("%s\n", s);
    scanf("%d", &d);
}

int main(int argc, char* argv[]){      
    if (argc < 5){ 
        printf("Not enough arguments, at least 4 must be provided (input_image, output_image, filter_width, filter_weights)");
        return 1; 
    }
    FILE* input_image = fopen(argv[1],"rb");
    if (input_image == NULL){
        printf("Input image not found!\n");
        return 1;
    }
    FILE* output_image = fopen(argv[2], "wb+");
    
    //########## Custom char loading (for fun) ########## 
    int nbi = get_byte_size_of_file(input_image);
    fseek(input_image, 0, SEEK_SET);  
    char chars_read[nbi];
    read_char_array_from_file(input_image, nbi, chars_read);     
    
    ///########## Built-in char loading (no fun) ########## 
    /*
    char* chars_read = NULL;
    fseek(input_image, 0, SEEK_END);
    int nbi = ftell(input_image);
    rewind(input_image);
    chars_read[nbi];
    fread(chars_read, sizeof(char), nbi, input_image);
    */
  
    char output_chars[nbi]; 

    int filter_width = atoi(argv[3]);
    int num_weights = filter_width * filter_width;
    if( (argc-4) != num_weights ){
        printf("Not enough filter weights!\n");
        return 1;
    }

    float filter_weights[filter_width*filter_width];
 
    seperated_str_to_float_array(argv, filter_weights, 4, filter_width);    
    
    doFiltering(chars_read, filter_weights, filter_width, output_chars);
    
    fwrite(output_chars, 1, nbi, output_image); 
    fputc('\0', output_image);

    fclose(input_image);
    fclose(output_image);
    return 0;
}


