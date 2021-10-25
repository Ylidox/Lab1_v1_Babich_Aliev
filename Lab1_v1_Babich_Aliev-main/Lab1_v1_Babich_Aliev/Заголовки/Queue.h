#pragma once
#include <vector>
#include <string>
using namespace std;
class Queue
{
private:
	vector<char> listActions;
public:
	Queue() {
		listActions = {};
	}
	void push(char c) {
		listActions.push_back(c);
	}
	char shift() {
		return listActions.at(listActions.size() - 1);
	}
};

