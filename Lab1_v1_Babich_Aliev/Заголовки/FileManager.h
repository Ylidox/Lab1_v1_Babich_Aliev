#pragma once
#include <string>
#include <map>

using namespace std;

class FileManager
{
private:
	string path;
public:
	string getPath();

	void setPath(string path);

	FileManager();

	FileManager(string path);

	void writeToFile(string record);

	string* readFromFile();

	int length();
};


