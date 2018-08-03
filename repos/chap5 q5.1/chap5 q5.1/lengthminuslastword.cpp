#include "stdafx.h"
#include <string>
using namespace std;
//returns index of last char before space 
string::size_type lengthminuslast(const string& s) {
	
	string::size_type length = s.find_last_of(" ");
	return length;
}