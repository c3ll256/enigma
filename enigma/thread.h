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
	Thread(); //���캯��
	void stop(); //ֹͣ�߳�
	QString RootPath; // txt �� bmp·��
	QString SavePath; // ����·��
	bool Flag; // ���룬�����־
	bool isSaveSideChecked;//�Ƿ��Ǳ������Ա�
	QZXing decoder;//��������ʵ��	
	QCheckBox *chk;//����ui
	QTextBrowser *tb;
	void run();
private:
	volatile bool stopeed; // ���ر�־
	void enCode(); // ���뺯��
	void deCode(); // ���뺯��
	encoder QRres;
};
#endif // THREAD_H
