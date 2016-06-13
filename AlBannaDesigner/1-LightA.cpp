#include"1-LightA.h"
bool keys[1024];
GLfloat lastX, lastY;
bool firstMouse;
Camera camera1 = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
glm::vec2 mousePosG;
namespace ABTGLC
{
	BGLC::BGLC(GLint width, GLint height, char*title)
	{
		this->InializeStand(width, height, title);
		this->WIDTH = width;
		this->HEIGHT = height;
		InitAtConstructor = true;//If We Declare this function before last line the programme wil crroupt
	}
	glm::vec2 BGLC::ReturnMousPos()
	{
		this->mousePos = mousePosG;
		return this->mousePos;
	}
	//”‰ﬁÊ„ »⁄„· œ«·… «Œ—Ï „À· «·ﬂÊ‰” —«ﬂ Ê—
	void BGLC::InializeStand(GLint width, GLint height, char*title)
	{
		if (InitAtConstructor == true)
		{
			std::cout << "You Inialaized Data At Consructor ?\n";
			return;
		}
		this->WIDTH = width;
		this->HEIGHT = height;
		this->Title = title;
		glfwInit();
		// Set all the required options for GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		this->window = glfwCreateWindow(this->WIDTH, this->HEIGHT, this->Title, nullptr, nullptr);

		glfwMakeContextCurrent(this->window);
		glfwSetKeyCallback(this->window, key_callback);
		glfwSetCursorPosCallback(this->window, mouse_callback);
		glfwSetScrollCallback(this->window, scroll_callback);

		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		//	glfwSetInputMode(window,);
		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		glewInit();
		// Define the viewport dimensions
		glViewport(0, 0, this->WIDTH, this->HEIGHT);
		this->DeltaTime = 0.0f;	// Time between current frame and last frame
		this->LastFrame = 0.0f;  	// Time of last frame
		bool keys[1024];
		lastX = this->WIDTH / 2;
		lastY = this->HEIGHT / 2;
		firstMouse = true;
	}
	void BGLC::INITCallBackFunctions(){}
	int BGLC::AddShaders(char*VsPath, char*FragsPath){return 1;}
}
///LightSection Class
namespace ABTGLC
{
	LightSection::LightSection(GLint width, GLint height, char*title) :BGLC(width, height, title){};
	void LightSection::SetVarValues()
	{
		CamInh = &camera1;
		this->lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
	}
	void LightSection::DoAll()
	{
		//	this->SetAllCallBacks();
		this->SetVarValues();
		this->CreateLampCube();
		this->CreateLightenCube();
		this->CreateShaders();
		this->CreateTextures();
		//	this->CreateCameras();
		//this->NumActiveCam = this->AddCamera(glm::vec3(0.0f,0.0f,-3.0f));
		this->InfinityLoop();
	}
	void LightSection::SetAllCallBacks()
	{
		glfwSetKeyCallback(window, key_callback);
		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback);
	}
	GLuint LightSection::loadTexture(GLchar* path)
	{
		//Generate texture ID and load texture data 
		GLuint textureID;
		glGenTextures(1, &textureID);
		int width, height;
		unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
		// Assign texture to ID
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		// Parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		SOIL_free_image_data(image);
		return textureID;
	}

	void LightSection::CreateLightenCube()
	{
		glGenVertexArrays(1, &containerVAO);
		glGenBuffers(1, &containerVBO);

		glBindBuffer(GL_ARRAY_BUFFER, containerVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CubeWithNorm), CubeWithNorm, GL_DYNAMIC_DRAW);
		glBindVertexArray(containerVAO);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3*sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
		this->LightenCube = true;

	}
	void LightSection::CreateLampCube()
	{
		glGenVertexArrays(1, &lightVAO);
		glGenBuffers(1, &lightVBO);
		// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
		glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(NonTexCube), NonTexCube, GL_STATIC_DRAW);
		glBindVertexArray(lightVAO);
		// Set the vertex attributes (only position data for the lamp))
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		this->LampCube = true;
	}
	void LightSection::CreateTextures()
	{

		glGenTextures(1, &this->Texture1);
		glBindTexture(GL_TEXTURE_2D, this->Texture1);//all upcoming gl_texture_2d operation now have effect on this texture object
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
		////////////////TexNo2
		this->TexNo1 = true;
		glGenTextures(1, &this->Texture2);
		glBindTexture(GL_TEXTURE_2D, this->Texture2);
		//set texture warping parametres
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		GLfloat MyBorderColor2[] = { 0.4f, 0.2f, 0.5f, 0.9f };
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
		this->TexNo2 = true;
	}
	void LightSection::CreateShaders()
	{
		this->lightingShader.CreatShader("shaders\\ContAsClass\\LightenObject.vs", "shaders\\ContAsClass\\LightenObject.frag");
		this->lampShader.CreatShader("shaders\\ContAsClass\\Lamp.vs", "shaders\\ContAsClass\\Lamp.frag");
	}
	void LightSection::CreateCameras()
	{
		//this->camera1(glm::vec3(0.0f, 0.0f, 3.0f));
		camera1 = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
	}
	void LightSection::MyLoaderShader()
	{
		//	this->AddShaders("shaders\\NewManipSphareDraw.vs", "shaders\\NewManipSphareDraw.frag");
	}
	void LightSection::MyLoaderCamera()
	{
		this->AddCamera(glm::vec3(0.0f, 1.0f, 2.0f));
	}
	int LightSection::AddCamera(glm::vec3 position)
	{
		return 1;
	}
	void LightSection::CheckCration()
	{
		if (this->TexNo1 == false)
			std::cout << "WARN::TEXTURE NO 1 NOT COMPILED ";
		if (this->TexNo2 == false)
			std::cout << "WARN::TEXTURE NO 2 NOT COMPILED ";
		if (this->LightenCube == false)
			std::cout << "WARN::LIGHTEN CUBE NOT CREATED ";
		if (this->LampCube == false)
			std::cout << "WARN::LAMP CUBE NOT CREATED ";

	}
	void LightSection::InfinityLoop()
	{
		while (!glfwWindowShouldClose(this->window))
		{

			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement();
			glEnable(GL_DEPTH_TEST);
			// Clear the colorbuffer
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Use cooresponding shader when setting uniforms/drawing objects
			lightingShader.Use();
			GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
			GLint lightColorLoc = glGetUniformLocation(lightingShader.Program, "lightColor");
			glUniform3f(objectColorLoc, 0.5f, 0.5f, 0.21f);
			glUniform3f(lightColorLoc, 1.0f, 0.5f, 1.0f);

			// Create camera transformations
			glm::mat4 view;
			view = camera1.GetViewMatrix();
			glm::mat4 projection = glm::perspective(camera1.Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
			// Get the uniform locations
			GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
			GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
			GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
			GLuint LightPosLoc = glGetUniformLocation(lightingShader.Program, "lightPos");
			GLuint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
			// Pass the matrices to the shader
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform3f(LightPosLoc,lightPos.x,lightPos.y,lightPos.z);
			glm::vec3 RealyCmaDir;
			RealyCmaDir.x = camera1.Position.x - camera1.Front.x;
			RealyCmaDir.y = camera1.Position.y - camera1.Front.y;
			RealyCmaDir.z = camera1.Position.z - camera1.Front.z;
			glUniform3f(viewPosLoc, RealyCmaDir.x, RealyCmaDir.y, RealyCmaDir.z);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "Time"), glfwGetTime());
			// Draw the container (using container's vertex attributes)
			glBindVertexArray(containerVAO);
			glm::mat4 model;
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			///////////////////////////////////////////////////////////////////All Works Up this///////////////////////////
			// Also draw the lamp object, again binding the appropriate shader
			lampShader.Use();
			// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
			modelLoc = glGetUniformLocation(lampShader.Program, "model");
			viewLoc = glGetUniformLocation(lampShader.Program, "view");
			projLoc = glGetUniformLocation(lampShader.Program, "projection");
			// Set matrices
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
			model = glm::mat4();
			model = glm::translate(model, lightPos);
			model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			// Draw the light object (using light's vertex attributes)
			glBindVertexArray(lightVAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	}
	void LightSection::Do_Movement()
	{
		// Camera controls
		if (keys[GLFW_KEY_W])
			camera1.ProcessKeyboard(FORWARD, this->DeltaTime);
		if (keys[GLFW_KEY_S])
			camera1.ProcessKeyboard(BACKWARD, this->DeltaTime);
		if (keys[GLFW_KEY_A])
			camera1.ProcessKeyboard(LEFT, this->DeltaTime);
		if (keys[GLFW_KEY_D])
			camera1.ProcessKeyboard(RIGHT, this->DeltaTime);
		if (keys[GLFW_KEY_Z])
			camera1.ProcessKeyboard(UP, this->DeltaTime);
		if (keys[GLFW_KEY_X])
			camera1.ProcessKeyboard(DOWN, this->DeltaTime);
		if (keys[GLFW_KEY_M])//to show or hide cursor
			camera1.MouseStatuse(this->window);
		if (keys[GLFW_KEY_PAGE_UP])
			camera1.ProcessKeyboard(RATESPEEDUP, this->DeltaTime);
		if (keys[GLFW_KEY_PAGE_DOWN])
			camera1.ProcessKeyboard(RATESPEEDDOWN, this->DeltaTime);
		if (keys[GLFW_KEY_SPACE])
			camera1.ProcessKeyboard(RESET, this->DeltaTime);
		if (keys[GLFW_KEY_F])
			camera1.ProcessKeyboard(RESET, this->DeltaTime);
		//this->Cameras[CameraNumber].ProcessKeyboard(RESET, this->DeltaTime);
	}
	LightSection::~LightSection()
	{
		//this->SHADERS.clear();
		glDeleteVertexArrays(1,&this->containerVAO);
		glDeleteVertexArrays(1, &this->lightVAO);
		glDeleteBuffers(1, &this->containerVBO);
		glDeleteVertexArrays(1, &this->lightVBO);
	}
}
namespace ABTGLC
{
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);

		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
	void mouse_callback(GLFWwindow* window, double xpos, double ypos)
	{
		mousePosG.x = xpos;
		mousePosG.y = ypos;
		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		GLfloat xoffset = xpos - lastX;
		GLfloat yoffset = lastY - ypos;

		lastX = xpos;
		lastY = ypos;
		if (keys[GLFW_KEY_LEFT_CONTROL])
		{
			camera1.ProcessMouseMovement(xoffset, yoffset, true);
		}
		else if (!keys[GLFW_KEY_LEFT_CONTROL])

		{
			camera1.ProcessMouseMovement(xoffset, yoffset);
		}
	}

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		camera1.ProcessMouseScroll(yoffset);
	}

}