//Not succedefdcdcdc
#if 0
#include <iostream>
#include <cmath>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include "Shader.h"
#include "Camera.h"
#include"AdditionalPersonalFunctions.h"
#include<vector>
#include<thread>
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movement();
void do_mouse_movement();
//void ScallerVertices(ScVe verarray, int SVsize);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

//VI

bool Wind = true;
// Camera
Camera  camera(glm::vec3(0.0f, 0.0f, 4.0f));
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool    keys[1024];
GLfloat  Gypos;
GLfloat Gxpos;
// Light attributes
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

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
	GLFWwindow* SecondWindow = glfwCreateWindow(WIDTH, HEIGHT, "AlBannaDesignerNo2", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// GLFW Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	
////////////////////////////SecondWindow///////
	glfwMakeContextCurrent(SecondWindow);

	// Set the required callback functions
	glfwSetKeyCallback(SecondWindow, key_callback);
	glfwSetCursorPosCallback(SecondWindow, mouse_callback);
	glfwSetScrollCallback(SecondWindow, scroll_callback);

	// GLFW Options
	glfwSetInputMode(SecondWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);

	//////////////////////////////////////////////////
	//BasicColorLightingMotion
	// Build and compile our shader program
	//Shader lightingShader("shaders\\BasicColorLighting.vs", "shaders\\BasicColorLighting.frag");
	//Shader lampShader("shaders\\BasicColorLamp.vs", "shaders\\BasicColorLamp.frag");
	///	Shader lightingShader("shaders\\BasicColorLightingMotion.vs", "shaders\\BasicColorLightingMotion.frag");
	///	Shader lampShader("shaders\\BasicColorLamp.vs", "shaders\\BasicColorLamp.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	Shader lightingShader("shaders\\Lighting maps.vs", "shaders\\Lighting maps.frag");
	Shader lampShader("shaders\\BasicColorLamp.vs", "shaders\\BasicColorLamp.frag");



	GLfloat vertices[] = {
		// Positions           // Normals           // Texture Coords
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
	};

	///////////////////

	///////////////////////////////

	//int mms = CalculateArrayPower(vertices);
	//std::cout << mms;
	///////////////////////////////////////////////////////
	glfwMakeContextCurrent(window);

	GLfloat CopVer[6 * 6 * 8];
	AutoCopyArray(vertices, CopVer, 6 * 6 * 8);
	ScallerVertex(vertices, 6 * 6 * 8, 1.0f);//ver : obj   .. ..... CopVer  ->light
	// First, set the container's VAO (and VBO)
	GLuint VBO, containerVAO;
	glGenVertexArrays(1, &containerVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CopVer), CopVer, GL_STATIC_DRAW);
	glBindVertexArray(containerVAO);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
	GLuint lightVAO, lightVBO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
	glGenBuffers(1, &lightVBO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Set the vertex attributes (only position data for the lamp))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	////texture
	//load and craete a texture  NO1
	GLuint diffuseMap;
	glGenTextures(1, &diffuseMap);
	glBindTexture(GL_TEXTURE_2D, diffuseMap);//all upcoming gl_texture_2d operation now have effect on this texture object

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
	unsigned char*image = SOIL_load_image("resources\\textures\\container2.png", &width, &height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);//first RGB for texture and second for source image
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

