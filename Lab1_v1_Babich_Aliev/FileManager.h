#pragma once
#include <string>
#include <map>

using namespace std;

class FileManager
{
public:
	string path;

	FileManager();

	FileManager(string path);

	void writeToFile(string record);

	string* readFromFile();

	int length();
};

