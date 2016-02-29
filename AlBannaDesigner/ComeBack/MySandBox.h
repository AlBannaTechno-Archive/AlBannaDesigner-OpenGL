//#pragma once
#define Compilation 0
#if Compilation
#ifndef __MATERIAL__
#define __MATERIAL__
#include"1-LightA.h"
#include<States.h>

/*
בבÊהָםו ÝדÚÙד ַבֿזַב זַבָםַהַÊ ַבדזּזֹֿ Ýם ו׀ַ ַבדבÝ Ûםׁ וַדֹ בÚדב 
ָׁהַדּ ױהֿזÞ ַבׁדַב 
זבַßה ַבדוד ÝÞ 
וז ַבֳּׂ ַב־ַױ ַָבװַֿׁ 
זַבֳּׂ ַב־ַױ ֵָהװֱַ ַבֳׁßַה ַב־ַױֹ ַָבדÚַבֹּ 
CreateWidget Function
DoAll Function 
InfinityLoop Function  
זַבדÊÛםַׁÊ ַב־ַױֹ ָודַ 
ׂםַֹֿ Úבל ׀ַבß הֽÊַּ ַבל Úהַױׁ ַבֳׁßַה זום 

static GLfloat Widget[]
static GLint WidInds[] =

זדַ ֿזה ׀ַבß Ýוז Êַָּׁ Þָב ַבהַּֽ ָÊ״ָםÞ ַבÚדבםֹ 
Úבדַ ַההַ בד הּֽ Ýם Ê״ָםÞוַ ַם Úדבםֹ ױהֿזÞ ַבׁדַב 
Úבל ַבה׃־ ַבֽֿםֹֻ דה ַבװַֿׁ ז׀ַבß בזּזֿ ֵװßַבםֹ Úהֿם Ýם ַבÊה׃םÞ 
ָםה דֿ־בַÊם ַבÚַֿםֹ 
זַב gl_FragCoord
ז gl_FragColor
זבַדהם ַÚבד ַה 
gl_FragColor =color ַם Ê׃ַזם ַבבזה ַבÚַֿם ַבב׀ם ה׃Ê־ֿדו Ýם ַבה׃־ ַבֽֿםֹֻ 
ֳדַ 
gl_FragCoord 
Ýוז םÚָׁ Úה ַב׃״ֽ ַז ַבָß׃ב ֵה ַּׂ Ê׃דםÊו ß׀ַבß 
ַבב׀ם םÊד Êבזםהו ַבַה 
בַההַ הÚבד ַה ַבÝַּׁדםהÊ װַֿׁ םÊד Êßַׁׁ ָÚֿֿ ָß׃בַÊ ַבװַװֹ 
ֳם ַה ßב ָß׃ב בו הֱַֿ ־ַױ Ýֵ׀ַ ָׁ״הַ דֻבַ בזה ַבָß׃ ָדזÞÚו
זוז gl_FragCoord 
}
ַבַה הֽÊַּ בהזײםֽ ַדׁ ֱַ־ׁ 
זוז ַההַ ßהַ הׁםֿ ּÚב ַבָׁהַדּ םÚדב דַָװֹׁ Ýם ַבזÞÊ ַב׀ם םÊד Ýםו ÊÛםםׁ ַבװַֿׁ ַם ַהו ßבדַ Êד ÊÛםםׁ
װםֶ Ýם דבÝ ַבװַֿׁ םÊÛםׁ ַבָׁהַדּ ַם ַזה בַםה
זÞֿ ÞדÊ ָÚֹֿ דַֽזבַÊ בÝÚב ׀ַבß Úה ״ׁםÞ ַבÊÚֿםב Ýם ßבַ׃ ַבװַֿׁ 
םדßהß ַבּׁזÚ ַבםו ֵ׀ַ ֳֿׁÊ ִׁםֹ ַבÚֿםבַÊ ֳז ַבֵײַÝַÊ ַָבֳֽׁל זÊֳָֿ ָ Re
ReUse For Example
זבַßה ו׀ַ בד םÝבֽ בַהַ Ýם ַבזַÞÚ הֽÊַּ בֵÚַֹֿ ּדםÚ ַב־״זַÊ ָדַ Ýם ׀ַבß ßב דַ Êד Úדבו
Ýם ַבַֿבֹ DoAll
זַָבÊַבם הֽה הֽהַּ בהֱַֿ ו׀ו ַבַֿבֹ דֹׁ ֳ־ׁל 
זו׀ַ םÚהם ַההַ ׃הײÚ בזָ בַהוֶַם םÊזÞÝ Úבל װׁ״ ַÛבַÞ ַבהַÝ׀ֹ 
ַֿ־ב בזָ דֻבו 
ַבל ַם Úֿֿ הׁםֿ דה ַבדַׁÊ Úבל ֽ׃ָ ַבÊÚֿםב 
זו׀ו בם׃Ê דװßבֹ בַהו םßÝם ַÛבַÞ ַבהַÝ׀ֹ דֹׁ זַֹֽֿ בםםױב ÊÛםםׁ ַבַÛבַÞ בּדםÚ ַבבזַָÊ
ַז ַבÝַÊ
ַבדוד הֽÊַּ ב״ׁםÞֹ בדÚׁÝֹ וב Êד ÊÛםםׁ ַבװַֿׁ ַד בַ 
ָָ׃ַ״ ה׃Ê־ֿד ַבßבַ׃ ַבב׀ם Þדהַ ֵָהװֶַו דה ד׀ֹֿ 
זוז ַבßבַ׃ StringLoader
ו׀ַ ַבßבַ׃ ׃ם׃דֽ בהַ ָÊֽדםב ּדםÚ ָםַהַÊ ַבװַֿׁ Úה ״ׁםÞ ַבד׃ַׁ ַבב׀ם הÚ״םו ַםַו ַֿ־ב 
ַ׃Êׁהּ ַם ַֿ־ב ׃ב׃בֹ הױםֹ 
זדה ֻד ההװֶ ßֶַה ֶַ־ׁ דה הÝ׃ הזÚ ַבßבַ׃ -ָÝׁײ ַההַ ַהװֶהַ ַבßֶַה ַבַזב---
ו׀ַ ַבßֶַה ַבַֻהם ׃םÞזד ָהÝ׃ זÙםÝֹ ַבßֶַה ַבַזבל 
זבַßה Ýם ֱַ־ׁ ׃״ׁ דה ַבÊßַׁ 
Ýם ֽםה ַה ַבֳזב םÊד Ýם ֳזב ׃״ׁ דה ַבÊßַׁׁ 
זָדÞַׁהֹ ּֽדודַ ׃םÊײֽ בהַ וב ֻֽֿ ÊÛםםׁ ַד בַ 
הֽה ַָב״ָÚ הÞַׁה ַבּֽד ַבÚֿֿם 
ַם Úֿֿ ַבÚהַױׁ בַה דÞַׁהֹ ּדםÚ ַבÚהַױׁ ַדׁ דßבÝ בב׀ַßֹׁ 
ב׀ַבß םßÝם ַה הÞזד ָÊÚֿםב זבז ֽׁÝ Ýם דבÝ ַבװַֿׁ ֻד הֽÝÙו 
ÝםÊÛםׁ ַבָׁהַדּ זÝÞַ בו בÊֽÞÞ ַבװׁ״ זדה ֻד הÞזד ַָבÊÛםםׁ ßדַ הװֱַ
ÝÚבהַ ו׀ַ בÊּהָ Úֿד ֽֿזֻ ÊÛםםׁ Úהֿ Ê׃ַזם Úֿֿ ַבֽׁזÝ 
ַם בז ֽ׀Ýהַ ־ד׃ֹ זַײÝהַ ־ד׃ֹ ַֽׁÝ 


״ָÚַ ַָבַדßַה ַבÊ־בם ַ׃ַ׃ַ Úה Ýßֹׁ ַבָֻֽ וב והַß ÊÛםׁ ַד בַ 
זַבÝׁײ ֶַֿדַ ַה והַß ÊÛםםׁ זבַßה ו׀ַ ־״םׁ  הזÚַ דַ 
בֳה ו׀ַ ׃םßׁׁ ַבָׁהַדּ דה ַָֿםÊו ַבל ÊוַםÊו ֳßֻׁ דה דֹׁ Ýם ַבַֻהםֹ זו׀ַ 
דובß בב׀ַßֹׁ 
זבַßה ֳׁל ַה ַבֳÝײב ַה הÞַׁה בהÞׁׁ
ׁÛד ַהו ֵ׀ַ ßַה דבÝ ַבװַֿׁ ßָםׁ ַַַַַַּֿ
דֻבַ 1000 ׃״ׁ Ýֵהו דה ַבֳÝײב הÙׁםַ Úֿד Úדב ַבדַֻׁהֹ בַהוַ ׃Êײׁהַ בÊֽדםבוד ּדםÚ 
זבַßה Úבל ßב ַֽב Ýו׀ַ Ûםׁ ױֽםֽ Úדבםַ 

בַהו Ýם ßב ַבֳֽזַב ׃םÊד Êֽדםב ו׀ו ַבדבÝַÊ Ýם ַבװַֿׁ ַ׃ַ׃ַ
Þָב ßב װםֶ


״ָÚַ ֵ׀ַ ֻֽֿ ֳם ־״ֳ ַֻהֱַ Úדבםֹ Êּׁדֹ ַבֳßזַֿ ַב־ַױֹ ַָבװַֿׁ 

ֳֻהֱַ ַבÊßַׁׁ Ý׃הÚׁÝוַ דה ַָֻÊ ַבװַװֹ ָֿזה ÊÛםׁ זÙוזׁ ׁ׃ַבֹ ־״ַ Ýם װַװֹ 
ַבßזדַהֿ ַב׃זֱַֿ 
Êזײֽ הזÚ ַב־״ֳ זדßַהו
*/
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
static GLfloat vert[] = {
	0.5f, 0.7f, 0.0f,  // Top Right
	0.8f, -0.8f, 0.0f,  // Bottom Right
	-0.4f, -0.6f, 0.0f,  // Bottom Left
	-0.3f, 0.4f, 0.0f   // Top Left 

};
static GLfloat Widget[] = {
	-1.0f, 1.0f, 0.0f,
	1.0f,1.0f,0.0f,
	-1.0f,-1.0f,0.0f,
	1.0f,-1.0f,0.0f,

	/*
	[ [-1,1], [1,1], [-1,-1], [1,-1] ]
	*/
};
static GLint WidInds[] = {
	0,1,2,3,
};
struct Points
{
	GLfloat x, y, z;
};
class tup :public ABTGLC::LightSection
{
private:
	bool UsedOnce = false;
public:
	StringLoader GetFragShadPath;

