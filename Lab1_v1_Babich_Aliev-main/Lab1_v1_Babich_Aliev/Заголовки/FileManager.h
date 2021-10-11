#pragma once
#include <string>

using namespace std;

class FileManager
{
private:
	string path;
public:
	FileManager();

	FileManager(string path);

	void addRecord(string record);

	string readFile();

	string clearString(string s);
};
