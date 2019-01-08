#pragma once

#include <QWidget>
#include "ui_place.h"
#include <QScrollArea>
#include "fede.h"
#include "Input.h"
#include "VirtualSensor.h"
#include <qdatetime.h>
#include "qDebug.h"
#include <QPainter>
#include <QProxyStyle>
#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include <QMediaPlayer>
#include <QPrinter>
#include <QVideoWidget>

#include <QMediaPlaylist>
extern QString color1 ;
extern QString color2 ;
extern QString color3;

class place : public QWidget
{
	Q_OBJECT

public:
	place(QWidget *parent = Q_NULLPTR);
	~place();
	void stylesheet();
	void choose(int a);
	void place::closeEvent(QCloseEvent * e);
	QTimer *timer1;
	QTimer *timer2;

	void onRestart();
	QMediaPlayer *player;
	QMediaPlaylist *_pMediaPlaylist;
	void openPlayFile_clicked();
	QString timing_content(QDateTime a);

private slots:
	void Click_pushButton_save();
	void Click_pushButton_over();
	void Click_pushButton_save_2();
	void Click_pushButton_begin();
	void Click_pushButton_begin_3();
	void Click_pushButton_begin_2();
	void Click_pushButton_color();
	void Click_pushButton();
	void Click_pushButton_2();
	void Click_pushButton_3();
	void Click_pushButton_4();
	void Click_pushButton_5();
	void Click_pushButton_6();
	void Click_change();
	void Click_pushButton_local();
	void Click_pushButton_back();
	void Click_pushButton_paint();
	void Click_pushButton_paint_2();

	void ToPlace();
	void ToContent1(bool s);
	void ToContent2(bool s);
	void ToContent3(bool s);
	void ToContent4(bool s);
	void ToContent5(bool s);
	void ToContent6(bool s);
	void ToContent7(bool s);
	void ToContent8(bool s);
	void ToContent9(bool s);
	void ToContent10(bool s);
	void ToContent11(bool s);
	void ToContent_stop();

	
public slots:
	void timerUpdate(void);
	void timing();
	void timing1();

	void OnBtnClicked(void);

private:
	Ui::place ui;
};
