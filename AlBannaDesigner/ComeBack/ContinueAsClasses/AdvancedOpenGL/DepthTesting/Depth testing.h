//#pragma once
#define Compilation 1
#if Compilation
#ifndef __MATERIAL__
#define __MATERIAL__
#include<../AlBannaDesigner/ComeBack/ContinueAsClasses/1-LightA/1-LightA.h>
#include<../AlBannaDesigner/Header Files/States.h>
#include<../AlBannaDesigner/Header Files/modelBoord.h>
static State::StatesPro Mystates("Commands.co");

class tup :public ABTGLC::LightSection
{
private:

public:
	Shader OnColorshad;
	Shader AdvancedShader;
	GLuint cubeVAO, cubeVBO;
	GLuint planeVAO, planeVBO;
	Shader SandBox;
	GLuint cubeTexture;
	GLuint floorTexture;
	Model *ourModel;

	tup(GLint x, GLint y, char*t) :LightSection(x, y, t){};
	//We Will Ovride The Function pf loop and we need also to overide DoAll Function To use our InfinityLoop function instead of the base class function's
	void CreateShaders()
	{
		this->AdvancedShader.CreatShader("shaders\\ContAsClass\\debthTesting.vs","shaders\\ContAsClass\\debthTesting.frag");
		this->OnColorshad.CreatShader("shaders\\ContAsClass\\debthTesting.vs", "shaders\\ContAsClass\\shaderSingleColor.frag");
	//shaderSingleColor
		//	this->lightingShader.CreatShader("shaders\\ContAsClass\\LCDirectionalLight.vs", "shaders\\ContAsClass\\LCDirectionalLight.frag");
	//	this->lampShader.CreatShader("shaders\\ContAsClass\\Lamp.vs", "shaders\\ContAsClass\\Lamp.frag");
		//		this->SandBox.CreatShader("shaders\\ContAsClass\\Material.vs", "shaders\\ContAsClass\\SandBox2.frag");
	
	ourModel = new Model("E:\\Programming\\OpenGl\\booksAndCourses\\VI The BEST BOOK TO LEARN Open gl\\AllFiles\\AllCodesTocheck\\21. Model\\nanosuit\\nanosuit.obj");

	}
	
