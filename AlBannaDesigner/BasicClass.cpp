#if 0
#include"BasicClass.h"

bool keys[1024];
GLfloat lastX, lastY;
bool firstMouse;
Camera camera1 = Camera(glm::vec3(0.0f, 0.0f, 3.0f));

namespace ABTGLC
{
	BGLC::BGLC(GLint width, GLint height, char*title)
	{
		this->InializeStand(width, height, title);
		InitAtConstructor = true;//If We Declare this function before last line the programme wil crroupt
	}
	//”‰ﬁÊ„ »⁄„· œ«·… «Œ—Ï „À· «·ﬂÊ‰” —«ﬂ Ê—
	void BGLC::InializeStand(GLint width, GLint height, char*title)
	{
		if (InitAtConstructor == true)
		{
			std::cout<<"You Inialaized Data At Consructor ?\n";
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
	void BGLC::INITCallBackFunctions()
	{
		// Set the required callback functions
	//	glfwSetKeyCallback(window, key_callback);
	//	glfwSetCursorPosCallback(window, mouse_callback);
	//	glfwSetScrollCallback(window, scroll_callback);

	}
	int BGLC::AddShaders(char*VsPath, char*FragsPath)
	{
		//Paused Now
	//	this->SHADERS.push_back(Shader(VsPath, FragsPath));
	//	return this->SHADERS.size()-1;
		return 1;
	}
}
namespace ABTGLC
{
	LightSection::LightSection(GLint width, GLint height, char*title) :BGLC(width, height, title){};

	void LightSection::DoAll()
	{
	//	this->SetAllCallBacks();
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
		glfwSetScrollCallback(window,scroll_callback);

	}
	void LightSection::CreateLightenCube()
	{
		glGenVertexArrays(1, &this->VAO2);
		glGenBuffers(1, &this->VBO2);
		glBindVertexArray(this->VAO2);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO2);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(this->MyCubs.MyCube), this->MyCubs.MyCube, GL_DYNAMIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, sizeof(MyCube),MyCube, GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		// TexCoord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		glBindVertexArray(0);//release
		this->LightenCube = true;

	}
	void LightSection::CreateLampCube()
	{
		glGenVertexArrays(1, &this->VAO1);
		glGenBuffers(1, &this->VBO1);
		glBindVertexArray(this->VAO1);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO1);
	//	glBufferData(GL_ARRAY_BUFFER, sizeof(this->MyCubs.NonTexCube), this->MyCubs.NonTexCube, GL_DYNAMIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, sizeof(NonTexCube), NonTexCube, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);//release
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
		this->shader1.CreatShader("shaders\\NewManipSphareDraw.vs", "shaders\\NewManipSphareDraw.frag");
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
	//	Cameras.push_back(Camera(position, up, yaw, pitch));
	//	Cameras.push_back(Camera(position));
	//	return Cameras.size();
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
			glfwPollEvents();
			this->Do_Movement();
			this->CheckCration();
			glClearColor(0.4f, 0.6f, 0.7f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			////////Put Shader Here
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, this->Texture1);
			glUniform1i(glGetUniformLocation(this->shader1.Program, "shaderUseAnyname"), 0);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, Texture2);
			glUniform1i(glGetUniformLocation(this->shader1.Program, "secondshader"), 1);
			this->shader1.Use();
			////Matricies
			glm::mat4 projection = glm::perspective(camera1.Zoom, (float)this->WIDTH / (float)this->HEIGHT, 0.1f, 100.0f);
			glm::mat4 view = camera1.GetViewMatrix();

			GLuint ViewLocation = glGetUniformLocation(this->shader1.Program, "view");
			glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, glm::value_ptr(view));

			GLuint ProjectionLocation = glGetUniformLocation(this->shader1.Program, "projection");
			glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

			GLuint ModelLocation = glGetUniformLocation(this->shader1.Program, "model");

			glm::vec3 Transnew;// = GRATOR::SphricalPosition_Y_Z(4.0f, glm::vec3(0.0f, 0.0f, 0.0f), (GLfloat)(7.0f * glfwGetTime()), (GLfloat)(9 * glfwGetTime()));
			//	std::cout << "(" << Transnew.x << " , " << Transnew.y << " , " << Transnew.z << " )" << std::endl;
			glm::mat4 model;
			model = glm::translate(model, Transnew);
			GLfloat Cangle = 17.0f;
			model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));
			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
			glBindVertexArray(this->VAO2);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			///„‰ Â‰« ÌÊÃœ „‘ﬂ·… ›Ì ⁄—÷ Â–« «·„ﬂ⁄» 
			glm::vec3 intTrans(2.0f, 0.0f, 0.0f);
			glm::mat4 inmod = glm::translate(inmod, intTrans);
			//	inmod = glm::rotate(inmod, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));
			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(inmod));
			glBindVertexArray(this->VAO1);
			glDrawArrays(GL_TRIANGLES, 0, 36);

			for (int counter = 1; counter <= 20; counter++)
			{
				glm::vec3 Transnew; //= GRATOR::SphricalPosition_Y_Z(4.0f, glm::vec3(0.0f, 0.0f, 0.0f), (GLfloat)(7.0f * glfwGetTime())*counter, (GLfloat)(9 * glfwGetTime())*counter);
				//	std::cout << "(" << Transnew.x << " , " << Transnew.y << " , " << Transnew.z << " )" << std::endl;
				glm::mat4 model;
				model = glm::translate(model, Transnew);
				GLfloat Cangle = 17.0f;
				model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

				glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
				glBindVertexArray(this->VAO2);
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			for (int counter = 1; counter <= 20; counter++)
			{
				glm::vec3 Transnew;// = GRATOR::SphricalPosition_Y_Z(6.0f, glm::vec3(0.0f, 0.0f, 0.0f), -(GLfloat)(6.9f * glfwGetTime())*counter, -(GLfloat)(15 * glfwGetTime())*counter);
				glm::mat4 model;
				model = glm::translate(model, Transnew);
				GLfloat Cangle = 17.0f;
				model = glm::rotate(model, Cangle*(GLfloat)glfwGetTime(), glm::vec3(1.0f, 0.6f, 0.0f));

				glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, glm::value_ptr(model));
				glBindVertexArray(this->VAO2);
				glDrawArrays(GL_TRIANGLES, 0, 36);

			}
			glBindVertexArray(0);
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
		//this->Cameras[CameraNumber].ProcessKeyboard(RESET, this->DeltaTime);
	}

	LightSection::~LightSection()
	{
		//this->SHADERS.clear();
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
#endif