#pragma once
#ifndef __STATES__
#define __STATES__
#include<../AlBannaDesigner/Header Files/AdditionalClasses.h>
namespace State
{
class StatesPro
{
private:
	char*FilePath;
	bool CheckPos(std::string Search)
	{
		StringLoader ml(FilePath);
		std::string Asearch;//A word after space , B word before space
		std::string Bsearch;
		size_t Apos;
		size_t Bpos;
		Asearch = " " + Search;
		Bsearch = Search + " ";
		Apos = ml.StData.find(Asearch);
		Bpos = ml.StData.find(Bsearch);
		if (Apos != std::string::npos || Bpos != std::string::npos)
			return true;
		else
			return false;
	}
public:
	StatesPro(char*path)
	{
		FilePath = path;
	}
	void Commands()
	{
		StringLoader ml(FilePath);//file at the same folder of programme
		if (this->CheckPos("red") == true)
			red = true; else red= false;
		if (this->CheckPos("green") == true)
			green = true;else green= false;
		if (this->CheckPos("blue") == true)
			blue = true; else blue= false;

		if (this->CheckPos("lightsource") == true)
			lightsource = true; else lightsource = false;
		if (this->CheckPos("cube") == true)
			cube = true; else cube = false;

	}

public:
	bool red = false;
	bool green = false;
	bool blue = false;
	bool lightsource = false;
	bool cube = false;
};
}

#endif
/*

void OldCommands()
{
StringLoader ml("Commands.co");//file at the same folder of programme

//	if (true==ml.StData.find("printHellow"))
//		std::cout << "We Find printHellow";
//const std::string sentence = "My printer is not working.";
std::cout << "sentence: " << ml.StData << std::endl;
std::string search;
size_t pos;
search = "print";
pos = ml.StData.find(search);
if (pos != std::string::npos)
std::cout << "sentence contains " << search << std::endl;
else
std::cout << "sentence does not contains " << search << std::endl;
}

*/