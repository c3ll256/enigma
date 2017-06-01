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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "encoder.h"

QT_BEGIN_NAMESPACE

class Ui_enigmaClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    encoder *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *enigmaClass)
    {
        if (enigmaClass->objectName().isEmpty())
            enigmaClass->setObjectName(QStringLiteral("enigmaClass"));
        enigmaClass->resize(600, 400);
        centralWidget = new QWidget(enigmaClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 130, 181, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 290, 171, 51));
        widget = new encoder(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(320, 50, 221, 221));
        enigmaClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(enigmaClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        enigmaClass->setStatusBar(statusBar);

        retranslateUi(enigmaClass);

        QMetaObject::connectSlotsByName(enigmaClass);
    } // setupUi

    void retranslateUi(QMainWindow *enigmaClass)
    {
        enigmaClass->setWindowTitle(QApplication::translate("enigmaClass", "enigma", Q_NULLPTR));
        pushButton->setText(QApplication::translate("enigmaClass", "Decode", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("enigmaClass", "Encode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enigmaClass: public Ui_enigmaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENIGMA_H
