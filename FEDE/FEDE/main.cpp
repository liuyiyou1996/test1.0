#include "fede.h"
#include "place.h"
#include "Input.h"
#include "QProcess.h"


#include <QtWidgets/QApplication>
#pragma execution_character_set("utf-8") 

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//a.setQuitOnLastWindowClosed(false);
	//Input a1;
	//a1.show();
	place p;
	//p.show();
	//w.setFixedSize(w.width(), w.height());
	p.setWindowTitle(QObject::tr("事故应急演练评估"));
	p.show();
	int e = a.exec();
	if (e == 777)
	{
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
		return 0;
	}
	return e;
}
void    onRestart()
{
	qApp->quit();   // 或者   aApp->closeAllWindows();
	QProcess::startDetached(qApp->applicationFilePath(), QStringList());
}