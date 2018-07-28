#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "Encoder.h"
#include "common.h"

using namespace std;

// constructors
Encoder::Encoder()
{
	srand(time(NULL));
	setShift(rand() % ALPHABET_AMOUNT);
	setRule();
}

Encoder::Encoder(const int shift)
{
	setShift(shift);
	setRule();
}

Encoder::Encoder(const string keyword)
{
	setShift(0);
	string keywordTemp = removeDuplicateChar(keyword);
	setRule(keywordTemp);
}

// other functions
const string Encoder::process(const string str) const
{
	string re = str;
	
	for(int i = 0; i < str.length(); i++)
	{
		auto findResult = rule.find(str[i]);
		if(findResult != rule.end())
		{
			re[i] = (char)(findResult->second);
		}
	}
	
	return re;
}

// private functions
void Encoder::setShift(const int shift)
{
	this->shift = shift;
	
	if(shift != 0)
	{
		this->keyword = "";
	}
}

void Encoder::setRule()
{
	char key;
	char value;
	for(int i = 0; i < ALPHABET_AMOUNT; i++)
	{
		key = 'a' + i;
		value = 'a' + i + shift;
		if(value > 'z')
		{
			value -= ALPHABET_AMOUNT;
		}
		rule.insert({key, value});
		rule.insert({key, value});
		//cout << key << " " << value << endl;
		
		key = 'A' + i;
		value = 'A' + i + shift;
		if(value > 'Z')
		{
			value -= ALPHABET_AMOUNT;
		}
		rule.insert({key, value});
	}
}

const string Encoder::removeDuplicateChar(const string str)
{
	string re = "";
	
	for(int i = 0; i < str.length(); i++)
	{
		if(re.find(str[i]) == string::npos)
		{
			re += str[i];
		}
	}
	//cout << re << endl;
	
	return re;
}

void Encoder::setRule(const string keyword) 
{
	char key;
	char value;
	int i = 0;
	
	string keywordTemp = toLowerCase(keyword);
	for(; i < keyword.length(); i++)
	{
		key = 'a' + i;
		value = keywordTemp[i];
		rule.insert({key, value});
		rule.insert({key-'a'+'A', value-'a'+'A'});
		//cout << key << ": " << value << endl;
	}
	
	value = keywordTemp[i-1];
	for(int j = 1; i < ALPHABET_AMOUNT; i++, j++)
	{
		// if find no key and value, then insert
		key = 'a' + i;
		value += 1;
		if(value > 'z')
		{
			value -= ALPHABET_AMOUNT;
		}
		while(keywordTemp.find(value) != string::npos)
		{
			value += 1;
		}
		//cout << key << ": " << (char)value << endl;
		rule.insert({key, value});
		rule.insert({key-'a'+'A', value-'a'+'A'});
	}
}
