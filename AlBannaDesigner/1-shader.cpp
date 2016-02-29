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
using namespace std;
///////////////
//function prototypes
void key_callback(GLFWwindow*window, int key, int scancode, int action, int mode);
GLint CAE(GLfloat*);///CalcilatArrayElements
//window dimensions
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
//////////////////////////////////////////////Shader//////////////////////////////////
	Shader *myshader=new Shader("shaders\\shad.vs","shaders\\shad.frag");
//	Shader myshader("shaders\\shad.vs", "shaders\\shad.frag");
	/////////////////////////////////////////////////////////////////////////////////
	GLfloat verticesC[] = {
		// First triangle
		0.5f, 0.5f, 0.0f, // Top Right
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, 0.5f, 0.0f, // Top Left
		// Second triangle
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f // Top Left
	};

	GLfloat verticesI[] = {
		0.5f, 0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
	};
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	////////////////////////////////////////////
	///////////////////////////
	//////////////////////////////////////////////
	GLfloat verticesC2[] = {
		// First triangle
		0.0f, 0.9f, 0.0f, // Top Right
		0.8f, -0.8f, 0.0f, // Bottom Right
		-0.6f, -0.7f, 0.0f, // Top Left
		// Second triangle
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f // Top Left
		///additional
		, 0.7f, 0.3f, 0.0f,
		0.2f, -0.9f, 0.0f,
		-0.5f, 0.4f, 0.0f

	};
	///VI$@#$@#$@#$@#$@#$#
	//When verticies%3!=0 and we paint all verticies the two another vertices will be connect to (0,0,0)f vertex as a third of them
	GLfloat verticesI2[] = {
		0.5f, 0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
	};
	GLuint indices2[] = {  // Note that we start from 0!
		0, 1, 2,// First Triangle
		1, 2, 3,
		2, 3, 1,
		3, 1, 2,

		//	1, 2, 3   // Second Triangle
	};

	//////////////////////////////////////
	/*
	VBO::vertex buffer objects::We manage this memory via so called vertex buffer objects (VBO) that can store a large number
	of vertices in the GPU’s memory
	//////////////////////////////////////
	VAO:A vertex array object (also known as VAO) can be bound just like a vertex buffer object and any
	subsequent vertex attribute calls from that point on will be stored inside the VAO. This has the
	advantage that when configuring vertex attribute pointers you only have to make those calls once
	and whenever we want to draw the object, we can just bind the corresponding VAO. This makes
	switching between different vertex data and attribute configurations as easy as binding a different
	VAO. All the state we just set is stored inside the VAO.
	///////////////////////\\\/\/\/\/\/\/\/\/\/////////\\\\\\\\\\\\---->
	EBO::Element Buffer Objects::
	There is one last thing we’d like to discuss when rendering vertices and that is element buffer objects
	abbreviated to EBO. To explain how element buffer objects work it’s best to give an example:
	suppose we want to draw a rectangle instead of a triangle. We can draw a rectangle using two
	triangles (OpenGL mainly works with triangles). This will generate the following set of vertices

	*/
#define index //we will configure the method which we will use to creat the shapes
	//when we use index we need to use verticesI
	//when we use Content we will define content
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

#ifdef content
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesC), verticesC, GL_STATIC_DRAW);
#endif
#ifdef index
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI), verticesI, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
#endif
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	////////////////////We Will release
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	/////////////////////////////////////////------------------------------------//////
	GLuint VBO2, VAO2, EBO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);
#ifdef content
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesC2), verticesC2, GL_STATIC_DRAW);
#endif
#ifdef index
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI2), verticesI2, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
#endif
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	/*
	0: from shader
	layout (location = 0) in vec3 position
	location=0
	3: vec3
	GL_FLOAT: type of elements in vec3 is float always
	GL_FALSE: convert our values into
	*/
	glEnableVertexAttribArray(0);

	///////////////Releas
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#define second//or first
	int CoV1 = 6; //CAE(verticesC);
	int CoV2 = 6; //CAE(verticesC2);
	////No problem to set the number of verices more than the actual number


	GLint nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

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
		
		/////////////////////
#ifdef first
		glBindVertexArray(VAO);
#ifdef content
		glDrawArrays(GL_TRIANGLES, 0, CoV2);
#endif
#ifdef index
		glDrawElements(GL_TRIANGLES, CoV2, GL_UNSIGNED_INT, 0);
#endif
#endif
#ifdef second
		glBindVertexArray(VAO2);
#ifdef content
		glDrawArrays(GL_TRIANGLES, 0, CoV2);
#endif
#ifdef index
		glDrawElements(GL_TRIANGLES, CoV2, GL_UNSIGNED_INT, 0);
#endif
#endif
		glBindVertexArray(0);
		//////////////////////
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
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
GLint CAE(GLfloat*Arr)
{
	int mk = sizeof(Arr) / sizeof(GLfloat);
	std::cout << "Number of element = " << mk << std::endl;
	return mk;
}
#endif
