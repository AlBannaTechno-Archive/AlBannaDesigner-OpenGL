#if 0
/*

*/

#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<string>
#include<vector>
#include"shader.h"
#include<SOIL.h>
using namespace std;
void key_callback(GLFWwindow*window, int key, int scancode, int action, int mode);
GLint CAE(GLfloat*);
const GLuint WIDTH = 800, HEIGHT = 600;


int main()
{
	std::cout << "Hello Starting GLFW Context OpenGL 3.3" << std::endl;
	glfwInit();
	//set all the required options for glew
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	////////////////////// My Vertices

	GLFWwindow*window = glfwCreateWindow(800, 600, "AlBannaDesigner", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "Failed To Creat GLFW Window " << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed To Initiliaze GLEW" << endl;
		return -1;
	}
	glViewport(0, 0, WIDTH, HEIGHT);
	Shader *myshader = new Shader("shaders\\texture1.vs", "shaders\\texture1.frag");
	GLuint VBO2, VAO2, EBO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);
	glBindVertexArray(VAO2);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		////////////////////////
		glClearColor(0.2f, 0.4f, 0.6f, 0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		///////////////////////
		//	myshader.Use();
		///////////////
		GLfloat timeValue = glfwGetTime();
		GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
		GLfloat redvalue = (cos(timeValue) / 3) + 0.2;
		GLfloat bluevalue = (sin(timeValue) / 4) + 0.6;
		GLint vertexColorLocation = glGetUniformLocation(myshader->Program, "testcolor");
		myshader->Use();
		glUniform4f(vertexColorLocation, redvalue, greenValue, bluevalue, 1.0f);
		glBindVertexArray(0);
		//////////////////////
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
	glDeleteBuffers(1, &EBO2);
	glfwTerminate();
	return 0;


}
void key_callback(GLFWwindow*window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE&&action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
#endif
