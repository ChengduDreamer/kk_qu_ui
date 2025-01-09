#include <iostream>
#include <qapplication.h>
#include <qwidget.h>
#include "yk_button.h"

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QWidget* w = new QWidget();
	w->resize(800, 600);
	w->show();

	app.exec();
	return 0;
}