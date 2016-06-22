#if 0

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
#include "Shader.h"
#include"camera.h"
#include<GraphicalCalculator.h>
#include<thread>
#include<string>
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow*window, double xpos, double ypos);
void scroll_callback(GLFWwindow*window, double xoffset, double yoffset);
void do_movements(GLFWwindow*window);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
///camera standers
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

GLfloat yaw = -90.0f;
GLfloat pitch = 0.0f;
GLfloat lastx = WIDTH / 2;
GLfloat lasty = HEIGHT / 2;
GLfloat fov = 45.f;
GLfloat SpeedRat = 1.0;

bool Keys[1024];
GLfloat DeltaTime = 0.0f;
GLfloat LastFrame = 0.0f;
GLfloat CurrentFrame;
////TRackKeys
short PressM2toshowMouse = 0;
bool PressM2toshowMouseStatues = false;
/////
// The MAIN function, from here we start the application and run the game loop
void llp()
{

}
void TestThreadU()
{
	std::string st;
	std::cin >> st;
	if (st == "osa")
		std::cout << "OK" << std::endl;

}
float Rot = 0;
float Rotz = 0;
int main()
{
	
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	// Create a GLFWwindow object that we can use for GLFW's functions
	static GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "AlBannaDesigner", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	///tell open gl to hide cursor and capture it 
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//	glfwSetInputMode(window,);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);


	// Build and compile our shader program
	Shader ourShader("shaders\\TheCamera.vs", "shaders\\TheCamera.frag");
	GLfloat MyCube[] = {
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
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};
	//we will make graid on ZX Plane
	/*

	int graidline = 10;
	GLfloat MyGraidXz[] = {
	-(graidline + 1), 0.0f, -(graidline+1),
	};
	GLfloat MyGraidxZ[] = {
	-(graidline + 1), 0.0f, -(graidline + 1),
	};
	for (int gral = -graidline; gral <= graidline; gral++)
	{
	MyGraidXz += {-graidline,0.0f,(GLfloat)(gral)};
	}
	for (int gral = -graidline; gral <= graidline; gral++)
	{
	MyGraidxZ += {(GLfloat)(gral), 0.0f, };
	}

	*/
	///////////////////////
	GLuint VAOcube, VBOcube;
	glGenVertexArrays(1, &VAOcube);
	glGenBuffers(1, &VBOcube);

	glBindVertexArray(VAOcube);
	glBindBuffer(GL_ARRAY_BUFFER, VBOcube);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MyCube), MyCube, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);//release
	////////////////////////
	//load and craete a texture  NO1
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);//all upcoming gl_texture_2d operation now have effect on this texture object

	//set the texture warping parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat MyBorderColor[] = { 0.6f, 0.7f, 0.3f, 0.5f };//Because we use GL_CLAMP_TO_BORDER opition
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBorderColor);
	///set the texture filtering parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Load image ,creat texture and generate mipmaps
	GLint width, height;
	unsigned char*image = SOIL_load_image("resources\\textures\\container.jpg", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);//first RGB for texture and second for source image
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	//Texture NO2
	GLuint texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);

	//set texture warping parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat MyBorderColor2[] = { 1.0f, 0.2f, 0.7f, 0.9f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBorderColor2);
	//set texture filtering parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);//we use GLML with MIN Not With MAG
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Load image And Creat texture and generate mipmaps
	GLint width2, height2;
	unsigned char *imag2 = SOIL_load_image("resources\\textures\\awesomeface.png", &width2, &height2, 0, SOIL_LOAD_RGB);
	//Set Image On The Shader
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, imag2);
	glGenerateMipmap(GL_TEXTURE_2D);
	//Release
	SOIL_free_image_data(imag2);
	glBindTexture(GL_TEXTURE_2D, 0);
	////matricies
	//	glm::mat4 model;
	//	model = glm::rotate(model,-55.0f,glm::vec3(1.0f,0.0f,0.0f));
	glm::mat4 view;
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(45.0f, (GLfloat)(WIDTH / HEIGHT), 0.1f, 100.0f);
	glm::vec3 REcordPosCam = cameraPos;
