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
	void ClickButton1();
	void ClickButton2();
public:
		enigma(QWidget *parent = 0);
		~enigma();
			QImage img;
			QZXing dcoder;
			QZXing createcode;
			QString deco;
			QString str;
			QRcode *qr;
private:
			Ui::enigmaClass ui;
};

