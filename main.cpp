#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Encoder.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	string keyword = "jasfe";
	cout << keyword << endl;
	Encoder e(keyword);
	string str = "I am the bone of my sword.";
	str = e.process(str);
	cout << str << endl;
	
	return 0;
}
