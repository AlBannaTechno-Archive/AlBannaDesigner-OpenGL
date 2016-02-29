//#pragma once
#define Compilation 0
#if Compilation
#ifndef __MATERIAL__
#define __MATERIAL__
#include"1-LightA.h"
#include<States.h>
static State::StatesPro Mystates("Commands.co");
class tup :public ABTGLC::LightSection
{
private:
public:
	tup(GLint x, GLint y, char*t) :LightSection(x, y, t){};
	//We Will Ovride The Function pf loop and we need also to overide DoAll Function To use our InfinityLoop function instead of the base class function's
	void CreateShaders()
	{
		this->lightingShader.CreatShader("shaders\\ContAsClass\\Material.vs", "shaders\\ContAsClass\\Material.frag");
		this->lampShader.CreatShader("shaders\\ContAsClass\\Lamp.vs", "shaders\\ContAsClass\\Lamp.frag");
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
			GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
			GLint lightColorLoc = glGetUniformLocation(lightingShader.Program, "lightColor");
			glUniform3f(objectColorLoc, 0.5f, 0.5f, 0.21f);
			glUniform3f(lightColorLoc, 1.0f, 0.5f, 1.0f);

			// Create camera transformations
			glm::mat4 view;
			view = this->CamInh->GetViewMatrix();
			glm::mat4 projection = glm::perspective(this->CamInh->Zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
			// Get the uniform locations
			GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
			GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
			GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");
			GLuint LightPosLoc = glGetUniformLocation(lightingShader.Program, "light.position");
			GLuint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
			//Material
			GLint matAmbientLoc = glGetUniformLocation(lightingShader.Program, "material.ambient");
			GLint matDiffuseLoc = glGetUniformLocation(lightingShader.Program, "material.diffuse");
			GLint matSpecularLoc = glGetUniformLocation(lightingShader.Program, "material.specular");
			GLint matShineLoc = glGetUniformLocation(lightingShader.Program, "material.shininess");
			glUniform3f(matAmbientLoc, 0.4f, 0.6f, 0.31f);
			glUniform3f(matDiffuseLoc, 1.0f, 0.5f, 0.31f);
			glUniform3f(matSpecularLoc, 0.5f, 0.5f, 0.5f);
			glUniform1f(matShineLoc, 64.0f);
			//Set Light Options
			GLint lightAmbientLoc = glGetUniformLocation(lightingShader.Program, "light.ambient");
			GLint lightDiffuseLoc = glGetUniformLocation(lightingShader.Program, "light.diffuse");
			GLint lightSpecularLoc = glGetUniformLocation(lightingShader.Program, "light.specular");
			glUniform3f(lightAmbientLoc, 0.2f, 0.2f, 0.2f);
			glUniform3f(lightDiffuseLoc, 0.5f, 0.5f, 0.5f); // Let’s darken the light abit to fit the scene
			glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);


			// Pass the matrices to the shader
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform3f(LightPosLoc, lightPos.x, lightPos.y, lightPos.z);
			glm::vec3 RealyCmaDir;
			RealyCmaDir.x = this->CamInh->Position.x - this->CamInh->Front.x;
			RealyCmaDir.y = this->CamInh->Position.y - this->CamInh->Front.y;
			RealyCmaDir.z = this->CamInh->Position.z - this->CamInh->Front.z;
			glUniform3f(viewPosLoc, RealyCmaDir.x, RealyCmaDir.y, RealyCmaDir.z);
			glUniform1f(glGetUniformLocation(lightingShader.Program, "Time"), glfwGetTime());
			// Draw the container (using container's vertex attributes)
			glBindVertexArray(containerVAO);
			glm::mat4 model;
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			if (Mystates.cube==true)
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
			if (Mystates.lightsource==true)
				glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	}

};
#endif
#endif