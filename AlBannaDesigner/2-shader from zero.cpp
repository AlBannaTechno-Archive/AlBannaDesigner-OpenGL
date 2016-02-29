#if 0

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
	Shader *shad = new Shader("shaders\\shaderfromzero.vs","shaders\\shaderfromzero.frag");
	//////////////////
	GLfloat svertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left 
	};
	GLuint sindices[] = {
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1,&EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(svertices),svertices,GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(sindices),sindices,GL_STATIC_DRAW);
	//position attribute
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	//color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3*sizeof(float)));
	glEnableVertexAttribArray(0);
	//texcord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	////release DATA
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	//Load and creat texture

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.4f, 0.1f, 0.7f, 0.6f);;
		glClear(GL_COLOR_BUFFER_BIT);
		shad->Use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1,&VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
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