#ifndef __GL_CLASS__
#define __GL_CLASS__
///GL Includeing files
#include<GL\glew.h>
#include<iostream>
#include<string>
///////Qt Include:
#include<QtWidgets\QVBoxLayout>
#include<QtWidgets\qapplication.h>
#include<QtOpenGL\qgl.h>
#include<QtWidgets\qwidget.h>
#include<QtWidgets\qpushbutton.h>
#include<QtCore\qobject.h>
//Static Files To Use with Gl Program

using namespace std;
//function prototypes
//window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

//SHADERS
static const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";

static const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
//////////////////////////////
class GLClass :public QGLWidget
{
protected:
	void initializeGL();//we will overriding this function from QGLWidget Class
public:
	void paintGL();//we will overriding this function from QGLWidget Class
public://Gl Contenent
	int testLoop = 0;
	GLint VSsuccess;
	GLchar VSinfoLog[512];
	GLuint fragmentShader;
	GLuint vertexShader;
	GLint FSsuccess;
	GLchar FSinflog[512];
	GLuint shaderProgram;
	GLint SPsuccess;
	GLchar SPinfolog[512];
	GLuint VBO, VAO, EBO;
	GLuint VBO2, VAO2, EBO2;
public:
	~GLClass();//”‰ﬁÊ„ » ⁄œÌ· Â–« «·„Âœ„ ·ÌﬁÊ„ »«” œ⁄«„ «·„Âœ„ «·«”«”Ì ≈÷«›… «·Ï „«”‰÷⁄Â ›Ì Â–« «·„Âœ„
};


#endif