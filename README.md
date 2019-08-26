# about
GPU supported decoding of RTSP stream

## brief
Demonstrates decoding a RTSP video stream using GPU hardware for decoding, color conversion, and resizing to 1080p resolution.  It is an extension of existing open source code.  FFMPEG is employed with integrated GPU support for video decoding the RTSP stream.  Separate cuda code is used for color conversion.  OpenCV GPU-accelerated resizer is employed for resizing to 1080p.

## build
make 

## run
./server

## dependency
* ffmpeg 3.3  (prebuilt libraries included)
* tested with cuda 9.0 (custom install)
* opencv 2.4.13.6  (custom built for target pc, Ubuntu 18.04, NVidia 1060 GPU)

```
export CMAKE_PREFIX_PATH=/path/to/opencv/lib
export LD_LIBRARY_PATH=$CMAKE_PREFIX_PATH/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/path/to/ffmpeg/lib:$LD_LIBRARY_PATH
```
