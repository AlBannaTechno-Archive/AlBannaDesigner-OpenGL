#if 0
#include<AdditionalClasses.h>
#include"CBShader.h"
#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
//#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
//#include "Shader.h"
//#include"camera.h"

///Constants
GLint WIDTH = 800;
GLint HEIGHT = 600;



int main()
{

	StringLoader stl("C:\\tmp\\pps.sdb");
	std::cout << stl.PCData << std::endl;
	//initialize GLFW
	glfwInit();
	//set required options for GLFW Window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//set OpenGL Work In Core-Profile-Mode
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Creat Our GLFW Window Object 
	GLFWwindow*window = glfwCreateWindow(WIDTH, HEIGHT, "ALBANNACOMEBACK", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "ERROR::INITALAIZE::FAILED TO CREATE WINDOW" << std::endl;
		glfwTerminate();
		return -1;
	}
	//Make Current Context Of OpenGL To Our Window
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::INITIALAIZE::FAILED TO INITILIAZE GLFW " << std::endl;
		return -1;
	}
	////////////////////Creating Shaders
	///Create vertex shader
	//Sizing ViewPort

	glViewport(0, 0, WIDTH, HEIGHT);
//	CBShader shader("BeforeComeBack.vs","BeforeComeBack.frag");
	CBShader shader("shaders\\retest.vs.txt", "shaders\\retest.frag.txt");
	//Shader shader("shaders\\BeforeComeBack.vs", "shaders\\TheCamera.frag");
	GLfloat verticesI[] = {
		0.5f, 0.7f, 0.0f,  // Top Right
		0.5f, -0.2f, 0.0f,  // Bottom Right
		-0.5f, -0.4f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
	};
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	///Creat Processing Draw Elements
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	//Set Buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI), verticesI, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	///Set Attributes Which Send To shader
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	///UnBind All Non-Used Objects
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	/////////////////////

	////////////
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.6f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.Use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}

#endif