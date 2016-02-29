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
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
//#include "Shader.h"
//#include"camera.h"
#include<GraphicalCalculator.h>
///Constants
GLint WIDTH = 800;
GLint HEIGHT = 600;
//Functions Prototypes
void key_CallBack(GLFWwindow*window, int key, int scancode, int action, int mode);

int main()
{

	StringLoader stl("shaders\\CBTexture.vs");
	std::cout << "\nVertex Shader\n\n\n" << stl.PCData << std::endl;
	StringLoader st2("shaders\\CBTexture.frag");
	std::cout << "\nFragment Shader\n\n\n" << st2.PCData << std::endl;
	//system("start E:\Programming\OpenGl\my projects\ApplicationOfflineProjetcReturnFromZero\AlBannaDesigner\AlBannaDesigner\ComeBack\CBTexture.cpp");
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
	glfwSetKeyCallback(window, key_CallBack);
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
	CBShader shader("shaders\\CB3DCUBE.vs", "shaders\\CB3DCUBE.frag");
	//Shader shader("shaders\\BeforeComeBack.vs", "shaders\\TheCamera.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat verticesI[] = {
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};


	///Creat Processing Draw Elements
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	//Set Buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI), verticesI, GL_DYNAMIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	///Set Attributes Which Send To shader
	//First Postion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	///UnBind All Non-Used Objects
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	/////////////////////Texture
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	//Set Texture warping parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat MyBordeColor[] = { 0.8f, 0.9f, 0.1f, 0.6f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBordeColor);
	//Set Texture filtring parametre 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//load image 
	GLint width, height;
	unsigned char*image = SOIL_load_image("resources\\textures\\container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	///////////Tex2
	GLuint texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	//warping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat MyBorderColor2[] = { 1.0f, 0.2f, 0.7f, 0.9f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBorderColor2);
	//filtring
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);//we use GLML with MIN Not With MAG
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	////////////Load image
	GLint width2, height2;
	unsigned char*imag2 = SOIL_load_image("resources\\textures\\awesomeface.png", &width2, &height2, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, imag2);
	glGenerateMipmap(GL_TEXTURE_2D);
	//Release
	SOIL_free_image_data(imag2);
	glBindTexture(GL_TEXTURE_2D, 0);
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.6f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.Use();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(shader.Program, "shaderUseAnyname"), 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(shader.Program, "shaderUseAnyname"), 1);

		glBindVertexArray(VAO);
		//glm::vec4 vec(1.0f,0.3f,0.6f,1.0f);
		//	glm::mat4 trans;
		glm::mat4 model;
		//	glm::mat4 view;
		glm::mat4 proj;

		glm::mat4 view;
		glm::mat4 generalrot;
		//	view = glm::translate(view, glm::vec3(0.3,0.5,0.4));


		//	GLuint transLoca = glGetUniformLocation(shader.Program,"trans");
		GLuint modelLoca = glGetUniformLocation(shader.Program, "model");
		GLuint viewLoca = glGetUniformLocation(shader.Program, "view");
		GLuint projLoca = glGetUniformLocation(shader.Program, "projection");
		proj = glm::perspective(45.0f, (GLfloat)(WIDTH / HEIGHT), 0.1f, 100.0f);
		glm::vec3 Transnew = GRATOR::SphricalPosition_Y_Z(2.0f, glm::vec3(0.0f, 0.0f, 0.0f), 0.0f, (GLfloat)(40 * glfwGetTime()));


		view = glm::translate(view, Transnew);
		model = glm::rotate(model, (GLfloat)(glfwGetTime())*20.0f, glm::vec3(1.0f, -1.0f, 0.0f));
	
		
		glUniformMatrix4fv(modelLoca, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoca, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoca, 1, GL_FALSE, glm::value_ptr(proj));
		glDrawArrays(GL_TRIANGLES,0,36);

		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
void key_CallBack(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
#endif
