#if 1
#include<QtWidgets\qapplication.h>
#include<QtWidgets\qpushbutton.h>
#include"GLQtWindContainer.h"

int main(int argc, char**argv)
{
	QApplication myApp(argc, argv);
	GLQtWindContainer wid;
	wid.show();
	return myApp.exec();
}
#endif