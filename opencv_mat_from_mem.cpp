#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <unistd.h>
// include 用于共享内存访问的 包含文件
#include <sys/ipc.h>
#include <sys/shm.h>
// 固定分配 5m 内存，用于存储视频帧
#define SHAREMEMSIZE 52428800
using namespace cv;
int main(int args, char** argv)
{
	key_t memkey = 1024;
	// 正式开发的时候，根据视频源配置，内存ID 从 1024 开始依次递增，验证开发的时候，只默认一个视频源
	// 开始分配内存
	int shm_id = shmget(memkey, SHAREMEMSIZE, IPC_CREAT|0644);
	uchar* ptr;
	int frame_count=0;
	for(;;)
	{
		usleep(25000);
		ptr = (uchar*)shmat(shm_id,NULL,0);
		if(NULL!=ptr)
		{
			Mat frame(cv::Size(1920,1080), CV_8UC3);
			frame.data = ptr;
			if(!frame.empty())
			{
				cv::imwrite(std::string("./test_from_sharemem_" + std::to_string(frame_count++) + ".jpg").c_str(),frame);
			}
		}
	}
	return 0;
}
