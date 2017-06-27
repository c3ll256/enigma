#include "enigma.h"
#include "encoder.h"
#include <ui_enigma.h>
#include <qimage.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <QFile>

enigma::enigma(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	EnCode.Flag = true; 
	//encode信号与槽连接 begin
	connect(ui.btnEncodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnEncodeChooseAddress()));
	connect(ui.rbtnEncodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeSaveSide()));
	connect(ui.rbtnEncodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeChoose()));
	connect(ui.btnEncode, SIGNAL(clicked()), this, SLOT(clickBtnEncode()));
	//encode信号与槽连接 end
	//dencode信号与槽连接 begin
	connect(ui.btnDecodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnDecodeChooseAddress()));
	connect(ui.rbtnDecodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeSaveSide()));
	connect(ui.rbtnDecodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeChoose()));
	connect(ui.btnDecode, SIGNAL(clicked()), this, SLOT(clickBtnDecode()));
	//dencode信号与槽连接 end
}

enigma::~enigma()
{
}

void enigma::clickBtnEncodeChooseAddress()//选择要编码的txt的文件夹根路径
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");//windows目录格式
		ui.lineTxtNowAddress->setText(getPath);
	}
}

void enigma::clickBtnDecodeChooseAddress()//选择要编码的bmp的文件夹根路径
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");
		ui.lineBmpNowAddress->setText(getPath);
	}
}

void enigma::clickRbtnEncodeSaveSide()//选择保存图片到文本旁
{
	ui.lineEncodeSaveNowAddress->setEnabled(false);
}

void enigma::clickRbtnDecodeSaveSide()//选择保存图片到文本旁
{
	  ui.lineDecodeSaveNowAddress->setEnabled(false);
}

void enigma::clickRbtnEncodeChoose()//选择保存的图片路径
{
	ui.lineEncodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");
		ui.lineEncodeSaveNowAddress->setText(getPath);
	}
}

void enigma::clickRbtnDecodeChoose()//选择保存的文本路径
{
	ui.lineDecodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");
		ui.lineDecodeSaveNowAddress->setText(getPath);
	}
}

void enigma::clickBtnEncode()//开始编码
{
	EnCode.Flag = true;
	QString txtPathText(ui.lineTxtNowAddress->text()), savePathText(ui.lineEncodeSaveNowAddress->text());
	txtPathText.replace("\\", "/");//更换QT能工作的目录
	savePathText.replace("\\", "/");
	QDir txtPath(txtPathText),savePath(savePathText);
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
	ui.btnEncode->setEnabled(false);
	ui.txtEncodeDebug->setText("");
	ui.lblEncodeState->setStyleSheet("color:black;");
	ui.lblEncodeState->setText(QStringLiteral("编码中..."));
	EnCode.isSaveSideChecked = ui.rbtnEncodeSaveSide->isChecked();//是否保存在旁边
	EnCode.RootPath = txtPathText;  // 设置编码线程根目录
	EnCode.SavePath = savePathText;  //设置编码线程保存目录
	EnCode.chk = ui.chkEncodeDebug;//设置ui指针
	EnCode.tb = ui.txtEncodeDebug;
	EnCode.start(); // 解码线程开始工作
	//结束编码
	ui.lblEncodeState->setStyleSheet("color:green");
	ui.lblEncodeState->setText(QStringLiteral("编码结束。"));
	ui.btnEncode->setEnabled(true);

}

void enigma::clickBtnDecode()//开始解码
{
	DeCode.Flag = false;
	QString bmpPathText(ui.lineBmpNowAddress->text()), savePathText(ui.lineDecodeSaveNowAddress->text());
	bmpPathText.replace("\\", "/");//更换QT能工作的目录
	savePathText.replace("\\", "/");
	QDir bmpPath(bmpPathText), savePath(savePathText);
	if (!bmpPath.exists())//判断需要解码的根文件夹是否存在
	{
		ui.lblDecodeState->setStyleSheet("color:red;");
		ui.lblDecodeState->setText(QStringLiteral("需要解码的根文件夹不存在"));
		return;
	}
	if (ui.rbtnDecodeChoose->isChecked())
	{//如果另存到同一路径下，则看是否存在或能否创建
		if (!savePath.exists() && !savePath.mkdir(ui.lineDecodeSaveNowAddress->text()))
		{
			ui.lblDecodeState->setStyleSheet("color:red;");
			ui.lblDecodeState->setText(QStringLiteral("保存地址不存在并且创建失败"));
			return;
		}
	}
	//开始解码
	ui.btnDecode->setEnabled(false);
	ui.lblDecodeState->setStyleSheet("color:black;");
	ui.lblDecodeState->setText(QStringLiteral("解码中..."));
	DeCode.isSaveSideChecked = ui.rbtnDecodeSaveSide->isChecked();
	DeCode.RootPath = bmpPathText; // 设置解码线程根目录
	DeCode.SavePath = savePathText; //设置解码线程保存目录
	DeCode.chk = ui.chkDecodeDebug;//设置ui指针
	DeCode.tb = ui.txtDecodeDebug;
	DeCode.start(); // 解码线程开始工作
	//结束解码
	ui.lblDecodeState->setStyleSheet("color:green");
	ui.lblDecodeState->setText(QStringLiteral("解码结束。"));
	ui.btnDecode->setEnabled(true);
}