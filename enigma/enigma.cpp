#include "enigma.h"
#include <ui_enigma.h>
#include <qimage.h>
#include <qmessagebox.h>

enigma::enigma(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(ClickButton1()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(ClickButton2()));
}

enigma::~enigma()
{
}

void enigma::ClickButton1()
{
	img.load("sample.png");
	deco = dcoder.decodeImage(img);
	QMessageBox inmessage;
	inmessage.about(NULL, "decode", deco);
}

void enigma::ClickButton2()
{
	ui.widget->generateString("yooooooo");
}
