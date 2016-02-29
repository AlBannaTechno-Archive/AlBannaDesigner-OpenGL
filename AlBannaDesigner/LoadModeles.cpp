#if 0

// Std. Includes
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
GLfloat GM;
int LLMN;
//Â‰«  Ê÷⁄ «·‘Ì›—« 
// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "Shader.h"
#include "Camera.h"
#include "model.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include <SOIL.h>
////////////
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

#include <windows.h>

inline void delay(unsigned long ms)
{
	Sleep(ms);
}

#else  /* presume POSIX */

#include <unistd.h>

inline void delay(unsigned long ms)
{
	usleep(ms * 1000);
}

#endif 
// Properties
GLuint screenWidth = 800, screenHeight = 600;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void Do_Movement();

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
bool mkeys[1024];

GLfloat mlastX = 400, mlastY = 300;
bool mfirstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
GLFWwindow*CamTransWindow;
// The MAIN function, from here we start our application and run the Game loop
int main()
{
	/*
	
	glGenObject(1, &objectId);
	// Bind object to context
	glBindObject(GL_WINDOW_TARGET, objectId);
	// Set options of object currently bound to GL_WINDOW_TARGET
	glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_WIDTH, 800);
	glSetObjectOption(GL_WINDOW_TARGET, GL_OPTION_WINDOW_HEIGHT, 600);
	// Set context target back to default
	glBindObject(GL_WINDOW_TARGET, 0);

	*/
	// Create object
	GLuint objectId = 0;

	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);
	CamTransWindow = window;
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);

	// Setup and compile our shaders
	Shader shader("shaders\\LoadModeles.vs", "shaders\\LoadModeles.frag");
	Shader lampShader("shaders\\lamp.vs", "shaders\\lamp.frag");

	// Load models
	Model ourModel("E:\\Programming\\OpenGl\\booksAndCourses\\VI The BEST BOOK TO LEARN Open gl\\AllFiles\\AllCodesTocheck\\21. Model\\nanosuit\\nanosuit.obj");
	// Used a lamp object here. Find one yourself on the internet, or create your own one ;) (or be oldschool and set the VBO and VAO yourselves)
//	Model lightBulb("E:\\Programming\\OpenGl\\booksAndCourses\\VI The BEST BOOK TO LEARN Open gl\\AllFiles\\AllCodesTocheck\\21. Model\\nanosuit\\nanosuit.obj");
	Model lightBulb("resources\\objects\\Tesst.obj");
	// Draw in wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Point light positions
	glm::vec3 pointLightPositions[] = {
		glm::vec3(2.3f, -1.6f, -3.0f),
		glm::vec3(-1.7f, 0.9f, 1.0f)
	};
//	delay(30);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Check and call events
		glfwPollEvents();
		Do_Movement();

		// Clear the colorbuffer
		glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Use();   // <-- Don't forget this one!
		// Transformation matrices
		glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));

		// Set the lighting uniforms
		glUniform3f(glGetUniformLocation(shader.Program, "viewPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Point light 1
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[0].diffuse"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[0].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[0].linear"), 0.009);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[0].quadratic"), 0.0032);
		// Point light 2
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[1].diffuse"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(shader.Program, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[1].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[1].linear"), 0.009);
		glUniform1f(glGetUniformLocation(shader.Program, "pointLights[1].quadratic"), 0.0032);

		// Draw the loaded model
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(shader);

		// Draw the lamps
		lampShader.Use();
		glUniformMatrix4fv(glGetUniformLocation(lampShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(lampShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		for (GLuint i = 0; i < 2; i++)
		{
			model = glm::mat4();
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f)); // Downscale lamp object (a bit too large)
			glUniformMatrix4fv(glGetUniformLocation(lampShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			lightBulb.Draw(lampShader);
		}

		// Swap the buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

#pragma region "User input"

// Moves/alters the camera positions based on user input
void Do_Movement()
{


	// Camera controls
	if (mkeys[GLFW_KEY_W])
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (mkeys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (mkeys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (mkeys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
	if (mkeys[GLFW_KEY_Z])
		camera.ProcessKeyboard(UP, deltaTime);
	if (mkeys[GLFW_KEY_X])
		camera.ProcessKeyboard(DOWN, deltaTime);
	if (mkeys[GLFW_KEY_M])//to show or hide cursor
		camera.MouseStatuse(CamTransWindow);
	if (mkeys[GLFW_KEY_PAGE_UP])
		camera.ProcessKeyboard(RATESPEEDUP,deltaTime);
	if (mkeys[GLFW_KEY_PAGE_DOWN])
		camera.ProcessKeyboard(RATESPEEDDOWN,deltaTime);
	if (mkeys[GLFW_KEY_SPACE])
		camera.ProcessKeyboard(RESET, deltaTime);
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		mkeys[key] = true;
	else if (action == GLFW_RELEASE)
		mkeys[key] = false;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (mfirstMouse)
	{
		mlastX = xpos;
		mlastY = ypos;
		mfirstMouse = false;
	}

	GLfloat xoffset = xpos - mlastX;
	GLfloat yoffset = mlastY - ypos;

	mlastX = xpos;
	mlastY = ypos;
	if (mkeys[GLFW_KEY_LEFT_CONTROL])
	{
	camera.ProcessMouseMovement(xoffset, yoffset,true);
	}
	else if (!mkeys[GLFW_KEY_LEFT_CONTROL])

	{
		camera.ProcessMouseMovement(xoffset, yoffset);
	}
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

#pragma endregion



#pragma endregion

#endif