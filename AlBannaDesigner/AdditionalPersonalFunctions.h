#pragma once
#ifndef ADD_PRO_FUN_
#define ADD_PRO_FUN_
#include<iostream>
#include<vector>;
using namespace std;
//the sol for this idea via use stack
namespace ABT
{
	class test
	{
	private:
	public:
		void mmsdk();
	};
	template<class TT>
	//#define TT int
	class CStanderVert
	{
	private:
	public:
		CStanderVert()
		{
			size = 0;
		}
		//	template<class TT>
		TT *Pointer;
		int size;
		void mmsd();
		//	template<class TT>
		void CopyCreatArrayFrVecToArr(std::vector<TT> Vec)
		{
			size = Vec.size();
		//	*Pointer = Vec[1];
			for (int m = 0; m < size; m++)
			{
		//		*(Pointer + m) = new TT;
			}
			for (int m = 0; m < size; m++)
			{
			//	*(Pointer + m) = Vec[m];
			}
		}

	};

}
////////////////////////////////////////////Strart From Here//////////////////////////////

template<class TT>
void ScallerVertex(TT *arraypointer, int size, TT scaller)
{
	for (int m = 0; m < size; m++)
	{
		*(arraypointer + m) *= scaller;
	}
}
//bool Xmod, bool Ymod, bool Zmod;

/*
char*={a1,a2,a3,b1,b2,b3,b4,c1,c2
		a4,a5,a6,b4,b5,b6,b7,c3,c4
}
->elements vector<elements<numberof elements for every step >>
--->from last  vector->>
vector.begin::number of variables 
vector[1]=step for variable 1 :3
vector[2]=step for variabel 2 :3
vector[2]=step for variabel 2 :2
...////
vector.end=size of all variables (number of all variable values = at the last thing => 18 =size -older-) 
*/
template<class TT>
void ScallerVertexAttOpp(TT *arraypointer,vector<int>ElementAttributes,vector<bool>StatuesOfVariable , TT scaller)
{
	int NumberOfVariables = ElementAttributes.begin();
	int NumberOfAllElements = ElementAttributes.end();
	//Calculate Number Of Elements Per Step
	int NumberOfElementsPerStep=0;
	for (int m = 0; m < (StatuesOfVariable.size()); m++)
	{
		NumberOfElementsPerStep=ElementAttributes[m] * StatuesOfVariable[m];
	}

	//StatuesOfVariable[n]->ElementAttributes[n+]
//	vector<int<bool>>;
	/*
	ÃæáÇ äÏÎá Çáì ÇáãÕİæİÉ 
	Ëã äÏæÑ İíåÇ ÈÚÏÏ ãÑÇÊ ÚäÇÕÑåÇ 
	Ëã äÖÚ ãÕİææİÉ áÍÇáÉ ßá ÚäÕÑ 
	ÍíË Çäå ãËáÇ 
	ÇĞÇ ßÇä ÇáãÊÛíÑ Ó ÓíÊã ÊÛííÑå æÚÏ Şíãå ÏÇÆãÇ ËáÇËÉ 
	İÅäå íÊã ÍÓÇÈ ÌãíÚ ÇáŞíã ÇááÊí ÓÊÊÛíÑ İí ÍÇáÊäÇ Úä ØÑíŞ ÇáÇÊí 
	äæÌÏ ÇáÎØæÉ ÇáßáíÉ ááÚäÇÕÑ 
	æÇááÊí ÊäÊÌ Úä ØÑíŞ ÖÑÈ ÚÏÏ ÇáÚäÇÕÑ İí Øæá ßá ÚäÕÑ 
	æäÚäí ÈÇáÚäÇÕÑ åäÇ ÇáãÊÛíÑÇÊ
	Ãí ÖÑÈ ßá ãÊÛíÑ İí ÚÏÏå İí ÇáãÑÉ ÇáæÇÍÏÉ æÌãÚ åĞå ÇáŞíã 
	İíäÊÌ áäÇ ãÈÇÔÑÉ ßã ÚäÕÑ ÓíÊã ŞİÒå İí ßá ãÑÉ 
	*/

	for (int m = 2; m < (ElementAttributes.size() - 4); m++)//General Loop in Vector
	{
	//	if ();
	}
	/*
	
		for (int s = 0; s < StatuesOfVariable.size();s++)
		{
			if (StatuesOfVariable[m] == true)
			{
				for (int f = 0; f < ElementAttributes[0]; f++)
				{

				}
			}
		}


	
	*/

}
///ÇáÈÑäÇãÌ ÇáÊÇáí áäÓÎ ÇáãÕİæİÇÊ
template<class TT>
void AutoCopyArray(TT*essential, TT*secondry, int size)
{
	for (int m = 0; m < size; m++)
	{
		*(secondry + m) = *(essential + m);
	}
}

template<class TT>
int CalculateArrayPower(TT*arr)
{
	int num=0;
//	num = sizeof(arr) / sizeof(arr[0]);
	while (arr)
	{
		
	}
	return num;
}

#endif