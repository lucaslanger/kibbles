# Remember to compile the library first and set your 
# LD_LIBRARY_PATH environment variable
import os
import ctypes
import sys
clib = ctypes.cdll.LoadLibrary("./libfast_filter.so")

filter_width = int( sys.argv[3] )
filter_weights = []

for i in range(0,filter_width*filter_width):
    filter_weights.append( float(sys.argv[4+i] ))

CFloatArrayType = ctypes.c_float * len(filter_weights)
cfloat_array_instance = CFloatArrayType( *filter_weights )

with open( sys.argv[1], 'rb' ) as img_in:
    img_data = img_in.read()

filesize = os.path.getsize(sys.argv[1])

datain = (ctypes.c_ubyte * filesize)(*[ctypes.c_ubyte(ord(c)) for c in img_data])
dataout = (ctypes.c_ubyte * filesize)() 

clib.doFiltering(datain, cfloat_array_instance, filter_width, dataout )
with open('somefile.bmp', 'wb') as f:
    f.write(dataout)
