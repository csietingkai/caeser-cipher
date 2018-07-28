#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

#include "Checker.h"
#include "Decoder.h"
#include "Dictionary.h"

using namespace std;

// constructors
Checker::Checker()
{
	
} 

// other functions
const bool Checker::isEnglish(const string article, string* result) const
{
	bool re = false;
	
	for(int i = 0; i < 26; i++)
	{
		Decoder d(i);
		isEnglish(article, result, d);
	}
	
	return re;
}

const bool Checker::isEnglish(const string article, string* result, Decoder d) const
{
	bool re = false;
	
	// remove sign like :'.,
	string articleTemp = article;
	articleTemp = removeSign(articleTemp);
	//cout << articleTemp << endl;
	
	articleTemp = d.process(articleTemp);
	//cout << articleTemp << endl;
	// string tokens
	vector<string> tokens;
	stringstream ss(articleTemp);
	string temp;
	while(getline(ss, temp, ' '))
	{
		tokens.push_back(temp);
	}
	//for(int i = 0; i < tokens.size(); i++)
	//	cout << tokens[i] << endl;
	
	// correct rate >= 0.8, this will be consider english
	int vocabularyAmount = tokens.size();
	int correctCounter = 0;
	double rate = 0.8;
	int correctLimit = vocabularyAmount * rate + 1;
	
	for(int i = 0; i < vocabularyAmount; i++)
	{
		if(dictionary.check(tokens[i]) == true)
		{
			correctCounter++;
		}
		if(correctCounter >= correctLimit)
		{
			re = true;
			break;
		}
	}
	if(re == true)
	{
		*result = articleTemp;
	}
	
	return re;
}

// private functions
const string Checker::removeSign(string str) const
{
	vector<char> toRemove;
	toRemove.push_back('\"');
	toRemove.push_back('\'');
	toRemove.push_back('\\');
	toRemove.push_back(',');
	toRemove.push_back('.');
	toRemove.push_back(':');
	toRemove.push_back(';');
	toRemove.push_back('-');
	toRemove.push_back('[');
	toRemove.push_back(']');
	toRemove.push_back('{');
	toRemove.push_back('}');
	toRemove.push_back('(');
	toRemove.push_back(')');
	
	//cout << toRemove.size() << endl;
	for(int i = 0; i < toRemove.size(); i++)
	{
		str.erase(remove(str.begin(), str.end(), toRemove[i]), str.end());
	}
	
	return str;
}
