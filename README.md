### 将 OpenCV Mat 存 取 共享内存 例子

该例子的作用，用于一个视频源的视频数据提供给多个进程使用。


使用内存文件进行管理，只能用于单机，但性能优于Redis进行内存管理。

例子代码依赖：OpenCV 4.2.0

在操作系统 Ubuntu 16.04 中测试通过
