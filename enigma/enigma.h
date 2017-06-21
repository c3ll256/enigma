#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_enigma.h"
#include <QZXing.h>
#include <qimage.h>
#include <qrencode.h>
#include <qwidget.h>
#include <qpainter.h>
#include <qfile.h>
#include <encoder.h>
#include <qtimer.h>
#include <thread.h>

class enigma : public QMainWindow
{
	Q_OBJECT
signals :
	void ResetSlot(QString, QString); //线程通信
	public slots:
	void clickBtnEncodeChooseAddress();
	void clickRbtnEncodeSaveSide();
	void clickRbtnEncodeChoose();
	void clickBtnEncode();
public:
	enigma(QWidget *parent = 0);
	~enigma();
	QString RootPath; // 根目录
	QString SavePath;// 保存目录
private:
	Ui::enigmaClass ui;
	int count;
	QTime Timer;
	Thread EnCode;
	Thread DeCode;
};

