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
	//encode�ź�������� begin
	connect(ui.btnEncodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnEncodeChooseAddress()));
	connect(ui.rbtnEncodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeSaveSide()));
	connect(ui.rbtnEncodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeChoose()));
	connect(ui.btnEncode, SIGNAL(clicked()), this, SLOT(clickBtnEncode()));
	//encode�ź�������� end
	//dencode�ź�������� begin
	connect(ui.btnDecodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnDecodeChooseAddress()));
	connect(ui.rbtnDecodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeSaveSide()));
	connect(ui.rbtnDecodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeChoose()));
	connect(ui.btnDecode, SIGNAL(clicked()), this, SLOT(clickBtnDecode()));
	//dencode�ź�������� end
}

enigma::~enigma()
{
}

void enigma::clickBtnEncodeChooseAddress()//ѡ��Ҫ�����txt���ļ��и�·��
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		ui.lineTxtNowAddress->setText(getPath);
	}
	RootPath = getPath;
}

void enigma::clickBtnDecodeChooseAddress()//ѡ��Ҫ�����bmp���ļ��и�·��
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		ui.lineTxtNowAddress->setText(getPath);
	}
	RootPath = getPath;
}

void enigma::clickRbtnEncodeSaveSide()//ѡ�񱣴�ͼƬ���ı���
{
	ui.lineEncodeSaveNowAddress->setEnabled(false);
}

void enigma::clickRbtnDecodeSaveSide()//ѡ�񱣴�ͼƬ���ı���
{
	  ui.lineDecodeSaveNowAddress->setEnabled(false);
}

void enigma::clickRbtnEncodeChoose()//ѡ�񱣴��ͼƬ·��
{
	ui.lineEncodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		ui.lineEncodeSaveNowAddress->setText(getPath);
	}
	enigma::SavePath = getPath;
}

void enigma::clickRbtnDecodeChoose()//ѡ�񱣴���ı�·��
{
	ui.lineDecodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		ui.lineDecodeSaveNowAddress->setText(getPath);
	}
	enigma::SavePath = getPath;
}

void enigma::clickBtnEncode()//��ʼ����
{
	EnCode.Flag = true;
	RootPath = ui.lineTxtNowAddress->text();
	QDir txtPath(ui.lineTxtNowAddress->text()),savePath(ui.lineEncodeSaveNowAddress->text());
	if (!txtPath.exists())//�ж���Ҫ����ĸ��ļ����Ƿ����
	{
		ui.lblEncodeState->setStyleSheet("color:red;");
		ui.lblEncodeState->setText(QStringLiteral("��Ҫ����ĸ��ļ��в�����"));
		return;
	}
	if (ui.rbtnEncodeChoose->isChecked())
	{//�����浽ͬһ·���£����Ƿ���ڻ��ܷ񴴽�
		if (!savePath.exists() && !savePath.mkdir(ui.lineEncodeSaveNowAddress->text()))
		{
			ui.lblEncodeState->setStyleSheet("color:red;");
			ui.lblEncodeState->setText(QStringLiteral("�����ַ�����ڲ��Ҵ���ʧ��"));
			return;
		}
	}
	//��ʼ����
	ui.chkEncodeDebug->setEnabled(false);
	ui.btnEncode->setEnabled(false);
	ui.lblEncodeState->setStyleSheet("color:black;");
	ui.lblEncodeState->setText(QStringLiteral("������..."));
	count = 0;
	//QStringList allTxtPath = getAllFilePath(true,ui.lineTxtNowAddress->text());
	if (ui.lineEncodeSaveNowAddress->isEnabled() == false) // ���ñ���Ŀ¼Ϊ��ǰ·��
		SavePath = RootPath; 
	EnCode.RootPath = enigma::RootPath; // ���ñ����̸߳�Ŀ¼
	EnCode.SavePath = enigma::SavePath; //���ñ����̱߳���Ŀ¼
	EnCode.start(); // �����߳̿�ʼ����
	//��������
	//ui.lblEncodeState->setText(QStringLiteral("���������"));

}

void enigma::clickBtnDecode()//��ʼ����
{
	DeCode.Flag = false;
	RootPath = ui.lineTxtNowAddress->text();
	QDir txtPath(ui.lineTxtNowAddress->text()), savePath(ui.lineDecodeSaveNowAddress->text());
	if (!txtPath.exists())//�ж���Ҫ����ĸ��ļ����Ƿ����
	{
		ui.lblDecodeState->setStyleSheet("color:red;");
		ui.lblDecodeState->setText(QStringLiteral("��Ҫ����ĸ��ļ��в�����"));
		return;
	}
	if (ui.rbtnDecodeChoose->isChecked())
	{//�����浽ͬһ·���£����Ƿ���ڻ��ܷ񴴽�
		if (!savePath.exists() && !savePath.mkdir(ui.lineDecodeSaveNowAddress->text()))
		{
			ui.lblDecodeState->setStyleSheet("color:red;");
			ui.lblDecodeState->setText(QStringLiteral("�����ַ�����ڲ��Ҵ���ʧ��"));
			return;
		}
	}
	//��ʼ����
	ui.chkDecodeDebug->setEnabled(false);
	ui.btnDecode->setEnabled(false);
	ui.lblDecodeState->setStyleSheet("color:black;");
	ui.lblDecodeState->setText(QStringLiteral("������..."));
	count = 0;
	//QStringList allTxtPath = getAllFilePath(true,ui.lineTxtNowAddress->text());
	if (ui.lineDecodeSaveNowAddress->isEnabled() == false) // ���ñ���Ŀ¼Ϊ��ǰ·��
		SavePath = RootPath;
	DeCode.RootPath = enigma::RootPath; // ���ý����̸߳�Ŀ¼
	DeCode.SavePath = enigma::SavePath; //���ý����̱߳���Ŀ¼
	DeCode.start(); // �����߳̿�ʼ����
					//��������
					//ui.lblEncodeState->setText(QStringLiteral("���������"));

}