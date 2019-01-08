#pragma once

#include <QWidget>
#include "ui_Record.h"
#include "place.h"

class Record : public QWidget
{
	Q_OBJECT

public:
	Record(QWidget *parent = Q_NULLPTR);
	~Record();
	void stylesheet();

private:
	Ui::Record ui;
};
