//============================================================================
// Name        : autoMsg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "autoMsg.h"

struct dataInfo
{
public:
	dataInfo()
	{
		str = "test string";
	}
	string getStr(void)
	{
		return str;
	}

private:
	string str;

};

int main() {
	AutoMsg<dataInfo> testInst;
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string outStr = testInst->getStr();
	cout << "Output: "<<outStr << endl;
	return 0;
}
