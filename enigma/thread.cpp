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
	endUpdateUI();
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
	int Count = 0, success = 0; // 递增序列
	QDateTime firstTime = QDateTime::currentDateTime(), lastTime = QDateTime::currentDateTime();//编码时间
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
		lastTime = nowtime;
		QString nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // 当前系统时间格式
		file.close(); // 关闭文件
		QRres.generateString(text); // 设置二维码信息
		QString target_Path = (isSaveSideChecked ? fileInfo.path() + "/" : SavePath) + nowtime_text + (Count < 100 ? "0" : "") + (Count < 10 ? "0" : "") + QString::number(Count, 10) + ".bmp"; //保存 bmp文件的文件名
		nowtime_text = nowtime.toString("hh:mm:ss");
		Count++; // 序列递增
		if (QRres.saveImage(target_Path))// 文件名，图片大小为250*250
		{
			success++;
			if (chk->isChecked())//开启调试则显示调试信息
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("字节 成功"));
			}
		}
		else
		{
			if (chk->isChecked())
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("字节 失败"));
			}
		}
	}
	if (chk->isChecked())
	{
		tb->append(QStringLiteral("耗时:") + QString::number(firstTime.msecsTo(lastTime) % 60000 / 1000.0, 'f', 2) + QStringLiteral("秒 共") + QString::number(Count) + QStringLiteral("个 成功率:") + QString::number((double)success / Count * 100, 'f', 2) + "%");
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
	int Count = 0, success = 0, flag = 0; // 递增序列
	QDateTime firstTime = QDateTime::currentDateTime(), lastTime = QDateTime::currentDateTime();//解码时间
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo;
		QString absoluteFilePath;
		QString nowtime_text;
		try
		{
			fileInfo = dirIterator.fileInfo();
			absoluteFilePath = fileInfo.absoluteFilePath(); // 文件完整路径
			QString decodeData = decoder.decodeImageFromFile(absoluteFilePath); //解码并保存文本
			QDateTime nowtime = QDateTime::currentDateTime(); //获取当前系统时间
			lastTime = nowtime;
			nowtime_text = nowtime.toString("yyyyMMddhhmmss"); // 当前系统时间格式
			QString target_Path = (isSaveSideChecked ? fileInfo.path() + "/" : SavePath) + nowtime_text + (Count < 100 ? "0" : "") + (Count < 10 ? "0" : "") + QString::number(Count, 10) + ".txt"; //保存txt文件的文件名
			QFile file(target_Path);
			file.open(QIODevice::WriteOnly | QIODevice::Text);
			QTextStream in(&file);
			in << decodeData;//写入解码数据至文件
			file.flush();//刷新文件
			file.close();//关闭文件
			Count++; // 序列递增
			success++;
			nowtime_text = nowtime.toString("hh:mm:ss");
			if (chk->isChecked())//开启调试则显示调试信息
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("字节 成功"));
			}
		}
		catch (const std::exception&)
		{
			if (chk->isChecked())
			{
				absoluteFilePath.replace("/", "\\");
				tb->append(nowtime_text + " " + absoluteFilePath + " " + QString::number(fileInfo.size()) + QStringLiteral("字节 失败"));
			}
		}
	}
	if (chk->isChecked())
	{
		tb->append(QStringLiteral("耗时:") + QString::number(firstTime.msecsTo(lastTime) % 60000 / 1000.0, 'f', 2) + QStringLiteral("秒 共") + QString::number(Count) + QStringLiteral("个 成功率:") + QString::number((double)success / Count * 100, 'f', 2) + "%");
	}
}