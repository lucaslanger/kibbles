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
        printf("Not enough arguments, at least 4 must be provided (input_image, output_image, filter_width, filter_eights)");
        return 1; 
    }
    FILE* input_image = fopen(argv[1],"rb");
    if (input_image == NULL){
        printf("Input image not found!\n");
        return 1;
    } 
    //custom reading
    int nbi = get_byte_size_of_file(input_image);  
    
    char* chars_read = (char*) malloc( sizeof(char)*(nbi+1) );
    read_char_array_from_file(input_image, nbi, chars_read);     
    chars_read[nbi] = '\0';
    
    //With stdio
    //char* chars_read = NULL;
    //fseek(input_image, 0, SEEK_END);
    //int nbi = ftell(input_image);
    //rewind(fp);
    //chars_read = (char*) malloc( (nbi+1)*sizeof(char) );
    //fread(chars_read, nbi, input_image);
    //chars_read[nbi] = '\0';

    FILE* output_image = fopen(argv[2], "wb+");
    char* output_chars = (char*) malloc( sizeof(char)*(nbi+1) );   
 
    int filter_width = atoi(argv[3]);
  
    float* filter_weights = (float*) malloc(sizeof(float)*filter_width*filter_width);
    seperated_str_to_float_array(argv, filter_weights, 4, filter_width);    
    
    printf("The number of bytes to write, filterwidth: %d %d\n", nbi, filter_width);
    debug("about to filter");
    doFiltering(chars_read, filter_weights, filter_width, output_chars);
    debug("filter done");
    
    fwrite(output_chars, 1, nbi+1, output_image); 

    free(chars_read);
    free(output_chars);
    free(filter_weights);

    fclose(input_image);
    fclose(output_image);
    return 0;
}


