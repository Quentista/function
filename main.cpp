#include <QApplication>
#include <Function.h>

int main(int argc, char** argv)
{
	QApplication app (argc, argv);


	Function func;
	func.resize(600,300);
	func.show();

	return app.exec();
}

