#pragma once

#include <QWidget>
#include "ui_VirtualSensor.h"

class VirtualSensor : public QWidget
{
	Q_OBJECT

public:
	VirtualSensor(QWidget *parent = Q_NULLPTR);
	~VirtualSensor();

private slots:
	void Click_pushButton();
	void Click_pushButton_2();
	void Click_pushButton_3();
	void Click_pushButton_4();
	void Click_pushButton_5();
	void Click_pushButton_6();
	void Click_pushButton_7();
	void Click_pushButton_8();
	void Click_pushButton_9();
	void Click_pushButton_10();
	void Click_pushButton_11();
	void Click_pushButton_12();
	void Click_pushButton_step();
	void Click_pushButton_step2();
	void Click_pushButton_step3();
	void Click_pushButton_fail();
	void Click_pushButton_fail_2();
	void Click_pushButton_fail_3();
	void Click_pushButton_fail_4();
	void Click_pushButton_fail_5();
	void Click_pushButton_fail_7();
	void Click_pushButton_fail_8();
	void Click_pushButton_fail_9();
	void Click_pushButton_fail_10();
	void Click_pushButton_fail_11();
	void Click_pushButton_success();
	void Click_pushButton_success_2();
	void Click_pushButton_success_3();
	void Click_pushButton_success_4();
	void Click_pushButton_success_5();
	void Click_pushButton_success_7();
	void Click_pushButton_success_8();
	void Click_pushButton_success_9();
	void Click_pushButton_success_10();
	void Click_pushButton_success_11();
	
signals:	
	void Test1(bool s);
	void Test2(bool s);
	void Test3(bool s);
	void Test4(bool s);
	void Test5(bool s);
	void Test6(bool s);
	void Test7(bool s);
	void Test8(bool s);
	void Test9(bool s);
	void Test10(bool s);
	void Test11(bool s);
	void Test_stop();
private:
	Ui::VirtualSensor ui;
};
