#include <iostream>
#include <fstream>
#include <set>

#include "Dictionary.h"

using namespace std;

// constructors
Dictionary::Dictionary()
{
	constructor("words");
}

Dictionary::Dictionary(const string filename)
{
	constructor(filename);
}

// other functions
const bool Dictionary::check(const string word) const
{
	return words.find(word) != words.end();
}

// private functions
void Dictionary::constructor(const string filename)
{
	string word;
	ifstream dictionaryFile(filename);
	if(dictionaryFile.is_open())
	{
		while(!dictionaryFile.eof())
		{
			getline(dictionaryFile, word);
			addWord(word);
		}
		dictionaryFile.close();
	}
	else
	{
		throw invalid_argument("file no found");
	}
}

void Dictionary::addWord(const string word)
{
	words.insert(word);
}
