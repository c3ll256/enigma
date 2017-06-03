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
public:
		enigma(QWidget *parent = 0);
		~enigma();
private:
			Ui::enigmaClass ui;
};

