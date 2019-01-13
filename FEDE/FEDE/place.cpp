#include "place.h"
#include "QMessageBox";
#pragma execution_character_set("utf-8") 
int score = 0;
int yesornot = 0;
int form_1_weight[28];//权重
QDateTime begin_time;//获取开始时间
QDateTime begin_time1;//获取开始时间
double score_finish;
QString Timing;
QTime timedebuge;//声明一个时钟对象
QString color1 = "#4182C3";
QString color2 = "#17abe3";
QString color3 = "#2a79bd";
int color_choose = 1;
int size_choose = 1;
int choose1 = 0;
int table_col = 10;
int currentIndex = 0;//当前页面
int currentIndex_old = 0;// 上一个页面
int currentPlace = 0;//当前场景
int MissNum = 0;
bool MissOrNot =false;
bool Finish = true;
int stage = 0;
QString time1[15];
int score_auto[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int score_auto_all;
void pdf_form_data_1();

/*
 演练保障  form_1_weight[0]-form_1_weight[5]
[
	安全保障性
	医疗保障性
	通讯保障程度
	人员保障完善度
	器材保障度
	场地保障度
}
 演练目标和计划 form_1_weight[6]-form_1_weight[9]
{
	演练目标的明确性
	演练计划的合理性
	指挥人员对演练计划的明确度
	参演人员对于演练目标明确度
}
指挥人员和救援人员的能力 form_1_weight[10]-form_1_weight[23]
{
	任务分配的合理程度
	任务分配明确程度
	演练通讯情况
	演练人员对计划遵守程度
	对于特殊情况的处置能力
	指挥人员对于演练现场的掌握情况
	对于救援细节的处理情况
	现场救援秩序情况
	对于不法分子追捕能力
	行动效率
	对于现场的保护情况
	人员受伤情况
	演练人员救援技能熟练度
	演练人员的协作能力
}
演练结束  form_1_weight[24]-form_1_weight[27]
{
	演练花费的时间
	救援结束后现场的处理情况
	被救援人员的安置和救护情况
	演练结束人员集合和疏散情况
}

*/
QString score2[105][3];
int pdf_data[105];

int form_2_weight[105][3];//权重
/*
检验预案   form_2_weight[0]-form_2_weight[2]
{
通过开展应急演练，是否对应急预案下列情况进行检查：
1、是否通过开展应急演练，查找应急预案中存在的问题；
2、是否提出完善应急预案意见；
3、是否提出提高应急预案的实用性和可操作性针对性意见。

}

完善准备  form_2_weight[3]-form_2_weight[5]
{
通过开展应急演练，是否对应对突发事件下列情况进行检查：
1、应急队伍是否进行配备，是否满足现在应急救援需要；
2、是否进行现场应急救援物资、装备储备，是否满足现场应
急救援需要；
3、是否进行应急救援技术准备，准备情况是否到位。
}

锻炼队伍  form_2_weight[6]-form_2_weight[7]
{
通过开展应急演练，对应急救援队伍是否达到下列锻炼效果：
1、是否增强演练组织单位、参与单位和人员等对应急预案的
熟悉程度；
2、是否有效提高演练单位、人员应急处置能力。
}

磨合机制  form_2_weight[8]-form_2_weight[11]
{
通过开展应急演练，是否达到下列磨合机制的效果：
1、是否进一步明确相关单位和人员的职责，理顺工作关系；
2、是否有效提高应急指挥员的指挥协调能力；
3、应急救援机制是否运转有序；
4、是否进一步完善应急机制。
}

科普宣教  form_2_weight[12]
{
通过开展应急演练，是否达到普及应急知识，提高公众风险防
范意识和自救呼救等灾害应对能力的目的。
}

应急演练目标制定  form_2_weight[13]-form_2_weight[15]
{
1、是否制定应急演练目标；
2、应急演练目标是否完善、有针对性；
3、演练目标是否可行。
}

应急演练原则  form_2_weight[16]-form_2_weight[19]
{
应急演练原则的制定是否符合下列要求：
1、是否结合实际、合理定位；
2、是否着眼实战、讲求实效；
3、是否精心组织、确保安全；
4、是否统筹规划、厉行节约。
}
应急演练分类   form_2_weight[20]-form_2_weight[22]
[
本次应急演练采用的形式：
1、按组织形式划分，本次应急演练类别为：
①桌面演练；②实战演练。
2、按内容划分，本次应急演练类别为：
①单项演练；②综合演练。
1、按目的与作用划分，本次应急演练类别为：
①检验性演练；②示范性演练；③研究性演练

}

应急演练计划（方案）form_2_weight[23]-form_2_weight[26]
[
演练计划（方案）是否符合下列要求
1、是否根据实际情况，制定应急演练计划（方案）；
2、演练计划（方案）是否符合相关法律法规和应急预案规定；
3、演练计划（方案）是否符合按照先“单项后综合、先桌面
后实战、循序渐进、时空有序”的原则制定；
4、演练计划（方案）中是否合理规划应急演练的频次、规模
、形式、时间、地点等。

}

应急演练组织机构  form_2_weight[27]-form_2_weight[30]
{
应急演练组织机构是否符合下列要求：
1、是否成立应急演练组织机构；
2、应急演练组织机构是否完善，职责是否明确
3、应急演练组织机构是否按照“策划、保障、实施、评估”
进行职能分工；
4、参演队伍是否包括应急预案管理部门人员、专兼职应急救
援队伍以及志愿者队伍等。

}
应急演练情景设置  form_2_weight[31]-form_2_weight[36]
{
应急演练场景中是否包括下列内容：
1、事件类别；
2、发生的时间地点；
3、发展速度、强度与危险性；
4、受影响范围、人员和物资分布；
5、已造成的损失、后续发展预测；
6、气象及其他环境条件等。

}
人员保障  form_2_weight[37]-form_2_weight[39]
{
应急演练是否包括下列人员：
1、演练领导小组、演练总指挥、总策划；
2、文案人员、控制人员、评估人员、保障人员；
3、参演人员、模拟人员。

}
经费保障  form_2_weight[40]-form_2_weight[42]
{
1、应急演练经费是否纳入年度预算；
2、应急演练经费是否及时拨付；
3、演练经费专款专用、节约高效。
}

场地保障  form_2_weight[43]-form_2_weight[45]
{
1、是否选择合适的演练场地；
2、演练场的是否有足够的空间、良好的交通、生活、卫生和
生产条件；
3、是否干扰公众生产生活。
}
物资器材保障  form_2_weight[46]-form_2_weight[48]
{
1、应急预案和演练方案是否有纸质文本、演示文档等信息材料；
2、应急抢修物资准备是否满足演练要求；
3、是否能够全面模拟演练场景。

}

通信保障   form_2_weight[49]-form_2_weight[52]
{
1、应急指挥机构、总策划、控制人员、参演人员、模拟人员等；
之间是否建立及时可靠的信息传递渠道；
2、通讯器材配置是否满足抢险救援内部、外部通信联络需要；
3、演练现场是否建立多种公共和专用通信信息网络；
4、能否保证演练控制信息的快速传递。
}

安全保障  form_2_weight[53]-form_2_weight[55]
{
1、是否针对应急演练可能出现的风险制定预防控制措施；
2、是否根据需要为演练人员配备个体防护装备
3、演练现场是否有必要的安保措施，是否对演练现场进行封闭或
管制，保证演练安全进行；
}

演练启动  form_2_weight[56]
{
演练前，演练总指挥是否对演练的意义、目标、组织机构及职能
分工、演练方案、演练程序、注意事项进行统一说明。
}

演练指挥与行动 form_2_weight[57]-form_2_weight[61]
{
1、是否由演练总指挥负责演练实施全过程的指挥控制；
2、应急指挥机构是否按照演练方案指挥各参演队伍和人员，开
展模拟演练事件的应急处置行动，完成各项演练活动；
3、演练控制人员是否充分掌握演练方案，按演练方案的要求，熟
练发布控制信息，协调参演人员完成各项演练任务；
4、参演人员是否严格执行控制消息和指令，按照演练方案规定的
程序开展应急处置行动，完成各项演练活动；
5、模拟人员是否按照演练方案要求，模拟未参加演练的单位或
人员的行动，并作出信息反馈。

}

演练过程控制  form_2_weight[62]-form_2_weight[69]
{
1、桌面演练过程控制：
1）在讨论式桌面演练中；演练活动是否围绕对所提出问题进行
讨论；
2）是否由总策划以口头或书面形式，部署引入一个或若干个问题；
3）参演人员是否根据应急预案及相关规定，讨论应采取的行动；
4）由总策划按照演练方案发出控制消息，参演人员接受到事件信
息后，是否通过角色扮演或模拟操作，完成应急处置活动。
2、实战演练过程控制：
1）在实战演练中，是否要通过传递控制消息来控制演练过程；
2）总策划按照演练方案发出控制消息后，控制人员是否立即向参
演人员和模拟人员传递控制消息；
3）参演人员和模拟人员接受到信息后，是否按照发生真实事件时
的应急处置程序或根据应急行动方案，采取相应的应急处置行动；
4）演练过程中，控制人员是否随时掌握演练进展情况，并向总策
划报告演练中出现的各种问题。
}

演练解说   form_2_weight[70]-form_2_weight[74]
{
1、在演练实施过程中，是否安排专人对演练进行解说；
2、演练解说是否包括以下内容：
1）演练背景描述；
2）进程讲解；
3）案例介绍；
4）环境渲染等。


}

演练记录  form_2_weight[75]-form_2_weight[81]
{
1、在演练实施过程中，是否安排专门人员，采用文字、照片和音
像等手段记录演练过程；
2、文字记录是否包括以下内容：
1）演练实际开始与结束时间；
2）演练过程控制情况；
3）各项演练活动中参演人员的表现；
4）意外情况及其处置；
5）是否详细记录可能出现的人员“伤亡”（如进入“危险”场所
而无安全防护，在所规定的时间内不能完成疏散等）及财产“损
失”等情况；
6）文字、照片照片和音像记录是否全方位反映演练实施过程。
}

宣传教育  form_2_weight[82]-form_2_weight[83]
{
1、是否针对应急演练对其他人员进行宣传教育；
2、通过宣传教育是否有效提高其他人员的抢险救援意识、普及抢
险救援知识和技能。
}

应急演练结束与终止  form_2_weight[84]-form_2_weight[86]
{
1、演练完毕，是否由总策划发出结束信号，演练总指挥宣布演练
结束；
2、演练结束后所有人员是否停止演练活动，按预定方案集合进行
现场总结讲评或者组织疏散；
3、演练结束后是否指定专人负责组织人员对演练现场进行清理和
恢复。

}

演练评估  form_2_weight[87]-form_2_weight[93]
{
1、演练结束后是否组织有关人员对应急演练过程进行评估。
2、应急演练评估是否包括下列几个方面：
1）演练执行情况；
2）预案的合理性和可操作性；
3）应急指挥人员的指挥协调能力；
4）参演人员的处置能力；
5）演练所用设备的适用性；
6）演练目标的实现情况、演练的成本效益分析、对完善预案的建
议等。
}


演练总结  form_2_weight[94]-form_2_weight[99]
{
1、演练结束后演练单位是否对演练进行系统和全面总结，并形成
演练总结报告；
2、演练总结报告是否包括下列内容：
1）演练目的；
2）时间和地点；
3）参演单位和人员；
4）演练方案概要；
5）发现的问题与原因，经验和教训、以及改进有关工作的建议等。
}

成功运用  form_2_weight[100]-form_2_weight[103]
{
1、对演练中暴露出来的问题，演练单位是否及时采取措施予以改
进；
2、是否及时组织对应急预案的修订、完善；
3、是否有针对性的加强应急人员地教育和培训；
4、是否对应急物资装备进行有计划地更新等。
}

*/

class CustomTabStyle : public QProxyStyle
{
public:
	QSize sizeFromContents(ContentsType type, const QStyleOption *option,
		const QSize &size, const QWidget *widget) const
	{
		QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
		if (type == QStyle::CT_TabBarTab) {
			s.transpose();
			s.rwidth() = 140; // 设置每个tabBar中item的大小
			s.rheight() = 44;
		}
		return s;
	}

	void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
	{
		if (element == CE_TabBarTabLabel) {
			if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
				QRect allRect = tab->rect;

				if (tab->state & QStyle::State_Selected) {
					painter->save();
					painter->setPen(color1);
					painter->setBrush(QBrush(QColor(color1)
					));
					painter->drawRect(allRect.adjusted(6, 6, -6, -6));
					painter->restore();
				}
				QTextOption option;
				option.setAlignment(Qt::AlignCenter);
				if (tab->state & QStyle::State_Selected) {
					painter->setPen(0xffffff);
					painter->restore();

				}
				else {
					painter->setPen((0x778f98));
					painter->restore();

				}

				painter->drawText(allRect, tab->text, option);
				return;
			}
		}

		if (element == CE_TabBarTab) {
			QProxyStyle::drawControl(element, option, painter, widget);
		}
	}
};


