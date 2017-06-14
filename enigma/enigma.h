#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_enigma.h"
#include <QZXing.h>
#include <qimage.h>
#include <qrencode.h>
#include <qwidget.h>
#include <qpainter.h>

class enigma : public QMainWindow
{
	Q_OBJECT
		public slots:
	void clickBtnEncodeChooseAddress();
	void clickRbtnEncodeSaveSide();
	void clickRbtnEncodeChoose();
	void clickBtnEncode();
public:
	enigma(QWidget *parent = 0);
	~enigma();
	QZXing encoder;
	bool setFlag = false;
private:
	Ui::enigmaClass ui;
	int count;
	QStringList getAllFilePath(bool isTxt,QString path);
};

