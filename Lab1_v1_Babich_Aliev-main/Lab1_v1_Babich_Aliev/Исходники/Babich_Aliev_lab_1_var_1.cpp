#include <iostream>
#include <iomanip>
#include <compare>
#include "FileManager.h"

int main()
{
	FileManager fm;
	fm.addRecord("dgd g g  + 11kg gggg");
	string s = fm.clearString(fm.readFile());
	cout << s;
}