place::place(QWidget *parent)
	: QWidget(parent)
{
		ui.setupUi(this);
		ui.pushButton_begin_2->hide();
		ui.pushButton_begin_3->hide();
		ui.label_name->setText("");
		ui.label_name_2->setText("");
		ui.label_name_3->setText("");
		ui.pushButton_over->setEnabled(false);
		ui.pushButton_begin->setEnabled(false);
		ui.tabWidget->setCurrentIndex(0);
		ui.tabWidget_2->setCurrentIndex(0);
		ui.tabWidget->setTabEnabled(0, true);
		//ui.tabWidget->setTabEnabled(1, false);
		//ui.tabWidget->setTabEnabled(2, false);
		QSettings *configIniread = new QSettings("setting.ini", QSettings::IniFormat);
		color_choose = configIniread->value("/color").toInt();
		size_choose = configIniread->value("/size").toInt();

		delete configIniread;
		if (color_choose == 1)
		{
			color1 = "#4182C3";
			color2 = "#17abe3";
			color3 = "#2a79bd";
		}
		else if (color_choose == 2)
		{
			color1 = "#20B2AA";//绿
			color2 = "#48c9b0";
			color3 = "#0f7772";
		}
		else
		{
			color1 = "#778f98";//灰
			color2 = "#9cb7c0";
			color3 = "#576165";
		}
		if (size_choose == 1)
		{
			QFont font2;
			font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
			font2.setPointSize(20);
			font2.setBold(true);
			font2.setItalic(false);
			font2.setWeight(75);
			ui.label_12->setFont(font2);
		}
		if (size_choose == 2)
		{
			QFont font2;
			font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
			font2.setPointSize(30);
			font2.setBold(true);
			font2.setItalic(false);
			font2.setWeight(75);
			ui.label_12->setFont(font2);
		}
		if (size_choose == 3)
		{
			QFont font2;
			font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
			font2.setPointSize(35);
			font2.setBold(true);
			font2.setItalic(false);
			font2.setWeight(75);
			ui.label_12->setFont(font2);
		}

		
	choose(choose1);
	stylesheet();
	ui.comboBox->clear();
	ui.comboBox->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "摄像头1", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "摄像头2", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "摄像头3", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "摄像头4", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "摄像头4", Q_NULLPTR)

	);
	ui.comboBox_2->clear();
	ui.comboBox_2->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "主观赋权评估", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "客观赋权评估", Q_NULLPTR)
	);
	ui.comboBox_3->clear();
	ui.comboBox_3->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "主观赋权评估", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "客观赋权评估", Q_NULLPTR)
	);

	
	
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Click_pushButton()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_3()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(Click_pushButton_4()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(Click_pushButton_5()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(Click_pushButton_6()));
	connect(ui.pushButton_over, SIGNAL(clicked()), this, SLOT(Click_pushButton_over()));
	connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(Click_pushButton_save()));
	connect(ui.pushButton_save_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_save_2()));
	connect(ui.pushButton_begin, SIGNAL(clicked()), this, SLOT(Click_pushButton_begin()));
	connect(ui.pushButton_begin_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_begin_2()));
	connect(ui.pushButton_begin_3, SIGNAL(clicked()), this, SLOT(Click_pushButton_begin_3()));
	connect(ui.pushButton_color, SIGNAL(clicked()), this, SLOT(Click_pushButton_color()));
	connect(ui.pushButton_local, SIGNAL(clicked()), this, SLOT(Click_pushButton_local()));
	connect(ui.pushButton_back1, SIGNAL(clicked()), this, SLOT(Click_pushButton_back()));
	connect(ui.pushButton_back2, SIGNAL(clicked()), this, SLOT(Click_pushButton_back()));
	connect(ui.pushButton_back3, SIGNAL(clicked()), this, SLOT(Click_pushButton_back()));
	connect(ui.tabWidget_2, SIGNAL(currentChanged(int)), this, SLOT(Click_change()));
	connect(ui.pushButton_paint, SIGNAL(clicked()), this, SLOT(Click_pushButton_paint()));
	connect(ui.pushButton_paint_2, SIGNAL(clicked()), this, SLOT(Click_pushButton_paint_2()));

	
	ui.tabWidget->tabBar()->hide();


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
	ui.tableWidget->setColumnCount(6);
	ui.tableWidget->setRowCount(table_col);

	QStringList header;
	header << "队伍名称" << tr("队伍类型") << "评估时间" << "持续时间" << "评估分数" << "详情";
	ui.tableWidget->setHorizontalHeaderLabels(header);
	ui.tableWidget->verticalHeader()->setHidden(true);
	//ui.tableWidget->horizontalHeader()->setStyleSheet(QString("QHeaderView{font:12pt '黑体';};"));
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	for (int i = 0; i<table_col; i++)
	{
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem("未知队伍"));
		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		for (int j = 1; j < 6; j++)
		{
			ui.tableWidget->setItem(i, j, new QTableWidgetItem("无"));
			ui.tableWidget->item(i, j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
		QPushButton * pBtn = new QPushButton();
		QStringList qssbtn;//按钮
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

		pBtn->setFont(font1);
		pBtn->setStyleSheet(qssbtn.join(""));

		pBtn->setText("查看详情");
		connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));

		ui.tableWidget->setCellWidget(i, 5, pBtn); //如果点击按钮出现崩溃现象，就添加QTableWidgetItem  到按钮的那个单元格

	}
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
	timer->start(1000);
	timer1 = new QTimer(this);
	timer2 = new QTimer(this);

	ui.tabWidget_2->setTabPosition(QTabWidget::West);
	ui.tabWidget_2->tabBar()->setStyle(new CustomTabStyle);
	ui.tabWidget_2->setStyleSheet("QTabWidget::tab-bar{top:0px; }"
		"QTabWidget::pane{ \
            border-left: 1px solid #eeeeee;\
        }");





}

place::~place()
{
}
void place::Click_pushButton_local()
{
	QVBoxLayout *layout = new QVBoxLayout;
	QMediaPlayer* player = new QMediaPlayer;
	QVideoWidget* vw = new QVideoWidget;

	layout->addWidget(vw);
	ui.widget->setLayout(layout);

	player->setVideoOutput(vw);
	QString path = QFileDialog::getOpenFileName(this, tr("选择视频"), ".", tr("Image Files( *.mp4)"));//得到视频路径

	QFile file(path);
	if (!file.open(QIODevice::ReadOnly))
		qDebug() << "Could not open file";

	player->setMedia(QUrl::fromLocalFile(path));
	player->play();
	ui.widget->show();
}

