#ifndef ENCODER_H_
#define ENCODER_H_

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "common.h"

using namespace std;

class Encoder
{
	public:
		Encoder(); // random shift 
		Encoder(const int shift); // right shift how many alphabet, ex: a -> b mean right shift 1 bit
		Encoder(const string keyword);
				
		const string process(const string str) const;
	
	private:
		int shift = 0;
		string keyword = "";
		std::unordered_map<int, int> rule = {};
		
		const int ALPHABET_AMOUNT = 26;
		
		void setShift(const int shift); // shift!=0 -> keyword=""
		void setRule(); // keyword!="" -> shift = 0
		const string removeDuplicateChar(const string str);
		void setRule(const string);
};

#endif // ENCODER_H_
