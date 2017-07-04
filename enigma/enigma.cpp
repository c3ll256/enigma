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
	//�ź�������� begin
	connect(ui.btnEncodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnEncodeChooseAddress()));
	connect(ui.rbtnEncodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeSaveSide()));
	connect(ui.rbtnEncodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnEncodeChoose()));
	connect(ui.btnEncode, SIGNAL(clicked()), this, SLOT(clickBtnEncode()));
	connect(ui.btnDecodeChooseAddress, SIGNAL(clicked()), this, SLOT(clickBtnDecodeChooseAddress()));
	connect(ui.rbtnDecodeSaveSide, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeSaveSide()));
	connect(ui.rbtnDecodeChoose, SIGNAL(clicked()), this, SLOT(clickRbtnDecodeChoose()));
	connect(ui.btnDecode, SIGNAL(clicked()), this, SLOT(clickBtnDecode()));
	connect(&EnCode, SIGNAL(endUpdateUI()), this, SLOT(endUpdateEncodeUI()));
	connect(&DeCode, SIGNAL(endUpdateUI()), this, SLOT(endUpdateDecodeUI()));
	//�ź�������� end

	//����ָ�� begin
	EnCode.chk = ui.chkEncodeDebug;
	EnCode.tb = ui.txtEncodeDebug;
	DeCode.chk = ui.chkDecodeDebug;
	DeCode.tb = ui.txtDecodeDebug;
	//����ָ�� end
}

enigma::~enigma()
{
}

void enigma::clickBtnEncodeChooseAddress()//ѡ��Ҫ�����txt���ļ��и�·��
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");//windowsĿ¼��ʽ
		ui.lineTxtNowAddress->setText(getPath);
	}
}

void enigma::clickBtnDecodeChooseAddress()//ѡ��Ҫ�����bmp���ļ��и�·��
{
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");
		ui.lineBmpNowAddress->setText(getPath);
	}
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
		getPath.replace("/", "\\");
		ui.lineEncodeSaveNowAddress->setText(getPath);
	}
}

void enigma::clickRbtnDecodeChoose()//ѡ�񱣴���ı�·��
{
	ui.lineDecodeSaveNowAddress->setEnabled(true);
	QString getPath = QFileDialog::getExistingDirectory(this);
	if (!getPath.isNull())
	{
		getPath.replace("/", "\\");
		ui.lineDecodeSaveNowAddress->setText(getPath);
	}
}

void enigma::clickBtnEncode()//��ʼ����
{
	EnCode.Flag = true;
	QString txtPathText(ui.lineTxtNowAddress->text()), savePathText(ui.lineEncodeSaveNowAddress->text());
	txtPathText.replace("\\", "/");//����QT�ܹ�����Ŀ¼
	savePathText.replace("\\", "/");
	QDir txtPath(txtPathText),savePath(savePathText);
	if (!txtPath.exists()||txtPathText=="")//�ж���Ҫ����ĸ��ļ����Ƿ����
	{
		ui.lblEncodeState->setStyleSheet("color:red;");
		ui.lblEncodeState->setText(QStringLiteral("��Ҫ����ĸ��ļ��в�����"));
		return;
	}

	if (ui.rbtnEncodeChoose->isChecked())
	{//�����浽ͬһ·���£����Ƿ���ڻ��ܷ񴴽�
		if (savePathText == ""||(!savePath.exists() && !savePath.mkdir(ui.lineEncodeSaveNowAddress->text())))
		{
			ui.lblEncodeState->setStyleSheet("color:red;");
			ui.lblEncodeState->setText(QStringLiteral("�����ַ�����ڲ��Ҵ���ʧ��"));
			return;
		}
	}
	//��ʼ����
	ui.btnEncode->setEnabled(false);
	ui.txtEncodeDebug->setText("");
	ui.lblEncodeState->setStyleSheet("color:black;");
	ui.lblEncodeState->setText(QStringLiteral("������..."));
	EnCode.isSaveSideChecked = ui.rbtnEncodeSaveSide->isChecked();//�Ƿ񱣴����Ա�
	EnCode.RootPath = txtPathText;  // ���ñ����̸߳�Ŀ¼
	EnCode.SavePath = savePathText;  //���ñ����̱߳���Ŀ¼
	EnCode.start(); // �����߳̿�ʼ����
	//��������

}

void enigma::clickBtnDecode()//��ʼ����
{
	DeCode.Flag = false;
	QString bmpPathText(ui.lineBmpNowAddress->text()), savePathText(ui.lineDecodeSaveNowAddress->text());
	bmpPathText.replace("\\", "/");//����QT�ܹ�����Ŀ¼
	savePathText.replace("\\", "/");
	QDir bmpPath(bmpPathText), savePath(savePathText);
	if (!bmpPath.exists()||bmpPathText == "")//�ж���Ҫ����ĸ��ļ����Ƿ����
	{
		ui.lblDecodeState->setStyleSheet("color:red;");
		ui.lblDecodeState->setText(QStringLiteral("��Ҫ����ĸ��ļ��в�����"));
		return;
	}
	if (ui.rbtnDecodeChoose->isChecked())
	{//�����浽ͬһ·���£����Ƿ���ڻ��ܷ񴴽�
		if (savePathText==""||(!savePath.exists() && !savePath.mkdir(ui.lineDecodeSaveNowAddress->text())))
		{
			ui.lblDecodeState->setStyleSheet("color:red;");
			ui.lblDecodeState->setText(QStringLiteral("�����ַ�����ڲ��Ҵ���ʧ��"));
			return;
		}
	}
	//��ʼ����
	ui.btnDecode->setEnabled(false);
	ui.txtDecodeDebug->setText("");
	ui.lblDecodeState->setStyleSheet("color:black;");
	ui.lblDecodeState->setText(QStringLiteral("������..."));
	DeCode.isSaveSideChecked = ui.rbtnDecodeSaveSide->isChecked();
	DeCode.RootPath = bmpPathText; // ���ý����̸߳�Ŀ¼
	DeCode.SavePath = savePathText; //���ý����̱߳���Ŀ¼
	DeCode.start(); // �����߳̿�ʼ����
	//��������
}

void enigma::endUpdateEncodeUI()
{//���������ĵ���
	ui.lblEncodeState->setStyleSheet("color:green");
	ui.lblEncodeState->setText(QStringLiteral("�������..."));
	ui.btnEncode->setEnabled(true);
}

void enigma::endUpdateDecodeUI()
{//���������ĵ���
	ui.lblDecodeState->setStyleSheet("color:green");
	ui.lblDecodeState->setText(QStringLiteral("�������..."));
	ui.btnDecode->setEnabled(true);
}