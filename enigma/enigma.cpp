#include "enigma.h"
#include <ui_enigma.h>
#include <qimage.h>
#include <qmessagebox.h>

enigma::enigma(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

enigma::~enigma()
{
}
