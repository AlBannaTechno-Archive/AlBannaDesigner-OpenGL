#if 0
#include<AdditionalClasses.h>
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
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


int main()
{
	//initialize GLFW
	glfwInit();
	//set required options for GLFW Window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//set OpenGL Work In Core-Profile-Mode
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	//Creat Our GLFW Window Object 
	GLFWwindow*window = glfwCreateWindow(WIDTH,HEIGHT,"ALBANNACOMEBACK",nullptr,nullptr);
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
	///Create Shader Object
	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
	//Get Shader Source
	glShaderSource(vertexshader,1,&vertexShaderSource,NULL);
	//Compiling Shader
	glCompileShader(vertexshader);
	GLint SuccessVertexShader;
	GLchar SVSInfoLog[512];
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &SuccessVertexShader);
	if (!SuccessVertexShader)
	{
		glGetShaderInfoLog(vertexshader, 512, NULL, SVSInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FALIED\n" << SVSInfoLog << std::endl;
	}
	//////Creat Fragment Shader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//Check
	GLint SuccessFragmentShader;
	GLchar SFSLogInfo[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &SuccessFragmentShader);
	if (!SuccessFragmentShader)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, SFSLogInfo);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << SFSLogInfo << std::endl;
	}
	///Creat Shader Programm
	GLuint shaderProgram = glCreateProgram();
	///Attach Vertex and fragment shader to the program
	glAttachShader(shaderProgram, vertexshader);
	glAttachShader(shaderProgram, fragmentShader);
	//Link all thos Together
	glLinkProgram(shaderProgram);
	//check
	GLint SPSuccess;
	GLchar SPInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &SPSuccess);
	if (!SPSuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, SPInfoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
	}
	//Release
	glDeleteShader(vertexshader);
	glDeleteShader(fragmentShader);
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
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI),verticesI,GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	///Set Attributes Which Send To shader
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	///UnBind All Non-Used Objects
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	/////////////////////

	////////////
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.6f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}

#endif