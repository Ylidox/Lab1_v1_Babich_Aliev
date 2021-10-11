#include "FileManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>

FileManager::FileManager() : path("data.txt") {}

FileManager::FileManager(string path) 
{
	this->path = path;
}

void FileManager::addRecord(string record) 
{
	ofstream out(path, ios::app);
	if (out.is_open())
	{
		out << record << endl;
	}
	out.close();
}

string FileManager::readFile()
{
	std::ifstream in(path);
	string line;
	string output = "";
	if (in.is_open())
	{
		while (getline(in, line))
		{
			output += line;
		}
	}
	in.close();
	return output;
}

string FileManager::clearString(string s)
{
	std::regex regular(" {1,}");
	return regex_replace(s, regular, "");
}