	StringLoader First;
	StringLoader ReCount;
	Shader *SandBoxShader;
	GLuint WG_VAO, WG_VBO, WG_EBO;
	GLuint ScreenVAO;
	GLuint ScreenVBO,ScreenEBO;
	GLuint TestVAO, TestVBO;
	std::vector<GLfloat>ScreenVerteices;
	std::vector<GLint>ScreenIndecies;
	std::vector<Points>ScreenPoints;
	Shader SandBox;
	tup(GLint x, GLint y, char*t) :LightSection(x, y, t){};
	//We Will Ovride The Function pf loop and we need also to overide DoAll Function To use our InfinityLoop function instead of the base class function's
	void CreateShaders()
	{
		if (this->UsedOnce==false)
			this->GetFragShadPath.Load("FSP.osa");
		else
			this->GetFragShadPath.ReLoad("FSP.osa");
		//"shaders\\ContAsClass\\MySandBox.vs", "shaders\\ContAsClass\\MySandBox.frag"
		this->SandBoxShader = new Shader("VS.vs",this->GetFragShadPath.StData.c_str());
		this->UsedOnce = true;
		
		//	this->lightingShader.CreatShader("shaders\\ContAsClass\\MySandBox.vs", "shaders\\ContAsClass\\MySandBox.frag");
	//	this->lampShader.CreatShader("shaders\\ContAsClass\\Lamp.vs", "shaders\\ContAsClass\\Lamp.frag");
		//		this->SandBox.CreatShader("shaders\\ContAsClass\\Material.vs", "shaders\\ContAsClass\\SandBox2.frag");
	}
	void GetScreenVerts(int wid,int hei)
	{
		for (int i = 0; i < wid; i++)
		{
			for (int n = 0; n < hei; n++)
			{
				ScreenVerteices.push_back(i/10.0f);
				ScreenVerteices.push_back(n/10.0f);
				ScreenVerteices.push_back(0/10.0f);
			}
		}
	//	for (int v = 0; v < this->ScreenVerteices.size();v++)
	//		std::cout << this->ScreenVerteices[v]<<"f,";
		ScreenVerteices.push_back(0);
		ScreenVerteices.push_back(wid);
		ScreenVerteices.push_back(1);
		for (int m = 0; m < ScreenVerteices.size()-3; m++)
		{
			this->ScreenIndecies.push_back(m + 3);
		}

	}
	void CreatWidGet()
	{
		glGenVertexArrays(1, &this->WG_VAO);
		glGenBuffers(1, &this->WG_VBO);
		glGenBuffers(1, &this->WG_EBO);
		glBindVertexArray(this->WG_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->WG_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Widget), Widget, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->WG_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(WidInds), WidInds, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		
	}
	void TestFul()
	{
		
		//we should use strucr to store 3 values at once
		this->ScreenVerteices.push_back(-1.0f);
		this->ScreenVerteices.push_back(1.0f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(-1.0f);
		this->ScreenVerteices.push_back(-1.0f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(1.0f);
		this->ScreenVerteices.push_back(-1.0f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(1.0f);
		this->ScreenVerteices.push_back(1.0f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(-1.0f);
		this->ScreenVerteices.push_back(1.0f);
		this->ScreenVerteices.push_back(0.0f);

		this->ScreenVerteices.push_back(-1.0f/2);
		this->ScreenVerteices.push_back(1.0f/2);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(-1.0f/2);
		this->ScreenVerteices.push_back(-1.0f/2);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(1.0f/2);
		this->ScreenVerteices.push_back(-1.0f/2);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(1.0f/2);
		this->ScreenVerteices.push_back(1.0f/2);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(-1.0f/2);
		this->ScreenVerteices.push_back(1.0f/2);
		this->ScreenVerteices.push_back(0.0f);


		/*
		this->ScreenVerteices.push_back(0.5f);
		this->ScreenVerteices.push_back(0.7f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(0.8f);
		this->ScreenVerteices.push_back(-0.8f);
		this->ScreenVerteices.push_back(0.0f);
		this->ScreenVerteices.push_back(-0.2f);
		this->ScreenVerteices.push_back(-0.2f);
		this->ScreenVerteices.push_back(-0.0f);
		this->ScreenVerteices.push_back(-0.3f);
		this->ScreenVerteices.push_back(0.4f);
		this->ScreenVerteices.push_back(0.0f);
	
		*/
	}
	void DoAll()
	{
		//	Mystates.Commands(); //here used once
		//	this->SetAllCallBacks();
	//	this->GetScreenVerts(800, 600);
		//this->TestFul();
		this->CreatWidGet();
//		this->GetScreenVerts(10,10);
		this->SetVarValues();
		this->CreateScreene();
		
		//this->CreateLampCube();
	//	this->CreateLightenCube();
		this->CreateShaders();
	//	this->CreateTextures();
		//	this->CreateCameras();
		//this->NumActiveCam = this->AddCamera(glm::vec3(0.0f,0.0f,-3.0f));
		this->InfinityLoop();
	}
	void CreateScreene()
	{
		glGenVertexArrays(1, &this->TestVAO);
		glGenBuffers(1, &this->TestVBO);
		glBindVertexArray(this->TestVAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->TestVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

		glGenVertexArrays(1, &this->ScreenVAO);
		glGenBuffers(1, &this->ScreenVBO);
		glGenBuffers(1, &this->ScreenEBO);
		glBindVertexArray(this->ScreenVAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->ScreenVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*this->ScreenVerteices.size(), this->ScreenVerteices.data(), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ScreenEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLfloat)*this->ScreenIndecies.size(), this->ScreenIndecies.data(), GL_STATIC_DRAW);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		//this->LightenCube = true;
		///////////////////////////////////////////
		
		/*
		glGenVertexArrays(1, &this->TestVAO);
		glGenBuffers(1, &this->TestVBO);
		glBindBuffer(GL_ARRAY_BUFFER, this->TestVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 9, vert, GL_STATIC_DRAW);
		glBindVertexArray(containerVAO);
		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		//this->LightenCube = true;
		*/

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
#define lightingShader SandBoxShader
	void InfinityLoop()
	{
	//	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	//	std::cout << "W H " << this->WIDTH << "  " << this->HEIGHT << std::endl;
		while (!glfwWindowShouldClose(this->window))
		{
			this->First.Warn = false;
			this->GetFragShadPath.Warn = false;
			this->ReCount.Warn = false;
			this->First.Load(this->GetFragShadPath.StData.c_str());
			//Re Compiling Shader To Be Onlin 
			//this->CreateShaders();
			////////////here used every once
			glm::vec2 mp = this->ReturnMousPos();
			Mystates.Commands();
			GLfloat CurrentFrame = glfwGetTime();
			this->DeltaTime = CurrentFrame - this->LastFrame;
			this->LastFrame = CurrentFrame;
			glUniform1f(glGetUniformLocation(lightingShader->Program, "time"), glfwGetTime());
			glUniform2f(glGetUniformLocation(lightingShader->Program, "screen"),800,600);
			glUniform2f(glGetUniformLocation(lightingShader->Program, "mouse"), mp.x, mp.y);
			glUniform2f(glGetUniformLocation(lightingShader->Program, "resolution"),WIDTH,HEIGHT);

			//	std::cout << mp.x << "  " << mp.y;
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();
			Do_Movement();
		//	glEnable(GL_DEPTH_TEST);
			glClearColor(0.3f,0.4f,0.6f,1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			// Use cooresponding shader when setting uniforms/drawing objects
			lightingShader->Use();
		//	glBindVertexArray(this->ScreenVAO);
		//	glDrawArrays(GL_TRIANGLE_STRIP, 0, this->ScreenVerteices.size());
		
			//Corect
			glBindVertexArray(this->WG_VAO);
			glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

	//		glBindVertexArray(this->ScreenVAO);
	//		glDrawElements(GL_TRIANGLES, this->ScreenIndecies.size(), GL_UNSIGNED_INT, 0);


			//	glBindVertexArray(this->TestVAO);
		//	glDrawArrays(GL_TRIANGLES, 0, 12);
			glBindVertexArray(0);
			// Swap the screen buffers
			glfwSwapBuffers(window);
			glm::vec2 ml;
		//	delete this->SandBoxShader;
			glDeleteShader(this->SandBoxShader->Program);
		//	delete this->SandBoxShader;
		//	this->CreateShaders();
			//this->SandBoxShader->ReCreate("shaders\\ContAsClass\\MySandBox.vs", "shaders\\ContAsClass\\MySandBox.frag");
		//	this->ReCount.Warn = false;
			this->ReCount.Load(this->GetFragShadPath.StData.c_str());
			if (ReCount.StData.size() != First.StData.size())//ו׀ַ ַב׃״ׁ ֵ׀ַ Êד ֵבÛֶַו ַבָׁהַדּ בַ םÚדב זֽÞםÞֹ ַהַ בַ ַÚבד ַב׃ָָ
				this->DoAll();
		}
		glDeleteVertexArrays(1,&this->ScreenVAO);
		glDeleteBuffers(1,&this->ScreenVBO);
		glDeleteVertexArrays(1, &this->TestVAO);
		glDeleteBuffers(1, &this->TestVBO);
		glDeleteVertexArrays(1, &this->WG_VAO);
		glDeleteBuffers(1, &this->WG_VBO);
		glDeleteBuffers(1, &this->WG_EBO);

	}

};
#endif
#endif