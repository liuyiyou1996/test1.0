#pragma once

#include <QWidget>
#include "ui_Input.h"
#include "place.h"
#include "QMessageBox";
#pragma execution_character_set("utf-8") 

extern QString Team_name;
extern QString Team_from;
extern QString Team_number;
extern QString Team_boss;
extern QString Team_phone;
extern QString Team_rater;
class Input : public QWidget
{
	Q_OBJECT

public:
	Input(QWidget *parent = Q_NULLPTR);
	~Input();
	void stylesheet();
private slots:
	void Click_pushButton();
	void Click_pushButton_2();

signals:
	void BackTo();
private:
	Ui::Input ui;
};
