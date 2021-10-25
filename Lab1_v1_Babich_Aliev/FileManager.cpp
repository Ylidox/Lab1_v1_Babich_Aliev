#include "FileManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

FileManager::FileManager() : path("RUS.txt") {}

FileManager::FileManager(string path)
{
	this->path = path;
}

void FileManager::writeToFile(string record)
{
	ofstream out(path, ios::app);
	if (out.is_open())
	{
		out << record << endl;
	}
	out.close();
}

string* FileManager::readFromFile()
{
	std::ifstream in(path);
	string word = "";
	string* words = new string[length()];
	if (in.is_open())
	{
		int i = 0;
		while (getline(in, word))
		{
			words[i] = word;
			i++;
		}
	}
	in.close();
	return words;
}

int FileManager::length()
{
	std::ifstream in(path);
	string word;
	int length = 0;
	if (in.is_open())
	{
		while (getline(in, word))
		{
			length++;
		}
	}
	in.close();
	return length;
}