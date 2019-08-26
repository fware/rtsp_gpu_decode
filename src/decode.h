/**  
 *  Copyright (c) 2017 LGPL, Inc. All Rights Reserved
 *  @author Chen Qian (chinahbcq@qq.com)
 *  @date 2017.04.18 11:32:44
 *  @author Fred Ware (fred.w.ware@gmail.com)
 *  @date 2019.08.24
 *	@brief modified work
 **/
#include <string>
#include <time.h>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/opengl_interop.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/gpu/gpu.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>



#ifdef __cplusplus
extern "C"{
#endif

#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavutil/error.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/fifo.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libswresample/swresample.h"
#include "libavfilter/avfilter.h"
#include "libavfilter/avfiltergraph.h"
#include "libavfilter/buffersink.h"
#include "libavfilter/buffersrc.h"

/**
 * ffmpeg intializer
 *
 * @return success 0
 */
int ffmpeg_global_init();

/**
 * ffmpeg video decode wrapper. Controls and manipulates decoded content
 * 
 * @param addr 
 * @param flag 
 * @param cpu_cb cpu 
 * @param gpu_cb gpu 
 * @param use_hw_decode GPU-true, CPU-false
 * @param only_key_frame 
 *
 * @return success-0
 */
int ffmpeg_video_decode(const std::string &addr, 
		int flag,
		int (*cpu_cb)(const int type, cv::Mat&),
		int (*gpu_cb)(const int type, cv::gpu::GpuMat &),
		bool use_hw_decode = true, 
		bool only_key_frame = false);

#ifdef __cplusplus
}
#endif

