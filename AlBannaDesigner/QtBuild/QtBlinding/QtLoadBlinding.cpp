#include<IfQInstalled.h>
#if __QT_INSTALLED__
#if 0
#include"QtLoadBlinding.h"
void QtGLBlinding::initializeGL()
{
	tu->DoAll();
}
void QtGLBlinding::paintGL()
{
	tu->DoLoop();
}
#endif
#endif
