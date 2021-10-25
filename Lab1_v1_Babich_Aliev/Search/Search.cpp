#include <regex>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include "FileManager.h"
using namespace std;

int analyz(string str, regex reg) {
	string lines = str;
	cmatch result;
	int size = lines.length();
	int out = 0;
	for (int i = 0; ; i++) {
		regex_search(lines.c_str(), result, reg);

		lines = result.suffix();
		if (size == lines.length()) break;

		out++;
		size = lines.length();
	}
	return out;
}

int main()
{
    setlocale(LC_CTYPE, "rus");

	FileManager file;
	file.setPath("file.txt");

	string* lines = file.readFromFile();
	
	regex sg("[йфцчвскмпнртгшлщдзжх][яыуаеёиоьъэ]");
	regex gg("[яыуаеёиоьъэ][яыуаеёиоьъэ]");
	regex ss("[йфцчвскмпнртгшлщдзжх][йфцчвскмпнртгшлщдзжх]");

	int pattern1 = 0;
	int pattern2 = 0;
	int pattern3 = 0;

	int len = file.length();
	for (int i = 0; i < len; i++) {
		pattern1 += analyz(lines[i], sg);
		pattern2 += analyz(lines[i], gg);
		pattern3 += analyz(lines[i], ss);
	}
	cout << pattern1 << endl;
	cout << pattern2 << endl;
	cout << pattern3 << endl;
}
