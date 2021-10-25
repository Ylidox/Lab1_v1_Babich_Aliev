#pragma once
#include "PhysicalQuantity.h"
#include "string.h"
#include <vector>
using namespace std;
class Stack
{
private:
	vector< vector<double>> array;
	vector<char> listTypesElements;
public:
	Stack() {
		array = {};
		listTypesElements = {};
	}
	void push(double x, char type) {
		vector<double> q = { x, 0, 0 };
		listTypesElements.push_back(type);
		array.push_back(q);
	}
	void push(vector<double> &x, char type) {
		listTypesElements.push_back(type);
		array.push_back(x);
	}
	void push(double x, double y, double z, char type) {
		listTypesElements.push_back(type);
		vector<double> q = {x, y, z};
		array.push_back(q);
	}
	vector<double> pop() {
		vector<double> q = array.at( array.size() - 1);
		array.pop_back();
		listTypesElements.pop_back();
		return q;
	}
	char findTypeLastElement() {
		return listTypesElements.at(array.size() - 1);
	}
};

