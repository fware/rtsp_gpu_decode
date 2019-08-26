#if use gcc, you need to link libstdc++ : gcc -lstdc++ xxx.cpp
#note:  Must use gcc version LESS THAN version 6
#note:  Tested on laptop (Ubuntu 18.04) with NVidia GeForce GTX 1060/PCIe/SSE2
CC = /usr/bin/g++-5
CFLAGS = -g 
CUDA_PATH = /usr/local/cuda
CUDA_FLAG = -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 -gencode arch=compute_37,code=sm_37 -gencode arch=compute_50,code=sm_50 -gencode arch=compute_52,code=sm_52 -gencode arch=compute_60,code=sm_60 -gencode arch=compute_60,code=compute_60
INCPATH = -Isrc/ffmpeg/include -Isrc/*.h -I$(CMAKE_PREFIX_PATH)/include -I$(CUDA_PATH)/include
LIBPATH = -Lsrc/ffmpeg/lib -L$(CMAKE_PREFIX_PATH)/lib
LIB = -lavcodec -lavfilter -lavutil -lswscale -lavdevice -lavformat -lswresample -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_gpu -lopencv_contrib 
all:
	$(CC) -o decode.o -c $(INCPATH) $(CFLAGS) src/decode.cpp
	$(CC) -o main.o -c $(INCPATH) $(CFLAGS) src/main.cpp
	nvcc -ccbin $(CC) -m64 $(CUDA_FLAG) -o yuv2bgr.o -c $(INCPATH) $(CFLAGS) src/yuv2bgr.cu
	nvcc -ccbin $(CC) -m64 $(CUDA_FLAG) main.o decode.o yuv2bgr.o $(CFLAGS) $(LIBPATH) $(LIB) -o server
clean:
	rm *.o
	rm server
