#include "place.h"
#include "QMessageBox";
#pragma execution_character_set("utf-8") 
int score = 0;
int yesornot = 0;
int form_1_weight[28];//Ȩ��
QDateTime begin_time;//��ȡ��ʼʱ��
QDateTime begin_time1;//��ȡ��ʼʱ��
double score_finish;
QString Timing;
QTime timedebuge;//����һ��ʱ�Ӷ���
QString color1 = "#4182C3";
QString color2 = "#17abe3";
QString color3 = "#2a79bd";
int color_choose = 1;
int size_choose = 1;
int choose1 = 0;
int table_col = 10;
int currentIndex = 0;//��ǰҳ��
int currentIndex_old = 0;// ��һ��ҳ��
int currentPlace = 0;//��ǰ����
int MissNum = 0;
bool MissOrNot =false;
bool Finish = true;
int stage = 0;
QString time1[15];
int score_auto[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int score_auto_all;
void pdf_form_data_1();

/*
 ��������  form_1_weight[0]-form_1_weight[5]
[
	��ȫ������
	ҽ�Ʊ�����
	ͨѶ���ϳ̶�
	��Ա�������ƶ�
	���ı��϶�
	���ر��϶�
}
 ����Ŀ��ͼƻ� form_1_weight[6]-form_1_weight[9]
{
	����Ŀ�����ȷ��
	�����ƻ��ĺ�����
	ָ����Ա�������ƻ�����ȷ��
	������Ա��������Ŀ����ȷ��
}
ָ����Ա�;�Ԯ��Ա������ form_1_weight[10]-form_1_weight[23]
{
	�������ĺ���̶�
	���������ȷ�̶�
	����ͨѶ���
	������Ա�Լƻ����س̶�
	������������Ĵ�������
	ָ����Ա���������ֳ����������
	���ھ�Ԯϸ�ڵĴ������
	�ֳ���Ԯ�������
	���ڲ�������׷������
	�ж�Ч��
	�����ֳ��ı������
	��Ա�������
	������Ա��Ԯ����������
	������Ա��Э������
}
��������  form_1_weight[24]-form_1_weight[27]
{
	�������ѵ�ʱ��
	��Ԯ�������ֳ��Ĵ������
	����Ԯ��Ա�İ��ú;Ȼ����
	����������Ա���Ϻ���ɢ���
}

*/
QString score2[105][3];
int pdf_data[105];

int form_2_weight[105][3];//Ȩ��
/*
����Ԥ��   form_2_weight[0]-form_2_weight[2]
{
ͨ����չӦ���������Ƿ��Ӧ��Ԥ������������м�飺
1���Ƿ�ͨ����չӦ������������Ӧ��Ԥ���д��ڵ����⣻
2���Ƿ��������Ӧ��Ԥ�������
3���Ƿ�������Ӧ��Ԥ����ʵ���ԺͿɲ���������������

}

����׼��  form_2_weight[3]-form_2_weight[5]
{
ͨ����չӦ���������Ƿ��Ӧ��ͻ���¼�����������м�飺
1��Ӧ�������Ƿ�����䱸���Ƿ���������Ӧ����Ԯ��Ҫ��
2���Ƿ�����ֳ�Ӧ����Ԯ���ʡ�װ���������Ƿ������ֳ�Ӧ
����Ԯ��Ҫ��
3���Ƿ����Ӧ����Ԯ����׼����׼������Ƿ�λ��
}

��������  form_2_weight[6]-form_2_weight[7]
{
ͨ����չӦ����������Ӧ����Ԯ�����Ƿ�ﵽ���ж���Ч����
1���Ƿ���ǿ������֯��λ�����뵥λ����Ա�ȶ�Ӧ��Ԥ����
��Ϥ�̶ȣ�
2���Ƿ���Ч���������λ����ԱӦ������������
}

ĥ�ϻ���  form_2_weight[8]-form_2_weight[11]
{
ͨ����չӦ���������Ƿ�ﵽ����ĥ�ϻ��Ƶ�Ч����
1���Ƿ��һ����ȷ��ص�λ����Ա��ְ����˳������ϵ��
2���Ƿ���Ч���Ӧ��ָ��Ա��ָ��Э��������
3��Ӧ����Ԯ�����Ƿ���ת����
4���Ƿ��һ������Ӧ�����ơ�
}

��������  form_2_weight[12]
{
ͨ����չӦ���������Ƿ�ﵽ�ռ�Ӧ��֪ʶ����߹��ڷ��շ�
����ʶ���ԾȺ��ȵ��ֺ�Ӧ��������Ŀ�ġ�
}

Ӧ������Ŀ���ƶ�  form_2_weight[13]-form_2_weight[15]
{
1���Ƿ��ƶ�Ӧ������Ŀ�ꣻ
2��Ӧ������Ŀ���Ƿ����ơ�������ԣ�
3������Ŀ���Ƿ���С�
}

Ӧ������ԭ��  form_2_weight[16]-form_2_weight[19]
{
Ӧ������ԭ����ƶ��Ƿ��������Ҫ��
1���Ƿ���ʵ�ʡ�����λ��
2���Ƿ�����ʵս������ʵЧ��
3���Ƿ�����֯��ȷ����ȫ��
4���Ƿ�ͳ��滮�����н�Լ��
}
Ӧ����������   form_2_weight[20]-form_2_weight[22]
[
����Ӧ���������õ���ʽ��
1������֯��ʽ���֣�����Ӧ���������Ϊ��
��������������ʵս������
2�������ݻ��֣�����Ӧ���������Ϊ��
�ٵ������������ۺ�������
1����Ŀ�������û��֣�����Ӧ���������Ϊ��
�ټ�������������ʾ�������������о�������

}

Ӧ�������ƻ���������form_2_weight[23]-form_2_weight[26]
[
�����ƻ����������Ƿ��������Ҫ��
1���Ƿ����ʵ��������ƶ�Ӧ�������ƻ�����������
2�������ƻ����������Ƿ������ط��ɷ����Ӧ��Ԥ���涨��
3�������ƻ����������Ƿ���ϰ����ȡ�������ۺϡ�������
��ʵս��ѭ�򽥽���ʱ�����򡱵�ԭ���ƶ���
4�������ƻ������������Ƿ����滮Ӧ��������Ƶ�Ρ���ģ
����ʽ��ʱ�䡢�ص�ȡ�

}

Ӧ��������֯����  form_2_weight[27]-form_2_weight[30]
{
Ӧ��������֯�����Ƿ��������Ҫ��
1���Ƿ����Ӧ��������֯������
2��Ӧ��������֯�����Ƿ����ƣ�ְ���Ƿ���ȷ
3��Ӧ��������֯�����Ƿ��ա��߻������ϡ�ʵʩ��������
����ְ�ֹܷ���
4�����ݶ����Ƿ����Ӧ��Ԥ����������Ա��ר��ְӦ����
Ԯ�����Լ�־Ը�߶���ȡ�

}
Ӧ�������龰����  form_2_weight[31]-form_2_weight[36]
{
Ӧ�������������Ƿ�����������ݣ�
1���¼����
2��������ʱ��ص㣻
3����չ�ٶȡ�ǿ����Σ���ԣ�
4����Ӱ�췶Χ����Ա�����ʷֲ���
5������ɵ���ʧ��������չԤ�⣻
6�������������������ȡ�

}
��Ա����  form_2_weight[37]-form_2_weight[39]
{
Ӧ�������Ƿ����������Ա��
1�������쵼С�顢������ָ�ӡ��ܲ߻���
2���İ���Ա��������Ա��������Ա��������Ա��
3��������Ա��ģ����Ա��

}
���ѱ���  form_2_weight[40]-form_2_weight[42]
{
1��Ӧ�����������Ƿ��������Ԥ�㣻
2��Ӧ�����������Ƿ�ʱ������
3����������ר��ר�á���Լ��Ч��
}

���ر���  form_2_weight[43]-form_2_weight[45]
{
1���Ƿ�ѡ����ʵ��������أ�
2�����������Ƿ����㹻�Ŀռ䡢���õĽ�ͨ�����������
����������
3���Ƿ���Ź����������
}
�������ı���  form_2_weight[46]-form_2_weight[48]
{
1��Ӧ��Ԥ�������������Ƿ���ֽ���ı�����ʾ�ĵ�����Ϣ���ϣ�
2��Ӧ����������׼���Ƿ���������Ҫ��
3���Ƿ��ܹ�ȫ��ģ������������

}

ͨ�ű���   form_2_weight[49]-form_2_weight[52]
{
1��Ӧ��ָ�ӻ������ܲ߻���������Ա��������Ա��ģ����Ա�ȣ�
֮���Ƿ�����ʱ�ɿ�����Ϣ����������
2��ͨѶ���������Ƿ��������վ�Ԯ�ڲ����ⲿͨ��������Ҫ��
3�������ֳ��Ƿ������ֹ�����ר��ͨ����Ϣ���磻
4���ܷ�֤����������Ϣ�Ŀ��ٴ��ݡ�
}

��ȫ����  form_2_weight[53]-form_2_weight[55]
{
1���Ƿ����Ӧ���������ܳ��ֵķ����ƶ�Ԥ�����ƴ�ʩ��
2���Ƿ������ҪΪ������Ա�䱸�������װ��
3�������ֳ��Ƿ��б�Ҫ�İ�����ʩ���Ƿ�������ֳ����з�ջ�
���ƣ���֤������ȫ���У�
}

��������  form_2_weight[56]
{
����ǰ��������ָ���Ƿ�����������塢Ŀ�ꡢ��֯������ְ��
�ֹ���������������������ע���������ͳһ˵����
}

����ָ�����ж� form_2_weight[57]-form_2_weight[61]
{
1���Ƿ���������ָ�Ӹ�������ʵʩȫ���̵�ָ�ӿ��ƣ�
2��Ӧ��ָ�ӻ����Ƿ�����������ָ�Ӹ����ݶ������Ա����
չģ�������¼���Ӧ�������ж�����ɸ����������
3������������Ա�Ƿ�����������������������������Ҫ����
������������Ϣ��Э��������Ա��ɸ�����������
4��������Ա�Ƿ��ϸ�ִ�п�����Ϣ��ָ��������������涨��
����չӦ�������ж�����ɸ����������
5��ģ����Ա�Ƿ�����������Ҫ��ģ��δ�μ������ĵ�λ��
��Ա���ж�����������Ϣ������

}

�������̿���  form_2_weight[62]-form_2_weight[69]
{
1�������������̿��ƣ�
1��������ʽ���������У�������Ƿ�Χ�ƶ�������������
���ۣ�
2���Ƿ����ܲ߻��Կ�ͷ��������ʽ����������һ�������ɸ����⣻
3��������Ա�Ƿ����Ӧ��Ԥ������ع涨������Ӧ��ȡ���ж���
4�����ܲ߻�����������������������Ϣ��������Ա���ܵ��¼���
Ϣ���Ƿ�ͨ����ɫ���ݻ�ģ����������Ӧ�����û��
2��ʵս�������̿��ƣ�
1����ʵս�����У��Ƿ�Ҫͨ�����ݿ�����Ϣ�������������̣�
2���ܲ߻�����������������������Ϣ�󣬿�����Ա�Ƿ��������
����Ա��ģ����Ա���ݿ�����Ϣ��
3��������Ա��ģ����Ա���ܵ���Ϣ���Ƿ��շ�����ʵ�¼�ʱ
��Ӧ�����ó�������Ӧ���ж���������ȡ��Ӧ��Ӧ�������ж���
4�����������У�������Ա�Ƿ���ʱ����������չ����������ܲ�
�����������г��ֵĸ������⡣
}

������˵   form_2_weight[70]-form_2_weight[74]
{
1��������ʵʩ�����У��Ƿ���ר�˶��������н�˵��
2��������˵�Ƿ�����������ݣ�
1����������������
2�����̽��⣻
3���������ܣ�
4��������Ⱦ�ȡ�


}

������¼  form_2_weight[75]-form_2_weight[81]
{
1��������ʵʩ�����У��Ƿ���ר����Ա���������֡���Ƭ����
����ֶμ�¼�������̣�
2�����ּ�¼�Ƿ�����������ݣ�
1������ʵ�ʿ�ʼ�����ʱ�䣻
2���������̿��������
3������������в�����Ա�ı��֣�
4������������䴦�ã�
5���Ƿ���ϸ��¼���ܳ��ֵ���Ա��������������롰Σ�ա�����
���ް�ȫ�����������涨��ʱ���ڲ��������ɢ�ȣ����Ʋ�����
ʧ���������
6�����֡���Ƭ��Ƭ�������¼�Ƿ�ȫ��λ��ӳ����ʵʩ���̡�
}

��������  form_2_weight[82]-form_2_weight[83]
{
1���Ƿ����Ӧ��������������Ա��������������
2��ͨ�����������Ƿ���Ч���������Ա�����վ�Ԯ��ʶ���ռ���
�վ�Ԯ֪ʶ�ͼ��ܡ�
}

Ӧ��������������ֹ  form_2_weight[84]-form_2_weight[86]
{
1��������ϣ��Ƿ����ܲ߻����������źţ�������ָ����������
������
2������������������Ա�Ƿ�ֹͣ���������Ԥ���������Ͻ���
�ֳ��ܽὲ��������֯��ɢ��
3�������������Ƿ�ָ��ר�˸�����֯��Ա�������ֳ����������
�ָ���

}

��������  form_2_weight[87]-form_2_weight[93]
{
1�������������Ƿ���֯�й���Ա��Ӧ���������̽���������
2��Ӧ�����������Ƿ�������м������棺
1������ִ�������
2��Ԥ���ĺ����ԺͿɲ����ԣ�
3��Ӧ��ָ����Ա��ָ��Э��������
4��������Ա�Ĵ���������
5�����������豸�������ԣ�
6������Ŀ���ʵ������������ĳɱ�Ч�������������Ԥ���Ľ�
��ȡ�
}


�����ܽ�  form_2_weight[94]-form_2_weight[99]
{
1������������������λ�Ƿ����������ϵͳ��ȫ���ܽᣬ���γ�
�����ܽᱨ�棻
2�������ܽᱨ���Ƿ�����������ݣ�
1������Ŀ�ģ�
2��ʱ��͵ص㣻
3�����ݵ�λ����Ա��
4������������Ҫ��
5�����ֵ�������ԭ�򣬾���ͽ�ѵ���Լ��Ľ��йع����Ľ���ȡ�
}

�ɹ�����  form_2_weight[100]-form_2_weight[103]
{
1���������б�¶���������⣬������λ�Ƿ�ʱ��ȡ��ʩ���Ը�
����
2���Ƿ�ʱ��֯��Ӧ��Ԥ�����޶������ƣ�
3���Ƿ�������Եļ�ǿӦ����Ա�ؽ�������ѵ��
4���Ƿ��Ӧ������װ�������мƻ��ظ��µȡ�
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
			s.rwidth() = 140; // ����ÿ��tabBar��item�Ĵ�С
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
			color1 = "#20B2AA";//��
			color2 = "#48c9b0";
			color3 = "#0f7772";
		}
		else
		{
			color1 = "#778f98";//��
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
		<< QApplication::translate("MainWindowClass", "����ͷ1", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "����ͷ2", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "����ͷ3", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "����ͷ4", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "����ͷ4", Q_NULLPTR)

	);
	ui.comboBox_2->clear();
	ui.comboBox_2->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "���۸�Ȩ����", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "�͹۸�Ȩ����", Q_NULLPTR)
	);
	ui.comboBox_3->clear();
	ui.comboBox_3->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "���۸�Ȩ����", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "�͹۸�Ȩ����", Q_NULLPTR)
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
		<< QApplication::translate("MainWindowClass", "��", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "��", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "��", Q_NULLPTR)
	);

	ui.comboBox_size->clear();
	ui.comboBox_size->insertItems(0, QStringList()
		<< QApplication::translate("MainWindowClass", "С", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "��", Q_NULLPTR)
		<< QApplication::translate("MainWindowClass", "��", Q_NULLPTR)
	);
	ui.tableWidget->setColumnCount(6);
	ui.tableWidget->setRowCount(table_col);

	QStringList header;
	header << "��������" << tr("��������") << "����ʱ��" << "����ʱ��" << "��������" << "����";
	ui.tableWidget->setHorizontalHeaderLabels(header);
	ui.tableWidget->verticalHeader()->setHidden(true);
	//ui.tableWidget->horizontalHeader()->setStyleSheet(QString("QHeaderView{font:12pt '����';};"));
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	for (int i = 0; i<table_col; i++)
	{
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem("δ֪����"));
		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		for (int j = 1; j < 6; j++)
		{
			ui.tableWidget->setItem(i, j, new QTableWidgetItem("��"));
			ui.tableWidget->item(i, j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
		QPushButton * pBtn = new QPushButton();
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

		pBtn->setFont(font1);
		pBtn->setStyleSheet(qssbtn.join(""));

		pBtn->setText("�鿴����");
		connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));

		ui.tableWidget->setCellWidget(i, 5, pBtn); //��������ť���ֱ������󣬾����QTableWidgetItem  ����ť���Ǹ���Ԫ��

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
	QString path = QFileDialog::getOpenFileName(this, tr("ѡ����Ƶ"), ".", tr("Image Files( *.mp4)"));//�õ���Ƶ·��

	QFile file(path);
	if (!file.open(QIODevice::ReadOnly))
		qDebug() << "Could not open file";

	player->setMedia(QUrl::fromLocalFile(path));
	player->play();
	ui.widget->show();
}

void place::Click_change()//ҳ���л�
{
	currentIndex_old = currentIndex;
	currentIndex =ui.tabWidget_2->currentIndex();
	ui.label_name->setText("");
	ui.label_name_2->setText("");
	ui.label_name_3->setText("");

	//ui.label_logo->setText(QString::number(currentIndex, 10));
	if (currentIndex == 0)
	{
		ui.label_12->setText("��������ѡ��");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/all.png);");

	}
	else if (currentIndex == 1)
	{
		switch (currentPlace)
		{
		case 0:
			ui.label_12->setText("��������");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/all.png);");
			break;
		case 1:
			ui.label_12->setText("�������ֳ���");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/fire.png);");
			break;
	    case  2:
			ui.label_12->setText("����̮���¹ʳ���");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/building.png);");
			break;
		case  3:
			ui.label_12->setText("��ҵ�¹ʳ���");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/factory.png);");
			break;
		case  4:
			ui.label_12->setText("��·��ͨ�¹ʳ���");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/road.png);");
			break;
		case  5:
			ui.label_12->setText("�������������");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/traffic.png);");
			break;
		case  6:
			ui.label_12->setText("ˮ����������");
			ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/logo.png);");
			break;

		}
		
	}
	else if (currentIndex == 2)
	{
		ui.label_12->setText("������¼");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/record.png);");
	}
	else if (currentIndex == 3)
	{
		ui.label_12->setText("ϵͳ����");
		ui.label_logo->setStyleSheet("border-image:url(:/FEDE/Resources/setting.png);");
	}
}
void place::Click_pushButton()//��
{
	if (Finish == true)
	{
		choose1 = 1;
		currentPlace = 1;
		ui.label_content->setText("ָ��Ա�Ӿ�");
		ui.label_content_2->setText("���ͼ��ᾯ��");
		ui.label_content_3->setText("ָ��λ�ü���");
		ui.label_content_4->setText("�����ж�ָ��");
		ui.label_content_5->setText("��λ�ֺ��ֳ�");
		ui.label_content_6->setText("ͨ�Ų�������");
		ui.label_content_7->setText("��ӿ����ֳ�");
		ui.label_content_8->setText("Σ��Ʒ����");
		ui.label_content_9->setText("���ͱ�����Ա");
		ui.label_content_10->setText("����ֺ��ֳ�");
		ui.label_content_11->setText("��Ա�ֳ�����");
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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_2()//����
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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_5()
{
	if (Finish == true)
	{
	choose1 = 2;
	currentPlace = 5;
	ui.label_content->setText("ָ��Ա�Ӿ�");
	ui.label_content_2->setText("���ͼ��ᾯ��");
	ui.label_content_3->setText("ָ��λ�ü���");
	ui.label_content_4->setText("�����ж�ָ��");
	ui.label_content_5->setText("��λ�ֺ��ֳ�");
	ui.label_content_6->setText("���þ����־");
	ui.label_content_7->setText("����ֳ���Ա");
	ui.label_content_8->setText("����������Ա");
	ui.label_content_9->setText("�����ֳ�����");
	ui.label_content_10->setText("�ָ��ֳ�ͨ��");
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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_6()
{
	if (Finish == true)
	{
	choose1 = 1;
	currentPlace = 6;

	ui.label_content->setText("ָ��Ա�Ӿ�");
	ui.label_content_2->setText("���ͼ��ᾯ��");
	ui.label_content_3->setText("ָ��λ�ü���");
	ui.label_content_4->setText("�����ж�ָ��");
	ui.label_content_5->setText("��λ�ֺ��ֳ�");
	ui.label_content_6->setText("ͨ�Ų�������");
	ui.label_content_7->setText("����¹��ֳ�");
	ui.label_content_8->setText("���þ����־");
	ui.label_content_9->setText("��Ԯ��Ա���");
	ui.label_content_10->setText("������Ӧˮ��");
	ui.label_content_11->setText("Ӫ�ȱ�����Ա");
	ui.label_content_12->setText("�˲������ֳ�");

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
		QMessageBox::about(NULL, "����", "��δ��ɵ��������̣�����ɻ��˳�����ѡ�񳡾�");
		ui.tabWidget_2->setCurrentIndex(1);

	}
}
void place::Click_pushButton_color()
{
	QSettings *configIniWrite = new QSettings("setting.ini", QSettings::IniFormat);
	configIniWrite->setValue("/color", ui.comboBox_color->currentIndex() + 1);//1 �� 2��  3��
	configIniWrite->setValue("/size", ui.comboBox_size->currentIndex() + 1);//1 �� 2��  3��
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
		color1 = "#20B2AA";//��
		color2 = "#48c9b0";
		color3 = "#0f7772";
	}
	else
	{
		color1 = "#778f98";//��
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
	button = QMessageBox::question(this, tr("��ʾ"), QString(tr("ȷ���˳��������̣�")), QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::No) {

	}
	else if (button == QMessageBox::Yes) 
	{
		onRestart();
	}
}
void place::Click_pushButton_paint()
{

	QString file_path1 = QFileDialog::getSaveFileName(this, "����������ı���洢λ��", QString(), "*.pdf");  //���ļ��Ի����������·��
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //���� file_path+=".pdf"
		}
	}
	QPrinter printer_text;
	printer_text.setOutputFormat(QPrinter::PdfFormat);
	printer_text.setOutputFileName(file_path1);//pdfnameΪҪ�����pdf�ļ���
	printer_text.setPageSize(QPrinter::A4); //����ֽ�ųߴ磬Ĭ�ϲ����þ���A4

	QTextDocument text_document;
	QTextDocument text_document2;

	QString html = GeneratePicWord1();//�Զ���ĺ�������������html����
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
		QPrinter pic_printer(QPrinter::HighResolution); //��һ�ֱַ��ʳ�ʼ��
														//QPrinter printerPixmap(QPrinter::HighResolution);
		pic_printer.setPageSize(QPrinter::A4); //����ֽ�ųߴ磬Ĭ�ϲ����þ���A4
		pic_printer.setOutputFormat(QPrinter::PdfFormat); //���������ʽpdf
		QString file_path = QFileDialog::getSaveFileName(this, "����������ı���洢λ��", QString(), "*.pdf");  //���ļ��Ի����������·��
		if (!file_path.isEmpty())
		{
			if (QFileInfo(file_path).suffix().isEmpty())
			{
				file_path.append(".pdf");  //���� file_path+=".pdf"
			}
		}
		pic_printer.setOutputFileName(file_path);
		QPixmap pixmap = QPixmap::grabWidget(ui.scrollAreaWidgetContents, ui.scrollAreaWidgetContents->rect()); //ץȡ����widget���򣬿���ץȡ����ؼ�����Qt5�Ƽ��µ�API QWidget::grab
																													//QPixmap pixmap2 = QPixmap::grabWidget(ui.label_2_2, ui.label_2_2->rect()); //ץȡ����widget���򣬿���ץȡ����ؼ�����Qt5�Ƽ��µ�API QWidget::grab
																													//QPixmap pixmap3 = QPixmap::grabWidget(ui.label_2_3, ui.label_2_3->rect()); //ץȡ����widget���򣬿���ץȡ����ؼ�����Qt5�Ƽ��µ�API QWidget::grab
																													//pixmap.load("1.png");
		QPainter pic_painter;

		pic_painter.begin(&pic_printer);

		QRect rect = pic_painter.viewport(); //��ȡpainter���ӿ�����

		int factor = rect.width() / pixmap.width(); //����painter�ӿ�������ץȡͼƬ����ĳߴ��������

		pic_painter.scale(factor - 1.5, factor - 1.5); //����ʱ���ձ������ӷŴ�
										   //pic_painter.scale(1, 1); //����ʱ���ձ������ӷŴ�

		pic_painter.drawPixmap(10, 170, pixmap); //�������껭ͼ
												 //pic_painter.scale(1,1); //�ظ���������������ܴ�����,�˲�ò�Ʋ���Ҫ
		rect = pic_painter.viewport(); //��ȡpainter���ӿ�����

									   // factor = pixmap.width() / pixmap2.width(); //����painter�ӿ�������ץȡͼƬ����ĳߴ��������
		pic_printer.setResolution(QPrinter::ScreenResolution); //Ҳ�������������ķֱ���

		pic_painter.scale(0.15, 0.15); //����ʱ���ձ������ӷŴ�
		if (0)
		{
			QPoint point(700, 150);
			int i1 = 200;
			QString message = QString("%1").arg("         �¹�Ӧ�������������");
			pic_painter.drawText(point, message);
			int y = point.y();
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("ϵͳ����������").arg(ui.label_12->text());
			pic_painter.drawText(point, message);
			y = point.y();
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("�����������ƣ�").arg(Team_name);
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("�Զ�����������").arg(QString::number(score_auto_all, 10));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("�˹�����������").arg(QString::number(score, 10));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("�ϼ�����������").arg(QString::number(score_finish, 'g', 6));
			pic_painter.drawText(point, message);
			y = y + i1;
			point.setY(y);
			message = QString("%1        %2").arg("�ϼƳ���ʱ�䣺").arg(Timing);
			pic_painter.drawText(point, message);
		}

		//pic_painter.drawText(10, i * 30, "hello world"); //�������꣨����Σ����,�ı�ΪQString���ͣ��ж������غ������������һ��
		pic_painter.end();
		//QPrinter text_printer; //�ı����ɲ�Ҫ����resolution������������ҵ�
		//QPainter text_painter;
		//text_printer.setOutputFormat(QPrinter::PdfFormat);
	}
	//text_printer.setOutputFileName("test_text.pdf"); //ֱ����������ļ�·������Ի��߾���·��

	//text_painter.begin(&text_printer);

	//for (int i = 0; i<5; i++)

	//	text_painter.drawText(10, i * 30, "hello world"); //�������꣨����Σ����,�ı�ΪQString���ͣ��ж������غ������������һ��

	//text_painter.end();

	//Qt5 pdfwriter����pdf
	QString file_path1 = QFileDialog::getSaveFileName(this, "����������ı���洢λ��", QString(), "*.pdf");  //���ļ��Ի����������·��
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //���� file_path+=".pdf"
		}
	}

	QFile pdfFile(file_path1);
	pdfFile.open(QIODevice::WriteOnly);                 // ��Ҫд���pdf�ļ�
	QPdfWriter* pPdfWriter = new QPdfWriter(&pdfFile);  // ����pdfд����
	pPdfWriter->setPageSize(QPagedPaintDevice::A4);     // ����ֽ��ΪA4
	pPdfWriter->setResolution(300);                     // ����ֽ�ŵķֱ���Ϊ300,���������Ϊ3508X2479

	int iMargin = 60;                   // ҳ�߾�
	pPdfWriter->setPageMargins(QMarginsF(iMargin, iMargin, iMargin, iMargin));

	QPainter* pPdfPainter = new QPainter(pPdfWriter);   // qt���ƹ���

														// ����,����
	QTextOption option(Qt::AlignHCenter | Qt::AlignVCenter);
	option.setWrapMode(QTextOption::WordWrap);

	// �����ϱ�����
	int iTop = 100;

	// �ı����2100
	int iContentWidth = 2100;

	// ����,22����
	QFont font;
	//font.setFamily("simhei.ttf");
	int fontSize = 22;
	font.setPointSize(fontSize);
	pPdfPainter->setFont(font);                    // Ϊ���ƹ�����������
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 90),
		"�ҵı����ҽ���", option);

	// ����,16���֣������
	fontSize = 16;
	font.setPointSize(fontSize);
	pPdfPainter->setFont(font);
	option.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	iTop += 60;
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 60),
		QString::fromLocal8Bit("1��Ŀ¼һ"));
	iTop += 60;
	// �������2�ַ�
	int iLeft = 120;
	pPdfPainter->drawText(QRect(iLeft, iTop, iContentWidth - iLeft, 60),
		QString::fromLocal8Bit("�ҵ�Ŀ¼һ�����ݡ�"), option);
	iTop += 60;
	pPdfPainter->drawText(QRect(0, iTop, iContentWidth, 60), QString::fromLocal8Bit("2��Ŀ¼��"));
	iTop += 60;
	pPdfPainter->drawText(QRect(iLeft, iTop, iContentWidth - iLeft, 60),
		QString::fromLocal8Bit("�ҵ�Ŀ¼һ������"), option);

	delete pPdfPainter;
	delete pPdfWriter;
	pdfFile.close();
#endif
	QString file_path1 = QFileDialog::getSaveFileName(this, "����������ı���洢λ��", QString(), "*.pdf");  //���ļ��Ի����������·��
	if (!file_path1.isEmpty())
	{
		if (QFileInfo(file_path1).suffix().isEmpty())
		{
			file_path1.append(".pdf");  //���� file_path+=".pdf"
		}
	}
	QPrinter printer_text;
	printer_text.setOutputFormat(QPrinter::PdfFormat);
	printer_text.setOutputFileName(file_path1);//pdfnameΪҪ�����pdf�ļ���
	printer_text.setPageSize(QPrinter::A4); //����ֽ�ųߴ磬Ĭ�ϲ����þ���A4

	QTextDocument text_document;
	QTextDocument text_document2;

	QString html = GeneratePicWord();//�Զ���ĺ�������������html����
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
	title0.push_back(("����"));
	title0.push_back(("����"));


	QString html;
	//��һҳ���ֲ���
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	html += QString("<th><font size = \"14\">Ӧ�������������</font>   </th>");
	for (int k = 0; k <= 3; k++)
	{
		html += "<br / >";
	}
	html += "<h3 align=\"center\">" + current_date + "</h3><br>";

	QString a[12];
	a[0] = "ϵͳ����������";
	a[2] = "�����������ƣ�";
	a[4] = "�Զ�����������";
	a[6] = "�˹�����������";
	a[8] = "�ϼ�����������";
	a[10] = "�ϼƳ���ʱ�䣺";
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
	//���1����
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
	html += QString("<th><font size = \"10\">�������</font>   </th>");

	//���2����
	QStringList title;
	title.push_back(("������Ŀ"));
	title.push_back(("�������ݼ�Ҫ��"));
	title.push_back(("�������"));
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"500\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >" ;

	for (int i = 0; i < title.count(); i++)
	{

		html +=QString("<th><font size=\"5\">%1</font>   </th>").arg(title.at(i));

	}
	html +="< font size = \"3\">";
	QString b[105][2];
	b[0][0]="����Ԥ��";	b[0][1] =  "1���Ƿ�ͨ����չӦ������������Ӧ��Ԥ���д��ڵ�����";
	b[1][0] = "����Ԥ��";b[1][1] = "2���Ƿ��������Ӧ��Ԥ�����";
	b[2][0] = "����Ԥ��";b[2][1] = "3���Ƿ�������Ӧ��Ԥ����ʵ���ԺͿɲ�������������";
	b[3][0] = "����׼��";b[3][1] = "1��Ӧ�������Ƿ�����䱸���Ƿ���������Ӧ����Ԯ��Ҫ";
	b[4][0] = "����׼��"; b[4][1] = "2���Ƿ�����ֳ�Ӧ����Ԯ���ʡ�װ���������Ƿ������ֳ�Ӧ����Ԯ��Ҫ";
	b[5][0] = "����׼��"; b[5][1] = "3���Ƿ����Ӧ����Ԯ����׼����׼������Ƿ�λ";
	b[6][0] = "��������"; b[6][1] = "1���Ƿ���ǿ������֯��λ�����뵥λ����Ա�ȶ�Ӧ��Ԥ������Ϥ�̶�";
	b[7][0] = "��������"; b[7][1] = "2���Ƿ���Ч���������λ����ԱӦ����������";
	b[8][0] = "ĥ�ϻ���"; b[8][1] = "1���Ƿ��һ����ȷ��ص�λ����Ա��ְ����˳������ϵ";
	b[9][0] = "ĥ�ϻ���"; b[9][1] = "2���Ƿ���Ч���Ӧ��ָ��Ա��ָ��Э������";
	b[10][0] = "ĥ�ϻ���"; b[10][1] = "3��Ӧ����Ԯ�����Ƿ���ת����";

	b[11][0] = "ĥ�ϻ���"; b[11][1] = "4���Ƿ��һ������Ӧ������";
	b[12][0] = "��������"; b[12][1] = "ͨ����չӦ���������Ƿ�ﵽ�ռ�Ӧ��֪ʶ����߹��ڷ��շ�����ʶ���ԾȺ��ȵ��ֺ�Ӧ��������Ŀ��";
	b[13][0] = "Ӧ������Ŀ���ƶ�"; b[13][1] = "1���Ƿ��ƶ�Ӧ������Ŀ��";
	b[14][0] = "Ӧ������Ŀ���ƶ�"; b[14][1] = "2��Ӧ������Ŀ���Ƿ����ơ��������";
	b[15][0] = "Ӧ������Ŀ���ƶ�"; b[15][1] = "3������Ŀ���Ƿ����";
	b[16][0] = "Ӧ������ԭ��"; b[16][1] = "1���Ƿ���ʵ�ʡ�����λ";
	b[17][0] = "Ӧ������ԭ��"; b[17][1] = "2���Ƿ�����ʵս������ʵЧ";
	b[18][0] = "Ӧ������ԭ��"; b[18][1] = "3���Ƿ�����֯��ȷ����ȫ";
	b[19][0] = "Ӧ������ԭ��"; b[19][1] = "4���Ƿ�ͳ��滮�����н�Լ";
	b[20][0] = "Ӧ����������"; b[20][1] = "1������֯��ʽ���֣�����Ӧ���������Ϊ����������������ʵս����";

	b[21][0] = "Ӧ����������"; b[21][1] = "2�������ݻ��֣�����Ӧ���������Ϊ���ٵ������������ۺ�����";
	b[22][0] = "Ӧ����������"; b[22][1] = "3����Ŀ�������û��֣�����Ӧ���������Ϊ���ټ�������������ʾ�������������о�������";
	b[23][0] = "Ӧ�������ƻ�"; b[23][1] = "1���Ƿ����ʵ��������ƶ�Ӧ�������ƻ�";
	b[24][0] = "Ӧ�������ƻ�"; b[24][1] = "2�������ƻ����������Ƿ������ط��ɷ����Ӧ��Ԥ���涨";
	b[25][0] = "Ӧ�������ƻ�"; b[25][1] = "3�������ƻ����������Ƿ���ϰ����ȡ�������ۺϡ��������ʵս��ѭ�򽥽���ʱ�����򡱵�ԭ���ƶ�";
	b[26][0] = "Ӧ�������ƻ�"; b[26][1] = "4�������ƻ������������Ƿ����滮Ӧ��������Ƶ�Ρ���ģ����ʽ��ʱ�䡢�ص��";
	b[27][0] = "Ӧ��������֯����"; b[27][1] = "1���Ƿ����Ӧ��������֯����";
	b[28][0] = "Ӧ��������֯����"; b[28][1] = "2��Ӧ��������֯�����Ƿ����ƣ�ְ���Ƿ���ȷ";
	b[29][0] = "Ӧ��������֯����"; b[29][1] = "3��Ӧ��������֯�����Ƿ��ա��߻������ϡ�ʵʩ������������ְ�ֹܷ�";
	b[30][0] = "Ӧ��������֯����"; b[30][1] = "4�����ݶ����Ƿ����Ӧ��Ԥ����������Ա��ר��ְӦ����Ԯ�����Լ�־Ը�߶����";

	b[31][0] = "Ӧ�������龰�Ƿ����"; b[31][1] = "1���¼����";
	b[32][0] = "Ӧ�������龰�Ƿ����"; b[32][1] = "2��������ʱ��ص�";
	b[33][0] = "Ӧ�������龰�Ƿ����"; b[33][1] = "3����չ�ٶȡ�ǿ����Σ����";
	b[34][0] = "Ӧ�������龰�Ƿ����"; b[34][1] = "4����Ӱ�췶Χ����Ա�����ʷֲ�";
	b[35][0] = "Ӧ�������龰�Ƿ����"; b[35][1] = "5������ɵ���ʧ��������չԤ��";
	b[36][0] = "Ӧ�������龰�Ƿ����"; b[36][1] = "6������������������";
	b[37][0] = "��Ա�����Ƿ����"; b[37][1] = "1�������쵼С�顢������ָ�ӡ��ܲ߻�";
	b[38][0] = "��Ա�����Ƿ����"; b[38][1] = "2���İ���Ա��������Ա��������Ա��������Ա";
	b[39][0] = "��Ա�����Ƿ����"; b[39][1] = "3��������Ա��ģ����Ա";
	b[40][0] = "���ѱ���"; b[40][1] = "1��Ӧ�����������Ƿ��������Ԥ��";

	b[41][0] = "���ѱ���"; b[41][1] = "2��Ӧ�����������Ƿ�ʱ����";
	b[42][0] = "���ѱ���"; b[42][1] = "3����������ר��ר�á���Լ��Ч";
	b[43][0] = "���ر���"; b[43][1] = "1���Ƿ�ѡ����ʵ���������";
	b[44][0] = "���ر���"; b[44][1] = "2�����������Ƿ����㹻�Ŀռ䡢���õĽ�ͨ�������������������";
	b[45][0] = "���ر���"; b[45][1] = "3���Ƿ���Ź�����������";
	b[46][0] = "�������ı���"; b[46][1] = "1��Ӧ��Ԥ�������������Ƿ���ֽ���ı�����ʾ�ĵ�����Ϣ����";
	b[47][0] = "�������ı���"; b[47][1] = "2��Ӧ����������׼���Ƿ���������Ҫ��";
	b[48][0] = "�������ı���"; b[48][1] = "3���Ƿ��ܹ�ȫ��ģ����������";
	b[49][0] = "ͨ�ű���"; b[49][1] = "1��Ӧ��ָ�ӻ������ܲ߻���������Ա��������Ա��ģ����Ա�ȣ�֮���Ƿ�����ʱ�ɿ�����Ϣ��������";
	b[50][0] = "ͨ�ű���"; b[50][1] = "2��ͨѶ���������Ƿ��������վ�Ԯ�ڲ����ⲿͨ��������Ҫ";

	b[51][0] = "ͨ�ű���"; b[51][1] = "3�������ֳ��Ƿ������ֹ�����ר��ͨ����Ϣ����";
	b[52][0] = "ͨ�ű���"; b[52][1] = "4���ܷ�֤����������Ϣ�Ŀ��ٴ���";
	b[53][0] = "��ȫ����"; b[53][1] = "1���Ƿ����Ӧ���������ܳ��ֵķ����ƶ�Ԥ�����ƴ�ʩ";
	b[54][0] = "��ȫ����"; b[54][1] = "2���Ƿ������ҪΪ������Ա�䱸�������װ��";
	b[55][0] = "��ȫ����"; b[55][1] = "3�������ֳ��Ƿ��б�Ҫ�İ�����ʩ���Ƿ�������ֳ����з�ջ���ƣ���֤������ȫ����";
	b[56][0] = "��������"; b[56][1] = "����ǰ��������ָ���Ƿ�����������塢Ŀ�ꡢ��֯������ְ�ֹܷ���������������������ע���������ͳһ˵��";
	b[57][0] = "����ָ�����ж�"; b[57][1] = "1���Ƿ���������ָ�Ӹ�������ʵʩȫ���̵�ָ�ӿ���";
	b[58][0] = "����ָ�����ж�"; b[58][1] = "2��Ӧ��ָ�ӻ����Ƿ�����������ָ�Ӹ����ݶ������Ա����չģ�������¼���Ӧ�������ж�����ɸ��������";
	b[59][0] = "����ָ�����ж�"; b[59][1] = "3������������Ա�Ƿ�����������������������������Ҫ����������������Ϣ��Э��������Ա��ɸ�����������";
	b[60][0] = "����ָ�����ж�"; b[60][1] = "4��������Ա�Ƿ��ϸ�ִ�п�����Ϣ��ָ��������������涨�ĳ���չӦ�������ж�����ɸ��������";

	b[61][0] = "����ָ�����ж�"; b[61][1] = "5��ģ����Ա�Ƿ�����������Ҫ��ģ��δ�μ������ĵ�λ����Ա���ж�����������Ϣ����";
	b[62][0] = "�������̿���"; b[62][1] = "1��������ʽ���������У�������Ƿ�Χ�ƶ�����������������";
	b[63][0] = "�������̿���"; b[63][1] = "2���Ƿ����ܲ߻��Կ�ͷ��������ʽ����������һ�������ɸ�����";
	b[64][0] = "�������̿���"; b[64][1] = "3��������Ա�Ƿ����Ӧ��Ԥ������ع涨������Ӧ��ȡ���ж�";
	b[65][0] = "�������̿���"; b[65][1] = "4�����ܲ߻�����������������������Ϣ��������Ա���ܵ��¼���Ϣ���Ƿ�ͨ����ɫ���ݻ�ģ����������Ӧ�����û";
	b[66][0] = "�������̿���"; b[66][1] = "1����ʵս�����У��Ƿ�Ҫͨ�����ݿ�����Ϣ��������������";
	b[67][0] = "�������̿���"; b[67][1] = "2���ܲ߻�����������������������Ϣ�󣬿�����Ա�Ƿ������������Ա��ģ����Ա���ݿ�����Ϣ";
	b[68][0] = "�������̿���"; b[68][1] = "3��������Ա��ģ����Ա���ܵ���Ϣ���Ƿ��շ�����ʵ�¼�ʱ��Ӧ�����ó�������Ӧ���ж���������ȡ��Ӧ��Ӧ�������ж���";
	b[69][0] = "�������̿���"; b[69][1] = "4�����������У�������Ա�Ƿ���ʱ����������չ����������ܲ߻����������г��ֵĸ������⡣";
	b[70][0] = "������˵"; b[70][1] = "1��������ʵʩ�����У��Ƿ���ר�˶��������н�˵";

	b[71][0] = "������˵"; b[71][1] = "2���Ƿ����������������";
	b[72][0] = "������˵"; b[72][1] = "3���Ƿ�������̽���";
	b[73][0] = "������˵"; b[73][1] = "4���Ƿ������������";
	b[74][0] = "������˵"; b[74][1] = "5���Ƿ����������Ⱦ";
	b[75][0] = "������¼"; b[75][1] = "1��������ʵʩ�����У��Ƿ���ר����Ա���������֡���Ƭ��������ֶμ�¼�������̣�";
	b[76][0] = "������¼�Ƿ����"; b[76][1] = "1������ʵ�ʿ�ʼ�����ʱ�䣻";
	b[77][0] = "������¼�Ƿ����"; b[77][1] = "2���������̿��������";
	b[78][0] = "������¼�Ƿ����"; b[78][1] = "3������������в�����Ա�ı��֣�";
	b[79][0] = "������¼�Ƿ����"; b[79][1] = "4������������䴦�ã�";
	b[80][0] = "������¼�Ƿ����"; b[80][1] = "5���Ƿ���ϸ��¼���ܳ��ֵ���Ա��������������롰Σ�ա��������ް�ȫ�����������涨��ʱ���ڲ��������ɢ�ȣ����Ʋ�����ʧ�������";

	b[81][0] = "������¼�Ƿ����"; b[81][1] = "6�����֡���Ƭ��Ƭ�������¼�Ƿ�ȫ��λ��ӳ����ʵʩ����";
	b[82][0] = "��������"; b[82][1] = "1���Ƿ����Ӧ��������������Ա��������������";
	b[83][0] = "��������"; b[83][1] = "2��ͨ�����������Ƿ���Ч���������Ա�����վ�Ԯ��ʶ���ռ����վ�Ԯ֪ʶ�ͼ��ܡ�";
	b[84][0] = "Ӧ��������������ֹ"; b[84][1] = "1��������ϣ��Ƿ����ܲ߻����������źţ�������ָ��������������";
	b[85][0] = "Ӧ��������������ֹ"; b[85][1] = "2������������������Ա�Ƿ�ֹͣ���������Ԥ���������Ͻ����ֳ��ܽὲ��������֯��ɢ";
	b[86][0] = "Ӧ��������������ֹ"; b[86][1] = "3�������������Ƿ�ָ��ר�˸�����֯��Ա�������ֳ���������ͻָ�";
	b[87][0] = "��������"; b[87][1] = "1�������������Ƿ���֯�й���Ա��Ӧ���������̽���������";
	b[88][0] = "���������Ƿ����"; b[88][1] = "1������ִ�����";
	b[89][0] = "���������Ƿ����"; b[89][1] = "2��Ԥ���ĺ����ԺͿɲ�����";
	b[90][0] = "���������Ƿ����"; b[90][1] = "3��Ӧ��ָ����Ա��ָ��Э������";


	b[91][0] = "���������Ƿ����"; b[91][1] = "4��������Ա�Ĵ�������";
	b[92][0] = "���������Ƿ����"; b[92][1] = "5�����������豸��������";
	b[93][0] = "���������Ƿ����"; b[93][1] = "6������Ŀ���ʵ������������ĳɱ�Ч�������������Ԥ���Ľ����";
	b[94][0] = "�����ܽ�"; b[94][1] = "1������������������λ�Ƿ����������ϵͳ��ȫ���ܽᣬ���γ������ܽᱨ��";
	b[95][0] = "�����ܽ��Ƿ����"; b[95][1] = "1������Ŀ��";
	b[96][0] = "�����ܽ��Ƿ����"; b[96][1] = "2��ʱ��͵ص�";
	b[97][0] = "�����ܽ��Ƿ����"; b[97][1] = "3�����ݵ�λ����Ա";
	b[98][0] = "�����ܽ��Ƿ����"; b[98][1] = "4������������Ҫ";
	b[99][0] = "�����ܽ��Ƿ����"; b[99][1] = "5�����ֵ�������ԭ�򣬾���ͽ�ѵ���Լ��Ľ��йع����Ľ����";
	b[100][0] = "�ɹ�����"; b[100][1] = "1���������б�¶���������⣬������λ�Ƿ�ʱ��ȡ��ʩ���ԸĽ�";

	b[101][0] = "�ɹ�����"; b[101][1] = "2���Ƿ�ʱ��֯��Ӧ��Ԥ�����޶�������";
	b[102][0] = "�ɹ�����"; b[102][1] = "3���Ƿ�������Եļ�ǿӦ����Ա�ؽ�������ѵ";
	b[103][0] = "�ɹ�����"; b[103][1] = "4���Ƿ��Ӧ������װ�������мƻ��ظ��µ�";
	QString resurt;
	pdf_form_data_1();
	for (int i = 0; i < 104; i++)
	{
		html += "<tr>";
		if (i!=20&& i != 21 && i != 22)
		{
			if (pdf_data[i] == 0)
				resurt = "��";
			else if (pdf_data[i] == 1)
				resurt = "��";
			else if (pdf_data[i] == 4)
				resurt = "��ȱ";
		}
		else
		{
			if (pdf_data[i] == 0)
				resurt = "ѡ��1";
			else if (pdf_data[i] == 1)
				resurt = "ѡ��2";
			else if (pdf_data[i] == 2)
				resurt = "ѡ��3";
			else if (pdf_data[i] == 4)
				resurt = "��ȱ";
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
	title0.push_back(("����"));
	title0.push_back(("����"));


	QString html;
	//��һҳ���ֲ���
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
	html += QString("<th><font size = \"14\">Ӧ�������������</font>   </th>");
	for (int k = 0; k <= 3; k++)
	{
		html += "<br / >";
	}
	html += "<h3 align=\"center\">" + current_date + "</h3><br>";

	QString a[12];
	a[0] = "ϵͳ����������";
	a[2] = "�����������ƣ�";
	a[4] = "�Զ�����������";
	a[6] = "�˹�����������";
	a[8] = "�ϼ�����������";
	a[10] = "�ϼƳ���ʱ�䣺";
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
	//���1����
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
	html += QString("<th><font size = \"10\">�������</font>   </th>");

	//���2����
	QStringList title;
	title.push_back(("������Ŀ"));
	title.push_back(("�������ݼ�Ҫ��"));
	title.push_back(("�������"));
	html += "<div style=\"margin-left:-80px\">";
	html += "<table width=\"500\" border=\"0.5\"align=\"center\"style=\"border-collapse:collapse;\"border-color=\"green\"margin-left:\"0px\";>";
	html += "<tr style=\"background-color:#ccc\" >";

	for (int i = 0; i < title.count(); i++)
	{

		html += QString("<th><font size=\"5\">%1</font>   </th>").arg(title.at(i));

	}
	html += "< font size = \"3\">";
	QString b[28][3];
	b[0][0] = "��������";	b[0][1] = "��ȫ������";
	b[1][0] = "��������"; b[1][1] = "ҽ�Ʊ�����";
	b[2][0] = "��������"; b[2][1] = "ͨѶ���ϳ̶�";
	b[3][0] = "��������"; b[3][1] = "��Ա�������ƶ�";
	b[4][0] = "��������"; b[4][1] = "���ı��϶�";
	b[5][0] = "��������"; b[5][1] = "���ر��϶�";
	b[6][0] = "����Ŀ��ͼƻ�"; b[6][1] = "����Ŀ�����ȷ��";
	b[7][0] = "����Ŀ��ͼƻ�"; b[7][1] = "�����ƻ��ĺ�����";
	b[8][0] = "����Ŀ��ͼƻ�"; b[8][1] = "ָ����Ա�������ƻ�����ȷ��";
	b[9][0] = "����Ŀ��ͼƻ�"; b[9][1] = "������Ա��������Ŀ����ȷ��";
	b[10][0] = "ָ����Ա�;�Ԯ��Ա������"; b[10][1] = "�������ĺ���̶�";

	b[11][0] = "ָ����Ա�;�Ԯ��Ա������"; b[11][1] = "���������ȷ�̶�";
	b[12][0] = "ָ����Ա�;�Ԯ��Ա������"; b[12][1] = "����ͨѶ���";
	b[13][0] = "ָ����Ա�;�Ԯ��Ա������"; b[13][1] = "������Ա�Լƻ����س̶�";
	b[14][0] = "ָ����Ա�;�Ԯ��Ա������"; b[14][1] = "������������Ĵ�������";
	b[15][0] = "ָ����Ա�;�Ԯ��Ա������"; b[15][1] = "ָ����Ա���������ֳ����������";
	b[16][0] = "ָ����Ա�;�Ԯ��Ա������"; b[16][1] = "���ھ�Ԯϸ�ڵĴ������";
	b[17][0] = "ָ����Ա�;�Ԯ��Ա������"; b[17][1] = "�ֳ���Ԯ�������";
	b[18][0] = "ָ����Ա�;�Ԯ��Ա������"; b[18][1] = "���ڲ�������׷������";
	b[19][0] = "ָ����Ա�;�Ԯ��Ա������"; b[19][1] = "�ж�Ч��";
	b[20][0] = "ָ����Ա�;�Ԯ��Ա������"; b[20][1] = "�����ֳ��ı������";

	b[21][0] = "ָ����Ա�;�Ԯ��Ա������"; b[21][1] = "��Ա�������";
	b[22][0] = "ָ����Ա�;�Ԯ��Ա������"; b[22][1] = "������Ա��Ԯ����������";
	b[23][0] = "ָ����Ա�;�Ԯ��Ա������"; b[23][1] = "������Ա��Э������";
	b[24][0] = "��������"; b[24][1] = "�������ѵ�ʱ��";
	b[25][0] = "��������"; b[25][1] = "��Ԯ�������ֳ��Ĵ������";
	b[26][0] = "��������"; b[26][1] = "����Ԯ��Ա�İ��ú;Ȼ����";
	b[27][0] = "��������"; b[27][1] = "����������Ա���Ϻ���ɢ���";

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
				resurt = "��ȱ";	
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
		button = QMessageBox::question(this, tr("�˳�"),
			QString(tr("ȷ���˳�����?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::No) {
			e->ignore();  //�����˳��źţ������������
		}
		else if (button == QMessageBox::Yes) {
			e->accept();  //�����˳��źţ������˳�
			
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
		button1 = QMessageBox::question(this, tr("���"),
			QString(tr("��δ��д�����ݣ��Ƿ����?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button1 == QMessageBox::No) {
			break;
		}
		else if (button1 == QMessageBox::Yes) {
		}
	}
	case false:	
	{
		inf = "  ����������" + ui.label_12->text() + "\n" + "  �������ƣ�" + Team_name + "\n" + "  �Զ�����������" + QString::number(score_auto_all, 10) + "\n" + "  �˹�����������" + QString::number(score, 10) + "\n" + "  �ܼ�����������" + QString::number(score_finish, 'g', 6) + "\n" + "  ����ʱ�䣺" + Timing + "  ";
		QMessageBox::about(NULL, "���", inf);
		int button;
		button = QMessageBox::question(this, tr("���"),
			QString(tr("���������ȷ���˳�����?")),
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
void place::Click_pushButton_save_2()//����
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
		button1 = QMessageBox::question(this, tr("���"),
			QString(tr("��δ��д�����ݣ��Ƿ����?")),
			QMessageBox::Yes | QMessageBox::No);
		if (button1 == QMessageBox::No) {
			break;
		}
		else if (button1 == QMessageBox::Yes) {
		}
	}
	case false:
	{
		inf = "  ����������" + ui.label_12->text() + "\n" + "  �������ƣ�" + Team_name + "\n" + "  �Զ�����������" + QString::number(score_auto_all, 10) + "\n" + "  �˹�����������" + QString::number(score, 10) + "\n" + "  �ܼ�����������" + QString::number(score_finish, 'g',6) + "\n" + "  ����ʱ�䣺" + Timing + "  ";
		QMessageBox::about(NULL, "���", inf);
		int button;
		button = QMessageBox::question(this, tr("���"),
			QString(tr("���������ȷ���˳�����?")),
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
	p->setWindowTitle(QObject::tr("����������Ϣ"));
	p->show();
	connect(p, SIGNAL(BackTo()), this, SLOT(ToPlace()));

	

}
void place::ToPlace()
{
	begin_time = QDateTime::currentDateTime();             //��ȡ������ʱ��
	connect(timer1, SIGNAL(timeout()), this, SLOT(timing()));
	timer1->start(500);
	ui.pushButton_over->setEnabled(true);
	ui.pushButton_begin->setEnabled(false);
	ui.label_name->setText(Team_name);
	ui.label_name_2->setText(Team_name);
	ui.label_name_3->setText(Team_name);

	VirtualSensor *t = new VirtualSensor();
	t->setWindowModality(Qt::WindowModal);
	t->setWindowTitle(QObject::tr("���⴫����"));
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��

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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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

	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��

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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��

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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��

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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	begin_time1 = QDateTime::currentDateTime();             //��ȡ������ʱ��
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
	s->setWindowTitle(QObject::tr("������¼"));
	s->show();
}
void place::stylesheet()
{
	QPalette palette(this->palette());
	setAutoFillBackground(true);
	palette.setColor(QPalette::Background, QColor(255, 255, 255, 255));	this->setPalette(palette);
	ui.label_47->setStyleSheet(QString::fromUtf8("background-color:%1;").arg(color3));//���ⱳ��
	QStringList qssbtn;//��ť
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
	
	

	QStringList qss;//�ı�����ʾ
	qss.append(QString("QLineEdit{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#555555"));
	qss.append(QString("QLineEdit:focus{border-style:none;padding:2px;border-radius:1px;border:2px solid %1;}").arg("#999999"));


	QStringList qsss;//�ı�����ʾ
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

	QStringList qss1;//ѡ��
	qss1.append(QString(("QComboBox{"          //ѡ���  
		" border: 2px solid %1;;"
		" border-radius: 5px;"
		"padding: 1px 2px 1px 2px;"
		" min-width: 4em; "
		"}"
		"QComboBox QAbstractItemView::item {min-height: 30px;}" //����ѡ��߶�
		"QComboBox::down-arrow{border-image:url(:/FEDE/Resources/arrow_down_gray.png);}" //������ͷ
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

	
	ui.tabWidget->setStyleSheet(                                            //��ǩ

		QString(
			"QTabWidget::tab-bar{left:20px; }"//��ǩ����λ��
			"QTabBar::tab{"
			"background: qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 #E1E1E1, stop:0.4 #DDDDDD,stop:0.5 #D8D8D8,stop:1.0 #D3D3D3);"
			"border:1px solid %1;border-bottom-color;"
			"border-top-left-radius:4px;border-top-right-radius:4px;padding: 2px;}"
			"}"
			"QTabBar::tab:selected{margin-top: 2px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:%1;border-color:#FFFFFF;color:white;min-width:90px;}"//ѡ��
			"QTabBar::tab:!selected{margin-top: 5px;margin-left: -1px; margin-right: -1px;border-bottom-color: #FFFFFF; background:#999999;border-color:#FFFFFF;color:white;min-width:90px;}"//δѡ��

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