	void SetUpBegOptions()
	{
	//	glDepthMask(GL_FALSE);
		///////////////////////////////////////
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glEnable(GL_STENCIL_TEST);
		glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	}
	void DoAll()
	{
		//	Mystates.Commands(); //here used once
		//	this->SetAllCallBacks();
		this->SetUpBegOptions();
		this->SetVarValues();
		this->CreateShaders();
		this->CreateTextures();
		this->InfinityLoopForAdvancedLighting();
	}
	void CreateLightenCube(){};
	void CreatShapes()
	{

	}
	void CreateTextures()
	{
		// Setup cube VAO	
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);
		glBindVertexArray(cubeVAO);
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);
		// Setup plane VAO
		glGenVertexArrays(1, &planeVAO);
		glGenBuffers(1, &planeVBO);
		glBindVertexArray(planeVAO);
		glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glBindVertexArray(0);
		//////////////////////////////////////////////////
		//LoadTextures
		this->cubeTexture = this->loadTexture("resources\\textures\\marble.jpg");
		this->floorTexture = this->loadTexture("resources\\textures\\metal.png");

	}
	void InfinityLoopForAdvancedLighting()
	{
		//InfinityLoop
		while (!glfwWindowShouldClose(this->window))
		{
			////////////here used every once
			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			
			Do_Movement();
			
	//		glEnable(GL_DEPTH_TEST);
	//		glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);			// Clear the colorbuffer
			
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			// Set uniforms
			
			this->OnColorshad.Use();
			glm::mat4 model;
			glm::mat4 view = this->CamInh->GetViewMatrix();
			glm::mat4 projection = glm::perspective(this->CamInh->Zoom, (float)this->WIDTH / (float)this->HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(this->OnColorshad.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(this->OnColorshad.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			this->AdvancedShader.Use();
		
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

			glEnable(GL_STENCIL_TEST);
			// Draw floor as normal, we only care about the containers. The floor should NOT fill the stencil buffer so we set its mask to 0x00
			glStencilMask(0x00);
			// Floor
			glBindVertexArray(planeVAO);
			glBindTexture(GL_TEXTURE_2D, floorTexture);
			model = glm::mat4();
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
			//this->ourModel->Draw(this->lightingShader);
			// == =============
			// 1st. Render pass, draw objects as normal, filling the stencil buffer
			glStencilFunc(GL_ALWAYS, 1, 0xFF);
			glStencilMask(0xFF);
			// Cubes
			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, cubeTexture);
			model = glm::translate(model, glm::vec3(-1.0f, 0.01f, -1.0f));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.01f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
		//	this->ourModel->Draw(this->lightingShader);
			// == =============
			// 2nd. Render pass, now draw slightly scaled versions of the objects, this time disabling stencil writing.
			// Because stencil buffer is now filled with several 1s. The parts of the buffer that are 1 are now not drawn, thus only drawing 
			// the objects' size differences, making it look like borders.
			glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
			glStencilMask(0x00);
	//		glDisable(GL_DEPTH_TEST);//Comment Here To Draw inline 
			// ÈÅÎÝÇÁ ÇáÓØÑ ÇáÓÇÈÞ äÍä äãäÚ ÇáÅØÇÑ ÇáÎÇÑÌí Çæ ÇáÊÍÏíÏ ÇáÎÇÕ ÈÇáÕäÏæÞ ãä ÊÌÇæÒ ÇáÇÑÖíÉ 
			//ÍíË áæ ÝÚáäÇå ÝÓäáÇÍÙ Çäå íÙåÑ ÍÊì æÅä äÙÑäÇ ãä ÇÓÝá Èá æíÙåÑ ßÇãáÇ æåÐÇ ÎØíÑ ÌÏÇÇ
			// ØÈÚÇ ÓäáÇÍÙ ÇáÇä Çäå íÙåÑ ãä ÇÓÝá Çí ÚäÏ ÇáäÒæá ÇÓÝá ÇáÇÑÖíÉ æÇáäÙÑ áÇÚáì 
			//ÓäáÇÍÙ Çäå íÙåÑ ßÓØÍ ãÑÈÚ ÝÞØ æåæ ÇáØÈíÚí æáÅÎÝÇÁ åÐÇ äÞæã ÈÊÛííÑ Þíã 
			// y -> 0.09f  Çæ ÇßÈÑ ãä Ðáß ÈÍíË äãäÚå ãä ÇáÅáÊÕÇÞ ÈÇáÇÑÖ æáÇ äÓÓì Çä ÍÌã åÐÇ ÇáÇØÇÑ ÃßÈÑ ãä ÍÌã ÇáÕäÏæÞ ÇáÃÓÇÓí
			this->OnColorshad.Use();
			GLfloat scale = 1.03;
			// Cubes
			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, cubeTexture);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(-1.0f, 0.03f, -1.0f));
			model = glm::scale(model, glm::vec3(scale, scale, scale));
			glUniformMatrix4fv(glGetUniformLocation(this->OnColorshad.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.03f, 0.0f));
			model = glm::scale(model, glm::vec3(scale, scale, scale));
			glUniformMatrix4fv(glGetUniformLocation(this->OnColorshad.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
		//	this->ourModel->Draw(this->OnColorshad);
			glStencilMask(0xFF);
			glEnable(GL_DEPTH_TEST);
			// Swap the buffers
			glfwSwapBuffers(window);
		}

	}
	void InfinityLoop()
	{

		while (!glfwWindowShouldClose(this->window))
		{

			////////////here used every once
			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement();

			// Clear the colorbuffer
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			// Use cooresponding shader when setting uniforms/drawing objects
			///////////////////////////////////
			glm::vec3 RealyCmaDir;
			RealyCmaDir.x = this->CamInh->Position.x - this->CamInh->Front.x;
			RealyCmaDir.y = this->CamInh->Position.y - this->CamInh->Front.y;
			RealyCmaDir.z = this->CamInh->Position.z - this->CamInh->Front.z;

			AdvancedShader.Use();
			glm::mat4 model;
			glm::mat4 view = this->CamInh->GetViewMatrix();
			glm::mat4 projection = glm::perspective(this->CamInh->Zoom, (float)this->WIDTH / (float)this->HEIGHT, 0.1f, 100.0f);
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			// Cubes
			glBindVertexArray(cubeVAO);
			glBindTexture(GL_TEXTURE_2D, cubeTexture);  // We omit the glActiveTexture part since TEXTURE0 is already the default active texture unit. (sampler used in fragment is set to 0 as well as default)		
			model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			model = glm::mat4();
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
			// Floor
			glBindVertexArray(planeVAO);
			glBindTexture(GL_TEXTURE_2D, floorTexture);
			model = glm::mat4();
			glUniformMatrix4fv(glGetUniformLocation(this->AdvancedShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
			glfwSwapBuffers(this->window);

		}

	}
};
#endif
#endif