void place::Click_change()//页面切换
{
	currentIndex_old = currentIndex;
	currentIndex =ui.tabWidget_2->currentIndex();
	ui.label_name->setText("");
	ui.label_name_2->setText("");
	ui.label_name_3->setText("");

	//ui.label_logo->setText(QString::number(currentIndex, 10));
	if (currentIndex == 0)
	{
		ui.label_12->setText("评估场景选择");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/all.png);");

	}
	else if (currentIndex == 1)
	{
		switch (currentPlace)
		{
		case 0:
			ui.label_12->setText("评估场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/all.png);");
			break;
		case 1:
			ui.label_12->setText("建筑火灾场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/fire.png);");
			break;
	    case  2:
			ui.label_12->setText("建筑坍塌事故场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/building.png);");
			break;
		case  3:
			ui.label_12->setText("工业事故场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/factory.png);");
			break;
		case  4:
			ui.label_12->setText("公路交通事故场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/road.png);");
			break;
		case  5:
			ui.label_12->setText("地铁与机场场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/traffic.png);");
			break;
		case  6:
			ui.label_12->setText("水域搜索场景");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/logo.png);");
			break;

		}
		
	}
	else if (currentIndex == 2)
	{
		ui.label_12->setText("评估记录");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/record.png);");
	}
	else if (currentIndex == 3)
	{
		ui.label_12->setText("系统设置");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/setting.png);");
	}
}
void place::Click_pushButton()//火
{
	if (Finish == true)
	{
		choose1 = 1;
		currentPlace = 1;
		ui.label_content->setText("指挥员接警");
		ui.label_content_2->setText("发送集结警报");
		ui.label_content_3->setText("指定位置集结");
		ui.label_content_4->setText("发出行动指令");
		ui.label_content_5->setText("定位灾害现场");
		ui.label_content_6->setText("通信操作测试");
		ui.label_content_7->setText("领队考察现场");
		ui.label_content_8->setText("危险品搬运");
		ui.label_content_9->setText("护送被困人员");
		ui.label_content_10->setText("监控灾害现场");
		ui.label_content_11->setText("人员现场集中");
		ui.label_content_12->setText("");

		ui.label_time->setText("00:00:00");
		ui.label_time_2->setText("00:00:00");
		ui.label_time_3->setText("00:00:00");
		ui.label_time_4->setText("00:00:00");
		ui.label_time_5->setText("00:00:00");
		ui.label_time_6->setText("00:00:00");
		ui.label_time_7->setText("00:00:00");
		ui.label_time_8->setText("00:00:00");
		ui.label_time_9->setText("00:00:00");
		ui.label_time_10->setText("00:00:00");
		ui.label_time_11->setText("00:00:00");
		ui.label_time_12->setText("");

		ui.tabWidget_2->setCurrentIndex(1);
		ui.tabWidget->setTabEnabled(0, true);
		ui.pushButton_begin->setEnabled(true);
		ui.label_timing->setText("");
		ui.label_name->setText("");
		Finish =false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_2()//建筑
{
	if (Finish == true)
	{
	choose1 = 1;
	currentPlace = 2;
	ui.tabWidget_2->setCurrentIndex(1);
	ui.tabWidget->setTabEnabled(0, true);
	ui.pushButton_begin->setEnabled(true);
	ui.label_timing->setText("");
	ui.label_name->setText("");
	Finish = false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_3()
{
	if (Finish == true)
	{
	choose1 = 1;
	currentPlace = 3;
	ui.tabWidget_2->setCurrentIndex(1);
	ui.tabWidget->setTabEnabled(0, true);
	ui.pushButton_begin->setEnabled(true);
	ui.label_timing->setText("");
	ui.label_name->setText("");
	Finish = false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_4()
{
	if (Finish == true)
	{
	choose1 = 1;
	currentPlace = 4;
	ui.tabWidget_2->setCurrentIndex(1);
	ui.tabWidget->setTabEnabled(0, true);
	ui.pushButton_begin->setEnabled(true);
	ui.label_timing->setText("");
	ui.label_name->setText("");
	Finish = false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_5()
{
	if (Finish == true)
	{
	choose1 = 2;
	currentPlace = 5;
	ui.label_content->setText("指挥员接警");
	ui.label_content_2->setText("发送集结警报");
	ui.label_content_3->setText("指定位置集结");
	ui.label_content_4->setText("发出行动指令");
	ui.label_content_5->setText("定位灾害现场");
	ui.label_content_6->setText("放置警戒标志");
	ui.label_content_7->setText("解救现场人员");
	ui.label_content_8->setText("运送受伤人员");
	ui.label_content_9->setText("处理现场险情");
	ui.label_content_10->setText("恢复现场通行");
	ui.label_content_11->setText("");
	ui.label_content_12->setText("");

	ui.label_time->setText("00:00:00");
	ui.label_time_2->setText("00:00:00");
	ui.label_time_3->setText("00:00:00");
	ui.label_time_4->setText("00:00:00");
	ui.label_time_5->setText("00:00:00");
	ui.label_time_6->setText("00:00:00");
	ui.label_time_7->setText("00:00:00");
	ui.label_time_8->setText("00:00:00");
	ui.label_time_9->setText("00:00:00");
	ui.label_time_10->setText("00:00:00");
	ui.label_time_11->setText("");
	ui.label_time_12->setText("");
	ui.tabWidget_2->setCurrentIndex(1);
	ui.tabWidget->setTabEnabled(0, true);
	ui.pushButton_begin->setEnabled(true);
	ui.label_timing->setText("");
	ui.label_name->setText("");
	Finish = false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_6()
{
	if (Finish == true)
	{
	choose1 = 1;
	currentPlace = 6;

	ui.label_content->setText("指挥员接警");
	ui.label_content_2->setText("发送集结警报");
	ui.label_content_3->setText("指定位置集结");
	ui.label_content_4->setText("发出行动指令");
	ui.label_content_5->setText("定位灾害现场");
	ui.label_content_6->setText("通信操作测试");
	ui.label_content_7->setText("侦查事故现场");
	ui.label_content_8->setText("放置警戒标志");
	ui.label_content_9->setText("救援人员检查");
	ui.label_content_10->setText("到达相应水域");
	ui.label_content_11->setText("营救被困人员");
	ui.label_content_12->setText("核查最终现场");

	ui.label_time->setText("00:00:00");
	ui.label_time_2->setText("00:00:00");
	ui.label_time_3->setText("00:00:00");
	ui.label_time_4->setText("00:00:00");
	ui.label_time_5->setText("00:00:00");
	ui.label_time_6->setText("00:00:00");
	ui.label_time_7->setText("00:00:00");
	ui.label_time_8->setText("00:00:00");
	ui.label_time_9->setText("00:00:00");
	ui.label_time_10->setText("00:00:00");
	ui.label_time_11->setText("00:00:00");
	ui.label_time_12->setText("00:00:00");

	ui.tabWidget_2->setCurrentIndex(1);
	ui.tabWidget->setTabEnabled(0, true);
	ui.pushButton_begin->setEnabled(true);
	ui.label_timing->setText("");
	ui.label_name->setText("");
	Finish = false;

	}
	else
	{
		QMessageBox::about(NULL, "警告", "有未完成的评估过程，请完成或退出后再选择场景");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_color()
{
	QSettings *configIniWrite = new QSettings("setting.ini", QSettings::IniFormat);
	configIniWrite->setValue("/color", ui.comboBox_color->currentIndex() + 1);//1 蓝 2绿  3灰
	configIniWrite->setValue("/size", ui.comboBox_size->currentIndex() + 1);//1 蓝 2绿  3灰
	delete configIniWrite;
	color_choose = ui.comboBox_color->currentIndex() + 1;
	size_choose = ui.comboBox_size->currentIndex() + 1;



	if (color_choose == 1)
	{
		color1 = "#4182C3";
		color2 = "#17abe3";
		color3 = "#2a79bd";
	}
	else if (color_choose == 2)
	{
		color1 = "#20B2AA";//绿
		color2 = "#48c9b0";
		color3 = "#0f7772";
	}
	else
	{
		color1 = "#778f98";//灰
		color2 = "#9cb7c0";
		color3 = "#576165";
	}
	if (size_choose == 1)
	{
		QFont font2;
		font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font2.setPointSize(20);
		font2.setBold(true);
		font2.setItalic(false);
		font2.setWeight(75);
		ui.label_12->setFont(font2);
	}
	if (size_choose == 2)
	{
		QFont font2;
		font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font2.setPointSize(30);
		font2.setBold(true);
		font2.setItalic(false);
		font2.setWeight(75);
		ui.label_12->setFont(font2);
	}
	if (size_choose == 3)
	{
		QFont font2;
		font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
		font2.setPointSize(35);
		font2.setBold(true);
		font2.setItalic(false);
		font2.setWeight(75);
		ui.label_12->setFont(font2);
	}
	stylesheet();

}

void place::timerUpdate(void)
{ 
	QDateTime time = QDateTime::currentDateTime();  
	QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
	ui.label_currecttime_1->setText(str);
}
void place::timing()
{
	Timing = (QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - begin_time.toMSecsSinceEpoch()).toUTC().toString("hh:mm:ss"));
	//qDebug() << "span" << QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - begin_time.toMSecsSinceEpoch()).toUTC().toString("hh:mm:ss");
	ui.label_timing->setText(Timing);

}
void place::timing1()
{
	if (stage == 1)
	{
		time1[0] = timing_content(begin_time1);
		ui.label_time->setText(time1[0]);
	}
	else if (stage == 2)
	{
		time1[1] = timing_content(begin_time1);
		ui.label_time_2->setText(time1[1]);
	}
	else if (stage == 3)
	{
		time1[2] = timing_content(begin_time1);
		ui.label_time_3->setText(time1[2]);
	}
	else if (stage == 4)
	{
		time1[3] = timing_content(begin_time1);
		ui.label_time_4->setText(time1[3]);
	}
	else if (stage == 5)
	{
		time1[4] = timing_content(begin_time1);
		ui.label_time_5->setText(time1[4]);
	}
	else if (stage == 6)
	{
		time1[5] = timing_content(begin_time1);
		ui.label_time_6->setText(time1[5]);
	}
	else if (stage == 7)
	{
		time1[6] = timing_content(begin_time1);
		ui.label_time_7->setText(time1[6]);
	}
	else if (stage == 8)
	{
		time1[7] = timing_content(begin_time1);
		ui.label_time_8->setText(time1[7]);
	}
	else if (stage == 9)
	{
		time1[8] = timing_content(begin_time1);
		ui.label_time_9->setText(time1[8]);
	}
	else if (stage == 10)
	{
		time1[9] = timing_content(begin_time1);
		ui.label_time_10->setText(time1[9]);
	}
	else if (stage == 11)
	{
		time1[10] = timing_content(begin_time1);
		ui.label_time_11->setText(time1[10]);
	}
}
QString place::timing_content(QDateTime time_now1)
{
	QString Timing1 = (QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - time_now1.toMSecsSinceEpoch()).toUTC().toString("hh:mm:ss"));
	//qDebug() << "span" << QDateTime::fromMSecsSinceEpoch(QDateTime::currentDateTime().toMSecsSinceEpoch() - begin_time.toMSecsSinceEpoch()).toUTC().toString("hh:mm:ss");
	return  Timing1;
}
void place::choose(int a)
{
	//ui.tabWidget->removeTab(a);
}
void place::Click_pushButton_back()
{
	int button;
	button = QMessageBox::question(this, tr("提示"), QString(tr("确认退出评估流程？")), QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::No) {

	}
	else if (button == QMessageBox::Yes) 
	{
		onRestart();
	}
}
void place::Click_pushButton_paint()
{

	QString file_path1 = QFileDialog::getSaveFileName(this, "输入待导出的报告存储位置", QString(), "*.pdf");  //用文件对话框设置输出路径
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //或者 file_path+=".pdf"
		}
	}
	QPrinter printer_text;
	printer_text.setOutputFormat(QPrinter::PdfFormat);
	printer_text.setOutputFileName(file_path1);//pdfname为要保存的pdf文件名
	printer_text.setPageSize(QPrinter::A4); //设置纸张尺寸，默认不设置就是A4

	QTextDocument text_document;
	QTextDocument text_document2;

	QString html = GeneratePicWord1();//自定义的函数，用来生成html代码
	text_document.setHtml(html);
	text_document.print(&printer_text);
	printer_text.newPage();
	text_document2.setHtml(html);
	text_document2.print(&printer_text);
}
void place::Click_pushButton_paint_2()
{
#if 0
	if (0)
	{
		QPrinter pic_printer(QPrinter::HighResolution); //用一种分辨率初始化
														//QPrinter printerPixmap(QPrinter::HighResolution);
		pic_printer.setPageSize(QPrinter::A4); //设置纸张尺寸，默认不设置就是A4
		pic_printer.setOutputFormat(QPrinter::PdfFormat); //设置输出格式pdf
		QString file_path = QFileDialog::getSaveFileName(this, "输入待导出的报告存储位置", QString(), "*.pdf");  //用文件对话框设置输出路径
		if (!file_path.isEmpty())
		{
			if (QFileInfo(file_path).suffix().isEmpty())
			{
				file_path.append(".pdf");  //或者 file_path+=".pdf"
			}
		}
		pic_printer.setOutputFileName(file_path);
		QPixmap pixmap = QPixmap::grabWidget(ui.scrollAreaWidgetContents, ui.scrollAreaWidgetContents->rect()); //抓取界面widget区域，可以抓取任意控件区域，Qt5推荐新的API QWidget::grab
																													//QPixmap pixmap2 = QPixmap::grabWidget(ui.label_2_2, ui.label_2_2->rect()); //抓取界面widget区域，可以抓取任意控件区域，Qt5推荐新的API QWidget::grab
																													//QPixmap pixmap3 = QPixmap::grabWidget(ui.label_2_3, ui.label_2_3->rect()); //抓取界面widget区域，可以抓取任意控件区域，Qt5推荐新的API QWidget::grab
																													//pixmap.load("1.png");
		QPainter pic_painter;

		pic_painter.begin(&pic_printer);

		QRect rect = pic_painter.viewport(); //获取painter的视口区域

		int factor = rect.width() / pixmap.width(); //计算painter视口区域与抓取图片区域的尺寸比例因子

		pic_painter.scale(factor - 1.5, factor - 1.5); //绘制时按照比例因子放大
										   //pic_painter.scale(1, 1); //绘制时按照比例因子放大

		pic_painter.drawPixmap(10, 170, pixmap); //按照坐标画图
												 //pic_painter.scale(1,1); //回复比例，否则字体很大不正常,此步貌似不需要
		rect = pic_painter.viewport(); //获取painter的视口区域

									   // factor = pixmap.width() / pixmap2.width(); //计算painter视口区域与抓取图片区域的尺寸比例因子
		pic_printer.setResolution(QPrinter::ScreenResolution); //也可以设置其他的分辨率

		pic_painter.scale(0.15, 0.15); //绘制时按照比例因子放大
		if (0)
		{
			QPoint point(700, 150);
			int i1 = 200;
			QString message = QString("%1").arg("         事故应急演练评估结果");
			pic_painter.drawText(point, message);
			int y = point.y();
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("系统评估场景：").arg(ui.label_12->text());
			pic_painter.drawText(point, message);
			y = point.y();
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("评估队伍名称：").arg(Team_name);
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("自动评估分数：").arg(QString::number(score_auto_all, 10));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("人工评估分数：").arg(QString::number(score, 10));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("合计评估分数：").arg(QString::number(score_finish, 'g', 6));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("合计持续时间：").arg(Timing);
			pic_painter.drawText(point, message);
		}

		//pic_painter.drawText(10, i * 30, "hello world"); //按照坐标（或矩形）输出,文本为QString类型，有多种重载函数，随便用哪一种
		pic_painter.end();
		//QPrinter text_printer; //文本生成不要设置resolution，否则输出会乱掉
		//QPainter text_painter;
		//text_printer.setOutputFormat(QPrinter::PdfFormat);
	}
	//text_printer.setOutputFileName("test_text.pdf"); //直接设置输出文件路径，相对或者绝对路径

	//text_painter.begin(&text_printer);

	//for (int i = 0; i<5; i++)

	//	text_painter.drawText(10, i * 30, "hello world"); //按照坐标（或矩形）输出,文本为QString类型，有多种重载函数，随便用哪一种

	//text_painter.end();

	//Qt5 pdfwriter生成pdf
	QString file_path1 = QFileDialog::getSaveFileName(this, "输入待导出的报告存储位置", QString(), "*.pdf");  //用文件对话框设置输出路径
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //或者 file_path+=".pdf"
		}
	}

	QFile pdfFile(file_path1);
	pdfFile.open(QIODevice::WriteOnly);                 // 打开要写入的pdf文件
	QPdfWriter* pPdfWriter = new QPdfWriter(&pdfFile);  // 创建pdf写入器
	pPdfWriter->setPageSize(QPagedPaintDevice::A4);     // 设置纸张为A4
	pPdfWriter->setResolution(300);                     // 设置纸张的分辨率为300,因此其像素为3508X2479

	int iMargin = 60;                   // 页边距
	pPdfWriter->setPageMargins(QMarginsF(iMargin, iMargin, iMargin, iMargin));

	QPainter* pPdfPainter = new QPainter(pPdfWriter);   // qt绘制工具

														// 标题,居中
	QTextOption option(Qt::AlignHCenter | Qt::AlignVCenter);
	option.setWrapMode(QTextOption::WordWrap);

	// 标题上边留白
	int iTop = 100;

	// 文本宽度2100
	int iContentWidth = 2100;

	// 标题,22号字
	QFont font;
	//font.setFamily("simhei.ttf");
	int fontSize = 22;
	font.setPointSize(fontSize);
	pPdfPainter->setFont(font);                    // 为绘制工具设置字体
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 90),
		"我的标题我骄傲", option);

	// 内容,16号字，左对齐
	fontSize = 16;
	font.setPointSize(fontSize);
	pPdfPainter->setFont(font);
	option.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	iTop += 60;
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 60),
		QString::fromLocal8Bit("1、目录一"));
	iTop += 60;
	// 左侧缩进2字符
	int iLeft = 120;
	pPdfPainter->drawText(QRect(iLeft, iTop, iContentWidth - iLeft, 60),
		QString::fromLocal8Bit("我的目录一的内容。"), option);
	iTop += 60;
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 60), QString::fromLocal8Bit("2、目录二"));
	iTop += 60;
	pPdfPainter->drawText(QRect(iLeft, iTop, iContentWidth - iLeft, 60),
		QString::fromLocal8Bit("我的目录一的内容"), option);

	delete pPdfPainter;
	delete pPdfWriter;
	pdfFile.close();
#endif
	QString file_path1 = QFileDialog::getSaveFileName(this, "输入待导出的报告存储位置", QString(), "*.pdf");  //用文件对话框设置输出路径
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //或者 file_path+=".pdf"
		}
	}
	QPrinter printer_text;
	printer_text.setOutputFormat(QPrinter::PdfFormat);
	printer_text.setOutputFileName(file_path1);//pdfname为要保存的pdf文件名
	printer_text.setPageSize(QPrinter::A4); //设置纸张尺寸，默认不设置就是A4

	QTextDocument text_document;
	QTextDocument text_document2;

	QString html = GeneratePicWord();//自定义的函数，用来生成html代码
	text_document.setHtml(html);
	text_document.print(&printer_text);
	printer_text.newPage();
	text_document2.setHtml(html);
	text_document2.print(&printer_text);
	//QTextBlock it = text_document.end();
	// it = text_document2.end();



}

