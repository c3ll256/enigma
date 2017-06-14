#include "enigma.h"
#include <ui_enigma.h>
#include <qimage.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <QZXing.h>

enigma::enigma(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//信号与槽连接 begin
	connect(ui.btnEncodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnEncodeChooseAddress()));
	connect(ui.rbtnEncodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeSaveSide()));
	connect(ui.rbtnEncodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeChoose()));
	connect(ui.btnEncode, SIGNAL(clicked()), this, SLOT(clickBtnEncode()));
	//信号与槽连接 end
}

enigma::~enigma()
{
}

void enigma::clickBtnEncodeChooseAddress()//选择要编码的txt的文件夹根路径
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		ui.lineTxtNowAddress->setText(getPath);
	}
}

void enigma::clickRbtnEncodeSaveSide()//选择保存图片到文本旁
{
	setFlag = false;
	ui.lineEncodeSaveNowAddress->setEnabled(false);
}

void enigma::clickRbtnEncodeChoose()//选择保存的图片路径
{
	ui.lineEncodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		setFlag = true;
		ui.lineEncodeSaveNowAddress->setText(getPath);
	}
}

void enigma::clickBtnEncode()//编码按钮触发事件
{
	QDir txtPath(ui.lineTxtNowAddress->text()),savePath(ui.lineEncodeSaveNowAddress->text());
	if (!txtPath.exists())//判断需要编码的根文件夹是否存在
	{
		ui.lblEncodeState->setStyleSheet("color:red;");
		ui.lblEncodeState->setText(QStringLiteral("需要编码的根文件夹不存在"));
		return;
	}
	if (ui.rbtnEncodeChoose->isChecked())
	{//如果另存到同一路径下，则看是否存在或能否创建
		if (!savePath.exists() && !savePath.mkdir(ui.lineEncodeSaveNowAddress->text()))
		{
			ui.lblEncodeState->setStyleSheet("color:red;");
			ui.lblEncodeState->setText(QStringLiteral("保存地址不存在并且创建失败"));
			return;
		}
	}
	//开始编码
	ui.chkEncodeDebug->setEnabled(false);
	ui.btnEncode->setEnabled(false);
	ui.lblEncodeState->setStyleSheet("color:black;");
	ui.lblEncodeState->setText(QStringLiteral("编码中..."));
	count = 0;
	QStringList allTxtPath = getAllFilePath(true,ui.lineTxtNowAddress->text());
	QString path;
	path = allTxtPath.at(0);
	QFile *file = new QFile(path);
	file->open(QIODevice::ReadOnly | QIODevice::Text);
	QString data = QString(file->readAll());
	file->close();
	QImage qrcode = encoder.encodeData(data);
	qrcode.save("123.jpg");
	ui.lblEncodeState->setText(data);
	//结束编码
}

QStringList enigma::getAllFilePath(bool isTxt,QString path)//获取所有文件路径
{
	QStringList filters;
	if (isTxt)//文件过滤
	{
		filters << QString("*.txt");
	}
	else
	{
		filters << QString("*.bmp");
	}
	QDirIterator dirIterator(path,
		filters,
		QDir::Files | QDir::NoSymLinks,
		QDirIterator::Subdirectories);
	QStringList stringList;
	while (dirIterator.hasNext())
	{
		dirIterator.next();
		QFileInfo fileInfo = dirIterator.fileInfo();
		QString absoluteFilePath = fileInfo.absoluteFilePath();
		stringList.append(absoluteFilePath);
	}
	return stringList;

}
