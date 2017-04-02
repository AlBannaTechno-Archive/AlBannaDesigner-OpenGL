#include<IfQInstalled.h>
#if __QT_INSTALLED__
#include<QtWidgets\qslider.h>
#include<QtWidgets\qpushbutton.h>
#include<QtWidgets\qlabel.h>
#include<QtWidgets\QSpacerItem>
#include<QtCore\qdebug.h>
#include<QtWidgets\qmenubar.h>
#include<QtGui\QKeyEvent>
#include"GLQtWindContainer.h"
#if QtCompilation
GLQtWindContainer::GLQtWindContainer()
{
	setMouseTracking(true);
	setLayout(mainLayout = new QVBoxLayout);//��� ����� ��� ��������
	QVBoxLayout *controlsLayout;//��� ����� ���� �����
	mainLayout->addLayout(controlsLayout = new QVBoxLayout);//����� ��� ��� ���� 
	MyGLClass = new GLClass;
	mainLayout->addWidget(MyGLClass);//����� ������ �����  ��� �� ���� ������ �� �� ���� �� ����� ��� �������� ����
//	connect(this->qc, SIGNAL(triggered()), this, SLOT(ChangedBar()));//Trigged =Cliced

}
void GLQtWindContainer::mouseMoveEvent(QMouseEvent *e)
{
	std::cout << "Mouse x,y" << e->x() << " , " << e->y() << "\n";
}
void GLQtWindContainer::SliderValueChanged()
{
	qDebug() << "Buttone Pressed ";
	this->close();
}

void GLQtWindContainer::keyPressEvent(QKeyEvent*e)
{
	if (int('A') == e->key())
		std::cout << "Key Borad Pressed";
	if (Qt::Key::Key_B == e->key())
		std::cout << "B Presses ";
	if (Qt::Key::Key_Escape == e->key())
		this->close();
}
#endif
#endif
