#pragma once//To bild this page once 
//eve if we chang it it's not build in ordinary mode but we need to press ReBuild Button
#ifndef __ABT__LOADER__
#define __ABT__LOADER__
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class StringLoader
{
	private:
		
	public:
		std::string OldPath;
		bool used = false;
		bool Warn = true;
		const char*PCData;
		std::string StData;
		StringLoader(){};
		void Load(const char*path)
		{
			this->used = true;
			this->OldPath = path;
			std::ifstream file;
			file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			try
			{
				file.open(path);
				std::stringstream fileStream;
				fileStream << file.rdbuf();
				file.close();
				StData =fileStream.str();
				PCData = StData.c_str();
			}
			catch (std::ifstream::failure d)
			{
				if (this->Warn==false)
					std::cout << "ERROR::LOADE::FILE" << std::endl;
			}
			this->PCData = this->StData.c_str();
		}
		StringLoader(const char*path)
		{
			this->Load(path);
		}
		void ReLoad(const char*path)
		{
			if (this->used == false)
			{
				std::cout << "ERROR::STRING-LOADER::\"You Must Use Load Function Before Using ReLoad\"" << std::endl;
				return;
			}
			this->StData.clear();
		//	for (int m = 0; m < this->StData.size(); m++) To Clear char*
			this->Load(path);
		}
	};
 
#endif