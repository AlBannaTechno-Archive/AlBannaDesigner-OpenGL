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


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// The MAIN function, from here we start the application and run the game loop
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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "AlBannaDesigner", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);


	// Build and compile our shader program
	Shader ourShader("shaders\\WorkOnMatricies.vs", "shaders\\WorkOnMatricies.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
		//	1,0,3,
		//	0,2,1
	};

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

	GLuint VAOcube,VBOcube;
	glGenVertexArrays(1, &VAOcube);
	glGenBuffers(1,&VBOcube);

	glBindVertexArray(VAOcube);
	glBindBuffer(GL_ARRAY_BUFFER,VBOcube);
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
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(45.0f,(GLfloat)(WIDTH/HEIGHT),0.1f,100.0f);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.4f, 0.6f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(ourShader.Program, "shaderUseAnyname"), 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "secondshader"), 1);
		ourShader.Use();
		////Matricies

		GLuint ViewLocation = glGetUniformLocation(ourShader.Program, "view");
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(view));

		GLuint ProjectionLocation = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

		GLuint ModelLocation = glGetUniformLocation(ourShader.Program, "model");

		for (int counter = 1; counter <= 10; counter++)
		{
			glm::mat4 model;
			model = glm::translate(model,cubePositions[counter]);
			GLfloat Cangle = 17.0f*counter;
			model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

			
			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glBindVertexArray(VAOcube);
			glDrawArrays(GL_TRIANGLES, 0, 36);

		}

		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAOcube);
	glDeleteBuffers(1, &VBOcube);

	glfwTerminate();
	return 0;

}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
#endif