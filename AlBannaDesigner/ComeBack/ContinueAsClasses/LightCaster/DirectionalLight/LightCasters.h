//#pragma once
#define Compilation 0
#if Compilation
#ifndef __MATERIAL__
#define __MATERIAL__
#include<../AlBannaDesigner/ComeBack/ContinueAsClasses/1-LightA/1-LightA.h>
#include<../AlBannaDesigner/Header Files/States.h>
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
	Shader SandBox;
	tup(GLint x, GLint y, char*t) :LightSection(x, y, t){};
	//We Will Ovride The Function pf loop and we need also to overide DoAll Function To use our InfinityLoop function instead of the base class function's
	void CreateShaders()
	{
		
		this->lightingShader.CreatShader("shaders\\ContAsClass\\LCDirectionalLight.vs", "shaders\\ContAsClass\\LCDirectionalLight.frag");
		this->lampShader.CreatShader("shaders\\ContAsClass\\Lamp.vs", "shaders\\ContAsClass\\Lamp.frag");
		//		this->SandBox.CreatShader("shaders\\ContAsClass\\Material.vs", "shaders\\ContAsClass\\SandBox2.frag");
	}
	void DoAll()
	{
		//	Mystates.Commands(); //here used once
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
		unsigned char*image = SOIL_load_image("resources\\textures\\container2.png", &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);//first RGB for texture and second for source image
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glBindTexture(GL_TEXTURE_2D, 0);

		//TextureForBorder

		glGenTextures(1, &this->Texture2);
		glBindTexture(GL_TEXTURE_2D, this->Texture2);//all upcoming gl_texture_2d operation now have effect on this texture object
		//set the texture warping parametres
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, MyBorderColor);
		///set the texture filtering parametres
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//Load image ,creat texture and generate mipmaps
		unsigned char*image2 = SOIL_load_image("resources\\textures\\container2_specular.png", &width, &height, 0, SOIL_LOAD_RGB);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);//first RGB for texture and second for source image
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image2);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void InfinityLoop()
	{

		while (!glfwWindowShouldClose(this->window))
		{

			////////////here used every once
			Mystates.Commands();
			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement();
			glEnable(GL_DEPTH_TEST);
			// Clear the colorbuffer
			GLfloat red = 0.0f, green = 0.0f, blue = 0.0f;
			if (Mystates.red == true)
				red = 1.0f;
			if (Mystates.blue == true)
				blue = 1.0f;
			if (Mystates.green == true)
				green = 1.0f;

			glClearColor(red, green, blue, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Use cooresponding shader when setting uniforms/drawing objects
			lightingShader.Use();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, this->Texture1);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, this->Texture2);

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
			//Material
			GLint matDiffuseLoc = glGetUniformLocation(lightingShader.Program, "material.diffuse");
			GLint matSpecularLoc = glGetUniformLocation(lightingShader.Program, "material.specular");
			GLint matShineLoc = glGetUniformLocation(lightingShader.Program, "material.shininess");
			glUniform1i(matDiffuseLoc, 0);//ãä Çáãåã ÌÏÇ ÊÐßÑ ØÑíÞÉ ÊãÑíÑ ÇáÅßÓÇÁ Ýí ÇáÎÇãÇÊ
			// æáÇ ääÓì Çä ÇáÇßÓÇÁ åæ ãä ÇáäæÚ sampler2D æíãÑÑ ÈÇáØÑíÞÉ ÇáÊí ÇÓÊÎÏãäÇåÇ
			//ÍíË Çä ÇáäæÚ åæ ÕÍíÍ gl uniform int gluniformi
			//ßãÇ Çä ÇáÑÞã ÇáãæÌæÏ Ýí ÇáãÏÎá ÇáËÇäí åæ ÑÞã ÇáÅßÓÇÁ ÇáãØáæÈ ÊãÑíÑå
			glUniform1i(matSpecularLoc, 1);
			glUniform1f(matShineLoc, 64.0f);
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
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.constant"),1.0f);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.linear"),0.09);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "light.quadratic"), 0.032);
			//this->lightPos = glm::vec3(-0.2f, -1.0f, -0.3f);
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
				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
			
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
			if (Mystates.lightsource == true)
				glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	}

};
#endif
#endif