QString place::GeneratePicWord()
{
	QStringList title0;
	title0.push_back(("名称"));
	title0.push_back(("内容"));


	QString html;
	//第一页文字部分
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	html += QString("<th><font size = \"14\">应急演练评估结果</font>   </th>");
	for (int k = 0; k <= 3; k++)
	{
		html += "<br / >";
	}
	html += "<h3 align=\"center\">" + current_date + "</h3><br>";

	QString a[12];
	a[0] = "系统评估场景：";
	a[2] = "评估队伍名称：";
	a[4] = "自动评估分数：";
	a[6] = "人工评估分数：";
	a[8] = "合计评估分数：";
	a[10] = "合计持续时间：";
	a[1] = ui.label_12->text();
	a[3] = Team_name;
	a[5] = QString::number(score_auto_all, 10);
	a[7] = QString::number(score, 10);
	a[9] = QString::number(score_finish, 'g', 6);
	a[11] = Timing;
	for (int k = 0; k <= 13; k++)
	{
		html += "<br / >";
	}
	//表格1部分
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"400\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >";

	//html += "<table align=\"center\" border=\"1\" cellspacing=\"0\" cellpadding=\"0\"  style=\"width: 100%; height: 100%;\"margin-left:-200\">";
	for (int i = 0; i < title0.count(); i++)
	{

		html += QString("<th><font size=\"6\" >%1</font>   </th>").arg(title0.at(i));

	}
	for (int i = 0; i < 12; i=i+2)
	{
		html += "< font size = \"10\">";
		html += "<tr>";
		html += QString("<td align=\"center\"><font size=\"5\" >%1</font></td>").arg(a[i]);
		html += QString("<td align=\"center\"><font size=\"5\" >%1</font></td>").arg(a[i+1]);
		html += "</tr>";
		html += "</font>";
	}
	html += "</table>";
	html += "</div>";
	for (int k=0; k <= 30; k++)
	{
		html += "<br / >";
	}
	html += QString("<th><font size = \"10\">评分情况</font>   </th>");

	//表格2部分
	QStringList title;
	title.push_back(("评估项目"));
	title.push_back(("评估内容及要求"));
	title.push_back(("评估结果"));
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"500\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >" ;

	for (int i = 0; i < title.count(); i++)
	{

		html +=QString("<th><font size=\"5\">%1</font>   </th>").arg(title.at(i));

	}
	html +="< font size = \"3\">";
	QString b[105][2];
	b[0][0]="检验预案";	b[0][1] =  "1、是否通过开展应急演练，查找应急预案中存在的问题";
	b[1][0] = "检验预案";b[1][1] = "2、是否提出完善应急预案意见";
	b[2][0] = "检验预案";b[2][1] = "3、是否提出提高应急预案的实用性和可操作性针对性意见";
	b[3][0] = "完善准备";b[3][1] = "1、应急队伍是否进行配备，是否满足现在应急救援需要";
	b[4][0] = "完善准备"; b[4][1] = "2、是否进行现场应急救援物资、装备储备，是否满足现场应急救援需要";
	b[5][0] = "完善准备"; b[5][1] = "3、是否进行应急救援技术准备，准备情况是否到位";
	b[6][0] = "锻炼队伍"; b[6][1] = "1、是否增强演练组织单位、参与单位和人员等对应急预案的熟悉程度";
	b[7][0] = "锻炼队伍"; b[7][1] = "2、是否有效提高演练单位、人员应急处置能力";
	b[8][0] = "磨合机制"; b[8][1] = "1、是否进一步明确相关单位和人员的职责，理顺工作关系";
	b[9][0] = "磨合机制"; b[9][1] = "2、是否有效提高应急指挥员的指挥协调能力";
	b[10][0] = "磨合机制"; b[10][1] = "3、应急救援机制是否运转有序";

	b[11][0] = "磨合机制"; b[11][1] = "4、是否进一步完善应急机制";
	b[12][0] = "科普宣教"; b[12][1] = "通过开展应急演练，是否达到普及应急知识，提高公众风险防范意识和自救呼救等灾害应对能力的目的";
	b[13][0] = "应急演练目标制定"; b[13][1] = "1、是否制定应急演练目标";
	b[14][0] = "应急演练目标制定"; b[14][1] = "2、应急演练目标是否完善、有针对性";
	b[15][0] = "应急演练目标制定"; b[15][1] = "3、演练目标是否可行";
	b[16][0] = "应急演练原则"; b[16][1] = "1、是否结合实际、合理定位";
	b[17][0] = "应急演练原则"; b[17][1] = "2、是否着眼实战、讲求实效";
	b[18][0] = "应急演练原则"; b[18][1] = "3、是否精心组织、确保安全";
	b[19][0] = "应急演练原则"; b[19][1] = "4、是否统筹规划、厉行节约";
	b[20][0] = "应急演练分类"; b[20][1] = "1、按组织形式划分，本次应急演练类别为：①桌面演练；②实战演练";

	b[21][0] = "应急演练分类"; b[21][1] = "2、按内容划分，本次应急演练类别为：①单项演练；②综合演练";
	b[22][0] = "应急演练分类"; b[22][1] = "3、按目的与作用划分，本次应急演练类别为：①检验性演练；②示范性演练；③研究性演练";
	b[23][0] = "应急演练计划"; b[23][1] = "1、是否根据实际情况，制定应急演练计划";
	b[24][0] = "应急演练计划"; b[24][1] = "2、演练计划（方案）是否符合相关法律法规和应急预案规定";
	b[25][0] = "应急演练计划"; b[25][1] = "3、演练计划（方案）是否符合按照先“单项后综合、先桌面后实战、循序渐进、时空有序”的原则制定";
	b[26][0] = "应急演练计划"; b[26][1] = "4、演练计划（方案）中是否合理规划应急演练的频次、规模、形式、时间、地点等";
	b[27][0] = "应急演练组织机构"; b[27][1] = "1、是否成立应急演练组织机构";
	b[28][0] = "应急演练组织机构"; b[28][1] = "2、应急演练组织机构是否完善，职责是否明确";
	b[29][0] = "应急演练组织机构"; b[29][1] = "3、应急演练组织机构是否按照“策划、保障、实施、评估”进行职能分工";
	b[30][0] = "应急演练组织机构"; b[30][1] = "4、参演队伍是否包括应急预案管理部门人员、专兼职应急救援队伍以及志愿者队伍等";

	b[31][0] = "应急演练情景是否包括"; b[31][1] = "1、事件类别";
	b[32][0] = "应急演练情景是否包括"; b[32][1] = "2、发生的时间地点";
	b[33][0] = "应急演练情景是否包括"; b[33][1] = "3、发展速度、强度与危险性";
	b[34][0] = "应急演练情景是否包括"; b[34][1] = "4、受影响范围、人员和物资分布";
	b[35][0] = "应急演练情景是否包括"; b[35][1] = "5、已造成的损失、后续发展预测";
	b[36][0] = "应急演练情景是否包括"; b[36][1] = "6、气象及其他环境条件";
	b[37][0] = "人员保障是否包括"; b[37][1] = "1、演练领导小组、演练总指挥、总策划";
	b[38][0] = "人员保障是否包括"; b[38][1] = "2、文案人员、控制人员、评估人员、保障人员";
	b[39][0] = "人员保障是否包括"; b[39][1] = "3、参演人员、模拟人员";
	b[40][0] = "经费保障"; b[40][1] = "1、应急演练经费是否纳入年度预算";

	b[41][0] = "经费保障"; b[41][1] = "2、应急演练经费是否及时拨付";
	b[42][0] = "经费保障"; b[42][1] = "3、演练经费专款专用、节约高效";
	b[43][0] = "场地保障"; b[43][1] = "1、是否选择合适的演练场地";
	b[44][0] = "场地保障"; b[44][1] = "2、演练场的是否有足够的空间、良好的交通、生活、卫生和生产条件";
	b[45][0] = "场地保障"; b[45][1] = "3、是否干扰公众生产生活";
	b[46][0] = "物资器材保障"; b[46][1] = "1、应急预案和演练方案是否有纸质文本、演示文档等信息材料";
	b[47][0] = "物资器材保障"; b[47][1] = "2、应急抢修物资准备是否满足演练要求";
	b[48][0] = "物资器材保障"; b[48][1] = "3、是否能够全面模拟演练场景";
	b[49][0] = "通信保障"; b[49][1] = "1、应急指挥机构、总策划、控制人员、参演人员、模拟人员等；之间是否建立及时可靠的信息传递渠道";
	b[50][0] = "通信保障"; b[50][1] = "2、通讯器材配置是否满足抢险救援内部、外部通信联络需要";

	b[51][0] = "通信保障"; b[51][1] = "3、演练现场是否建立多种公共和专用通信信息网络";
	b[52][0] = "通信保障"; b[52][1] = "4、能否保证演练控制信息的快速传递";
	b[53][0] = "安全保障"; b[53][1] = "1、是否针对应急演练可能出现的风险制定预防控制措施";
	b[54][0] = "安全保障"; b[54][1] = "2、是否根据需要为演练人员配备个体防护装备";
	b[55][0] = "安全保障"; b[55][1] = "3、演练现场是否有必要的安保措施，是否对演练现场进行封闭或管制，保证演练安全进行";
	b[56][0] = "演练启动"; b[56][1] = "演练前，演练总指挥是否对演练的意义、目标、组织机构及职能分工、演练方案、演练程序、注意事项进行统一说明";
	b[57][0] = "演练指挥与行动"; b[57][1] = "1、是否由演练总指挥负责演练实施全过程的指挥控制";
	b[58][0] = "演练指挥与行动"; b[58][1] = "2、应急指挥机构是否按照演练方案指挥各参演队伍和人员，开展模拟演练事件的应急处置行动，完成各项演练活动";
	b[59][0] = "演练指挥与行动"; b[59][1] = "3、演练控制人员是否充分掌握演练方案，按演练方案的要求，熟练发布控制信息，协调参演人员完成各项演练任务";
	b[60][0] = "演练指挥与行动"; b[60][1] = "4、参演人员是否严格执行控制消息和指令，按照演练方案规定的程序开展应急处置行动，完成各项演练活动";

	b[61][0] = "演练指挥与行动"; b[61][1] = "5、模拟人员是否按照演练方案要求，模拟未参加演练的单位或人员的行动，并作出信息反馈";
	b[62][0] = "演练过程控制"; b[62][1] = "1）在讨论式桌面演练中；演练活动是否围绕对所提出问题进行讨论";
	b[63][0] = "演练过程控制"; b[63][1] = "2）是否由总策划以口头或书面形式，部署引入一个或若干个问题";
	b[64][0] = "演练过程控制"; b[64][1] = "3）参演人员是否根据应急预案及相关规定，讨论应采取的行动";
	b[65][0] = "演练过程控制"; b[65][1] = "4）由总策划按照演练方案发出控制消息，参演人员接受到事件信息后，是否通过角色扮演或模拟操作，完成应急处置活动";
	b[66][0] = "演练过程控制"; b[66][1] = "1）在实战演练中，是否要通过传递控制消息来控制演练过程";
	b[67][0] = "演练过程控制"; b[67][1] = "2）总策划按照演练方案发出控制消息后，控制人员是否立即向参演人员和模拟人员传递控制消息";
	b[68][0] = "演练过程控制"; b[68][1] = "3）参演人员和模拟人员接受到信息后，是否按照发生真实事件时的应急处置程序或根据应急行动方案，采取相应的应急处置行动；";
	b[69][0] = "演练过程控制"; b[69][1] = "4）演练过程中，控制人员是否随时掌握演练进展情况，并向总策划报告演练中出现的各种问题。";
	b[70][0] = "演练解说"; b[70][1] = "1、在演练实施过程中，是否安排专人对演练进行解说";

	b[71][0] = "演练解说"; b[71][1] = "2、是否包含演练背景描述";
	b[72][0] = "演练解说"; b[72][1] = "3、是否包含进程讲解";
	b[73][0] = "演练解说"; b[73][1] = "4、是否包含案例介绍";
	b[74][0] = "演练解说"; b[74][1] = "5、是否包含环境渲染";
	b[75][0] = "演练记录"; b[75][1] = "1、在演练实施过程中，是否安排专门人员，采用文字、照片和音像等手段记录演练过程；";
	b[76][0] = "演练记录是否包含"; b[76][1] = "1）演练实际开始与结束时间；";
	b[77][0] = "演练记录是否包含"; b[77][1] = "2）演练过程控制情况；";
	b[78][0] = "演练记录是否包含"; b[78][1] = "3）各项演练活动中参演人员的表现；";
	b[79][0] = "演练记录是否包含"; b[79][1] = "4）意外情况及其处置；";
	b[80][0] = "演练记录是否包含"; b[80][1] = "5）是否详细记录可能出现的人员“伤亡”（如进入“危险”场所而无安全防护，在所规定的时间内不能完成疏散等）及财产“损失”等情况";

	b[81][0] = "演练记录是否包含"; b[81][1] = "6）文字、照片照片和音像记录是否全方位反映演练实施过程";
	b[82][0] = "宣传教育"; b[82][1] = "1、是否针对应急演练对其他人员进行宣传教育；";
	b[83][0] = "宣传教育"; b[83][1] = "2、通过宣传教育是否有效提高其他人员的抢险救援意识、普及抢险救援知识和技能。";
	b[84][0] = "应急演练结束与终止"; b[84][1] = "1、演练完毕，是否由总策划发出结束信号，演练总指挥宣布演练结束";
	b[85][0] = "应急演练结束与终止"; b[85][1] = "2、演练结束后所有人员是否停止演练活动，按预定方案集合进行现场总结讲评或者组织疏散";
	b[86][0] = "应急演练结束与终止"; b[86][1] = "3、演练结束后是否指定专人负责组织人员对演练现场进行清理和恢复";
	b[87][0] = "演练评估"; b[87][1] = "1、演练结束后是否组织有关人员对应急演练过程进行评估。";
	b[88][0] = "演练评估是否包括"; b[88][1] = "1）演练执行情况";
	b[89][0] = "演练评估是否包括"; b[89][1] = "2）预案的合理性和可操作性";
	b[90][0] = "演练评估是否包括"; b[90][1] = "3）应急指挥人员的指挥协调能力";


	b[91][0] = "演练评估是否包括"; b[91][1] = "4）参演人员的处置能力";
	b[92][0] = "演练评估是否包括"; b[92][1] = "5）演练所用设备的适用性";
	b[93][0] = "演练评估是否包括"; b[93][1] = "6）演练目标的实现情况、演练的成本效益分析、对完善预案的建议等";
	b[94][0] = "演练总结"; b[94][1] = "1、演练结束后演练单位是否对演练进行系统和全面总结，并形成演练总结报告";
	b[95][0] = "演练总结是否包括"; b[95][1] = "1）演练目的";
	b[96][0] = "演练总结是否包括"; b[96][1] = "2）时间和地点";
	b[97][0] = "演练总结是否包括"; b[97][1] = "3）参演单位和人员";
	b[98][0] = "演练总结是否包括"; b[98][1] = "4）演练方案概要";
	b[99][0] = "演练总结是否包括"; b[99][1] = "5）发现的问题与原因，经验和教训、以及改进有关工作的建议等";
	b[100][0] = "成功运用"; b[100][1] = "1、对演练中暴露出来的问题，演练单位是否及时采取措施予以改进";

	b[101][0] = "成功运用"; b[101][1] = "2、是否及时组织对应急预案的修订、完善";
	b[102][0] = "成功运用"; b[102][1] = "3、是否有针对性的加强应急人员地教育和培训";
	b[103][0] = "成功运用"; b[103][1] = "4、是否对应急物资装备进行有计划地更新等";
	QString resurt;
	pdf_form_data_1();
	for (int i = 0; i < 104; i++)
	{
		html += "<tr>";
		if (i!=20&& i != 21 && i != 22)
		{
			if (pdf_data[i] == 0)
				resurt = "是";
			else if (pdf_data[i] == 1)
				resurt = "否";
			else if (pdf_data[i] == 4)
				resurt = "空缺";
		}
		else
		{
			if (pdf_data[i] == 0)
				resurt = "选项1";
			else if (pdf_data[i] == 1)
				resurt = "选项2";
			else if (pdf_data[i] == 2)
				resurt = "选项3";
			else if (pdf_data[i] == 4)
				resurt = "空缺";
		}
	    html += QString( "<td align=\"center\"><font size=\"4\">%1</font></td>").arg(b[i][0]);
		html += QString("<td align=\"center\"><font size=\"4\">%1</font></td>").arg(b[i][1]);
		html += QString("<td align=\"center\"><font size=\"4\">%1</font></td>").arg(resurt);
		html += "</tr>";
	}
	html += "</font></table>";
	html += "</div>";

	return html;
}
QString place::GeneratePicWord1()
{
	QStringList title0;
	title0.push_back(("名称"));
	title0.push_back(("内容"));


	QString html;
	//第一页文字部分
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	html += QString("<th><font size = \"14\">应急演练评估结果</font>   </th>");
	for (int k = 0; k <= 3; k++)
	{
		html += "<br / >";
	}
	html += "<h3 align=\"center\">" + current_date + "</h3><br>";

	QString a[12];
	a[0] = "系统评估场景：";
	a[2] = "评估队伍名称：";
	a[4] = "自动评估分数：";
	a[6] = "人工评估分数：";
	a[8] = "合计评估分数：";
	a[10] = "合计持续时间：";
	a[1] = ui.label_12->text();
	a[3] = Team_name;
	a[5] = QString::number(score_auto_all, 10);
	a[7] = QString::number(score, 10);
	a[9] = QString::number(score_finish, 'g', 6);
	a[11] = Timing;
	for (int k = 0; k <= 13; k++)
	{
		html += "<br / >";
	}
	//表格1部分
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"400\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >";

	//html += "<table align=\"center\" border=\"1\" cellspacing=\"0\" cellpadding=\"0\"  style=\"width: 100%; height: 100%;\"margin-left:-200\">";
	for (int i = 0; i < title0.count(); i++)
	{

		html += QString("<th><font size=\"6\" >%1</font>   </th>").arg(title0.at(i));

	}
	for (int i = 0; i < 12; i = i + 2)
	{
		html += "< font size = \"10\">";
		html += "<tr>";
		html += QString("<td align=\"center\"><font size=\"5\" >%1</font></td>").arg(a[i]);
		html += QString("<td align=\"center\"><font size=\"5\" >%1</font></td>").arg(a[i + 1]);
		html += "</tr>";
		html += "</font>";
	}
	html += "</table>";
	html += "</div>";
	for (int k = 0; k <= 30; k++)
	{
		html += "<br / >";
	}
	html += QString("<th><font size = \"10\">评分情况</font>   </th>");

	//表格2部分
	QStringList title;
	title.push_back(("评估项目"));
	title.push_back(("评估内容及要求"));
	title.push_back(("评估结果"));
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"500\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >";

	for (int i = 0; i < title.count(); i++)
	{

		html += QString("<th><font size=\"5\">%1</font>   </th>").arg(title.at(i));

	}
	html += "< font size = \"3\">";
	QString b[28][3];
	b[0][0] = "演练保障";	b[0][1] = "安全保障性";
	b[1][0] = "演练保障"; b[1][1] = "医疗保障性";
	b[2][0] = "演练保障"; b[2][1] = "通讯保障程度";
	b[3][0] = "演练保障"; b[3][1] = "人员保障完善度";
	b[4][0] = "演练保障"; b[4][1] = "器材保障度";
	b[5][0] = "演练保障"; b[5][1] = "场地保障度";
	b[6][0] = "演练目标和计划"; b[6][1] = "演练目标的明确性";
	b[7][0] = "演练目标和计划"; b[7][1] = "演练计划的合理性";
	b[8][0] = "演练目标和计划"; b[8][1] = "指挥人员对演练计划的明确度";
	b[9][0] = "演练目标和计划"; b[9][1] = "参演人员对于演练目标明确度";
	b[10][0] = "指挥人员和救援人员的能力"; b[10][1] = "任务分配的合理程度";

	b[11][0] = "指挥人员和救援人员的能力"; b[11][1] = "任务分配明确程度";
	b[12][0] = "指挥人员和救援人员的能力"; b[12][1] = "演练通讯情况";
	b[13][0] = "指挥人员和救援人员的能力"; b[13][1] = "演练人员对计划遵守程度";
	b[14][0] = "指挥人员和救援人员的能力"; b[14][1] = "对于特殊情况的处置能力";
	b[15][0] = "指挥人员和救援人员的能力"; b[15][1] = "指挥人员对于演练现场的掌握情况";
	b[16][0] = "指挥人员和救援人员的能力"; b[16][1] = "对于救援细节的处理情况";
	b[17][0] = "指挥人员和救援人员的能力"; b[17][1] = "现场救援秩序情况";
	b[18][0] = "指挥人员和救援人员的能力"; b[18][1] = "对于不法分子追捕能力";
	b[19][0] = "指挥人员和救援人员的能力"; b[19][1] = "行动效率";
	b[20][0] = "指挥人员和救援人员的能力"; b[20][1] = "对于现场的保护情况";

	b[21][0] = "指挥人员和救援人员的能力"; b[21][1] = "人员受伤情况";
	b[22][0] = "指挥人员和救援人员的能力"; b[22][1] = "演练人员救援技能熟练度";
	b[23][0] = "指挥人员和救援人员的能力"; b[23][1] = "演练人员的协作能力";
	b[24][0] = "演练结束"; b[24][1] = "演练花费的时间";
	b[25][0] = "演练结束"; b[25][1] = "救援结束后现场的处理情况";
	b[26][0] = "演练结束"; b[26][1] = "被救援人员的安置和救护情况";
	b[27][0] = "演练结束"; b[27][1] = "演练结束人员集合和疏散情况";

	b[0][2] = ui.lineEdit_score1->text();
	b[1][2] = ui.lineEdit_score2->text();
	b[2][2] = ui.lineEdit_score3->text();
	b[3][2] = ui.lineEdit_score4->text();
	b[4][2] = ui.lineEdit_score5->text();
	b[5][2] = ui.lineEdit_score6->text();
	b[6][2] = ui.lineEdit_score7->text();
	b[7][2] = ui.lineEdit_score8->text();
	b[8][2] = ui.lineEdit_score9->text();
	b[9][2] = ui.lineEdit_score10->text();
	b[10][2] = ui.lineEdit_score11->text();

	b[11][2] = ui.lineEdit_score12->text(); 
	b[12][2] = ui.lineEdit_score13->text();
	b[13][2] = ui.lineEdit_score14->text();
	b[14][2] = ui.lineEdit_score15->text();
	b[15][2] = ui.lineEdit_score16->text();
	b[16][2] = ui.lineEdit_score17->text();
	b[17][2] = ui.lineEdit_score18->text();
	b[18][2] = ui.lineEdit_score19->text();
	b[19][2] = ui.lineEdit_score20->text();
	b[20][2] = ui.lineEdit_score21->text();

	b[21][2] = ui.lineEdit_score22->text();
	b[22][2] = ui.lineEdit_score23->text();
	b[23][2] = ui.lineEdit_score24->text();
	b[24][2] = ui.lineEdit_score25->text();
	b[25][2] = ui.lineEdit_score26->text();
	b[26][2] = ui.lineEdit_score27->text();
	b[27][2] = ui.lineEdit_score28->text();
	QString resurt;
	for (int i = 0; i < 28; i++)
	{
		html += "<tr>";
		if (b[i][2]=="")
		{
				resurt = "空缺";	
		}
		else
		{
			resurt = b[i][2];
		}
		html += QString("<td align=\"center\"><font size=\"4\">%1</font></td>").arg(b[i][0]);
		html += QString("<td align=\"center\"><font size=\"4\">%1</font></td>").arg(b[i][1]);
		html += QString("<td align=\"center\"><font size=\"4\">%1</font></td>").arg(resurt);
		html += "</tr>";
	}
	html += "</font></table>";
	html += "</div>";

	return html;
}
void place::onRestart()
{
	qApp->exit(777);
}
void place::closeEvent(QCloseEvent * e)
{
	//this->close();
	if (1)
	{
		int button;
		button = QMessageBox::question(this, tr("退出"),
			QString(tr("确认退出评估?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
			e->ignore();  //忽略退出信号，程序继续运行
		}
		else if (button == QMessageBox::Yes) {
			e->accept();  //接受退出信号，程序退出
			
		}
	
	}
	else
	{
	

	}
}
void place::Click_pushButton_save()
{
	for (int a = 0; a<105; a++)
	{
		score2[a][0] = "N";
		score2[a][1] = "N";
		score2[a][2] = "N";
	}
	for (int a = 0; a<105; a++)
	{
		form_2_weight[a][0] = 1;
		form_2_weight[a][1] = 2;
		form_2_weight[a][2] = 3;
	}
	QString inf;
	inf = QString::number(score, 10);
	score = 0;
	score2[0][0] = ui.radioButton_1_1->isChecked() ?  "Y" : "N";
	score2[0][1] = ui.radioButton_1_2->isChecked() ? "Y" : "N";
	score2[1][0] = ui.radioButton_1_3->isChecked() ? "Y" : "N";
	score2[1][1] = ui.radioButton_1_4->isChecked() ? "Y" : "N";
	score2[2][0] = ui.radioButton_1_5->isChecked() ? "Y" : "N";
	score2[2][1] = ui.radioButton_1_6->isChecked() ? "Y" : "N";
	score2[3][0] = ui.radioButton_1_7->isChecked() ? "Y" : "N";
	score2[3][1] = ui.radioButton_1_8->isChecked() ? "Y" : "N";
	score2[4][0] = ui.radioButton_1_9->isChecked() ? "Y" : "N";
	score2[4][1] = ui.radioButton_1_10->isChecked() ? "Y" : "N";
	score2[5][0] = ui.radioButton_1_11->isChecked() ? "Y" : "N";
	score2[5][1] = ui.radioButton_1_12->isChecked() ? "Y" : "N";
	score2[6][0] = ui.radioButton_1_13->isChecked() ? "Y" : "N";
	score2[6][1] = ui.radioButton_1_14->isChecked() ? "Y" : "N";
	score2[7][0] = ui.radioButton_1_15->isChecked() ? "Y" : "N";
	score2[7][1] = ui.radioButton_1_16->isChecked() ? "Y" : "N";
	score2[8][0] = ui.radioButton_1_17->isChecked() ? "Y" : "N";
	score2[8][1] = ui.radioButton_1_18->isChecked() ? "Y" : "N";
	score2[9][0] = ui.radioButton_1_19->isChecked() ? "Y" : "N";
	score2[9][1] = ui.radioButton_1_20->isChecked() ? "Y" : "N";
	score2[10][0] = ui.radioButton_1_21->isChecked() ? "Y" : "N";
	score2[10][1] = ui.radioButton_1_22->isChecked() ? "Y" : "N";
	score2[11][0] = ui.radioButton_1_23->isChecked() ? "Y" : "N";
	score2[11][1] = ui.radioButton_1_24->isChecked() ? "Y" : "N";
	score2[12][0] = ui.radioButton_1_25->isChecked() ? "Y" : "N";
	score2[12][1] = ui.radioButton_1_26->isChecked() ? "Y" : "N";

	score2[13][0] = ui.radioButton_2_1->isChecked() ? "Y" : "N";
	score2[13][1] = ui.radioButton_2_2->isChecked() ? "Y" : "N";
	score2[14][0] = ui.radioButton_2_3->isChecked() ? "Y" : "N";
	score2[14][1] = ui.radioButton_2_4->isChecked() ? "Y" : "N";
	score2[15][0] = ui.radioButton_2_5->isChecked() ? "Y" : "N";
	score2[15][1] = ui.radioButton_2_6->isChecked() ? "Y" : "N";
	score2[16][0] = ui.radioButton_2_7->isChecked() ? "Y" : "N";
	score2[16][1] = ui.radioButton_2_8->isChecked() ? "Y" : "N";
	score2[17][0] = ui.radioButton_2_9->isChecked() ? "Y" : "N";
	score2[17][1] = ui.radioButton_2_10->isChecked() ? "Y" : "N";
	score2[18][0] = ui.radioButton_2_11->isChecked() ? "Y" : "N";
	score2[18][1] = ui.radioButton_2_12->isChecked() ? "Y" : "N";
	score2[19][0] = ui.radioButton_2_13->isChecked() ? "Y" : "N";
	score2[19][1] = ui.radioButton_2_14->isChecked() ? "Y" : "N";
	score2[20][0] = ui.radioButton_2_15->isChecked() ? "Y" : "N";//1
	score2[20][1] = ui.radioButton_2_16->isChecked() ? "Y" : "N";
	score2[21][0] = ui.radioButton_2_17->isChecked() ? "Y" : "N";//2
	score2[21][1] = ui.radioButton_2_18->isChecked() ? "Y" : "N";
	score2[22][0] = ui.radioButton_2_19->isChecked() ? "Y" : "N";//3
	score2[22][1] = ui.radioButton_2_20->isChecked() ? "Y" : "N";
	score2[22][2] = ui.radioButton_2_21->isChecked() ? "Y" : "N";
	score2[23][0] = ui.radioButton_2_22->isChecked() ? "Y" : "N";
	score2[23][1] = ui.radioButton_2_23->isChecked() ? "Y" : "N";
	score2[24][0] = ui.radioButton_2_24->isChecked() ? "Y" : "N";
	score2[24][1] = ui.radioButton_2_25->isChecked() ? "Y" : "N";
	score2[25][0] = ui.radioButton_2_26->isChecked() ? "Y" : "N";
	score2[25][1] = ui.radioButton_2_27->isChecked() ? "Y" : "N";
	score2[26][0] = ui.radioButton_2_28->isChecked() ? "Y" : "N";
	score2[26][1] = ui.radioButton_2_29->isChecked() ? "Y" : "N";
	score2[27][0] = ui.radioButton_2_30->isChecked() ? "Y" : "N";
	score2[27][1] = ui.radioButton_2_31->isChecked() ? "Y" : "N";
	score2[28][0] = ui.radioButton_2_32->isChecked() ? "Y" : "N";
	score2[28][1] = ui.radioButton_2_33->isChecked() ? "Y" : "N";
	score2[29][0] = ui.radioButton_2_34->isChecked() ? "Y" : "N";
	score2[29][1] = ui.radioButton_2_35->isChecked() ? "Y" : "N";
	score2[30][0] = ui.radioButton_2_36->isChecked() ? "Y" : "N";
	score2[30][1] = ui.radioButton_2_37->isChecked() ? "Y" : "N";
	score2[31][0] = ui.radioButton_2_38->isChecked() ? "Y" : "N";
	score2[31][1] = ui.radioButton_2_39->isChecked() ? "Y" : "N";
	score2[32][0] = ui.radioButton_2_40->isChecked() ? "Y" : "N";
	score2[32][1] = ui.radioButton_2_41->isChecked() ? "Y" : "N";
	score2[33][0] = ui.radioButton_2_42->isChecked() ? "Y" : "N";
	score2[33][1] = ui.radioButton_2_43->isChecked() ? "Y" : "N";
	score2[34][0] = ui.radioButton_2_44->isChecked() ? "Y" : "N";
	score2[34][1] = ui.radioButton_2_45->isChecked() ? "Y" : "N";
	score2[35][0] = ui.radioButton_2_46->isChecked() ? "Y" : "N";
	score2[35][1] = ui.radioButton_2_47->isChecked() ? "Y" : "N";
	score2[36][0] = ui.radioButton_2_48->isChecked() ? "Y" : "N";
	score2[36][1] = ui.radioButton_2_49->isChecked() ? "Y" : "N";
	score2[37][0] = ui.radioButton_2_50->isChecked() ? "Y" : "N";
	score2[37][1] = ui.radioButton_2_51->isChecked() ? "Y" : "N";
	score2[38][0] = ui.radioButton_2_52->isChecked() ? "Y" : "N";
	score2[38][1] = ui.radioButton_2_53->isChecked() ? "Y" : "N";
	score2[39][0] = ui.radioButton_2_54->isChecked() ? "Y" : "N";
	score2[39][1] = ui.radioButton_2_55->isChecked() ? "Y" : "N";
	score2[40][0] = ui.radioButton_2_56->isChecked() ? "Y" : "N";
	score2[40][1] = ui.radioButton_2_57->isChecked() ? "Y" : "N";
	score2[41][0] = ui.radioButton_2_58->isChecked() ? "Y" : "N";
	score2[41][1] = ui.radioButton_2_59->isChecked() ? "Y" : "N";
	score2[42][0] = ui.radioButton_2_60->isChecked() ? "Y" : "N";
	score2[42][1] = ui.radioButton_2_61->isChecked() ? "Y" : "N";
	score2[43][0] = ui.radioButton_2_62->isChecked() ? "Y" : "N";
	score2[43][1] = ui.radioButton_2_63->isChecked() ? "Y" : "N";
	score2[44][0] = ui.radioButton_2_64->isChecked() ? "Y" : "N";
	score2[44][1] = ui.radioButton_2_65->isChecked() ? "Y" : "N";
	score2[45][0] = ui.radioButton_2_66->isChecked() ? "Y" : "N";
	score2[45][1] = ui.radioButton_2_67->isChecked() ? "Y" : "N";
	score2[46][0] = ui.radioButton_2_68->isChecked() ? "Y" : "N";
	score2[46][1] = ui.radioButton_2_69->isChecked() ? "Y" : "N";
	score2[47][0] = ui.radioButton_2_70->isChecked() ? "Y" : "N";
	score2[47][1] = ui.radioButton_2_71->isChecked() ? "Y" : "N";
	score2[48][0] = ui.radioButton_2_72->isChecked() ? "Y" : "N";
	score2[48][1] = ui.radioButton_2_73->isChecked() ? "Y" : "N";
	score2[49][0] = ui.radioButton_2_74->isChecked() ? "Y" : "N";
	score2[49][1] = ui.radioButton_2_75->isChecked() ? "Y" : "N";
	score2[50][0] = ui.radioButton_2_76->isChecked() ? "Y" : "N";
	score2[50][1] = ui.radioButton_2_77->isChecked() ? "Y" : "N";
	score2[51][0] = ui.radioButton_2_78->isChecked() ? "Y" : "N";
	score2[51][1] = ui.radioButton_2_79->isChecked() ? "Y" : "N";
	score2[52][0] = ui.radioButton_2_80->isChecked() ? "Y" : "N";
	score2[52][1] = ui.radioButton_2_81->isChecked() ? "Y" : "N";
	score2[53][0] = ui.radioButton_2_82->isChecked() ? "Y" : "N";
	score2[53][1] = ui.radioButton_2_83->isChecked() ? "Y" : "N";
	score2[54][0] = ui.radioButton_2_84->isChecked() ? "Y" : "N";
	score2[54][1] = ui.radioButton_2_85->isChecked() ? "Y" : "N";
	score2[55][0] = ui.radioButton_2_86->isChecked() ? "Y" : "N";
	score2[55][1] = ui.radioButton_2_87->isChecked() ? "Y" : "N";
	score2[56][0] = ui.radioButton_2_88->isChecked() ? "Y" : "N";
	score2[56][1] = ui.radioButton_2_89->isChecked() ? "Y" : "N";
	score2[57][0] = ui.radioButton_2_90->isChecked() ? "Y" : "N";
	score2[57][1] = ui.radioButton_2_91->isChecked() ? "Y" : "N";
	score2[58][0] = ui.radioButton_2_92->isChecked() ? "Y" : "N";
	score2[58][1] = ui.radioButton_2_93->isChecked() ? "Y" : "N";
	score2[59][0] = ui.radioButton_2_94->isChecked() ? "Y" : "N";
	score2[59][1] = ui.radioButton_2_95->isChecked() ? "Y" : "N";
	score2[60][0] = ui.radioButton_2_96->isChecked() ? "Y" : "N";
	score2[60][1] = ui.radioButton_2_97->isChecked() ? "Y" : "N";
	score2[61][0] = ui.radioButton_2_98->isChecked() ? "Y" : "N";
	score2[61][1] = ui.radioButton_2_99->isChecked() ? "Y" : "N";
	score2[62][0] = ui.radioButton_2_100->isChecked() ? "Y" : "N";
	score2[62][1] = ui.radioButton_2_101->isChecked() ? "Y" : "N";
	score2[63][0] = ui.radioButton_2_102->isChecked() ? "Y" : "N";
	score2[63][1] = ui.radioButton_2_103->isChecked() ? "Y" : "N";
	score2[64][0] = ui.radioButton_2_104->isChecked() ? "Y" : "N";
	score2[64][1] = ui.radioButton_2_105->isChecked() ? "Y" : "N";
	score2[65][0] = ui.radioButton_2_106->isChecked() ? "Y" : "N";
	score2[65][1] = ui.radioButton_2_107->isChecked() ? "Y" : "N";
	score2[66][0] = ui.radioButton_2_108->isChecked() ? "Y" : "N";
	score2[66][1] = ui.radioButton_2_109->isChecked() ? "Y" : "N";
	score2[67][0] = ui.radioButton_2_100->isChecked() ? "Y" : "N";
	score2[67][1] = ui.radioButton_2_111->isChecked() ? "Y" : "N";
	score2[68][0] = ui.radioButton_2_112->isChecked() ? "Y" : "N";
	score2[68][1] = ui.radioButton_2_113->isChecked() ? "Y" : "N";
	score2[69][0] = ui.radioButton_2_114->isChecked() ? "Y" : "N";
	score2[69][1] = ui.radioButton_2_115->isChecked() ? "Y" : "N";
	score2[70][0] = ui.radioButton_2_116->isChecked() ? "Y" : "N";
	score2[70][1] = ui.radioButton_2_117->isChecked() ? "Y" : "N";
	score2[71][0] = ui.radioButton_2_118->isChecked() ? "Y" : "N";
	score2[71][1] = ui.radioButton_2_119->isChecked() ? "Y" : "N";
	score2[72][0] = ui.radioButton_2_120->isChecked() ? "Y" : "N";
	score2[72][1] = ui.radioButton_2_121->isChecked() ? "Y" : "N";
	score2[73][0] = ui.radioButton_2_122->isChecked() ? "Y" : "N";
	score2[73][1] = ui.radioButton_2_123->isChecked() ? "Y" : "N";
	score2[74][0] = ui.radioButton_2_124->isChecked() ? "Y" : "N";
	score2[74][1] = ui.radioButton_2_125->isChecked() ? "Y" : "N";
	score2[75][0] = ui.radioButton_2_126->isChecked() ? "Y" : "N";
	score2[75][1] = ui.radioButton_2_127->isChecked() ? "Y" : "N";
	score2[76][0] = ui.radioButton_2_128->isChecked() ? "Y" : "N";
	score2[76][1] = ui.radioButton_2_129->isChecked() ? "Y" : "N";
	score2[77][0] = ui.radioButton_2_130->isChecked() ? "Y" : "N";
	score2[77][1] = ui.radioButton_2_131->isChecked() ? "Y" : "N";
	score2[78][0] = ui.radioButton_2_132->isChecked() ? "Y" : "N";
	score2[78][1] = ui.radioButton_2_133->isChecked() ? "Y" : "N";
	score2[79][0] = ui.radioButton_2_134->isChecked() ? "Y" : "N";
	score2[79][1] = ui.radioButton_2_135->isChecked() ? "Y" : "N";
	score2[80][0] = ui.radioButton_2_136->isChecked() ? "Y" : "N";
	score2[80][1] = ui.radioButton_2_137->isChecked() ? "Y" : "N";
	score2[81][0] = ui.radioButton_2_138->isChecked() ? "Y" : "N";
	score2[81][1] = ui.radioButton_2_139->isChecked() ? "Y" : "N";
	score2[82][0] = ui.radioButton_2_140->isChecked() ? "Y" : "N";
	score2[82][1] = ui.radioButton_2_141->isChecked() ? "Y" : "N";
	score2[83][0] = ui.radioButton_2_142->isChecked() ? "Y" : "N";
	score2[83][1] = ui.radioButton_2_143->isChecked() ? "Y" : "N";
	score2[84][0] = ui.radioButton_2_144->isChecked() ? "Y" : "N";
	score2[84][1] = ui.radioButton_2_145->isChecked() ? "Y" : "N";
	score2[85][0] = ui.radioButton_2_146->isChecked() ? "Y" : "N";
	score2[85][1] = ui.radioButton_2_147->isChecked() ? "Y" : "N";
	score2[86][0] = ui.radioButton_2_148->isChecked() ? "Y" : "N";
	score2[86][1] = ui.radioButton_2_149->isChecked() ? "Y" : "N";
	score2[87][0] = ui.radioButton_2_150->isChecked() ? "Y" : "N";
	score2[87][1] = ui.radioButton_2_151->isChecked() ? "Y" : "N";
	score2[88][0] = ui.radioButton_2_152->isChecked() ? "Y" : "N";
	score2[88][1] = ui.radioButton_2_153->isChecked() ? "Y" : "N";
	score2[89][0] = ui.radioButton_2_154->isChecked() ? "Y" : "N";
	score2[89][1] = ui.radioButton_2_155->isChecked() ? "Y" : "N";
	score2[90][0] = ui.radioButton_2_156->isChecked() ? "Y" : "N";
	score2[90][1] = ui.radioButton_2_157->isChecked() ? "Y" : "N";
	score2[91][0] = ui.radioButton_2_158->isChecked() ? "Y" : "N";
	score2[91][1] = ui.radioButton_2_159->isChecked() ? "Y" : "N";
	score2[92][0] = ui.radioButton_2_160->isChecked() ? "Y" : "N";
	score2[92][1] = ui.radioButton_2_161->isChecked() ? "Y" : "N";
	score2[93][0] = ui.radioButton_2_162->isChecked() ? "Y" : "N";
	score2[93][1] = ui.radioButton_2_163->isChecked() ? "Y" : "N";
	score2[94][0] = ui.radioButton_2_164->isChecked() ? "Y" : "N";
	score2[94][1] = ui.radioButton_2_165->isChecked() ? "Y" : "N";
	score2[95][0] = ui.radioButton_2_166->isChecked() ? "Y" : "N";
	score2[95][1] = ui.radioButton_2_167->isChecked() ? "Y" : "N";
	score2[96][0] = ui.radioButton_2_168->isChecked() ? "Y" : "N";
	score2[96][1] = ui.radioButton_2_169->isChecked() ? "Y" : "N";
	score2[97][0] = ui.radioButton_2_170->isChecked() ? "Y" : "N";
	score2[97][1] = ui.radioButton_2_171->isChecked() ? "Y" : "N";
	score2[98][0] = ui.radioButton_2_172->isChecked() ? "Y" : "N";
	score2[98][1] = ui.radioButton_2_173->isChecked() ? "Y" : "N";
	score2[99][0] = ui.radioButton_2_174->isChecked() ? "Y" : "N";
	score2[99][1] = ui.radioButton_2_175->isChecked() ? "Y" : "N";
	score2[100][0] = ui.radioButton_2_176->isChecked() ? "Y" : "N";
	score2[100][1] = ui.radioButton_2_177->isChecked() ? "Y" : "N";
	score2[101][0] = ui.radioButton_2_178->isChecked() ? "Y" : "N";
	score2[101][1] = ui.radioButton_2_179->isChecked() ? "Y" : "N";
	score2[102][0] = ui.radioButton_2_180->isChecked() ? "Y" : "N";
	score2[102][1] = ui.radioButton_2_181->isChecked() ? "Y" : "N";
	score2[103][0] = ui.radioButton_2_182->isChecked() ? "Y" : "N";
	score2[103][1] = ui.radioButton_2_183->isChecked() ? "Y" : "N";

	for (int c = 0; c < 103; c++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (score2[c][b] == "Y")
			{
				score += form_2_weight[c][b];
			}
		}
		
	}
	score_finish = (score_auto_all * 4 + score * 6) / 10;

	MissOrNot = false;

	for (int c1 = 0; c1 < 103; c1++)
	{
		if (score2[c1][0] == "N"&&score2[c1][1] == "N"&&score2[c1][2] == "N")
		{
			MissNum = c1;
			MissOrNot = true;
			break;
		}
	}


	switch (MissOrNot)
	{
	case true:
	{
		int button1;
		button1 = QMessageBox::question(this, tr("完成"),
			QString(tr("有未填写的内容，是否继续?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button1 == QMessageBox::No) {
			break;
		}
		else if (button1 == QMessageBox::Yes) {
		}
	}
	case false:	
	{
		inf = "  评估场景：" + ui.label_12->text() + "\n" + "  队伍名称：" + Team_name + "\n" + "  自动评估分数：" + QString::number(score_auto_all, 10) + "\n" + "  人工评估分数：" + QString::number(score, 10) + "\n" + "  总计评估分数：" + QString::number(score_finish, 'g', 6) + "\n" + "  持续时间：" + Timing + "  ";
		QMessageBox::about(NULL, "完成", inf);
		int button;
		button = QMessageBox::question(this, tr("完成"),
			QString(tr("完成评估，确认退出评估?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {

		}
		else if (button == QMessageBox::Yes) {
			Finish = true;
			ui.tabWidget->setCurrentIndex(0);
			ui.pushButton_over->setEnabled(false);
			ui.pushButton_begin->setEnabled(true);
			ui.tabWidget_2->setCurrentIndex(0);
			onRestart();

		}
	}
	}

	
	

}
void place::Click_pushButton_save_2()//机场
{
	for (int a = 0; a<28; a++)
	{
		form_1_weight[a] = 1;
	}
	QString inf;
	inf = QString::number(score, 10);
	score = 0;
	score += ui.lineEdit_score1->text().toInt()*form_1_weight[0];
	score += ui.lineEdit_score2->text().toInt()*form_1_weight[1];
	score += ui.lineEdit_score3->text().toInt()*form_1_weight[2];
	score += ui.lineEdit_score4->text().toInt()*form_1_weight[3];
	score += ui.lineEdit_score5->text().toInt()*form_1_weight[4];
	score += ui.lineEdit_score6->text().toInt()*form_1_weight[5];
	score += ui.lineEdit_score7->text().toInt()*form_1_weight[6];
	score += ui.lineEdit_score8->text().toInt()*form_1_weight[7];
	score += ui.lineEdit_score9->text().toInt()*form_1_weight[8];
	score += ui.lineEdit_score10->text().toInt()*form_1_weight[9];
	score += ui.lineEdit_score11->text().toInt()*form_1_weight[10];
	score += ui.lineEdit_score12->text().toInt()*form_1_weight[11];
	score += ui.lineEdit_score13->text().toInt()*form_1_weight[12];
	score += ui.lineEdit_score14->text().toInt()*form_1_weight[13];
	score += ui.lineEdit_score15->text().toInt()*form_1_weight[14];
	score += ui.lineEdit_score16->text().toInt()*form_1_weight[15];
	score += ui.lineEdit_score17->text().toInt()*form_1_weight[16];
	score += ui.lineEdit_score18->text().toInt()*form_1_weight[17];
	score += ui.lineEdit_score19->text().toInt()*form_1_weight[18];
	score += ui.lineEdit_score20->text().toInt()*form_1_weight[19];
	score += ui.lineEdit_score21->text().toInt()*form_1_weight[20];
	score += ui.lineEdit_score22->text().toInt()*form_1_weight[21];
	score += ui.lineEdit_score23->text().toInt()*form_1_weight[22];
	score += ui.lineEdit_score24->text().toInt()*form_1_weight[23];
	score += ui.lineEdit_score25->text().toInt()*form_1_weight[24];
	score += ui.lineEdit_score26->text().toInt()*form_1_weight[25];
	score += ui.lineEdit_score27->text().toInt()*form_1_weight[26];
	score += ui.lineEdit_score28->text().toInt()*form_1_weight[27];
	score_finish = (score_auto_all*4 + score*6)/10;
	MissOrNot = false;

	if ((ui.lineEdit_score1->text() == NULL)||
		(ui.lineEdit_score2->text() == NULL)||
		(ui.lineEdit_score3->text() == NULL) ||
		(ui.lineEdit_score4->text() == NULL) ||
		(ui.lineEdit_score5->text() == NULL) ||
		(ui.lineEdit_score6->text() == NULL) ||
		(ui.lineEdit_score7->text() == NULL) ||
		(ui.lineEdit_score8->text() == NULL) ||
		(ui.lineEdit_score9->text() == NULL) ||
		(ui.lineEdit_score10->text() == NULL) ||
		(ui.lineEdit_score11->text() == NULL) ||
		(ui.lineEdit_score12->text() == NULL) ||
		(ui.lineEdit_score13->text() == NULL) ||
		(ui.lineEdit_score14->text() == NULL) ||
		(ui.lineEdit_score15->text() == NULL) ||
		(ui.lineEdit_score16->text() == NULL) ||
		(ui.lineEdit_score17->text() == NULL) ||
		(ui.lineEdit_score18->text() == NULL) ||
		(ui.lineEdit_score19->text() == NULL) ||
		(ui.lineEdit_score20->text() == NULL) ||
		(ui.lineEdit_score21->text() == NULL) ||
		(ui.lineEdit_score22->text() == NULL) ||
		(ui.lineEdit_score23->text() == NULL) ||
		(ui.lineEdit_score24->text() == NULL) ||
		(ui.lineEdit_score25->text() == NULL) ||
		(ui.lineEdit_score26->text() == NULL) ||
		(ui.lineEdit_score27->text() == NULL) ||
		(ui.lineEdit_score28->text() == NULL) 
		 )
		MissOrNot=true;
	switch (MissOrNot)
	{
	case true:
	{
		int button1;
		button1 = QMessageBox::question(this, tr("完成"),
			QString(tr("有未填写的内容，是否继续?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button1 == QMessageBox::No) {
			break;
		}
		else if (button1 == QMessageBox::Yes) {
		}
	}
	case false:
	{
		inf = "  评估场景：" + ui.label_12->text() + "\n" + "  队伍名称：" + Team_name + "\n" + "  自动评估分数：" + QString::number(score_auto_all, 10) + "\n" + "  人工评估分数：" + QString::number(score, 10) + "\n" + "  总计评估分数：" + QString::number(score_finish, 'g',6) + "\n" + "  持续时间：" + Timing + "  ";
		QMessageBox::about(NULL, "完成", inf);
		int button;
		button = QMessageBox::question(this, tr("完成"),
			QString(tr("完成评估，确认退出评估?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {

		}
		else if (button == QMessageBox::Yes) {
			Finish = true;
			ui.tabWidget->setCurrentIndex(0);
			ui.pushButton_over->setEnabled(false);
			ui.pushButton_begin->setEnabled(true);
			ui.tabWidget_2->setCurrentIndex(0);
			onRestart();



		}
	}
	}

	

}
void place::Click_pushButton_over()
{
	//ui.tabWidget->setTabEnabled(1, true);
	//ui.tabWidget->setTabEnabled(0, false);
	ui.tabWidget->setCurrentIndex(choose1);
	timer1->stop();
	
}
void place::Click_pushButton_begin()
{
	

	Input *p = new Input();
	p->setWindowModality(Qt::WindowModal);
	p->setWindowTitle(QObject::tr("输入评估信息"));
	p->show();
	connect(p, SIGNAL(BackTo()), this, SLOT(ToPlace()));

	

}
void place::ToPlace()
{
	begin_time = QDateTime::currentDateTime();             //获取或设置时间
	connect(timer1, SIGNAL(timeout()), this, SLOT(timing()));
	timer1->start(500);
	ui.pushButton_over->setEnabled(true);
	ui.pushButton_begin->setEnabled(false);
	ui.label_name->setText(Team_name);
	ui.label_name_2->setText(Team_name);
	ui.label_name_3->setText(Team_name);

	VirtualSensor *t = new VirtualSensor();
	t->setWindowModality(Qt::WindowModal);
	t->setWindowTitle(QObject::tr("虚拟传感器"));
	t->show();
	connect(t, SIGNAL(Test1(bool)), this, SLOT(ToContent1(bool)));
	connect(t, SIGNAL(Test2(bool)), this, SLOT(ToContent2(bool)));
	connect(t, SIGNAL(Test3(bool)), this, SLOT(ToContent3(bool)));
	connect(t, SIGNAL(Test4(bool)), this, SLOT(ToContent4(bool)));
	connect(t, SIGNAL(Test5(bool)), this, SLOT(ToContent5(bool)));
	connect(t, SIGNAL(Test6(bool)), this, SLOT(ToContent6(bool)));
	connect(t, SIGNAL(Test7(bool)), this, SLOT(ToContent7(bool)));
	connect(t, SIGNAL(Test8(bool)), this, SLOT(ToContent8(bool)));
	connect(t, SIGNAL(Test9(bool)), this, SLOT(ToContent9(bool)));
	connect(t, SIGNAL(Test10(bool)), this, SLOT(ToContent10(bool)));
	connect(t, SIGNAL(Test11(bool)), this, SLOT(ToContent11(bool)));
	connect(t, SIGNAL(Test_stop()), this, SLOT(ToContent_stop()));

}
void place::ToContent1(bool s)
{
	stage = 2;
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	if (s == true)
	{
		ui.label_finish->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[0] = 1;

	}
	else
	{
		ui.label_finish->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[0] = 0;

	}
	ui.label_finish_2->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");
	
	ui.label_content->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent2(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间

	stage = 3;
	if (s == true)
	{
		ui.label_finish_2->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[1] = 1;

	}
	else
	{
		ui.label_finish_2->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[1] = 0;

	}
	ui.label_finish_3->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");
	ui.label_content_2->setStyleSheet(QString("color: %1").arg("#999999"));


}
void place::ToContent3(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	stage = 4;
	if (s == true)
	{
		ui.label_finish_3->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[2] = 1;

	}
	else
	{
		ui.label_finish_3->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[2] = 0;

	}
	ui.label_finish_4->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");

	
	ui.label_content_3->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent4(bool s)
{

	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间

	stage = 5;
	if (s == true)
	{
		ui.label_finish_4->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[3] = 1;

	}
	else
	{
		ui.label_finish_4->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[3] = 0;

	}
	ui.label_finish_5->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");

	ui.label_content_4->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent5(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	stage = 6;
	if (s == true)
	{
		ui.label_finish_5->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[4] = 1;

	}
	else
	{
		ui.label_finish_5->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[4] = 0;

	}
	ui.label_finish_6->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");
	ui.label_content_5->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent6(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间

	stage = 7;
	if (s == true)
	{
		ui.label_finish_6->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[5] = 1;

	}
	else
	{
		ui.label_finish_6->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[5] = 0;

	}
	ui.label_finish_7->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");


	ui.label_content_6->setStyleSheet(QString("color: %1").arg("#999999"));

	
}
void place::ToContent7(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	stage = 8;
	if (s == true)
	{
		ui.label_finish_7->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[6] = 1;

	}
	else
	{
		ui.label_finish_7->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[6] = 0;

	}
	ui.label_finish_8->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");


	ui.label_content_7->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent8(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间

	stage = 9;
	if (s == true)
	{
		ui.label_finish_8->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[7] = 1;

	}
	else
	{
		ui.label_finish_8->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[7] = 0;
	}
	ui.label_finish_9->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");


	ui.label_content_8->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent9(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	stage = 10;
	if (s == true)
	{
		ui.label_finish_9->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[8] = 1;

	}
	else
	{
		ui.label_finish_9->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[8] = 0;

	}
	ui.label_finish_10->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");


	ui.label_content_9->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent10(bool s)
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	stage = 11;
	if (s == true)
	{
		ui.label_finish_10->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[9] = 1;

	}
	else
	{
		ui.label_finish_10->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[9] = 0;

	}
	ui.label_finish_11->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");


	ui.label_content_10->setStyleSheet(QString("color: %1").arg("#999999"));

}
void place::ToContent11(bool s)
{
	if (s == true)
	{
		ui.label_finish_11->setStyleSheet("border-image: url(:/FEDE/Resources/finish.png);");
		score_auto[10] = 1;

	}
	else
	{
		ui.label_finish_11->setStyleSheet("border-image: url(:/FEDE/Resources/fail.png);");
		score_auto[10] = 0;

	}
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	timer2->stop();
	ui.label_content_11->setStyleSheet(QString("color: %1").arg("#999999"));
	score_auto_all = 0;
	for (int i = 0; i < 11; i++)
	{
		score_auto_all = score_auto[i] + score_auto_all;
	}
	score_auto_all = score_auto_all * 10;
}
void place::ToContent_stop()
{
	begin_time1 = QDateTime::currentDateTime();             //获取或设置时间
	connect(timer2, SIGNAL(timeout()), this, SLOT(timing1()));
	timer2->start(980);
	stage = 1;
	ui.label_finish->setStyleSheet("border-image: url(:/FEDE/Resources/ing.png);");

}

void place::Click_pushButton_begin_2()
{
	
}
void place::Click_pushButton_begin_3()
{
	
}
void place::OnBtnClicked(void)

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
void place::stylesheet()
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
	ui.pushButton_save->setStyleSheet(qssbtn.join(""));
	ui.pushButton_change->setStyleSheet(qssbtn.join(""));
	ui.pushButton_save_2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_change_2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_begin->setStyleSheet(qssbtn.join(""));
	ui.pushButton_over->setStyleSheet(qssbtn.join(""));
	ui.pushButton_color->setStyleSheet(qssbtn.join(""));
	ui.pushButton_begin_2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_begin_3->setStyleSheet(qssbtn.join(""));
	ui.pushButton_local->setStyleSheet(qssbtn.join(""));
	ui.pushButton_back1->setStyleSheet(qssbtn.join(""));
	ui.pushButton_back2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_back3->setStyleSheet(qssbtn.join(""));
	ui.pushButton_paint_2->setStyleSheet(qssbtn.join(""));
	ui.pushButton_paint->setStyleSheet(qssbtn.join(""));
	
	

	QStringList qss;//文本框显示
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));


	QStringList qsss;//文本框显示
	qsss.append(QString("QTextEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qsss.append(QString("QTextEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));
	ui.textEdit->setStyleSheet(qsss.join(""));
	ui.textEdit_2->setStyleSheet(qsss.join(""));
	//ui.tableWidget->verticalHeader()->hide();
	//ui.tableWidget_2->setStyleSheet(QString("background-color: %1").arg(color1));

	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(14);
	font.setBold(true);
	font.setItalic(false);
	font.setWeight(75);


	ui.label_5->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_5->setFont(font);
	ui.label_9->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_9->setFont(font);
	ui.label_31->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_31->setFont(font);
	ui.label_69->setStyleSheet(QString("color: %1").arg(color1));
	ui.label_69->setFont(font);
	ui.label_8->setFont(font);
	ui.label_name->setFont(font);
	QFont font1;
	font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font1.setPointSize(10);
	font1.setBold(false);
	font1.setWeight(50);
	ui.label_content->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_2->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_3->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_4->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_5->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_6->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_7->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_8->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_9->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_10->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_11->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content_12->setStyleSheet(QString("color: %1").arg(color3));

	ui.label_8->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_name->setStyleSheet(QString("color: %1").arg(color3));
	ui.label_content->setFont(font1);
	ui.label_content_2->setFont(font1);
	ui.label_content_3->setFont(font1);
	ui.label_content_4->setFont(font1);
	ui.label_content_5->setFont(font1);
	ui.label_content_6->setFont(font1);
	ui.label_content_7->setFont(font1);
	ui.label_content_8->setFont(font1);
	ui.label_content_9->setFont(font1);
	ui.label_content_10->setFont(font1);
	ui.label_content_11->setFont(font1);
	ui.label_content_12->setFont(font1);

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
	ui.comboBox->setStyleSheet(qss1.join(""));
	ui.comboBox_2->setStyleSheet(qss1.join(""));
	ui.comboBox->setFont(font1);
	ui.comboBox_2->setFont(font1);
	ui.comboBox_3->setStyleSheet(qss1.join(""));
	ui.comboBox_3->setFont(font1);
	ui.comboBox_color->setStyleSheet(qss1.join(""));
	ui.comboBox_color->setFont(font1);
	ui.comboBox_size->setStyleSheet(qss1.join(""));
	ui.comboBox_size->setFont(font1);
	ui.pushButton_save->setFont(font1);
	ui.pushButton_change->setFont(font1);
	ui.pushButton_save_2->setFont(font1);
	ui.pushButton_change_2->setFont(font1);
	ui.pushButton_begin->setFont(font1);
	ui.pushButton_over->setFont(font1);
	ui.pushButton_color->setFont(font1);
	ui.pushButton->setFont(font1);
	ui.pushButton_2->setFont(font1);
	ui.pushButton_3->setFont(font1);
	ui.pushButton_4->setFont(font1);
	ui.pushButton_5->setFont(font1);
	ui.pushButton_6->setFont(font1);
	ui.pushButton_begin_2->setFont(font1);
	ui.pushButton_begin_3->setFont(font1);
	ui.pushButton_local->setFont(font1);
	ui.pushButton_back1->setFont(font1);
	ui.pushButton_back2->setFont(font1);
	ui.pushButton_back3->setFont(font1);
	ui.pushButton_paint_2->setFont(font1);
	ui.pushButton_paint->setFont(font1);

	
	ui.tabWidget->setStyleSheet(                                            //标签

		QString(
			"QTabWidget::tab-bar{left:20px; }"//标签左右位置
			"QTabBar::tab{"
			"background: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #E1E1E1, stop:0.4 #DDDDDD,stop:0.5 #D8D8D8,stop:1.0 #D3D3D3);"
			"border:1px solid %1;border-bottom-color;"
			"border-top-left-radius:4px;border-top-right-radius:4px;padding: 2px;}"
			"}"
			"QTabBar::tab:selected{margin-top: 2px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:%1;border-color:#FFFFFF;color:white;min-width:90px;}"//选择
			"QTabBar::tab:!selected{margin-top: 5px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:#999999;border-color:#FFFFFF;color:white;min-width:90px;}"//未选择

		).arg(color2).arg(color1));

	ui.label_frame_9->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame_2->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame_3->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame_4->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));
	ui.label_frame_5->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));

	//ui.label->setStyleSheet(QString::fromUtf8("QFrame{border-radius: 5px;border: 2px solid %1;}").arg("#999999"));

}
void pdf_form_data_1() 
{
	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (score2[i][j] == "Y")
			{
				pdf_data[i] = j;
				break;
			}
			
		}
	}
	for (int i = 0; i < 105; i++)
	{
			if (score2[i][0] != "Y"&&score2[i][1] != "Y"&&score2[i][2] != "Y")
			{
				pdf_data[i] = 4;

			}
	}
	
}