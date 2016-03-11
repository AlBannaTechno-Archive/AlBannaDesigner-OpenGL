#if 1
#include"GLClass.h"
//All GL Content Needers
static GLfloat verticesC[] = {
	// First triangle
	0.5f, 0.5f, 0.0f, // Top Right
	0.5f, -0.5f, 0.0f, // Bottom Right
	-0.5f, 0.5f, 0.0f, // Top Left
	// Second triangle
	0.5f, -0.5f, 0.0f, // Bottom Right
	-0.5f, -0.5f, 0.0f, // Bottom Left
	-0.5f, 0.5f, 0.0f // Top Left
};

static GLfloat verticesI[] = {
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
static GLuint indices[] = {
	//0, 1, 3,
	//1, 2, 3
	0, 1, 2,
	0, 3, 2
};
///////////////////////
static GLfloat verticesC2[] = {
	// First triangle
	0.5f, 0.5f, 0.0f, // Top Right
	0.5f, -0.5f, 0.0f, // Bottom Right
	-0.5f, 0.5f, 0.0f, // Top Left
	// Second triangle
	0.5f, -0.5f, 0.0f, // Bottom Right
	-0.5f, -0.5f, 0.0f, // Bottom Left
	-0.5f, 0.5f, 0.0f // Top Left
};

static GLfloat verticesI2[] = {
	0.5f, 0.5f, 0.0f,  // Top Right
	0.5f, -0.5f, 0.0f,  // Bottom Right
	-0.5f, -0.5f, 0.0f,  // Bottom Left
	-0.5f, 0.5f, 0.0f   // Top Left 
};
static GLuint indices2[] = {  // Note that we start from 0!
	0, 1, 3,  // First Triangle
	1, 2, 3   // Second Triangle
};
//////////////////////////////

void GLClass::initializeGL()
{
	std::cout << "initializeGL" << endl;
		this->setMinimumSize(1280*.75,720*0.75);
//	this->setMaximumSize(500, 250);
//	this->setMinimumSize(500, 250);
	glewInit();
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	///
	VSsuccess;
	VSinfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &VSsuccess);
	if (!VSsuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, VSinfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << VSinfoLog << std::endl;
	}
	/////////
	fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	///////////////////////////////////////Check if fragment Shader Compiled Successfully or not 
	FSsuccess;
	FSinflog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &FSsuccess);
	if (!FSsuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, FSinflog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << FSinflog << std::endl;
	}
	///////////
	shaderProgram = glCreateProgram();
	//attache vertex and fragment shader to shader program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	//link all those toghther
	glLinkProgram(shaderProgram);
	/////Check if Shader Program Work Perfectly(linked successfully) or not
	SPsuccess;
	SPinfolog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &SPsuccess);
	if (!SPsuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, SPinfolog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << SPinfolog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI), verticesI, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	////////////////////We Will release
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	/////////////////////////////////////////------------------------------------//////
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(verticesI2), verticesI2, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	///////////////Releas
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	///////////////////////lllllllllllllooooooooopppppp
	////////////////////////

}
void GLClass::paintGL()
{
	std::cout << "PaintGL CALL";
	std::cout << "  loop " << this->testLoop;
	glViewport(0, 0, this->width(), this->height());
	glClearColor(0.2f, 0.4f, 0.6f, 0.2f);
	glClear(GL_COLOR_BUFFER_BIT);
	///////////////////////
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
GLClass::~GLClass()
{
	
 glDeleteVertexArrays(1, &VAO);
 glDeleteBuffers(1, &VBO);
 glDeleteBuffers(1, &EBO);
 glDeleteVertexArrays(1, &VAO2);
 glDeleteBuffers(1, &VBO2);
 glDeleteBuffers(1, &EBO2);
 
}
#endif