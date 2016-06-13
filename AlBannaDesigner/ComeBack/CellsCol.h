//#pragma once
#define Compilation 0
#if Compilation
#ifndef __MATERIAL__
#define __MATERIAL__
#include"1-LightA.h"
#include<States.h>
//#include<model.h>
#include<modelBoord.h>
static State::StatesPro Mystates("Commands.co");
static glm::vec3 cubePositions[] = {
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
class tup :public ABTGLC::LightSection
{
private:

public:
	Model *ourModel;
	Model*TestModel;
	Model*BCC;
	Shader SandBox;
	Shader OnColorshad;
	tup(GLint x, GLint y, char*t) :LightSection(x, y, t){};
	GLuint modelNum = 0;
	//We Will Ovride The Function pf loop and we need also to overide DoAll Function To use our InfinityLoop function instead of the base class function's
	void Introduction()
	{
		std::cout << "This Program Programmed By Osama Al Banna (Al Banna Techno )\nTo Simulating Unit Cells System\n";
		std::cout << "This Program Not Commercial (Free)\nAnd It's Source Code Not Avaliable For Public\n";
		std::cout << "Because This Program is a sub project from (Al Banna Designer) Project";
		std::cout << "\nThe programmer Do not bear any responsibility for any use of this program \n\n ";

		std::cout << "Press M To hide our show mouse\n";
		std::cout << "You can use a d w s To move Left Eigh Front Back \n";
		std::cout << "Use z x Top Bottom\n";
		std::cout << "You can go around the seen across using mouse \n";
		std::cout << "Zoom by MouseScroll\n Good Luck\n";
		std::cout << "Please Wiat : Loading......\n";
	}
	void ChoceModelNum()
	{
		std::cout << "Please choose a model whic you woudl like to show it from following models \n";
		std::cout << " 1 : BCC : Body-Centred Cubic\n";
		std::cout << " 2 : FCC : Face-Centred Cubic\n";
		std::cout << " 3 : HCP : Hexagonal Close Packed\n ";
		std::cin >> this->modelNum;
	}
	void CreateShaders()
	{

		this->lightingShader.CreatShader("\Loaders\\LCDirectionalLight.vs", "\Loaders\\LCDirectionalLight.frag");
		this->lampShader.CreatShader("Loaders\\Lamp.vs", "\Loaders\\Lamp.frag");
		//		this->SandBox.CreatShader("shaders\\ContAsClass\\Material.vs", "shaders\\ContAsClass\\SandBox2.frag");
	//	this->OnColorshad.CreatShader("shaders\\ContAsClass\\debthTesting.vs", "shaders\\ContAsClass\\shaderSingleColor.frag");

	}
	void CreatModeles()
	{
	//	ourModel = new Model("E:\\Programming\\OpenGl\\booksAndCourses\\VI The BEST BOOK TO LEARN Open gl\\AllFiles\\AllCodesTocheck\\21. Model\\nanosuit\\nanosuit.obj");
		BCC = new Model("Loaders\\models\\M#B%C^C&.3ds");
		//	TestModel = new Model("C:\\Users\\freecomp1\\Desktop\\te\\te.x");
	}
	void DoAll()
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		this->Introduction();
		//	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		//	Mystates.Commands(); //here used once
		//	this->SetAllCallBacks();
		this->SetVarValues();
		this->CreateLampCube();
		this->CreateLightenCube();
		this->CreateShaders();
		this->CreateTextures();
		this->CreatModeles();
		//	this->CreateCameras();
		//this->NumActiveCam = this->AddCamera(glm::vec3(0.0f,0.0f,-3.0f));
		
		this->ChoceModelNum();
		this->InfinityLoop();
	}
	void CreateLightenCube()
	{
		glGenVertexArrays(1, &containerVAO);
		glGenBuffers(1, &containerVBO);
		glBindBuffer(GL_ARRAY_BUFFER, containerVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(CubePosNormTex), CubePosNormTex, GL_DYNAMIC_DRAW);
		glBindVertexArray(containerVAO);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);
		glBindVertexArray(0);
		//this->LightenCube = true;

	}
	void CreateTextures()
	{

	}
	void InfinityLoop()
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	//	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		while (!glfwWindowShouldClose(this->window))
		{

			////////////here used every once
		//	Mystates.Commands();
			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement();
			glEnable(GL_DEPTH_TEST);
			//		glDepthFunc(GL_ALWAYS);

			// Clear the colorbuffer
	

			glClearColor(0.3, 0.3, 0.3, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			// Use cooresponding shader when setting uniforms/drawing objects
			lightingShader.Use();
			//		this->SandBox.Use();
			GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
			glUniform3f(objectColorLoc, 0.5f, 0.5f, 0.21f);

			// Create camera transformations
			glm::mat4 view;
			view = this->CamInh->GetViewMatrix();
			glm::mat4 projection = glm::perspective(this->CamInh->Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
			// Get the uniform locations


			GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
			GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
			GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");

			GLuint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");

			//Set Light Options
			GLint lightAmbientLoc = glGetUniformLocation(lightingShader.Program, "light.ambient");
			GLint lightDiffuseLoc = glGetUniformLocation(lightingShader.Program, "light.diffuse");
			GLint lightSpecularLoc = glGetUniformLocation(lightingShader.Program, "light.specular");
			GLint LightPosLoc = glGetUniformLocation(lightingShader.Program, "light.position");
			GLint LightSpotDirLoc = glGetUniformLocation(lightingShader.Program, "light.direction");
			GLint LightSpotCutOffLoc = glGetUniformLocation(lightingShader.Program, "light.cutOff");
			GLint LightSpotOutCutOffLoc = glGetUniformLocation(lightingShader.Program, "light.outerCutOff");


			glUniform3f(lightAmbientLoc, 0.5f, 0.5f, 0.5f);
			glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f); // Let’s darken the light abit to fit the scene
			glUniform3f(lightSpecularLoc, 0.4f, 0.7f, 0.9f);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.constant"), 1.0f);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.linear"), 0.09);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.quadratic"), 0.032);
			//this->lightPos = glm::vec3(-0.2f, -1.0f, -0.3f);
			glm::mat4 model1;
			model1 = glm::translate(model1, glm::vec3(0.0f, 0.0f, 0.0f)); // Translate it down a bit so it's at the center of the scene
			model1 = glm::scale(model1, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
			model1 = glm::rotate(model1,90.0f,glm::vec3(1.0f,0.0f,0.0f));
			glUniformMatrix4fv(glGetUniformLocation(this->lightingShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model1));


		//	ourModel->Draw(this->lightingShader, this->OnColorshad, false);
			if (this->modelNum == 1)
				BCC->Draw(this->lightingShader, this->OnColorshad, false);
			model1 = glm::rotate(model1, 270.0f, glm::vec3(1.0, 0.0, 0.0));
			model1 = glm::scale(model1, glm::vec3(0.09, 0.09, 0.09));
			glUniformMatrix4fv(glGetUniformLocation(this->lightingShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model1));
			//		TestModel->Draw(this->lightingShader);

			glUniform3f(LightPosLoc, this->CamInh->Position.x, this->CamInh->Position.y, this->CamInh->Position.z);
			glUniform3f(LightSpotDirLoc, this->CamInh->Front.x, this->CamInh->Front.y, this->CamInh->Front.z);
			glUniform1f(LightSpotCutOffLoc, glm::cos(glm::radians(12.5f)));
			glUniform1f(LightSpotOutCutOffLoc, glm::cos(glm::radians(17.5f)));
			// Pass the matrices to the shader
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
			glm::vec3 RealyCmaDir;
			RealyCmaDir.x = this->CamInh->Position.x - this->CamInh->Front.x;
			RealyCmaDir.y = this->CamInh->Position.y - this->CamInh->Front.y;
			RealyCmaDir.z = this->CamInh->Position.z - this->CamInh->Front.z;
			glUniform3f(viewPosLoc, RealyCmaDir.x, RealyCmaDir.y, RealyCmaDir.z);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "time"), glfwGetTime());
			// Draw the container (using container's vertex attributes)
			glBindVertexArray(containerVAO);
			glm::mat4 model;
			for (GLuint i = 0; i < 10; i++)
			{
				model = glm::mat4();
				model = glm::translate(model, cubePositions[i]);
				GLfloat angle = 20.0f * i;
				model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
				if (Mystates.cube == true)
					glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				//			glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			glBindVertexArray(0);

			glfwSwapBuffers(window);
		}
	}

};
#endif
#endif