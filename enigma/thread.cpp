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
	endUpdateUI();
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
	int Count = 0, success = 0; // ��������
	QDateTime firstTime = QDateTime::currentDateTime(), lastTime = QDateTime::currentDateTime();//����ʱ��
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
		lastTime = nowtime;
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // ��ǰϵͳʱ���ʽ
		file.close(); // �ر��ļ�
		QRres.generateString(text); // ���ö�ά����Ϣ
		QString target_Path = (isSaveSideChecked ? fileInfo.path() + "/" : SavePath) + nowtime_text + (Count < 100 ? "0" : "") + (Count < 10 ? "0" : "") + QString::number(Count, 10) + ".bmp"; //���� bmp�ļ����ļ���
		nowtime_text = nowtime.toString("hh:mm:ss");
		Count++; // ���е���
		if (QRres.saveImage(target_Path))// �ļ�����ͼƬ��СΪ250*250
		{
			success++;
			if (chk->isChecked())//������������ʾ������Ϣ
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("�ֽ� �ɹ�"));
			}
		}
		else
		{
			if (chk->isChecked())
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("�ֽ� ʧ��"));
			}
		}
	}
	if (chk->isChecked())
	{
		tb->append(QStringLiteral("��ʱ:") + QString::number(firstTime.msecsTo(lastTime) % 60000 / 1000.0, 'f', 2) + QStringLiteral("�� ��") + QString::number(Count) + QStringLiteral("�� �ɹ���:") + QString::number((double)success / Count * 100, 'f', 2) + "%");
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
	int Count = 0, success = 0, flag = 0; // ��������
	QDateTime firstTime = QDateTime::currentDateTime(), lastTime = QDateTime::currentDateTime();//����ʱ��
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo;
		QString absoluteFilePath;
		QString nowtime_text;
		try
		{
			fileInfo = dirIterator.fileInfo();
			absoluteFilePath = fileInfo.absoluteFilePath(); // �ļ�����·��
			QString decodeData = decoder.decodeImageFromFile(absoluteFilePath); //���벢�����ı�
			QDateTime nowtime = QDateTime::currentDateTime(); //��ȡ��ǰϵͳʱ��
			lastTime = nowtime;
			nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // ��ǰϵͳʱ���ʽ
			QString target_Path = (isSaveSideChecked ? fileInfo.path() + "/" : SavePath) + nowtime_text + (Count < 100 ? "0" : "") + (Count < 10 ? "0" : "") + QString::number(Count, 10) + ".txt"; //����txt�ļ����ļ���
			QFile file(target_Path);
			file.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream in(&file);
			in << decodeData;//д������������ļ�
			file.flush();//ˢ���ļ�
			file.close();//�ر��ļ�
			Count++; // ���е���
			success++;
			nowtime_text = nowtime.toString("hh:mm:ss");
			if (chk->isChecked())//������������ʾ������Ϣ
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("�ֽ� �ɹ�"));
			}
		}
		catch (const std::exception&)
		{
			if (chk->isChecked())
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("�ֽ� ʧ��"));
			}
		}
	}
	if (chk->isChecked())
	{
		tb->append(QStringLiteral("��ʱ:") + QString::number(firstTime.msecsTo(lastTime) % 60000 / 1000.0, 'f', 2) + QStringLiteral("�� ��") + QString::number(Count) + QStringLiteral("�� �ɹ���:") + QString::number((double)success / Count * 100, 'f', 2) + "%");
	}
}