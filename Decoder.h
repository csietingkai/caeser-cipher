#ifndef DECODER_H_
#define DECODER_H_

#include <iostream>
#include <unordered_map>

#include "common.h"

using namespace std;

class Decoder
{
	public:
		Decoder(); // we don't know how many shift will come
		Decoder(const int shift); // right shift how many alphabet
		Decoder(const string keyword);
				
		const string process(const string str) const;
	
	private:
		int shift = 0;
		string keyword = "";
		std::unordered_map<int, int> rule = {};
		
		const int ALPHABET_AMOUNT = 26;
		
		void setShift(const int shift);
		void setRule();
		const string removeDuplicateChar(const string str);
		void setRule(const string);
};

#endif // DECODER_H_
