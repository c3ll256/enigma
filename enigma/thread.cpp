#include "thread.h"
#include <qfiledialog.h>
#include <QFile>
#include "enigma.h"

Thread::Thread()
{
	stopeed = false;
	connect(this, SIGNAL(ResetSlot(QString, QString)), this, SLOT(ReceiveSlot(QString, QString)));
}

void Thread::run()
{
	if (Flag)
	{
		enCode(); // ���뺯��
	}
	else {
		deCode(); // ���뺯��
	}
	
}

void Thread::stop()
{
	stopeed = true;
}

void Thread::enCode() // ���̣߳����뺯��
{
	QStringList filters;
	QString path = Thread::RootPath;
	SavePath = SavePath + "/";
	filters << QString("*.txt");
	QDirIterator dirIterator(path, filters, QDir::Files | QDir::NoSymLinks,
	QDirIterator::Subdirectories);
	QStringList stringList;
	int Count = 000; // ��������
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo = dirIterator.fileInfo();
		QString absoluteFilePath = fileInfo.absoluteFilePath(); // �ļ�����·��
		QFile file(absoluteFilePath); // ���ļ�
		file.open(QIODevice::ReadOnly); // ���ļ�
		QTextStream in(&file);
		QString text = in.readAll(); // ��ȡ�ļ����ݲ����浽text��
		QDateTime nowtime = QDateTime::currentDateTime(); //��ȡ��ǰϵͳʱ��
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // ��ǰϵͳʱ���ʽ
		file.close(); // �ر��ļ�
		QRres.generateString(text); // ���ö�ά����Ϣ
		QString target_Path = SavePath + nowtime_text + QString::number(Count, 10) + ".bmp"; //���� bmp�ļ����ļ���
		Count++; // ���е���
		QRres.saveImage(target_Path, 252); // �ļ�����ͼƬ��СΪ252*252
		stringList.append(absoluteFilePath);
	}
}

void Thread::deCode() // ���̣߳����뺯��
{
	QStringList filters;
	QString path = Thread::RootPath;
	SavePath = SavePath + "/";
	filters << QString("*.bmp");
	QDirIterator dirIterator(path, filters, QDir::Files | QDir::NoSymLinks,
		QDirIterator::Subdirectories);
	QStringList stringList;
	int Count = 000; // ��������
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo = dirIterator.fileInfo();
		QString absoluteFilePath = fileInfo.absoluteFilePath(); // �ļ�����·��
		QString decodeData = decoder.decodeImageFromFile(absoluteFilePath); //���벢�����ı�
		QDateTime nowtime = QDateTime::currentDateTime(); //��ȡ��ǰϵͳʱ��
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // ��ǰϵͳʱ���ʽ
		QString target_Path = SavePath + nowtime_text + QString::number(Count, 10) + ".txt"; //����txt�ļ����ļ���
		QFile file(target_Path);
		file.open(QIODevice::WriteOnly | QIODevice::Text);//�����ļ�
		QTextStream in(&file);
		in << decodeData;//д������������ļ�
		file.flush();//ˢ���ļ�
		file.close();//�ر��ļ�
		Count++; // ���е���
		stringList.append(absoluteFilePath);
	}
}
