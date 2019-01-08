#include "VirtualSensor.h"
int check = 0;
VirtualSensor::VirtualSensor(QWidget *parent)
	: QWidget(parent)
{


	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Click_pushButton()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_3()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(Click_pushButton_4()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(Click_pushButton_5()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(Click_pushButton_6()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(Click_pushButton_7()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(Click_pushButton_8()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(Click_pushButton_9()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(Click_pushButton_10()));
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(Click_pushButton_11()));
	connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(Click_pushButton_12()));
	connect(ui.pushButton_step, SIGNAL(clicked()), this, SLOT(Click_pushButton_step()));
	connect(ui.pushButton_step2, SIGNAL(clicked()), this, SLOT(Click_pushButton_step2()));
	connect(ui.pushButton_step3, SIGNAL(clicked()), this, SLOT(Click_pushButton_step3()));
	connect(ui.pushButton_fail, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail()));
	connect(ui.pushButton_fail_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_2()));
	connect(ui.pushButton_fail_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_3()));
	connect(ui.pushButton_fail_4, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_4()));
	connect(ui.pushButton_fail_5, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_5()));
	connect(ui.pushButton_fail_7, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_7()));
	connect(ui.pushButton_fail_8, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_8()));
	connect(ui.pushButton_fail_9, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_9()));
	connect(ui.pushButton_fail_10, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_10()));
	connect(ui.pushButton_fail_11, SIGNAL(clicked()), this, SLOT(Click_pushButton_fail_11()));
	connect(ui.pushButton_success, SIGNAL(clicked()), this, SLOT(Click_pushButton_success()));
	connect(ui.pushButton_success_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_2()));
	connect(ui.pushButton_success_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_3()));
	connect(ui.pushButton_success_4, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_4()));
	connect(ui.pushButton_success_5, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_5()));
	connect(ui.pushButton_success_7, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_7()));
	connect(ui.pushButton_success_8, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_8()));
	connect(ui.pushButton_success_9, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_9()));
	connect(ui.pushButton_success_10, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_10()));
	connect(ui.pushButton_success_11, SIGNAL(clicked()), this, SLOT(Click_pushButton_success_11()));


}


VirtualSensor::~VirtualSensor()
{
}
void VirtualSensor::Click_pushButton()
{

	emit Test_stop();
}
void VirtualSensor::Click_pushButton_2()
{

}
void VirtualSensor::Click_pushButton_3()
{

}
void VirtualSensor::Click_pushButton_4()
{

}
void VirtualSensor::Click_pushButton_5()
{

}
void VirtualSensor::Click_pushButton_6()
{

}
void VirtualSensor::Click_pushButton_7()
{


}
void VirtualSensor::Click_pushButton_8()
{

}
void VirtualSensor::Click_pushButton_9()
{

}
void VirtualSensor::Click_pushButton_10()
{

}
void VirtualSensor::Click_pushButton_11()
{
}
void VirtualSensor::Click_pushButton_12()
{
	bool s = false;
	if (check == 3)
		s = true;
	emit Test6(s);
}
void VirtualSensor::Click_pushButton_step()
{
	ui.pushButton_step->setEnabled(false);
	check = 1;
}
void VirtualSensor::Click_pushButton_step2()
{
	ui.pushButton_step2->setEnabled(false);
	if (check == 1)
		check = 2;
}
void VirtualSensor::Click_pushButton_step3()
{
	ui.pushButton_step3->setEnabled(false);
	if (check == 2)
		check = 3;
}
void VirtualSensor::Click_pushButton_fail()
{
	emit Test1(false);

}
void VirtualSensor::Click_pushButton_fail_2()
{
	emit Test2(false);

}
void VirtualSensor::Click_pushButton_fail_3()
{
	emit Test3(false);

}
void VirtualSensor::Click_pushButton_fail_4()
{
	emit Test4(false);

}
void VirtualSensor::Click_pushButton_fail_5()
{
	emit Test5(false);

}

void VirtualSensor::Click_pushButton_fail_7()
{
	emit Test7(false);

}
void VirtualSensor::Click_pushButton_fail_8()
{
	emit Test8(false);

}
void VirtualSensor::Click_pushButton_fail_9()
{
	emit Test9(false);

}
void VirtualSensor::Click_pushButton_fail_10()
{
	emit Test10(false);

}
void VirtualSensor::Click_pushButton_fail_11()
{
	emit Test11(false);
	this->close();

}
void VirtualSensor::Click_pushButton_success()
{
	emit Test1(true);

}
void VirtualSensor::Click_pushButton_success_2()
{
	emit Test2(true);

}
void VirtualSensor::Click_pushButton_success_3()
{
	emit Test3(true);

}
void VirtualSensor::Click_pushButton_success_4()
{
	emit Test4(true);

}
void VirtualSensor::Click_pushButton_success_5()
{
	emit Test5(true);

}

void VirtualSensor::Click_pushButton_success_7()
{
	emit Test7(true);

}
void VirtualSensor::Click_pushButton_success_8()
{
	emit Test8(true);

}
void VirtualSensor::Click_pushButton_success_9()
{
	emit Test9(true);

}
void VirtualSensor::Click_pushButton_success_10()
{
	emit Test10(true);

}
void VirtualSensor::Click_pushButton_success_11()
{
	emit Test11(true);
	this->close();
}