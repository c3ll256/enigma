/********************************************************************************
** Form generated from reading UI file 'enigma.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENIGMA_H
#define UI_ENIGMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enigmaClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabEncode;
    QLineEdit *lineTxtNowAddress;
    QPushButton *btnEncode;
    QPushButton *btnEncodeChooseAddress;
    QRadioButton *rbtnEncodeSaveSide;
    QRadioButton *rbtnEncodeChoose;
    QLineEdit *lineEncodeSaveNowAddress;
    QCheckBox *chkEncodeDebug;
    QLabel *lblEncodeState;
    QLabel *label_2;
    QTextBrowser *txtEncodeDebug;
    QWidget *tabDecode;
    QLineEdit *lineBmpNowAddress;
    QPushButton *btnDecodeChooseAddress;
    QPushButton *btnDecode;
    QRadioButton *rbtnDecodeSaveSide;
    QRadioButton *rbtnDecodeChoose;
    QLineEdit *lineDecodeSaveNowAddress;
    QCheckBox *chkDecodeDebug;
    QLabel *label_3;
    QLabel *lblDecodeState;
    QTextBrowser *txtDecodeDebug;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *enigmaClass)
    {
        if (enigmaClass->objectName().isEmpty())
            enigmaClass->setObjectName(QStringLiteral("enigmaClass"));
        enigmaClass->resize(600, 413);
        centralWidget = new QWidget(enigmaClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 581, 381));
        tabEncode = new QWidget();
        tabEncode->setObjectName(QStringLiteral("tabEncode"));
        lineTxtNowAddress = new QLineEdit(tabEncode);
        lineTxtNowAddress->setObjectName(QStringLiteral("lineTxtNowAddress"));
        lineTxtNowAddress->setGeometry(QRect(20, 40, 261, 20));
        btnEncode = new QPushButton(tabEncode);
        btnEncode->setObjectName(QStringLiteral("btnEncode"));
        btnEncode->setGeometry(QRect(380, 40, 141, 23));
        btnEncodeChooseAddress = new QPushButton(tabEncode);
        btnEncodeChooseAddress->setObjectName(QStringLiteral("btnEncodeChooseAddress"));
        btnEncodeChooseAddress->setGeometry(QRect(300, 40, 75, 23));
        rbtnEncodeSaveSide = new QRadioButton(tabEncode);
        rbtnEncodeSaveSide->setObjectName(QStringLiteral("rbtnEncodeSaveSide"));
        rbtnEncodeSaveSide->setGeometry(QRect(20, 80, 141, 16));
        rbtnEncodeSaveSide->setChecked(true);
        rbtnEncodeChoose = new QRadioButton(tabEncode);
        rbtnEncodeChoose->setObjectName(QStringLiteral("rbtnEncodeChoose"));
        rbtnEncodeChoose->setGeometry(QRect(230, 80, 89, 16));
        rbtnEncodeChoose->setChecked(false);
        lineEncodeSaveNowAddress = new QLineEdit(tabEncode);
        lineEncodeSaveNowAddress->setObjectName(QStringLiteral("lineEncodeSaveNowAddress"));
        lineEncodeSaveNowAddress->setEnabled(false);
        lineEncodeSaveNowAddress->setGeometry(QRect(350, 80, 210, 20));
        chkEncodeDebug = new QCheckBox(tabEncode);
        chkEncodeDebug->setObjectName(QStringLiteral("chkEncodeDebug"));
        chkEncodeDebug->setGeometry(QRect(20, 320, 130, 20));
        lblEncodeState = new QLabel(tabEncode);
        lblEncodeState->setObjectName(QStringLiteral("lblEncodeState"));
        lblEncodeState->setGeometry(QRect(230, 110, 221, 16));
        label_2 = new QLabel(tabEncode);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 110, 81, 16));
        txtEncodeDebug = new QTextBrowser(tabEncode);
        txtEncodeDebug->setObjectName(QStringLiteral("txtEncodeDebug"));
        txtEncodeDebug->setGeometry(QRect(20, 140, 540, 170));
        tabWidget->addTab(tabEncode, QString());
        tabDecode = new QWidget();
        tabDecode->setObjectName(QStringLiteral("tabDecode"));
        lineBmpNowAddress = new QLineEdit(tabDecode);
        lineBmpNowAddress->setObjectName(QStringLiteral("lineBmpNowAddress"));
        lineBmpNowAddress->setGeometry(QRect(20, 40, 261, 20));
        btnDecodeChooseAddress = new QPushButton(tabDecode);
        btnDecodeChooseAddress->setObjectName(QStringLiteral("btnDecodeChooseAddress"));
        btnDecodeChooseAddress->setGeometry(QRect(300, 40, 75, 23));
        btnDecode = new QPushButton(tabDecode);
        btnDecode->setObjectName(QStringLiteral("btnDecode"));
        btnDecode->setGeometry(QRect(380, 40, 141, 23));
        rbtnDecodeSaveSide = new QRadioButton(tabDecode);
        rbtnDecodeSaveSide->setObjectName(QStringLiteral("rbtnDecodeSaveSide"));
        rbtnDecodeSaveSide->setGeometry(QRect(20, 80, 141, 16));
        rbtnDecodeSaveSide->setChecked(true);
        rbtnDecodeChoose = new QRadioButton(tabDecode);
        rbtnDecodeChoose->setObjectName(QStringLiteral("rbtnDecodeChoose"));
        rbtnDecodeChoose->setGeometry(QRect(230, 80, 89, 16));
        lineDecodeSaveNowAddress = new QLineEdit(tabDecode);
        lineDecodeSaveNowAddress->setObjectName(QStringLiteral("lineDecodeSaveNowAddress"));
        lineDecodeSaveNowAddress->setEnabled(false);
        lineDecodeSaveNowAddress->setGeometry(QRect(350, 80, 210, 20));
        chkDecodeDebug = new QCheckBox(tabDecode);
        chkDecodeDebug->setObjectName(QStringLiteral("chkDecodeDebug"));
        chkDecodeDebug->setGeometry(QRect(20, 320, 130, 20));
        label_3 = new QLabel(tabDecode);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 81, 16));
        lblDecodeState = new QLabel(tabDecode);
        lblDecodeState->setObjectName(QStringLiteral("lblDecodeState"));
        lblDecodeState->setGeometry(QRect(220, 110, 151, 16));
        txtDecodeDebug = new QTextBrowser(tabDecode);
        txtDecodeDebug->setObjectName(QStringLiteral("txtDecodeDebug"));
        txtDecodeDebug->setGeometry(QRect(20, 140, 540, 170));
        tabWidget->addTab(tabDecode, QString());
        enigmaClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(enigmaClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        enigmaClass->setStatusBar(statusBar);

        retranslateUi(enigmaClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(enigmaClass);
    } // setupUi

    void retranslateUi(QMainWindow *enigmaClass)
    {
        enigmaClass->setWindowTitle(QApplication::translate("enigmaClass", "enigma", Q_NULLPTR));
        lineTxtNowAddress->setText(QApplication::translate("enigmaClass", "\345\275\223\345\211\215\350\267\257\345\276\204", Q_NULLPTR));
        btnEncode->setText(QApplication::translate("enigmaClass", "\347\274\226\347\240\201\345\275\223\345\211\215\350\267\257\345\276\204\344\270\213\347\232\204\346\226\207\346\234\254", Q_NULLPTR));
        btnEncodeChooseAddress->setText(QApplication::translate("enigmaClass", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        rbtnEncodeSaveSide->setText(QApplication::translate("enigmaClass", "\347\274\226\347\240\201\345\233\276\347\211\207\344\277\235\345\255\230\345\210\260\346\226\207\346\234\254\346\227\201", Q_NULLPTR));
        rbtnEncodeChoose->setText(QApplication::translate("enigmaClass", "\351\200\211\346\213\251\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
        lineEncodeSaveNowAddress->setText(QApplication::translate("enigmaClass", "\345\275\223\345\211\215\350\267\257\345\276\204", Q_NULLPTR));
        chkEncodeDebug->setText(QApplication::translate("enigmaClass", "\345\274\200\345\220\257\350\257\246\347\273\206\350\260\203\350\257\225\344\277\241\346\201\257", Q_NULLPTR));
        lblEncodeState->setText(QString());
        label_2->setText(QApplication::translate("enigmaClass", "\344\277\241\346\201\257\347\273\237\350\256\241", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabEncode), QApplication::translate("enigmaClass", "\347\274\226\347\240\201", Q_NULLPTR));
        lineBmpNowAddress->setText(QApplication::translate("enigmaClass", "\345\275\223\345\211\215\350\267\257\345\276\204", Q_NULLPTR));
        btnDecodeChooseAddress->setText(QApplication::translate("enigmaClass", "\351\200\211\346\213\251\350\267\257\345\276\204", Q_NULLPTR));
        btnDecode->setText(QApplication::translate("enigmaClass", "\350\247\243\347\240\201\345\275\223\345\211\215\350\267\257\345\276\204\344\270\213\344\272\214\347\273\264\347\240\201", Q_NULLPTR));
        rbtnDecodeSaveSide->setText(QApplication::translate("enigmaClass", "\350\247\243\347\240\201\346\226\207\346\234\254\344\277\235\345\255\230\345\210\260\345\233\276\347\211\207\346\227\201", Q_NULLPTR));
        rbtnDecodeChoose->setText(QApplication::translate("enigmaClass", "\351\200\211\346\213\251\344\277\235\345\255\230\350\267\257\345\276\204", Q_NULLPTR));
        lineDecodeSaveNowAddress->setText(QApplication::translate("enigmaClass", "\345\275\223\345\211\215\350\267\257\345\276\204", Q_NULLPTR));
        chkDecodeDebug->setText(QApplication::translate("enigmaClass", "\345\274\200\345\220\257\350\257\246\347\273\206\350\260\203\350\257\225\344\277\241\346\201\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("enigmaClass", "\344\277\241\346\201\257\347\273\237\350\256\241", Q_NULLPTR));
        lblDecodeState->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabDecode), QApplication::translate("enigmaClass", "\350\247\243\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enigmaClass: public Ui_enigmaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENIGMA_H