//////////////Second Window opp

	glfwMakeContextCurrent(SecondWindow);
	AutoCopyArray(vertices, CopVer, 6 * 6 * 8);
	ScallerVertex(vertices, 6 * 6 * 8, 1.0f);//ver : obj   .. ..... CopVer  ->light
	// First, set the container's VAO (and VBO)
	glGenVertexArrays(1, &containerVAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(CopVer), CopVer, GL_STATIC_DRAW);
	glBindVertexArray(containerVAO);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
	glGenBuffers(1, &lightVBO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Set the vertex attributes (only position data for the lamp))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	////texture
	//load and craete a texture  NO1
	glGenTextures(1, &diffuseMap);
	glBindTexture(GL_TEXTURE_2D, diffuseMap);//all upcoming gl_texture_2d operation now have effect on this texture object

	//set the texture warping parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBorderColor);
	///set the texture filtering parametres
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//Load image ,creat texture and generate mipmaps
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);//first RGB for texture and second for source image
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);


	///////////////
	//////////////////////
	//	thread MouseMove(do_mouse_movement);
	//	thread Move(do_movement);
	struct Material{
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
		GLfloat shininess;
	};
	Material material;
	struct Light {
		glm::vec3 position;
		glm::vec3 ambient;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};
	Light light;
	// Game loop

	while (!glfwWindowShouldClose(window))
	{
		if (Wind == false)
		{
			glfwMakeContextCurrent(SecondWindow);
			Wind = !Wind;
		}
		else
		{
			glfwMakeContextCurrent(window);
			Wind = !Wind;

		}
		// Calculate deltatime of current frame
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		//	do_mouse_movement();//we will convert this to thread
		do_movement();
		//	Move.swap(Move);
		//	MouseMove.swap(MouseMove);
		// Clear the colorbuffer
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Use cooresponding shader when setting uniforms/drawing objects
		lightingShader.Use();
		///tex
		glUniform1i(glGetUniformLocation(lightingShader.Program, "material.diffuse"), 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap);


		GLint lightPosLoc = glGetUniformLocation(lightingShader.Program, "light.position");
		GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
		glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
		//		glUniform3f(viewPosLoc, (camera.Position.x - camera.Front.x), (camera.Position.y - camera.Front.y), (camera.Position.z - camera.Front.z));
		glUniform3f(viewPosLoc, (camera.Position.x), (camera.Position.y), (camera.Position.z));

		// Set lights properties
		glm::vec3 lightColor;
		//ﬁ„‰« »≈÷«›… lightPos.x Õ Ì Ì €Ì— „ﬂ«‰ «·»—Ìﬁ „⁄  €Ì— „ﬂ«‰ «·’‰œÊﬁ 
		//lightColor.x  = sin(glfwGetTime() * 2.0f);
		//lightColor.y = sin(glfwGetTime() * 5.7f);
		//lightColor.z  = sin(glfwGetTime() * 1.3f);
		lightColor.x = 1.0f;
		lightColor.y = 1.0f;
		lightColor.z = 1.0f;
		glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f); // Decrease the influence
		glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // Low influence
		glUniform3f(glGetUniformLocation(lightingShader.Program, "light.ambient"), ambientColor.x, ambientColor.y, ambientColor.z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "light.diffuse"), diffuseColor.x, diffuseColor.y, diffuseColor.z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "light.specular"), 1.0f, 1.0f, 1.0f);
		// Set material properties//we can use strucr material also
		glUniform3f(glGetUniformLocation(lightingShader.Program, "material.ambient"), 1.0f, 0.5f, 0.31f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "material.diffuse"), 1.0f, 0.5f, 0.31f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "material.specular"), 0.5f, 0.5f, 0.5f); // Specular doesn't have full effect on this object's material
		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 100.0f);

		// Create camera transformations
		glm::mat4 view;
		view = camera.GetViewMatrix();
		glm::mat4 projection = glm::perspective(camera.Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
		// Get the uniform locations
		GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
		GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
		// Pass the matrices to the shaders
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Draw the container (using container's vertex attributes)
		glBindVertexArray(containerVAO);
		glm::mat4 model;
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// Also draw the lamp object, again binding the appropriate shader
		lampShader.Use();
		// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
		modelLoc = glGetUniformLocation(lampShader.Program, "model");
		viewLoc = glGetUniformLocation(lampShader.Program, "view");
		projLoc = glGetUniformLocation(lampShader.Program, "projection");
		// Set matrices
		//view = glm::rotate(view, 30 * (GLfloat)glfwGetTime(), glm::vec3(1.0f, -1.0f, 1.0f));
		//	view = glm::translate(glm::mat4(1.0f),glm::vec3(1.0f,0.5f,0.5f));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		model = glm::mat4();//clear last value
		//	float c = (cos(glfwGetTime()*10) == 0) ? 1 : (cos(glfwGetTime())*10);
		//	lightPos.x = (GLfloat)(sin(glfwGetTime() * 10) == 0 || sin(glfwGetTime() * 10)!=1) ? lightPos.x*sin(20)*20 : (sin(glfwGetTime() * 10));
		//	std::cout << lightPos.x<<" ";
		//	lightPos.y *= (GLfloat)sin(glfwGetTime());
		model = glm::translate(model, lightPos);
		//	model = glm::translate(glm::mat4(1.0f), lightPos);
		//	model = glm::rotate(model,56.0f, glm::vec3(0.0f, 0.0f, 0.0f ));
		//	model = lightPos;
		//	model = glm::scale(model, glm::vec3(0.9f)); // Make it a smaller cube//it's affect on all thing position rotation 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// Draw the light object (using light's vertex attributes)
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
		glfwSwapBuffers(SecondWindow);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

void do_movement()
{
	// Camera controls
	if (keys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	//	Gxpos = xpos;
	//	Gypos = ypos;



	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;  // Reversed since y-coordinates go from bottom to left

	lastX = xpos;
	lastY = ypos;
	camera.ProcessMouseMovement(xoffset, yoffset);


}
void do_mouse_movement()
{
	if (firstMouse)
	{
		lastX = Gxpos;
		lastY = Gypos;
		firstMouse = false;
	}

	GLfloat xoffset = Gxpos - lastX;
	GLfloat yoffset = lastY - Gypos;  // Reversed since y-coordinates go from bottom to left

	lastX = Gxpos;
	lastY = Gypos;

	camera.ProcessMouseMovement(xoffset, yoffset);

}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}
#endif