#ifndef DICTIONATY_H_
#define DICTIONATY_H_

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

class Dictionary
{
	public:
		Dictionary(); // default open "words" file
		Dictionary(const string filename);
		
		const bool check(const string word) const;
	
	private:
		set<string> words;
		
		void constructor(const string filename);
		void addWord(const string word);
};

#endif // DICTIONATY_H_
