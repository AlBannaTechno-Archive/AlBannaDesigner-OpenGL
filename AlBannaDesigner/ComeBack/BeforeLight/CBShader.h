#ifndef __CB__SHADER__
#define __CB__SHADER__
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
//#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*

class StringLoader
{
private:
const char*PCData;
std::string StData;
public:
StringLoader(const char*path)
{
std::ifstream file;
file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
try
{
file.open(path);
std::stringstream fileStream;
fileStream << file.rdbuf();
file.close();
StData = fileStream.str();
}
catch (std::ifstream::failure d)
{
std::cout << "ERROR::LOADE::FILE" << std::endl;
}
this->PCData = this->StData.c_str();
}
};


*/
class CBShader
{
public:
	GLuint Program;
	//Constuctor To generate The Shader On The Fly
	CBShader(const GLchar*VertexPath,const GLchar*FragmentPath,const GLchar*GeoMetryPath=nullptr)
	{
		//Getting the vertex and fragment shader from filpath
		std::string vertexCode;
		std::string fragmentCode;
		std::string geometryCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		std::ifstream gShaderFile;
		//ensure that ifstream object can throw execption
		//«· √ﬂœ „‰ «” ÿ«⁄… «·⁄‰’— · „—Ì— «·«” ‰À‰«∆«  „⁄ try catch
		vShaderFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			//Try Openining Files
			vShaderFile.open(VertexPath);
			fShaderFile.open(FragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			//Read file-from buffer-contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			//Cloth File Handler
			vShaderFile.close();
			fShaderFile.close();
			//Copy Data To String Object
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
			//Check If GeoMetry Shader Path Is present,also we will load geometry shader
			if (GeoMetryPath!=nullptr)
			{
				gShaderFile.open(GeoMetryPath);
				std::stringstream gShaderStream;
				gShaderStream << gShaderFile.rdbuf();
				gShaderFile.close();
				geometryCode = gShaderStream.str();
			}

		}
		catch (std::ifstream::failure d)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCESSFULLY_READ" << std::endl;
		}
		//Copy Data To Character Array and using c Style ASCI To Compile It After this
		const GLchar *vShaderCode = vertexCode.c_str();
		const GLchar *fShaderCode = fragmentCode.c_str();
		//Compiling Shaders
		GLuint vertex, fragment;
		GLuint check;
		GLchar infoLog[512];
		//		First Vertex Shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex,1,&vShaderCode,NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex,"VERTEX");
		//		Second Fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment,1,&fShaderCode,NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");
		//		Third If Gemoetric shader used Do all last operation on it
		GLuint geometry;
		if (GeoMetryPath != nullptr)
		{
			const GLchar*gShaderCode = geometryCode.c_str();
			geometry = glCreateShader(GL_GEOMETRY_SHADER);
			glShaderSource(geometry,1,&gShaderCode,NULL);
			glCompileShader(geometry);
			checkCompileErrors(geometry,"GEOMETRY");
		}
		//Work ON Shader Program
		this->Program = glCreateProgram();
		glAttachShader(this->Program, vertex);
		glAttachShader(this->Program, fragment);
		if (GeoMetryPath != nullptr)
		{
			glAttachShader(this->Program, geometry);
		}
		glLinkProgram(this->Program);
		checkCompileErrors(this->Program, "PROGRAM");
		///delete all un necessery filies
		glDeleteShader(vertex);
		glDeleteShader(fragment);
		if (GeoMetryPath != nullptr)
		{
			glDeleteShader(geometry);
		}
		
	}
	void Use(){ glUseProgram(this->Program);}
protected:
	void  checkCompileErrors(GLuint shader, std::string type)
	{
		GLint check;
		GLchar infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &check);
			if (!check)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "| ERROR::SHADER_COMPILATION_ERROR-OF_TYPE : " << type << "|\n" << infoLog;
				std::cout << "\n| -- ----------------------------------------------------------------|" << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader,GL_LINK_STATUS,&check);
			if (!check)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "| ERROR::PROGRAM_LINKING_ERROR-OF_TYPE : " << type << "|\n" << infoLog;
				std::cout << "\n| -- ----------------------------------------------------------------|" << std::endl;
			}
		}
	}
};
#endif
#pragma once
