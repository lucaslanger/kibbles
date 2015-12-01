import ctypes
import sys
fast_filter = ctypes.cdll.LoadLibrary("./libfast_filter.so")

def main():
    if( len(sys.argv) < 4):
        print "Too few arguments"
        return 1;
    input_image = sys.argv[1]
    output_image = sys.argv[2]
    num_weights = int(sys.argv[3])**2
    weights = [float(f) for f in sys.argv[4:]]
    if len(weights) != num_weights:
        print "Invalid input: Please enter the correct number of weights: ", num_weights   
        return 1 
    chars_read = []
    with open(input_image,"rb") as f:
        while True:
            c = f.read(1)
            if c == "":
                break
            chars_read.append( ord(c) )
            
    CFloatArrayType = ctypes.c_float * num_weights
    c_weights = CFloatArrayType(*weights)
    
    CByteArrayType = ctypes.c_ubyte * len(chars_read)
    c_chars_read = CByteArrayType(*chars_read) 
    c_out_data = CByteArrayType()

    fast_filter.doFiltering(c_chars_read, c_weights, num_weights, c_out_data )
    print weights, num_weights
    with open(output_image,"wb+") as f_out:
        f_out.write(c_out_data)

main()
