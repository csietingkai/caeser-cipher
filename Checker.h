#ifndef CHECKER_H_
#define CHECKER_H_

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

#include "Decoder.h"
#include "Dictionary.h"

using namespace std;

class Checker
{
	public:
		Checker(); // default check english
		
		const bool isEnglish(const string article, string* result) const; // default check an article is english
		const bool isEnglish(const string article, string* result, Decoder d) const;
	
	private:
		Dictionary dictionary; 
		
		const string removeSign(string str) const; // modify content of str
};

#endif // CHECKER_H_
