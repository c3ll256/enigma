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
	void ResetSlot(QString, QString); //�߳�ͨ��
	public slots:
	void clickBtnEncodeChooseAddress();
	void clickBtnDecodeChooseAddress();
	void clickRbtnEncodeSaveSide();
	void clickRbtnDecodeSaveSide();
	void clickRbtnEncodeChoose();
	void clickRbtnDecodeChoose();
	void clickBtnEncode();
	void clickBtnDecode();
public:
	enigma(QWidget *parent = 0);
	~enigma();
	QString RootPath; // ��Ŀ¼
	QString SavePath;// ����Ŀ¼
private:
	Ui::enigmaClass ui;
	int count;
	QTime Timer;
	Thread EnCode;
	Thread DeCode;
};

