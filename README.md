### 转载声明

若需要将代码放到其他代码平台和论坛，请提供免费的下载方式并标注该代码的 github 的链接地址。

如放到 CSDN 时，请设置 0 积分下载。

感谢！

### 将 OpenCV Mat 存 取 共享内存 例子

该例子的作用，用于一个视频源的视频数据提供给多个进程使用。

使用内存文件进行管理，只能用于单机，但性能优于Redis进行内存管理。

例子代码依赖：OpenCV 4.2.0

执行编译脚本：

~~~bash
./build_opencv_mat_mem.sh
~~~

生成:

opencv_mat_to_mem 和 opencv_mat_from_mem 两个可执行文件。

~~~bash
# 执行 opencv_mat_to_mem 可以将视频源流中的视频帧图（mat）传输到 共享内存
./opencv_mat_to_mem <rtsp_address|video_file>
~~~

~~~bash
# 重新开一个窗口，执行 opencv_mat_from_mem 可以将共享内存中的视频帧(mat)数据，放入到新建的mat对象中，并转存到 I/O 磁盘上面
./opencv_mat_from_mem
~~~


在操作系统 Ubuntu 16.04 中测试通过
