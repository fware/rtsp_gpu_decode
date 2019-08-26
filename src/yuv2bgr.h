/**  
 *  Copyright (c) 2017 LGPL, Inc. All Rights Reserved
 *  @author Chen Qian (chinahbcq@qq.com)
 *  @date 2017.04.22 14:32:02
 *  @author Fred Ware (fred.w.ware@gmail.com)
 *  @date 2019.08.24
 *	@brief modified work
 */
#ifdef __cplusplus
extern "C"{
#endif

int cvtColor(unsigned char *d_req,
		unsigned char *d_res,
		int resolution,
		int height, 
		int width, 
		int linesize);

#ifdef __cplusplus
}
#endif
