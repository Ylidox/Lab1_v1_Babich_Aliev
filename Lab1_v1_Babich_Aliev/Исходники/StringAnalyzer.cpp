#include "StringAnalyzer.h"
#include <string>
StringAnalyzer::StringAnalyzer(std::string expression) {
	this->expression = expression;
}

StringAnalyzer::StringAnalyzer() {
	expression = "";
}