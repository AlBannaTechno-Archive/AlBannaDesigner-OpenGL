#if 0
#pragma once
#ifndef __GRAPHICAL__CALCULATOR__
#define __GRAPHICAL__CALCULATOR__
#define _USING_OPEN_GL
#ifdef _USING_OPEN_GL
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#endif
#ifdef _USING_GENERAL_C
#define GLfloat float
#define GLint int
#define GLuint unsigned int
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<vector>
#include<iostream>

namespace GRATOR
{

	float radius(glm::vec3 Centre, glm::vec3 PointPosition)
	{
		float DeltaX = Centre.x - PointPosition.x;
		float DeltaY = Centre.y - PointPosition.y;
		float DeltaZ = Centre.z - PointPosition.z;
		float Result = DeltaX*DeltaX + DeltaY*DeltaY + DeltaZ*DeltaZ;
		return (sqrt(Result));
	}
	glm::vec3 SphricalPosition_Y_Z(float Radius, glm::vec3 CentrePosition, float Yangle, float Zangle)
	{
		//Yangle->phi   Zangle->seta
		float Rx, Ry, Rz;
		Rx = Radius*sin(glm::radians(Zangle))*cos(glm::radians(Yangle));
		Ry = Radius*cos(glm::radians(Zangle));//ÅÖÇİÉ Çí ŞíãÉ åäÇ ÊÌÚá  ãÇáÓÇÑ  Úáì Ôßá ŞØÚ  äÇŞÕ
		Rz = Radius*sin(glm::radians(Zangle))*sin(glm::radians(Yangle));
		//		Rx = Rx*sin(glm::radians(30.0f));
		//		Ry *= sin(glm::radians(30.0f));
		//		Rz *= sin(glm::radians(30.0f));

		/*
		Rx = Radius*sin(glm::radians(Zangle))*cos(glm::radians(Yangle));
		Ry = Radius*cos(glm::radians(Zangle));//ÅÖÇİÉ Çí ŞíãÉ åäÇ ÊÌÚá  ãÇáÓÇÑ  Úáì Ôßá ŞØÚ  äÇŞÕ
		Rz = Radius*sin(glm::radians(Zangle))*sin(glm::radians(Yangle));

		*/

		glm::vec3 Result;
		Result.x = Rx + CentrePosition.x;
		Result.y = Ry + CentrePosition.y;
		Result.z = Rz + CentrePosition.z;
		//	std::cout << "X =" << Result.x << " Y =" << Result.y << " Z =" << Result.z << std::endl;
		return Result;
		/*
		ÇáŞØÑ äæÌÏå ÇÎÊíÇÑí
		æãä Ëã ÊÊã ÚãáíÉ äŞá ÇáÚäÇÕÑ Çæ ÇáäŞÇØÑ ÈÇÓÊÎÏÇã ãÕİæİÉ ÇáäŞá
		æÊäŞá ÇáŞíã ÇáãæÖÚ ÇáãÍÏÏ ÈÇáãÕİæİÉ ÇáÑÇÌÚÉ ãä åĞå ÇáÏÇáÉ
		*/
	}
	/*
	spherical Generator
	inputs : Radious , Horizon Step , Vertical Step ,Centre Position ,
	outputs : All Points Positions , All Points Indices ->Struct
	*/

	class Geometric
	{
	private:
	protected:
	public:
		std::vector<GLfloat>Vertices;
		std::vector<GLint>Indices;
		glm::vec3 *Centre;
		GLfloat*Radius;
		GLint*VerticesNumner;
		GLint*TrianglesNumber;
		GLint*HorizoneNumber;
		GLint*VerticalNumber;
		GLint*SquaresNumber;
		Geometric()
		{
			this->Centre = new glm::vec3;
			this->Radius = new GLfloat;
			this->VerticesNumner = new GLint;
			this->TrianglesNumber = new GLint;
			this->HorizoneNumber = new GLint;
			this->VerticalNumber = new GLint;
			this->SquaresNumber = new GLint;

		}
		~Geometric()
		{

			delete this->Centre;
			delete this->Radius;
			delete this->VerticesNumner;
			delete this->HorizoneNumber;
			delete this->VerticalNumber;
			delete this->TrianglesNumber;
			delete this->SquaresNumber;
			Vertices.clear();
			Indices.clear();
		}
	};
	class Sphare :public Geometric
	{
	private:
	protected:
		void GeneratIndices_Tri()
		{
			//P1=Counter+1
			//P2=Counter+HoraizonNumber
			//P3=Counter+2
			/*
			ÑŞã ÇáäŞØÉ ÇááÊí İæŞ äŞØÉ ãÚíÉ ÊÓÇæí
			Pn+VerticalNumber Çì äÏæÑ ÈÚÏåÇ ÏæÑÉ ßÇãáÉ
			ÇáÌÏíÏ ÍíË Mn
			åæ ÑŞã ÇáãÑÉ æÇáãÑÉ ÈåÇ ãÑÊÇä N1,N2
			Mn->Ns,Ns+1 Çí Çä ßá ãÑÉ ÊãËá ãÑÈÚ æßá ãÑÈÚ íÊßæä ãä ãËáËíä
			Ns=s+1,s+5,s+2
			Ns+1=s+2,s+5,s+6
			s=n ÍíË
			æÍíË Çä ßá ãÑÈÚ íÊã ÊßæíäÉ ÈÚÏÏ ÇÑÈÚ äŞÇØ
			İÅä ßá
			ÚÏÏ ÇáãÑÈÚÇÊ íÓÇæí = ÇáÚÏÏ Çáßáí ááäŞÇØ -äŞÇØ ÏæÑÉ ÇİŞíÉ ßÇãáÉ
			SquareNumber=VerteicesNumber-HorizonNumer
			*/
			for (int SqNumber = 0; SqNumber < *this->SquaresNumber; SqNumber++)
			{
				//First Triangle ( Number n)
				this->Indices.push_back(SqNumber + 1);
				this->Indices.push_back(SqNumber + 5);
				this->Indices.push_back(SqNumber + 2);
				//Second Triangle (Number n)
				this->Indices.push_back(SqNumber + 2);
				this->Indices.push_back(SqNumber + 5);
				this->Indices.push_back(SqNumber + 6);
			}
		}
	public:
		Sphare() :Geometric(){}
		/*
		spherical Generator
		inputs : Radious , Horizon Step , Vertical Step ,Centre Position ,
		outputs : All Points Positions , All Points Indices ->Struct
		*/
		void GenerateSphare(GLfloat radius, glm::vec3 Centre, GLint HnStep, GLint VnStep)
		{
			*this->Radius = radius;
			*this->Centre = Centre;
			*this->HorizoneNumber = 360 / HnStep;
			*this->VerticalNumber = 360 / VnStep;
			*this->VerticesNumner = *this->HorizoneNumber * *this->VerticalNumber;
			*this->SquaresNumber = *this->VerticesNumner - *this->VerticalNumber;
			*this->TrianglesNumber = *this->SquaresNumber * 2;
			for (int horz = 0; horz < *this->HorizoneNumber; horz++)
			{
				for (int vert = 0; vert < *this->VerticalNumber; vert++)
				{
					glm::vec3 TempS = SphricalPosition_Y_Z(*this->Radius, *this->Centre, vert*HnStep, horz*VnStep);
					this->Vertices.push_back(TempS.x);
					this->Vertices.push_back(TempS.y);
					this->Vertices.push_back(TempS.z);
				}
			}
			this->GeneratIndices_Tri();
		}

	};

}

#endif
#endif