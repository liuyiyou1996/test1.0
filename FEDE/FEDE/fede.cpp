#include "fede.h"
#pragma execution_character_set("utf-8") 

FEDE::FEDE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tabWidget->setCurrentIndex(0);
	stylesheet();

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Click_pushButton()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_3()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(Click_pushButton_4()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(Click_pushButton_5()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(Click_pushButton_6()));
	connect(ui.pushButton_color, SIGNAL(clicked()), this, SLOT(Click_pushButton_color()));

	ui.comboBox_color->clear();
	ui.comboBox_color->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "蓝", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "绿", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "灰", Q_NULLPTR)
	);
	
	ui.comboBox_size->clear();
	ui.comboBox_size->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "小", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "中", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "大", Q_NULLPTR)
	);
	
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
	timer->start(1000);

}

FEDE::~FEDE()
{

}

void FEDE::OnBtnClicked(void)

{
	QPushButton * senderObj = qobject_cast<QPushButton *>(sender());
	if (senderObj == 0)

	{
		return;
	}
	QModelIndex index = ui.tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y()));
	int row = index.row();
	qDebug() << "row:" << row;

	Record *s = new Record();
	s->setWindowModality(Qt::WindowModal);
	s->setWindowTitle(QObject::tr("评估记录"));
	s->show();
}

void FEDE::timerUpdate(void)
{
	QDateTime time = QDateTime::currentDateTime();
	QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
	ui.label_currecttime_1->setText(str);
}
void FEDE::color_change()//
{
	QSettings *configIniWrite = new QSettings("setting.ini", QSettings::IniFormat);
	configIniWrite->setValue("/color", 2);//1 蓝 2绿  3灰
	delete configIniWrite;

}
void FEDE::Click_pushButton()//火
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/fire.png);");
	//choose1 = 2;
	this->hide();
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_2()//建筑
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/building.png);");
	//choose1 = 2;
	this->hide();
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_3()
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/factory.png);");
	//choose1 = 2;
	this->hide();
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_4()
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/road.png);");
	//choose1 = 2;
	this->hide();
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_5()
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/traffic.png);");
	this->hide();
	//choose1 = 1;
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_6()
{
	ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/logo.png);");
	//choose1 = 2;
	this->hide();
	place *p = new place();
	p->setWindowModality(Qt::WindowModal);
	p->show();
}
void FEDE::Click_pushButton_color()
{
	

}
void FEDE::closeEvent(QCloseEvent * e)
{
	int button;
	button = QMessageBox::question(this, tr("退出"),
		QString(tr("确认退出应用?")),
		QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::No) {
		e->ignore();  //忽略退出信号，程序继续运行
	}
	else if (button == QMessageBox::Yes) {
		e->accept();  //接受退出信号，程序退出

	}



}

