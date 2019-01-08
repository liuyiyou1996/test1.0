/********************************************************************************
** Form generated from reading UI file 'Input.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Input)
    {
        if (Input->objectName().isEmpty())
            Input->setObjectName(QStringLiteral("Input"));
        Input->resize(327, 331);
        label = new QLabel(Input);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(Input);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 81, 21));
        label_2->setFont(font);
        label_3 = new QLabel(Input);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 81, 21));
        label_3->setFont(font);
        label_4 = new QLabel(Input);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 150, 81, 21));
        label_4->setFont(font);
        label_5 = new QLabel(Input);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 190, 81, 21));
        label_5->setFont(font);
        label_6 = new QLabel(Input);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 230, 61, 21));
        label_6->setFont(font);
        lineEdit = new QLineEdit(Input);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 30, 141, 25));
        lineEdit_2 = new QLineEdit(Input);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 70, 141, 25));
        lineEdit_3 = new QLineEdit(Input);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 110, 141, 25));
        lineEdit_4 = new QLineEdit(Input);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 150, 141, 25));
        lineEdit_5 = new QLineEdit(Input);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 190, 141, 25));
        lineEdit_6 = new QLineEdit(Input);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(130, 230, 141, 25));
        pushButton = new QPushButton(Input);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 280, 75, 23));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Input);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 280, 75, 23));
        pushButton_2->setFont(font);

        retranslateUi(Input);

        QMetaObject::connectSlotsByName(Input);
    } // setupUi

    void retranslateUi(QWidget *Input)
    {
        Input->setWindowTitle(QApplication::translate("Input", "Input", 0));
        label->setText(QApplication::translate("Input", "\351\230\237\344\274\215\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("Input", "\346\211\200\345\261\236\346\234\272\346\236\204", 0));
        label_3->setText(QApplication::translate("Input", "\344\272\272\345\221\230\346\225\260\351\207\217", 0));
        label_4->setText(QApplication::translate("Input", "\350\264\237\350\264\243\344\272\272", 0));
        label_5->setText(QApplication::translate("Input", "\350\201\224\347\263\273\346\226\271\345\274\217", 0));
        label_6->setText(QApplication::translate("Input", "\350\257\204\344\274\260\345\221\230", 0));
        pushButton->setText(QApplication::translate("Input", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("Input", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Input: public Ui_Input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
