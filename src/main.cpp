#include <stdio.h>
#include <stdlib.h>
#include "decode.h"
#include <pthread.h> 

#define TEST
static int NUM=1;

int cpu_callback(const int flag, cv::Mat &image) {
#ifdef TEST
	printf("get cpu image, image.width:%d, image.height:%d\n", image.cols, image.rows);
	char filename[100] = {0};
	if (flag == 1) {
		snprintf(filename, 100, "./image/1_%d.jpg", NUM ++);	
	} else {
		snprintf(filename, 100, "./image/2_%d.jpg", NUM ++);	
	}
	printf("filename:%s\n", filename);
	cv::imwrite(filename, image);
#endif
	return 0;
}


int gpu_callback(const int flag, cv::gpu::GpuMat &image) {
#ifdef TEST
	printf("get gpu image, image.width:%d, image.height:%d\n", image.cols, image.rows);
	cv::Mat mat(image.cols, image.rows, CV_8UC3);
	image.download(mat);
	char filename[100] = {0};

	if (flag == 1) {
		snprintf(filename, 100, "./image/1_%d.jpg", NUM ++);	
	} else {
		snprintf(filename, 100, "./image/2_%d.jpg", NUM ++);	
	}
	printf("filename:%s\n", filename);
	cv::imwrite(filename, mat);
	//cv::imshow("press ESC to exit", mat);
	//cv::waitKey(0);
#endif
	return 0;
}


void *videoHandle1(void *) {
	std::string rtsp_addr = "rtsp://192.168.0.5:8554/stream";
	printf("open video:%s\n", rtsp_addr.c_str());
	
	int flag = 1;	
	bool use_hw_decode = true; 
	bool only_key_frame = false;
	ffmpeg_video_decode(rtsp_addr, flag, cpu_callback, gpu_callback, use_hw_decode, only_key_frame);
}


void *videoHandle2(void *) {
	std::string rtsp_addr = "rtsp://192.168.0.5:8554/stream";
	printf("open video:%s\n", rtsp_addr.c_str());
	
	bool use_hw_decode = true;
	bool only_key_frame = false;
	int flag = 2;
	ffmpeg_video_decode(rtsp_addr, flag, cpu_callback, gpu_callback, use_hw_decode, only_key_frame);
}


int main() {
	//ffmpeg default initialization
	ffmpeg_global_init();
	
	//thread mode
	pthread_t t1,t2;
	pthread_create(&t1, NULL, videoHandle1, NULL);
	pthread_create(&t2, NULL, videoHandle2, NULL);  //Note:  Can run decoders on multiple threads
	                                                //       if there is need to perform separate video frames 
	                                                //       in parallel.

	getchar();
	
	return 0;
}