void FEDE::stylesheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);
	ui.label_47->setStyleSheet(QString::fromUtf8("background-color:%1;").arg(color3));//标题背景


	
	QStringList qssbtn;//按钮

	qssbtn.append(QString(
		"QPushButton:!enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid #AAAAAA;background:#e1e1e1;color:#777777} "
		"QPushButton:enabled {border-style:none;padding:2px;border-radius:5px;border:2px solid %1;background:%1;color:#FFFFFF} "
		"QPushButton:hover {border-style:none;padding:2px;border-radius:5px;border:2px solid %2;background:%2;color:#FFFFFF}"
		"QPushButton:pressed{border-style:none;padding:2px;border-radius:5px;border:2px solid %3;background:%3;color:#FFFFFF}"
		).arg(color1).arg(color2).arg(color3));


	ui.pushButton->setStyleSheet(qssbtn.join(""));
	ui.pushButton_2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_3->setStyleSheet(qssbtn.join(""));
	ui.pushButton_4->setStyleSheet(qssbtn.join(""));
	ui.pushButton_5->setStyleSheet(qssbtn.join(""));
	ui.pushButton_6->setStyleSheet(qssbtn.join(""));
	ui.pushButton_color->setStyleSheet(qssbtn.join(""));
	QStringList qss;//文本框显示
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));


	QStringList qsss;//文本框显示
	qsss.append(QString("QTextEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qsss.append(QString("QTextEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));

	//ui.tableWidget->verticalHeader()->hide();
	//ui.tableWidget_2->setStyleSheet(QString("background-color: %1").arg(color1));

	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(14);
	font.setBold(true);
	font.setItalic(false);
	font.setWeight(75);




	ui.label_77->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_77->setFont(font);
	ui.label_78->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_78->setFont(font);

	QFont font1;
	font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font1.setPointSize(10);
	font1.setBold(false);
	font1.setWeight(50);



	QStringList qss1;//选择
	qss1.append(QString(("QComboBox{"          //选择框  
		" border: 2px solid %1;;"
		" border-radius: 5px;"
		"padding: 1px 2px 1px 2px;"
		" min-width: 4em; "
		"}"
		"QComboBox QAbstractItemView::item {min-height: 30px;}" //下拉选项高度
		"QComboBox::down-arrow{border-image:url(:/FEDE/Resources/arrow_down_gray.png);}" //下拉箭头
		"QComboBox::drop-down {"
		"subcontrol-origin: padding;"
		" subcontrol-position: top right;"
		" width: 20px;"
		" border-left-width: 1px;"
		"border-left-color: darkgray;"
		"border-left-style: solid; /* just a single line */"
		"border-top-right-radius: 3px; /* same radius as the QComboBox */"
		" border-bottom-right-radius: 3px;"
		" }"
		" }"
		"QComboBox:focus{border: 2px solid #996666;}"
		)).arg("#555555"));
	ui.comboBox_color->setStyleSheet(qss1.join(""));
	ui.comboBox_size->setStyleSheet(qss1.join(""));
	ui.pushButton->setFont(font1);
	ui.pushButton_2->setFont(font1);
	ui.pushButton_3->setFont(font1);
	ui.pushButton_4->setFont(font1);
	ui.pushButton_5->setFont(font1);
	ui.pushButton_6->setFont(font1);
	ui.pushButton_color->setFont(font1);

	
	ui.tabWidget->setStyleSheet(                                            //标签

		QString("QTabWidget::tab-bar{left:20px;background:green; }"//标签左右位置
		"QTabBar::tab{"
		"min-width:175px;min-height:20px;"
		"background: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #E1E1E1, stop:0.4 #DDDDDD,stop:0.5 #D8D8D8,stop:1.0 #D3D3D3);"
		"border:1px solid %1;border-bottom-color:%1; /* same as the pane color */"
		"border-top-left-radius:4px;border-top-right-radius:4px;min-width:14ex;padding: 2px;}"
		"QTabBar::tab:selected, QTabBar::tab:hover {background:qlineargradient(x1:0,y1:0, x2:0,y2:1,stop:0 #fafafa,stop:0.4 #f4f4f4,stop:0.5 #e7e7e7,stop:1.0 #fafafa);"
		" 	border: 1px solid #FF0000;border-bottom: none;border-top-left-radius:4px;border-top-right-radius: 4px;"
		"}"
		"QTabBar::tab:selected{margin-top: 2px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:%1;border-color:#FFFFFF;color:white;min-width:90px;}"//选择
		"QTabBar::tab:!selected{margin-top: 5px;margin-left: 1px; margin-right: 1px;border-bottom-color: #DDDDDD; background:%2;border-color:#DDDDDD;color:#F5F5F5;min-width:90px;}"//未选择
		"QTabBar::tab:disabled{margin-top: 5px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:#999999;border-color:#FFFFFF;color:white;min-width:90px;}"//选择
		).arg(color2).arg(color1));
	ui.label_frame_7->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame_9->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));

}