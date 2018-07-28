#include <algorithm>
#include <iostream>
#include <random>

#include "common.h"

using namespace std;

const string toUpperCase(const string str)
{
	string re = str;
	
	for(int i = 0; i < re.length(); i++)
	{
		if(re[i] >= 'a' && re[i] <= 'z')
		{
			re[i] = re[i] - 'A' + 'a';
		}
	}
	
	return re;
}

const string toLowerCase(const string str)
{
	string re = str;
	
	for(int i = 0; i < re.length(); i++)
	{
		if(re[i] >= 'A' && re[i] <= 'Z')
		{
			re[i] = re[i] - 'A' + 'a';
		}
	}
	
	return re;
}

const string generateRandomString(const int length)
{
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	random_device rd;
	mt19937 g(rd());
	std::shuffle(alpha.begin(), alpha.end(), g);
	return alpha.substr(0, length);
}
