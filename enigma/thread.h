#ifndef THREAD_H
#define THREAD_H
#include <encoder.h>
#include <QThread>  

class Thread : public QThread
{
	Q_OBJECT
public:
	Thread(); //���캯��
	void stop(); //ֹͣ�߳�
	QString RootPath; // txt �� bmp·��
	QString SavePath; // ����·��
	bool Flag; // ���룬�����־
	// ���̹߳���
	void run();
private:
	volatile bool stopeed; // ���ر�־
	void Code(); // ���뺯��
	void DeCode(); // ���뺯��
	encoder QRres;
};
#endif // THREAD_H
