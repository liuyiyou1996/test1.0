#ifndef FEDE_H
#define FEDE_H

#include <QtWidgets/QMainWindow>
#include "ui_fede.h"
#include <QScrollArea>
#include "place.h"
#include "Record.h"
#include "QMessageBox";
#include"QSettings";
#include <QTimer>
#include <QCloseEvent>//头文件记得添加


class FEDE : public QMainWindow
{
	Q_OBJECT

public:
	FEDE(QWidget *parent = 0);
	~FEDE();
	void stylesheet();
	void closeEvent(QCloseEvent * e);
	void color_change();

private slots:
	void Click_pushButton();
	void Click_pushButton_2();
	void Click_pushButton_3();
	void Click_pushButton_4();
	void Click_pushButton_5();
	void Click_pushButton_6();
	void Click_pushButton_color();
public slots:
	void timerUpdate(void);
	void OnBtnClicked(void);

private:
	Ui::FEDEClass ui;
};

#endif // FEDE_H
