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
	void clickBtnDecodeChooseAddress();
	void clickRbtnEncodeSaveSide();
	void clickRbtnDecodeSaveSide();
	void clickRbtnEncodeChoose();
	void clickRbtnDecodeChoose();
	void clickBtnEncode();
	void clickBtnDecode();
	void endUpdateEncodeUI();
	void endUpdateDecodeUI();
public:
	enigma(QWidget *parent = 0);
	~enigma();

private:
	Ui::enigmaClass ui;
	QTime Timer;
	Thread EnCode;
	Thread DeCode;
};

