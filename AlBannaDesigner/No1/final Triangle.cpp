#if 1
/*

*/
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<string>
using namespace std;
//function prototypes
void key_callback(GLFWwindow*window, int key, int scancode, int action, int mode);
//window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

//SHADERS
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
	//////////////////////////////// Start Work From Here/->
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	///
	GLint VSsuccess;
	GLchar VSinfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &VSsuccess);
	if (!VSsuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, VSinfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << VSinfoLog << std::endl;
	}
	/////////
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	///////////////////////////////////////Check if fragment Shader Compiled Successfully or not 
	GLint FSsuccess;
	GLchar FSinflog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &FSsuccess);
	if (!FSsuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, FSinflog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << FSinflog << std::endl;
	}
	///////////
	GLuint shaderProgram = glCreateProgram();
	//attache vertex and fragment shader to shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	//link all those toghther
	glLinkProgram(shaderProgram);
	/////Check if Shader Program Work Perfectly(linked successfully) or not
	GLint SPsuccess;
	GLchar SPinfolog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &SPsuccess);
	if (!SPsuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, SPinfolog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << SPinfolog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	////////but Our Verteces Start From Here
	//////Explaination
	/*
	We but 4 points It's Called Vertices []{....}
	then we will Have Two methods to connect this points together
	First method: We Can Draw this point directly from vertices
	But be carful this will draw point's as it's inpute 
	to right->bottom right
	bottom right->bottom left
	bottom left->top left
	then top left->top right
	to draw rectangle 
	..........<-.
	.			.
	.			.	
	.->......->.

	Second Method
	Via use verteces index this give use more flexabilty to draw
	which we can use the index of vertecis to draw
	*/
	/////////////////////Continue
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
		/*
		0.5f, 0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
		*/
		0.5f, 0.7f, 0.0f,  // Top Right
		0.8f, -0.8f, 0.0f,  // Bottom Right
		-0.4f, -0.6f, 0.0f,  // Bottom Left
		-0.3f, 0.4f, 0.0f   // Top Left 
		
	};
	GLuint indices[] = { 
		//0, 1, 3,
		//1, 2, 3
		0,1,2,
		0,3,2
	};
	///////////////////////
	GLfloat verticesC2[] = {
		// First triangle
		0.5f, 0.5f, 0.0f, // Top Right
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, 0.5f, 0.0f, // Top Left
		// Second triangle
		0.5f, -0.5f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f // Top Left
	};

	GLfloat verticesI2[] = {
		0.5f, 0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
	};
	GLuint indices2[] = {  // Note that we start from 0!
		0, 1, 3,  // First Triangle
		1, 2, 3   // Second Triangle
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
	GLuint VBO,VAO,EBO;
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	/////////////////////////////////////////------------------------------------//////
	GLuint VBO2, VAO2, EBO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1,&EBO2);

	glBindVertexArray(VAO2);
#ifdef content
	glBindBuffer(GL_ARRAY_BUFFER,VBO2);
	glBufferData(GL_ARRAY_BUFFER,sizeof(verticesC2),verticesC2,GL_STATIC_DRAW);
#endif
#ifdef index
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(verticesI2),verticesI2,GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices2),indices2,GL_STATIC_DRAW);
#endif
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	///////////////Releas
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#define second//or first
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		////////////////////////
		glClearColor(0.2f, 0.4f, 0.6f, 0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		///////////////////////
		glUseProgram(shaderProgram);
		
#ifdef first
		glBindVertexArray(VAO);
#ifdef content
		glDrawArrays(GL_TRIANGLES, 0, 6);
#endif
#ifdef index
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#endif
#endif
#ifdef second
		glBindVertexArray(VAO);
#ifdef content
		glDrawArrays(GL_TRIANGLES, 0, 6);
#endif
#ifdef index
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
#endif
