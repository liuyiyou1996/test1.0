/********************************************************************************
** Form generated from reading UI file 'Record.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Record
{
public:
    QLabel *label_40;
    QLabel *label_42;
    QLabel *label_44;
    QLabel *label_29;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_38;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QStringLiteral("Record"));
        Record->resize(319, 413);
        label_40 = new QLabel(Record);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(210, 290, 54, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_40->setFont(font);
        label_42 = new QLabel(Record);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(190, 230, 71, 20));
        label_42->setFont(font);
        label_44 = new QLabel(Record);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(40, 30, 241, 171));
        label_44->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/movie.png);"));
        label_29 = new QLabel(Record);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(50, 230, 81, 21));
        label_29->setFont(font);
        label_41 = new QLabel(Record);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(50, 260, 71, 21));
        label_41->setFont(font);
        label_43 = new QLabel(Record);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(210, 260, 41, 21));
        label_43->setFont(font);
        label_38 = new QLabel(Record);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(50, 290, 71, 21));
        label_38->setFont(font);
        label_45 = new QLabel(Record);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(50, 320, 71, 21));
        label_45->setFont(font);
        label_46 = new QLabel(Record);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(50, 350, 71, 21));
        label_46->setFont(font);
        label_47 = new QLabel(Record);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(210, 320, 41, 21));
        label_47->setFont(font);
        label_48 = new QLabel(Record);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(210, 350, 41, 21));
        label_48->setFont(font);
        label = new QLabel(Record);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 301, 391));
        label->setFrameShape(QFrame::Box);
        label_2 = new QLabel(Record);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 281, 201));
        label_2->setFrameShape(QFrame::Box);
        label->raise();
        label_2->raise();
        label_40->raise();
        label_42->raise();
        label_44->raise();
        label_29->raise();
        label_41->raise();
        label_43->raise();
        label_38->raise();
        label_45->raise();
        label_46->raise();
        label_47->raise();
        label_48->raise();

        retranslateUi(Record);

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QWidget *Record)
    {
        Record->setWindowTitle(QApplication::translate("Record", "Record", 0));
        label_40->setText(QApplication::translate("Record", "\346\227\240", 0));
        label_42->setText(QApplication::translate("Record", "\346\234\252\347\237\245\345\206\205\345\256\271", 0));
        label_44->setText(QString());
        label_29->setText(QApplication::translate("Record", "\351\230\237\344\274\215\345\220\215\347\247\260:", 0));
        label_41->setText(QApplication::translate("Record", "\351\230\237\344\274\215\347\261\273\345\236\213:", 0));
        label_43->setText(QApplication::translate("Record", "\346\227\240", 0));
        label_38->setText(QApplication::translate("Record", "\350\257\204\344\274\260\346\227\266\351\227\264:", 0));
        label_45->setText(QApplication::translate("Record", "\346\214\201\347\273\255\346\227\266\351\227\264:", 0));
        label_46->setText(QApplication::translate("Record", "\350\257\204\344\274\260\345\276\227\345\210\206:", 0));
        label_47->setText(QApplication::translate("Record", "\346\227\240", 0));
        label_48->setText(QApplication::translate("Record", "\346\227\240", 0));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
