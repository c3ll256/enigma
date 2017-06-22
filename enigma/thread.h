#ifndef THREAD_H
#define THREAD_H
#include <encoder.h>
#include <QThread>  

class Thread : public QThread
{
	Q_OBJECT
public:
	Thread(); //构造函数
	void stop(); //停止线程
	QString RootPath; // txt 或 bmp路径
	QString SavePath; // 保存路径
	bool Flag; // 编码，解码标志
	// 子线程功能
	void run();
private:
	volatile bool stopeed; // 开关标志
	void Code(); // 编码函数
	void DeCode(); // 解码函数
	encoder QRres;
};
#endif // THREAD_H
