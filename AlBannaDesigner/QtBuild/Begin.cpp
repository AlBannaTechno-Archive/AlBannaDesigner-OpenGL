#if 0
#include<QtWidgets\qapplication.h>
#include<QtWidgets\qpushbutton.h>
#include"GLQtWindContainer.h"
#if QtCompilation
int main(int argc, char**argv)
{
	QApplication myApp(argc, argv);
	GLQtWindContainer wid;
	wid.show();
	return myApp.exec();
}
#endif
#endif