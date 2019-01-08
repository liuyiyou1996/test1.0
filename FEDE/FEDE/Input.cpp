#include "Input.h"
QString Team_name;
QString Team_from;
QString Team_number;
QString Team_boss;
QString Team_phone;
QString Team_rater;
Input::Input(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	stylesheet();
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Click_pushButton()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_2()));

}

Input::~Input()
{
}
void Input::Click_pushButton()
{
	if (ui.lineEdit->text()=="")
	{

		int button;
		button = QMessageBox::question(this, tr("��ʾ"),QString(tr("�������Ƶ���Ϣδ���룬�Ƿ����")),QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	else if (ui.lineEdit_2->text() == NULL)
	{
		int button;
		button = QMessageBox::question(this, tr("��ʾ"),
			QString(tr("������������Ϣδ���룬�Ƿ����")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	else if (ui.lineEdit_3->text() == NULL)
	{
		int button;
		button = QMessageBox::question(this, tr("��ʾ"),
			QString(tr("��Ա��������Ϣδ���룬�Ƿ����")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	else if (ui.lineEdit_4->text() == NULL)
	{
		int button;
		button = QMessageBox::question(this, tr("��ʾ"),
			QString(tr("�����˵���Ϣδ���룬�Ƿ����")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	else if (ui.lineEdit_5->text() == NULL)
	{
		int button;
		button = QMessageBox::question(this, tr("��ʾ"),
			QString(tr("��ϵ��ʽ����Ϣδ���룬�Ƿ����")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	else if (ui.lineEdit_6->text() == NULL)
	{
		int button;
		button = QMessageBox::question(this, tr("��ʾ"),
			QString(tr("����Ա����Ϣδ���룬�Ƿ����")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
		}
		else if (button == QMessageBox::Yes) {
			Team_name = ui.lineEdit->text();
			Team_from = ui.lineEdit_2->text();
			Team_number = ui.lineEdit_3->text();
			Team_boss = ui.lineEdit_4->text();
			Team_phone = ui.lineEdit_5->text();
			Team_rater = ui.lineEdit_6->text();
			emit BackTo();
			this->close();
		}
	}
	 
	
	else
	{
		Team_name = ui.lineEdit->text();
		Team_from = ui.lineEdit_2->text();
		Team_number = ui.lineEdit_3->text();
		Team_boss = ui.lineEdit_4->text();
		Team_phone = ui.lineEdit_5->text();
		Team_rater = ui.lineEdit_6->text();
		emit BackTo();
		this->close();
	}
	
}
void Input::Click_pushButton_2()
{

	this->close();
}

void Input::stylesheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);

	QStringList qss;//�ı�����ʾ
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));
	ui.lineEdit->setStyleSheet(qss.join(""));
	ui.lineEdit_4->setStyleSheet(qss.join(""));
	ui.lineEdit_2->setStyleSheet(qss.join(""));
	ui.lineEdit_3->setStyleSheet(qss.join(""));
	ui.lineEdit_5->setStyleSheet(qss.join(""));
	ui.lineEdit_6->setStyleSheet(qss.join(""));

	QStringList qssbtn;//��ť
	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
	).arg(color1).arg(color2).arg(color3));
	QFont font1;
	font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font1.setPointSize(10);
	font1.setBold(false);
	font1.setWeight(50);
	ui.pushButton->setFont(font1);
	ui.pushButton->setStyleSheet(qssbtn.join(""));
	ui.pushButton_2->setFont(font1);
	ui.pushButton_2->setStyleSheet(qssbtn.join(""));


	
}