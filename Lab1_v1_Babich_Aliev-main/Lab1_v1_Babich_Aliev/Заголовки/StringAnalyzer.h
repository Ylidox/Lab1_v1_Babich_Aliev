#pragma once
#include <string>
#include "ManagerStack.h"
#include <regex>
#include <vector>
#include <math.h>
#include "files.h"

using namespace std;
class StringAnalyzer
{
private:
	Stack stack;
	string expression;
public:
	StringAnalyzer(string expression);
	StringAnalyzer();
	
	string answer() {
		char type = stack.findTypeLastElement();
		vector<double> v = stack.pop();
		string out = "";
		if(type == 'm'){
			out += parseDouble(v[0]);
			out += "kg";
		}
		if (type == 'e') {
			out += parseDouble(v[0]);
			out += "J";
		}
		if (type == 'v') {
			out += parseDouble(v[0]);
			out += "xmps,";
			out += parseDouble(v[1]);
			out += "ymps,";
			out += parseDouble(v[2]);
			out += "zmps";
		}
		if (type == 'i') {
			out += parseDouble(v[0]);
			out += "xkgmps,";
			out += parseDouble(v[1]);
			out += "ykgmps,";
			out += parseDouble(v[2]);
			out += "zkgmps";
		}
		if (type == 'a') {
			out += parseDouble(v[0]);
			out += "xmpss,";
			out += parseDouble(v[1]);
			out += "ympss,";
			out += parseDouble(v[2]);
			out += "zmpss";
		}
		if (type == 'f') {
			out += parseDouble(v[0]);
			out += "xN,";
			out += parseDouble(v[1]);
			out += "yN,";
			out += parseDouble(v[2]);
			out += "zN";
		}
		return out;
	}
	string parseDouble(double& d) {
		return to_string(d);
	}
	void analyz() {
		string subExpression = expression;

		for (;;) {
			if (subExpression.length() == 0) break;
			string part = processingObjects(subExpression);
			
			if (part != "+" && part != "-" && part != "*" && part != "/")
				findQuantity(part);
			else {
				if (part == "+") summ();
				if (part == "*") multiply();
				if (part == "-") subtract();
				if (part == "/") divide();
			}
		}
	}
	void findQuantity(string str) {
		string local = str;

		cmatch result;
		regex number("[0-9]{1,}\.[0-9]{1,}");
		regex type("[a-z]{1,}");

		vector <double> d = { 0, 0, 0 };
		char phys;

		regex_search(str.c_str(), result, type);
		string s = result[0];
		if (s == "m") phys = 'h';
		if (s == "kg") phys = 'm';
		if (s == "J") phys = 'e';
		if (s == "xmps" || s == "ymps" || s == "ymps") phys = 'v';
		if (s == "xmpss" || s == "ympss" || s == "ympss") phys = 'a';
		if (s == "xN" || s == "yN" || s == "yN") phys = 'f';
		if (s == "xkgmps" || s == "ykgmps" || s == "zkgmps") phys = 'i';
		
		
		int size = local.length();
		for (int i = 0; ; i++) {
			regex_search(local.c_str(), result, number);

			if(result[0] != "") d[i] = stod(result[0]);

			local = result.suffix();
			if (size == local.length()) break;
			size = local.length();
		}

		stack.push(d[0], d[1], d[2], phys);
	}
	string processingObjects(string& str) {
		bool flag = true;
		bool bracket = false;
		string out = "";
		int i = 0;
		for (; i < str.size() && flag; i++) {
			if (str[i] == '(') bracket = true;

			if (bracket && str[i] != '(' && str[i] != ')') out += str[i];
			if (!bracket) {
				out += str[i];
				flag = false;
			}

			if (str[i] == ')') {
				bracket = false;
				flag = false;
			}
		}
		str.replace(0, i, "");
		return out;
	}
	void split(string str, string* out) {
		int index = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ','){
				index++;
				continue;
			}
			out[index] += str[i];
		}
	}

	double abs(vector<double> v) {
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}

	void summ() {
		char type1 = stack.findTypeLastElement();
		vector<double> quantyty1 = stack.pop();
		
		char type2 = stack.findTypeLastElement();
		vector<double> quantyty2 = stack.pop();
		if (type1 != type2) cout << "Invalid addition of values" << endl;
		
		vector<double> answer = {
			quantyty1[0] + quantyty2[0],
			quantyty1[1] + quantyty2[1],
			quantyty1[2] + quantyty2[2]
		};

		stack.push(answer, type1);
	}
	void subtract() {
		char type1 = stack.findTypeLastElement();
		vector<double> quantyty1 = stack.pop();

		char type2 = stack.findTypeLastElement();
		vector<double> quantyty2 = stack.pop();
		if (type1 != type2) cout << "Invalid subtraction of values" << endl;

		vector<double> answer = {
			quantyty2[0] - quantyty1[0],
			quantyty2[1] - quantyty1[1],
			quantyty2[2] - quantyty1[2]
		};

		stack.push(answer, type1);
	}

	void multiply() {

		char type1 = stack.findTypeLastElement();
		vector<double> quantyty1 = stack.pop();

		char type2 = stack.findTypeLastElement();
		vector<double> quantyty2 = stack.pop();

		if (type1 == 'm' && type2 == 'v' || 
			type1 == 'v' && type2 == 'm' || 
			type1 == 'i' && type2 == 'v' || 
			type1 == 'v' && type2 == 'i' || 
			type1 == 'f' && type2 == 'h' || 
			type1 == 'h' && type2 == 'f' || 
			type1 == 'm' && type2 == 'a' || 
			type1 == 'a' && type2 == 'm' ) {
		}else cout << "Invalid division of values" << endl;
			
		vector<double> answer = { 0,0,0 };
		
		if (type1 == 'm' && type2 == 'v' ||
			type1 == 'm' && type2 == 'a')
		{
			answer = {
				quantyty1[0] * quantyty2[0],
				quantyty1[0] * quantyty2[1],
				quantyty1[0] * quantyty2[2]
			};
		}else if (type1 == 'v' && type2 == 'm' ||
				  type1 == 'a' && type2 == 'm') {
			answer = {
				quantyty1[0] * quantyty2[0],
				quantyty1[1] * quantyty2[0],
				quantyty1[2] * quantyty2[0]
			};
		}else if ( type1 == 'i' && type2 == 'v' ||
				   type1 == 'v' && type2 == 'i') {
			double abs1 = abs(quantyty1);
			double abs2 = abs(quantyty2);
			answer = {
				abs1 * abs2, 0, 0
			};
		}else if (type1 == 'f' && type2 == 'h' ||
				  type1 == 'h' && type2 == 'f') {
			double abs1 = abs(quantyty1);
			double abs2 = abs(quantyty2);
			answer = {
				abs1 * abs2, 0, 0
			};
		}
		else {
			answer = {
				quantyty1[0] * quantyty2[0],
				quantyty1[1] * quantyty2[1],
				quantyty1[2] * quantyty2[2]
			};
		}

		char type = 'v';
		if (type1 == 'm' && type2 == 'v' || type1 == 'v' && type2 == 'm') type = 'i';
		if (type1 == 'i' && type2 == 'v' || type1 == 'v' && type2 == 'i') type = 'e';
		if (type1 == 'f' && type2 == 'h' || type1 == 'h' && type2 == 'f') type = 'e';
		if (type1 == 'm' && type2 == 'a' || type1 == 'a' && type2 == 'm') type = 'f';


		stack.push(answer, type);
	}
	void divide() {
		char type2 = stack.findTypeLastElement();
		vector<double> quantyty2 = stack.pop();

		char type1 = stack.findTypeLastElement();
		vector<double> quantyty1 = stack.pop();

		if (type1 == 'e' && type2 == 'v' ||
			type1 == 'i' && type2 == 'v' ||
			type1 == 'f' && type2 == 'a' ||
			type1 == 'i' && type2 == 'm' ||
			type1 == 'e' && type2 == 'p') {
		}
		else cout << "Invalid division of values" << endl;

		vector<double> answer = { 0,0,0 };

		if (type1 == 'e' && type2 == 'v' ||
			type1 == 'e' && type2 == 'i')
		{
			answer = {
				quantyty1[0] / quantyty2[0],
				quantyty1[0] / quantyty2[1],
				quantyty1[0] / quantyty2[2]
			};
		}else if (type1 == 'i' && type2 == 'v' ||
				  type1 == 'f' && type2 == 'a') {
			double abs1 = abs(quantyty1);
			double abs2 = abs(quantyty2);
			answer = {
				abs1 * abs2, 0, 0
			};
		}else if (type1 == 'i' && type2 == 'm') {
			answer = {
				quantyty1[0] / quantyty2[0],
				quantyty1[1] / quantyty2[0],
				quantyty1[2] / quantyty2[0]
			};
		}

		char type = 'i';
		if (type1 == 'e' && type2 == 'v') type = 'i';
		if (type1 == 'i' && type2 == 'v' ||
			type1 == 'f' && type2 == 'a') type = 'm';
		if (type1 == 'i' && type2 == 'm' ||
			type1 == 'e' && type2 == 'i') type = 'v';
		stack.push(answer, type);
	}
};

