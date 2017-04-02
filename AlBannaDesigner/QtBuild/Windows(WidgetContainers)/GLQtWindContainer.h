/*
�� ��� ������ ��� ��� ������ ����� ����� �� ������
��� �� ��� ������ ����� ��� ������ ������ ���� ������ ����� �� ������

*/
#include<IfQInstalled.h>
#if __QT_INSTALLED__
#pragma once
#ifndef __QT__GUI_A
#define __QT__GUI_A
#include<QtWidgets\qwidget.h>
#include<QtWidgets\QVBoxLayout>

#include<QtWidgets\qslider.h>
#include<QtWidgets\qpushbutton.h>
#include<QtWidgets\qlabel.h>
#include<QtWidgets\QSpacerItem>
#include<QtCore\qdebug.h>
#include<QtWidgets\qlcdnumber.h>
#include<QtGui\QMouseEvent>
#include<QtGui\QKeyEvent>
#include<QtGui\qpixmap.h>
#include<../AlBannaDesigner/QtBuild/QtBlinding/QtBlinding.h>
#include<../AlBannaDesigner/QtBuild/GLMainClass/GLClass.h>
#if QtCompilation
////----->>>>--->>>>---->>>>---->>>>
//class os;
class GLQtWindContainer :public QWidget
{

	int width1 = 500, height1 = 300;
	Q_OBJECT
//	GLClass *MyGLClass;//widget
	GLClass*MyGLClass;
	QVBoxLayout *mainLayout;//
	private slots:
	void SliderValueChanged();
public:
	//	void Mousing(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);//Overrided Function
	void keyPressEvent(QKeyEvent*);
	GLQtWindContainer();

};
#endif
#endif
#endif
