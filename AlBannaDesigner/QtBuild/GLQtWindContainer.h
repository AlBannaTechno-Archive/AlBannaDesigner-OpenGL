/*
İí åĞÇ ÇáßáÇÓ íÊã æÖÚ ÇáÇãæÑ ÇááÊí ÓÊÚÑÖ İí ÇáÔÇÔÉ
ÍíË Çä åĞÇ ÇáßáÇÓ íÍÊæì Êáß ÇáÇãæÑ æÇááÊí Êßæä ÌãíÚåÇ ÚÈÇÑÉ Úä ßáÇÓÇÊ

*/
#pragma once
#ifndef __QT__GUI_A
#define __QT__GUI_A
#include<QtWidgets\qwidget.h>
#include<QtWidgets\QVBoxLayout>
#include"GLClass.h"
#include<QtWidgets\qslider.h>
#include<QtWidgets\qpushbutton.h>
#include<QtWidgets\qlabel.h>
#include<QtWidgets\QSpacerItem>
#include<QtCore\qdebug.h>
#include<QtWidgets\qlcdnumber.h>
#include<QtGui\QMouseEvent>
#include<QtGui\QKeyEvent>
#include<QtGui\qpixmap.h>
////----->>>>--->>>>---->>>>---->>>>
//class os;
class GLQtWindContainer :public QWidget
{

	int width1 = 500, height1 = 300;
	Q_OBJECT
	GLClass *MyGLClass;//widget
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
