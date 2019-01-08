#include "Record.h"

Record::Record(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	stylesheet();

}

Record::~Record()
{
}
void Record::stylesheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);
	ui.label_2->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg(color1));
	ui.label->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));

}