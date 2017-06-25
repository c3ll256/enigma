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
		enCode(); // 编码函数
	}
	else {
		deCode(); // 解码函数
	}
	
}

void Thread::stop()
{
	stopeed = true;
}

void Thread::enCode() // 子线程，编码函数
{
	QStringList filters;
	QString path = Thread::RootPath;
	SavePath = SavePath + "/";
	filters << QString("*.txt");
	QDirIterator dirIterator(path, filters, QDir::Files | QDir::NoSymLinks,
	QDirIterator::Subdirectories);
	QStringList stringList;
	int Count = 000; // 递增序列
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo = dirIterator.fileInfo();
		QString absoluteFilePath = fileInfo.absoluteFilePath(); // 文件完整路径
		QFile file(absoluteFilePath); // 打开文件
		file.open(QIODevice::ReadOnly); // 打开文件
		QTextStream in(&file);
		QString text = in.readAll(); // 读取文件内容并保存到text中
		QDateTime nowtime = QDateTime::currentDateTime(); //获取当前系统时间
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // 当前系统时间格式
		file.close(); // 关闭文件
		QRres.generateString(text); // 设置二维码信息
		QString target_Path = SavePath + nowtime_text + QString::number(Count, 10) + ".bmp"; //保存 bmp文件的文件名
		Count++; // 序列递增
		QRres.saveImage(target_Path, 252); // 文件名，图片大小为252*252
		stringList.append(absoluteFilePath);
	}
}

void Thread::deCode() // 子线程，解码函数
{
	QStringList filters;
	QString path = Thread::RootPath;
	SavePath = SavePath + "/";
	filters << QString("*.bmp");
	QDirIterator dirIterator(path, filters, QDir::Files | QDir::NoSymLinks,
		QDirIterator::Subdirectories);
	QStringList stringList;
	int Count = 000; // 递增序列
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo = dirIterator.fileInfo();
		QString absoluteFilePath = fileInfo.absoluteFilePath(); // 文件完整路径
		QString decodeData = decoder.decodeImageFromFile(absoluteFilePath); //解码并保存文本
		QDateTime nowtime = QDateTime::currentDateTime(); //获取当前系统时间
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // 当前系统时间格式
		QString target_Path = SavePath + nowtime_text + QString::number(Count, 10) + ".txt"; //保存txt文件的文件名
		QFile file(target_Path);
		file.open(QIODevice::WriteOnly | QIODevice::Text);//创建文件
		QTextStream in(&file);
		in << decodeData;//写入解码数据至文件
		file.flush();//刷新文件
		file.close();//关闭文件
		Count++; // 序列递增
		stringList.append(absoluteFilePath);
	}
}
