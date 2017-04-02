#include<IfQInstalled.h>
#if __QT_INSTALLED__
#if 0
#ifndef __QT_LOAD_BLINDING__
#define __QT_LOAD_BLINDING__
#include"QtBlinding.h"
#include<QtWidgets\QVBoxLayout>
#include<QtWidgets\qapplication.h>
#include<QtOpenGL\qgl.h>
#include<QtWidgets\qwidget.h>
#include<QtWidgets\qpushbutton.h>
#include<QtCore\qobject.h>


class QtGLBlinding :public QGLWidget
{
protected:
	BlindingQt*tu = new BlindingQt(800, 600, "QtBlinding");
	void initializeGL();//we will overriding this function from QGLWidget Class
public:
	void paintGL();//we will overriding this function from QGLWidget Class
public://Gl Contenent
	
public:
	~QtGLBlinding();//����� ������ ��� ������ ����� �������� ������ ������� ����� ��� ������� �� ��� ������
};
#endif
#endif
#endif
