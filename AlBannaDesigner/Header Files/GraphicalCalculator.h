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

	float radius(glm::vec3 Centre,glm::vec3 PointPosition)
	{
		float DeltaX = Centre.x - PointPosition.x;
		float DeltaY = Centre.y - PointPosition.y;
		float DeltaZ = Centre.z - PointPosition.z;
		float Result = DeltaX*DeltaX + DeltaY*DeltaY + DeltaZ*DeltaZ;
		return (sqrt(Result));
	}
	glm::vec3 SphricalPosition_Y_Z(float Radius,glm::vec3 CentrePosition,float Yangle,float Zangle)
	{
		//Yangle->phi   Zangle->seta
		float Rx, Ry, Rz;
		Rx = Radius*sin(glm::radians(Zangle))*cos(glm::radians(Yangle));
		Ry = Radius*cos(glm::radians(Zangle));//إضافة اي قيمة هنا تجعل  مالسار  على شكل قطع  ناقص
		Rz = Radius*sin(glm::radians(Zangle))*sin(glm::radians(Yangle));
//		Rx = Rx*sin(glm::radians(30.0f));
//		Ry *= sin(glm::radians(30.0f));
//		Rz *= sin(glm::radians(30.0f));

		/*
		Rx = Radius*sin(glm::radians(Zangle))*cos(glm::radians(Yangle));
		Ry = Radius*cos(glm::radians(Zangle));//إضافة اي قيمة هنا تجعل  مالسار  على شكل قطع  ناقص
		Rz = Radius*sin(glm::radians(Zangle))*sin(glm::radians(Yangle));

		*/

		glm::vec3 Result;
		Result.x = Rx + CentrePosition.x;
		Result.y = Ry + CentrePosition.y;
		Result.z = Rz + CentrePosition.z;
	//	std::cout << "X =" << Result.x << " Y =" << Result.y << " Z =" << Result.z << std::endl;
		return Result;
		/*
		القطر نوجده اختياري 
		ومن ثم تتم عملية نقل العناصر او النقاطر باستخدام مصفوفة النقل 
		وتنقل القيم الموضع المحدد بالمصفوفة الراجعة من هذه الدالة 
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
		std::vector<GLuint>Indices;
		glm::vec3 *Centre;
		GLfloat*Radius;
		GLint*PointsNumber;
		GLint*TrianglesNumber;
		GLint*HorizoneNumber;
		GLint*VerticalNumber;
		GLint*SquaresNumber;
		Geometric()
		{
			this->Centre = new glm::vec3;
			this->Radius = new GLfloat;
			this->PointsNumber = new GLint;
			this->TrianglesNumber = new GLint;
			this->HorizoneNumber = new GLint;
			this->VerticalNumber = new GLint;
			this->SquaresNumber = new GLint;
	
		}
		~Geometric()
		{
			
			delete this->Centre;
			delete this->Radius;
			delete this->PointsNumber;
			delete this->HorizoneNumber;
			delete this->VerticalNumber;
			delete this->TrianglesNumber;
			delete this->SquaresNumber;
			Vertices.clear();
			Indices.clear();
		}
	};
	struct GenPos{
		GLfloat x;
		GLfloat y;
		GLfloat z;
	};
#define Notic_NO
	class Sphare :public Geometric
	{
	private:
		GenPos SphricalPosition_Y_Z_gp(GLfloat Radius, glm::vec3 CentrePosition, GLfloat Yangle, GLfloat Zangle)
		{

			//Yangle->phi   Zangle->seta
			GLfloat Rx, Ry, Rz;
			Rx = Radius*glm::sin(glm::radians(Zangle))*cos(glm::radians(Yangle));
			Ry = Radius*glm::cos(glm::radians(Zangle));//إضافة اي قيمة هنا تجعل  مالسار  على شكل قطع  ناقص
			if (Zangle == 180.0 || Yangle == 180.0)
			{
				Rz = 0;
				//وضعنا هذا لانه توجد مشكلة كبيرة 
				//وهي ان دالة الجيب ل 180 ترجع قيم ليست بأصفار وهذا خطأ 
			}
			else
				Rz = Radius*glm::sin(glm::radians(Zangle))*sin(glm::radians(Yangle));
	
			GenPos gp;
			gp.x = Rx + CentrePosition.x;
			gp.y = Ry + CentrePosition.y;
			gp.z = Rz + CentrePosition.z;
#ifdef Notic
			std::cout << "SphricalPosition_Y_Z_gp\n";
			std::cout << "\nRadius = " << Radius << "CentrePosition x y z = " << CentrePosition.x;
			std::cout << " " << CentrePosition.y << " " << CentrePosition.z << "Yangle = " << Yangle << "Zangle = " << Zangle;
			std::cout << std::endl;
			std::cout << "\n Rz= " << Rz << " sin(Zangle) " << glm::sin(glm::radians(Zangle)) << " sin(Yangle)  " << glm::sin(glm::radians(Yangle));
			std::cout << "\nRadians (Zangle) " << glm::radians(Zangle) << "  \n";
			std::cout << "\nX =" << gp.x << " Y =" << gp.y << " Z =" << gp.z << std::endl;
#endif
			return gp;
		}


	protected:
		void GeneratIndices_Tri()
		{
			//P1=Counter+1
			//P2=Counter+HoraizonNumber
			//P3=Counter+2
			/*
			رقم النقطة اللتي فوق نقطة معية تساوي
			Pn+VerticalNumber اى ندور بعدها دورة كاملة
			الجديد حيث Mn
			هو رقم المرة والمرة بها مرتان N1,N2
			Mn->Ns,Ns+1 اي ان كل مرة تمثل مربع وكل مربع يتكون من مثلثين
			Ns=s+1,s+5,s+2
			Ns+1=s+2,s+5,s+6
			s=n حيث
			وحيث ان كل مربع يتم تكوينة بعدد اربع نقاط
			فإن كل
			عدد المربعات يساوي = العدد الكلي للنقاط -نقاط دورة افقية كاملة
			SquareNumber=VerteicesNumber-HorizonNumer
			*/
			for (int SqNumber = 0; SqNumber < *this->SquaresNumber; SqNumber++)
			{
				//Default 1 5 2     2 5 6
				//First Triangle ( Number n)
				this->Indices.push_back(SqNumber + 0);
				this->Indices.push_back(SqNumber + 4);
				this->Indices.push_back(SqNumber + 1);
				//Second Triangle (Number n)
				this->Indices.push_back(SqNumber + 1);
				this->Indices.push_back(SqNumber + 4);
				this->Indices.push_back(SqNumber + 5);
			}
		}
	public:
		Sphare() :Geometric(){}
		/*
		spherical Generator 
		inputs : Radious , Horizon Step , Vertical Step ,Centre Position , 
		outputs : All Points Positions , All Points Indices ->Struct
		*/
		void GenerateSphare(GLfloat radius,glm::vec3 Centre,GLint HnStep,GLint VnStep)
		{
			*this->Radius = radius;
			*this->Centre = Centre;
			*this->HorizoneNumber = 360/HnStep;
			*this->VerticalNumber = 360 / VnStep;
			*this->PointsNumber = *this->HorizoneNumber * *this->VerticalNumber;
			*this->SquaresNumber = *this->PointsNumber - *this->VerticalNumber;
			*this->TrianglesNumber = *this->SquaresNumber * 2;
			for (int horz = 0; horz < *this->HorizoneNumber; horz++)
			{
				for (int vert = 0; vert < *this->VerticalNumber; vert++)
				{
				//	glm::vec3 TempS= SphricalPosition_Y_Z(*this->Radius, *this->Centre, vert*HnStep, horz*VnStep);
					GenPos TempS =this->SphricalPosition_Y_Z_gp(*this->Radius, *this->Centre, vert*HnStep, horz*VnStep);
					this->Vertices.push_back(TempS.x);
					this->Vertices.push_back(TempS.y);
					this->Vertices.push_back(TempS.z);
				}
			}
			this->GeneratIndices_Tri();
		}
		
		void PrintIndices()
		{
			std::cout<<"\nIndices \n";
			for (int m = 0; m < this->Indices.size(); m++)
			{
				std::cout << " " << this->Indices[m] << "  ";
			}
			std::cout << std::endl;
			std::cout << "Virtices \n";
			for (int m = 0; m < this->Vertices.size(); m++)
			{
				std::cout <<this->Vertices[m] << "\n";
			}
			std::cout << std::endl;
		}
		void PrintInfo()
		{
			std::cout << "Centre ( " << this->Centre->x << " , " << this->Centre->y << " , " << this->Centre->z << " )\n";
			std::cout << "Radius" << this->Radius << std::endl;
			std::cout << "HorizoneNumber  = " << this->HorizoneNumber << std::endl;
			std::cout << "VerticalNumber  = " << this->VerticalNumber << std::endl;
			std::cout << "PointsNumber  = " << this->PointsNumber << std::endl;
			std::cout << "SquaresNumber   = " << this->SquaresNumber << std::endl;
			std::cout << "TrianglesNumber =" << this->TrianglesNumber << std::endl;


			std::cout << "Centre ( " << this->Centre->x << " , " << this->Centre->y << " , " << this->Centre->z << " )\n";
			std::cout << "Radius" << *this->Radius << std::endl;
			std::cout << "HorizoneNumber  = " << *this->HorizoneNumber << std::endl;
			std::cout << "VerticalNumber  = " << *this->VerticalNumber << std::endl;
			std::cout << "PointsNumber    = " << *this->PointsNumber << std::endl;
			std::cout << "SquaresNumber   = " << *this->SquaresNumber << std::endl;
			std::cout << "TrianglesNumber =" << *this->TrianglesNumber << std::endl;
			std::cout << "Vertices.size   = " << this->Vertices.size() << std::endl;
			std::cout << "Indices.size    =" << this->Indices.size()<< std::endl;

		}
	};

}

#endif