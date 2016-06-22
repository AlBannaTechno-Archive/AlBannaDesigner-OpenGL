#if 0
/*

*/
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<string>
using namespace std;

void key_callback(GLFWwindow*window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE&&action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	////////////////////// My Vertices

	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f };
	/////////////////////////////////Creat Vertex Array Object VAO
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	//////////////////////////////////////
	//Create Vertec buffer and binding it and put it in memory
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	///////////////Create Vertex Shader
	const GLchar *vertexShaderSource = "#version 330 core\nlayout(location = 0) in vec3 position;\nvoid main(){gl_Position = vec4(position.x, position.y, position.z, 1);}";
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
	glCompileShader(vertexShader);
	/////////////////////////////////Check If vertex shader compiled succesfully or not
	GLint VSsuccess;
	GLchar VSinfoLog[512];
	glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&VSsuccess);
	if (!VSsuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, VSinfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << VSinfoLog << std::endl;
	}
	///////////////////////////////////////////Create Fragment Shader
	GLuint fragmentShader;
	const GLchar*fragmentShaderSource = "#version 33 core\nout vec4 color;\nvoid main(){color=vec4(1.0f, 0.5f, 0.2f, 1.0f);}";
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
	glCompileShader(fragmentShader);
	///////////////////////////////////////Check if fragment Shader Compiled Successfully or not 
	GLint FSsuccess;
	GLchar FSinflog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &FSsuccess);
	if (!FSsuccess)
	{
		glGetShaderInfoLog(vertexShader,512,NULL,FSinflog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << FSinflog << std::endl;
	}
	//////////////////////////////////Creat Shader Program
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
		//attache vertex and fragment shader to shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
		//link all those toghther
	glLinkProgram(shaderProgram);
	////////////////////////////////////////////////Check if Shader Program Work Perfectly(linked successfully) or not
	GLint SPsuccess;
	GLchar SPinfolog[512];
	glGetProgramiv(shaderProgram,GL_LINK_STATUS,&SPsuccess);
	if (!SPsuccess)
	{
		glGetProgramInfoLog(shaderProgram,512,NULL,SPinfolog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << SPinfolog << std::endl;
	}
	///Activating Shader Program
	glUseProgram(shaderProgram);
	////////Delete vertex shader and fragment shader from memory because we will not want thim
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	///Linking Vertex Attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	/////////////enable Vertex Attributes
	glEnableVertexAttribArray(0);
	///////////////////////////final
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES,0,3);
	glBindVertexArray(0);
	////////////////////////////////////////////
	GLFWwindow*window = glfwCreateWindow(800,600,"AlBannaDesigner",nullptr,nullptr);
	if (window == nullptr)
	{
		cout << "Failed To Creat GLFW Window " << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed To Initiliaze GLEW" << endl;
		return -1;
	}
	glViewport(0,0,800,600);
	glfwSetKeyCallback(window,key_callback);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		////////////////////////
		glClearColor(0.2f, 0.4f, 0.6f, 0.8f);
		glClear(GL_COLOR_BUFFER_BIT);
		///////////////////////
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;


}
#endif