//	std::thread Test(TestThreadU);
	float generalDecrea = 20;
	
	while (!glfwWindowShouldClose(window))
	{
		
		GLfloat CurrentFrame = glfwGetTime();
		DeltaTime = CurrentFrame - LastFrame;
		LastFrame = CurrentFrame;

		glfwPollEvents();
		do_movements(window);

		glClearColor(0.4f, 0.6f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(ourShader.Program, "shaderUseAnyname"), 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "secondshader"), 1);
		ourShader.Use();
		////Matricies
		projection = glm::perspective(fov, (GLfloat)(WIDTH / HEIGHT), 0.1f, 100.0f);
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		GLuint ViewLocation = glGetUniformLocation(ourShader.Program, "view");
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(view));

		GLuint ProjectionLocation = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

		GLuint ModelLocation = glGetUniformLocation(ourShader.Program, "model");
		
		/////////////////////////New

/////////////////////
		///GHBN
		/*
		
			for (int counter = 1; counter <= 20; counter++)
			{
				//glm::vec3 Transnew = GRATOR::SphricalPosition(7.0f, glm::vec3(0.0f, 0.0f, -10.0f), Rot, (GLfloat)(20 * counter + 20 * glfwGetTime()));
				glm::vec3 Transnew = GRATOR::SphricalPosition_Y_Z(7.0f, glm::vec3(0.0f, 0.0f, -10.0f), Rot, (GLfloat)(20 * counter +Rotz ));
				glm::mat4 model;
				model = glm::translate(model, Transnew);
				GLfloat Cangle = 17.0f;
				model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

				glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
				glBindVertexArray(VAOcube);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
		*/
		
		
		for (int counter = 1; counter <= 20; counter++)
		{
			glm::vec3 Transnew = GRATOR::SphricalPosition_Y_Z(10.0f, glm::vec3(0.0f, 0.0f, 0.0f), (GLfloat)(19.0f * glfwGetTime())*counter+Rot, (GLfloat)(9 * glfwGetTime())*counter+Rotz);
			glm::mat4 model;
			model = glm::translate(model, Transnew);
			GLfloat Cangle = 17.0f;
			model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glBindVertexArray(VAOcube);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		
		for (int counter = 1; counter <= 20; counter++)
		{
			glm::vec3 Transnew = GRATOR::SphricalPosition_Y_Z(10.0f, glm::vec3(0.0f, 0.0f, 0.0f), -(GLfloat)(15 * glfwGetTime())*counter, -(GLfloat)(15 * glfwGetTime())*counter);
			glm::mat4 model;
			model = glm::translate(model, Transnew);
			GLfloat Cangle = 17.0f;
			model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glBindVertexArray(VAOcube);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		
		


		/////////////////////////////////////////////////
		/*
		
		for (int counter = 1; counter <= 10; counter++)
		{
			glm::mat4 model;
			model = glm::translate(model, cubePositions[counter]);
			GLfloat Cangle = 17.0f*counter;
			model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));


			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glBindVertexArray(VAOcube);
			glDrawArrays(GL_TRIANGLES, 0, 36);

		}
		*/
		
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	//	Test.join();
	
	glDeleteVertexArrays(1, &VAOcube);
	glDeleteBuffers(1, &VBOcube);

	glfwTerminate();
	return 0;

}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	//ãæÖÚ ÇáßÇãíÑÇ ÝÞØ íãßä ÊÛííÑå Ïæä ÇáÅÚÊãÇÏ Úáì ÔíÆ ÁÇÎÑ ÈíäãÇ ÈÞíÉ ÎÕÇÆÕ ÇáßÇãíÑ
	//áÇÈÏ æÇä Êßæä äÇÊÌíÉ Úä ÍÇÕá ÖÑÈ ãÊÌåíä

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Keys[key] = true;
		else if (action == GLFW_RELEASE)
			Keys[key] = false;
	}
}
void do_movements(GLFWwindow*window)
{
	GLfloat cameraSpeed = 5.0f*DeltaTime*SpeedRat;
	if (Keys[GLFW_KEY_PAGE_UP])
	{
		SpeedRat += 0.2f;
		cameraSpeed = 5.0f*DeltaTime*SpeedRat;
	}
	if (Keys[GLFW_KEY_PAGE_DOWN])
	{
		if (5.0f*DeltaTime*SpeedRat < 0)//to prevent program from revers move direction
		{
			SpeedRat = 0.0f;
		}
		else
			SpeedRat -= 0.2f;
		cameraSpeed = 5.0f*DeltaTime*SpeedRat;
	}
	if (Keys[GLFW_KEY_W])
	{
		cameraPos += cameraSpeed * cameraFront;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_S])
	{
		cameraPos -= cameraSpeed * cameraFront;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_A])
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) *//ÍÇÕá ÇáÖÑÈ ÇáÅÊÌÇåí íÚØí ãÊÌåÇ ÚÇãæÏí ÚáíåãÇ æáÇßäå ãáÇÕÞ áåãÇ ÝäÖÑÈå Ýí ÞíãÉ áÊÍÑíßÉ 
			cameraSpeed;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_D])
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) *
			cameraSpeed;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_Z])
	{
		cameraPos += cameraUp*cameraSpeed;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_X])
	{
		cameraPos -= cameraUp*cameraSpeed;
		std::cout << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";
	}
	if (Keys[GLFW_KEY_SPACE])
	{
		if (cameraPos == glm::vec3(0.0f, 0.0f, 3.0f))
		{
			std::cout << "The Camera Was Reset IT'S Position Why Yo Press Reset Again? \n";
		}
		else
		{
			cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
			std::cout << "Reset Camera Position : " << "CP( " << cameraPos.x << " , " << cameraPos.y << " , " << cameraPos.z << " )\n ";

		}

	}
	if (Keys[GLFW_KEY_M])//to show or hide cursor
	{

		if (PressM2toshowMouse = 2)
		{

			if (PressM2toshowMouseStatues == false)
			{

				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
				PressM2toshowMouseStatues = !PressM2toshowMouseStatues;

			}
			else if (PressM2toshowMouseStatues == true)
			{
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				PressM2toshowMouseStatues = !PressM2toshowMouseStatues;
			}
			PressM2toshowMouse = 0;
		}
		else
			PressM2toshowMouse++;
	}
	if (Keys[GLFW_KEY_G])
	{
		Rot += SpeedRat;
	}
	if (Keys[GLFW_KEY_H])
	{
		Rot -= SpeedRat;
	}
	if (Keys[GLFW_KEY_B])
	{
		Rotz += SpeedRat;
	}
	if (Keys[GLFW_KEY_N])
	{
		Rotz -= SpeedRat;
	}

	/*
	äÍÊÇÌ Ýí ÇáæÇÞÚ áÊäÝíÐ  åÐå ÇáÝßÑÉ
	Çä äÞæã ÈäÞá åÐå ÇáäÞØ Úáì ÇáÏÇÆÑÉ ÇááÊí ãÑßÒåÇ ÇáãæÖÚ ÇáÎÇÕ ÈÇáßÇãíÑÇ
	æäÕÝ ÞØÑåÇ ãä åÐÇ ÇáãæÞÚ æÍÊì Çá cameraFront
	if (Keys[GLFW_KEY_V])
	{
	cameraFront.x += cameraSpeed/5;
	}
	if (Keys[GLFW_KEY_C])
	{
	cameraFront.x -= cameraSpeed / 5;
	}
	*/
}
bool firstmouse = true;
void mouse_callback(GLFWwindow*window, double xpos, double ypos)
{
	/*
	äÍÊÇÌ áØÑíÞÉ ÊÓãÍ ááßÇãíÑÇ ÈÇáÏæÑÇä Íæá ãÑßÒ ÇáÑÄíÉ
	Ãí Íæá äÞØÉ Çá front
	æåÐÇ ÓíÝíÏäÇ ÅÐÇ ÃÑÏäÇ ÇáÏæÑÇä Íæá äÕÑ ãÚíä ÚäÏ ÊÍÏíÏå
	*/
	if (firstmouse)
	{
		lastx = xpos;
		lasty = ypos;
		firstmouse = false;
	}
	GLfloat xoffset = xpos - lastx;
	GLfloat yoffset = -(ypos - lasty);
	lastx = xpos;
	lasty = ypos;

	GLfloat sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	//save motion
	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
		pitch = -89.0f;
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);

}
void scroll_callback(GLFWwindow*window, double xoffset, double yoffset)
{
	std::cout << "fov = " << fov;
	if (fov >= 1.0f&&fov <= 45.0f)
		fov -= yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
	/*

	if (fov >= 1.0f && fov <= 45.0f)
	fov -= yoffset;
	if (fov <= 1.0f)
	fov = 1.0f;
	if (fov >= 45.0f)
	fov = 45.0f;
	*/
}
#endif