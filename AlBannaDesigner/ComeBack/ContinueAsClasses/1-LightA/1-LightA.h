#ifndef __BASIC_CLASS__
#define __BASIC_CLASS__
//#include"GeneralIncluders.h"

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
#include<../AlBannaDesigner/Header Files/shader.h>
//#include "Shader.h"
#include<../AlBannaDesigner/Header Files/camera.h>
//#include"camera.h"
//#include<GraphicalCalculator.h>
#include<thread>
#include<string>
/////////////////////////////////
/*
Â‰«ﬂ «„— ·« «›Â„Â ÊÂÊ «‰Â ⁄‰œ «÷«›… «Ì „ €Ì— Â‰«
Ê„‰ À„ «” Œœ«„Â ›Ì „ﬂ«‰ ¡«Œ— ›Ì „·› ¡«Œ— ⁄‰ ÿ—Ìﬁ «· ÷„Ì‰ include
›«‰Â ÌÕœÀ Œÿ« Ì›Ìœ »«‰ Â–« €Ì— „”„ÊÕ Ê«‰ Â–«  ﬂ—«— ›Ì «· ⁄—Ì›
Ê·Â–« ›√ﬁ —Õ Ê÷⁄ «·„ €Ì—«  ›Ì ﬂ·«”
·«‰ „Ã«· «·√”„«¡ ›Ì Â–Â «·ﬁ÷Ì… ﬂ⁄œ„…
«Ê ‰” Œœ„ static
ÊÂÊ «·’ÕÌÕ ⁄‰œ «” Œœ«„ „ €Ì—«  »Ì‰ «·ÂÌœ— ›«Ì·“
*/
#include<../AlBannaDesigner/Header Files/Boint'sContainers.h>
// We can also load with, "" we are at the same folder
// but with <> we are in the main folder of solution
//#include"../../../Header Files/Boint'sContainers.h"
//#include"Boint'sContainers.h"
using namespace POCONTS;
namespace ABTGLC
{

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

	class BGLC
	{
	private:
		glm::vec2 mousePos;
	protected:
		GLint WIDTH, HEIGHT;
		char*Title;
		GLFWwindow* window;
		GLfloat DeltaTime;	// Time between current frame and last frame
		GLfloat LastFrame;  	// Time of last frame
		//	bool keys[1024];
		//	GLfloat lastX, lastY;
		//	bool firstMouse;
		bool InitAtConstructor = false;
	public://Variables
		//	std::vector<Shader>SHADERS;
		Camera *CamInh=new Camera();//this Camera Created To use By inherited Classes Because We can't Use camera1 there so it's not in class
		//std::vector<Camera>Cameras;
		

	public:
		GLuint NumActiveCam;
		BGLC(GLint width, GLint height, char*title);
		void InializeStand(GLint width, GLint height, char*title);
		void INITCallBackFunctions();
		int AddShaders(char*VsPath, char*FragsPath);
		glm::vec2 ReturnMousPos();
	};
	class LightSection :public BGLC
	{
	private:
		bool LightenCube = false;
		bool LampCube = false;
		bool TexNo1 = false;
		bool TexNo2 = false;
		void CheckCration();

		void SetAllCallBacks();
	protected:
		//std::vector<GLuint>VAO;
		//std::vector<GLuint>VBO;
		//std::vector<GLuint>EBO;
		GLuint containerVAO, containerVBO;
		GLuint lightVAO, lightVBO;
		//GLuint VAOcube, VBOcube;
		//POCONTS::CUBE MyCubs;
		//std::vector<GLuint>Textures;
		GLuint Texture1, Texture2;
		void Do_Movement();
		void CreateLightenCube();
		void CreateLampCube();
		void CreateTextures();
		void CreateShaders();
		void CreateCameras();
	protected:
		//Debreicated Functions
		void SetVarValues();
		void MyLoaderShader();
		void MyLoaderCamera();
		GLuint loadTexture(GLchar* path);
		int AddCamera(glm::vec3 position);
	public:
		Shader lightingShader;
		Shader lampShader;
		glm::vec3 lightPos;
	public:
		LightSection();
		LightSection(GLint width, GLint height, char*title);
		void DoAll();
		void InfinityLoop();
		~LightSection();
	};
}

#endif