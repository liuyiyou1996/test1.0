/********************************************************************************
** Form generated from reading UI file 'fede.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEDE_H
#define UI_FEDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FEDEClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QFrame *frame_22;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_frame_7;
    QWidget *tab_2;
    QLabel *label_frame_10;
    QTableWidget *tableWidget;
    QWidget *tab;
    QLabel *label_frame_9;
    QFrame *frame;
    QPushButton *pushButton_color;
    QLabel *label_77;
    QComboBox *comboBox_size;
    QLabel *label_78;
    QComboBox *comboBox_color;
    QLabel *label_12;
    QLabel *label_47;
    QLabel *label_logo;
    QLabel *label_14;
    QLabel *label_currecttime_1;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FEDEClass)
    {
        if (FEDEClass->objectName().isEmpty())
            FEDEClass->setObjectName(QStringLiteral("FEDEClass"));
        FEDEClass->resize(724, 612);
        centralWidget = new QWidget(FEDEClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 80, 691, 511));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        frame_22 = new QFrame(tab_4);
        frame_22->setObjectName(QStringLiteral("frame_22"));
        frame_22->setGeometry(QRect(10, 10, 681, 471));
        frame_22->setFrameShape(QFrame::StyledPanel);
        frame_22->setFrameShadow(QFrame::Raised);
        pushButton_6 = new QPushButton(frame_22);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(460, 340, 151, 31));
        pushButton_3 = new QPushButton(frame_22);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 140, 151, 31));
        pushButton = new QPushButton(frame_22);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 140, 141, 31));
        pushButton_5 = new QPushButton(frame_22);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 340, 141, 31));
        pushButton_2 = new QPushButton(frame_22);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 140, 141, 31));
        pushButton_4 = new QPushButton(frame_22);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 340, 141, 31));
        label_54 = new QLabel(frame_22);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(60, 70, 91, 51));
        label_54->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/fire_black.png);"));
        label_55 = new QLabel(frame_22);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(280, 70, 81, 61));
        label_55->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/building_black.png);"));
        label_56 = new QLabel(frame_22);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(500, 73, 71, 51));
        label_56->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/factory_black.png);"));
        label_57 = new QLabel(frame_22);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(70, 270, 81, 51));
        label_57->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/road_black.png);"));
        label_58 = new QLabel(frame_22);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(280, 270, 81, 51));
        label_58->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/traffic_black.png);"));
        label_59 = new QLabel(frame_22);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(490, 270, 81, 51));
        label_59->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/logo_black.png);"));
        label_frame_7 = new QLabel(frame_22);
        label_frame_7->setObjectName(QStringLiteral("label_frame_7"));
        label_frame_7->setGeometry(QRect(10, 10, 651, 451));
        label_frame_7->setFrameShape(QFrame::Box);
        label_frame_7->raise();
        pushButton_6->raise();
        pushButton_3->raise();
        pushButton->raise();
        pushButton_5->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        label_54->raise();
        label_55->raise();
        label_56->raise();
        label_57->raise();
        label_58->raise();
        label_59->raise();
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_frame_10 = new QLabel(tab_2);
        label_frame_10->setObjectName(QStringLiteral("label_frame_10"));
        label_frame_10->setGeometry(QRect(20, 20, 641, 451));
        label_frame_10->setFrameShape(QFrame::Box);
        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 40, 601, 411));
        tableWidget->setGridStyle(Qt::SolidLine);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_frame_9 = new QLabel(tab);
        label_frame_9->setObjectName(QStringLiteral("label_frame_9"));
        label_frame_9->setGeometry(QRect(20, 20, 641, 451));
        label_frame_9->setFrameShape(QFrame::Box);
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 40, 371, 131));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_color = new QPushButton(frame);
        pushButton_color->setObjectName(QStringLiteral("pushButton_color"));
        pushButton_color->setGeometry(QRect(250, 50, 75, 23));
        label_77 = new QLabel(frame);
        label_77->setObjectName(QStringLiteral("label_77"));
        label_77->setGeometry(QRect(30, 30, 81, 21));
        QFont font1;
        font1.setPointSize(11);
        label_77->setFont(font1);
        comboBox_size = new QComboBox(frame);
        comboBox_size->setObjectName(QStringLiteral("comboBox_size"));
        comboBox_size->setGeometry(QRect(130, 70, 91, 22));
        label_78 = new QLabel(frame);
        label_78->setObjectName(QStringLiteral("label_78"));
        label_78->setGeometry(QRect(30, 70, 81, 21));
        label_78->setFont(font1);
        comboBox_color = new QComboBox(frame);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));
        comboBox_color->setGeometry(QRect(130, 30, 91, 22));
        tabWidget->addTab(tab, QString());
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 10, 1101, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        label_12->setFont(font2);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_47 = new QLabel(centralWidget);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(-10, 0, 1381, 71));
        label_47->setStyleSheet(QStringLiteral("background-color: rgb(65, 130, 195);"));
        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(20, 10, 54, 51));
        label_logo->setStyleSheet(QStringLiteral("image: url(:/FEDE/Resources/all.png);"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 83, 71, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(10);
        label_14->setFont(font3);
        label_currecttime_1 = new QLabel(centralWidget);
        label_currecttime_1->setObjectName(QStringLiteral("label_currecttime_1"));
        label_currecttime_1->setGeometry(QRect(470, 83, 241, 21));
        label_currecttime_1->setFont(font3);
        FEDEClass->setCentralWidget(centralWidget);
        tabWidget->raise();
        label_47->raise();
        label_12->raise();
        label_logo->raise();
        label_14->raise();
        label_currecttime_1->raise();
        statusBar = new QStatusBar(FEDEClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FEDEClass->setStatusBar(statusBar);

        retranslateUi(FEDEClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FEDEClass);
    } // setupUi

    void retranslateUi(QMainWindow *FEDEClass)
    {
        FEDEClass->setWindowTitle(QApplication::translate("FEDEClass", "FEDE", 0));
        pushButton_6->setText(QApplication::translate("FEDEClass", "\346\260\264\345\237\237\346\220\234\346\225\221\345\234\272\346\231\257", 0));
        pushButton_3->setText(QApplication::translate("FEDEClass", "\345\267\245\344\270\232\344\272\213\346\225\205\345\234\272\346\231\257", 0));
        pushButton->setText(QApplication::translate("FEDEClass", "\345\273\272\347\255\221\347\201\253\347\201\276\345\234\272\346\231\257", 0));
        pushButton_5->setText(QApplication::translate("FEDEClass", "\345\234\260\351\223\201\344\270\216\346\234\272\345\234\272\345\234\272\346\231\257", 0));
        pushButton_2->setText(QApplication::translate("FEDEClass", "\345\273\272\347\255\221\345\235\215\345\241\214\344\272\213\346\225\205\345\234\272\346\231\257", 0));
        pushButton_4->setText(QApplication::translate("FEDEClass", "\345\205\254\350\267\257\344\272\244\351\200\232\344\272\213\346\225\205\345\234\272\346\231\257", 0));
        label_54->setText(QString());
        label_55->setText(QString());
        label_56->setText(QString());
        label_57->setText(QString());
        label_58->setText(QString());
        label_59->setText(QString());
        label_frame_7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("FEDEClass", "\350\257\204\344\274\260\351\200\211\346\213\251", 0));
        label_frame_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FEDEClass", "\350\257\204\344\274\260\350\256\260\345\275\225", 0));
        label_frame_9->setText(QString());
        pushButton_color->setText(QApplication::translate("FEDEClass", "\344\277\235\345\255\230", 0));
        label_77->setText(QApplication::translate("FEDEClass", "\350\211\262\345\275\251\350\256\276\347\275\256", 0));
        label_78->setText(QApplication::translate("FEDEClass", "\346\240\207\351\242\230\345\244\247\345\260\217", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FEDEClass", "\351\231\204\345\212\240\350\256\276\347\275\256", 0));
        label_12->setText(QApplication::translate("FEDEClass", "\344\272\213\346\225\205\345\272\224\346\200\245\346\274\224\347\273\203\350\257\204\344\274\260\345\271\263\345\217\260", 0));
        label_47->setText(QString());
        label_logo->setText(QString());
        label_14->setText(QApplication::translate("FEDEClass", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", 0));
        label_currecttime_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FEDEClass: public Ui_FEDEClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEDE_H
