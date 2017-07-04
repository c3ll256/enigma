#ifndef THREAD_H
#define THREAD_H
#include <encoder.h>
#include <QThread>  
#include <QZXing.h>
class QCheckBox;
class QTextBrowser;
class Thread : public QThread
{
	Q_OBJECT
		signals :
	void endUpdateUI();
public:
	Thread(); //构造函数
	void stop(); //停止线程
	QString RootPath; // txt 或 bmp路径
	QString SavePath; // 保存路径
	bool Flag; // 编码，解码标志
	bool isSaveSideChecked;//是否是保存在旁边
	QZXing decoder;//创建解码实例	
	QCheckBox *chk;//控制ui
	QTextBrowser *tb;
	void run();
private:
	volatile bool stopeed; // 开关标志
	void enCode(); // 编码函数
	void deCode(); // 解码函数
	encoder QRres;
};
#endif // THREAD_H
