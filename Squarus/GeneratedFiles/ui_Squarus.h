/********************************************************************************
** Form generated from reading UI file 'Squarus.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUARUS_H
#define UI_SQUARUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SquarusClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *SquarusClass)
    {
        if (SquarusClass->objectName().isEmpty())
            SquarusClass->setObjectName(QString::fromUtf8("SquarusClass"));
        SquarusClass->resize(1920, 1080);
        centralWidget = new QWidget(SquarusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 120, 571, 491));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        SquarusClass->setCentralWidget(centralWidget);

        retranslateUi(SquarusClass);

        QMetaObject::connectSlotsByName(SquarusClass);
    } // setupUi

    void retranslateUi(QMainWindow *SquarusClass)
    {
        SquarusClass->setWindowTitle(QApplication::translate("SquarusClass", "Squarus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SquarusClass: public Ui_SquarusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUARUS_H
