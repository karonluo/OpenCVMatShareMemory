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
	std::string video_url(argv[1]);
	// 开始分配内存
	int shm_id = shmget(memkey, SHAREMEMSIZE, IPC_CREAT|0644);
	uchar* ptr;
	ptr = (uchar*)shmat(shm_id, NULL, 0);
	printf("内存分配完成!\r\n");
	VideoCapture vc(video_url.c_str(), CAP_FFMPEG);
	if(vc.isOpened())
	{
		int data_len;
		Mat frame;
		for(;;)
		{
			usleep(25000);
			vc >> frame;
			if(!frame.empty())
			{
				std::memset(ptr, 0, data_len); // 清除内存中的数据
				data_len = frame.total() * frame.channels();
				printf("data_len = %d",data_len);
				std::memcpy(ptr, frame.data, data_len); // 将 frame 数据写入到 内存中
			}
		}
	}
	return 0;
}
