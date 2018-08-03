#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include<algorithm>
#include <iostream>
//shoud incldue iostream?
#include "grammar.h"
using namespace std;


bool space(const char& c) {
	return isspace(c);
}

bool notspace(const char& c) {
	return !isspace(c);
}


vector<string> splitter(const string& s) {
	vector<string> words;
	string::const_iterator iter = s.begin();
	while (iter != s.end()) {
		iter = find_if(iter, s.end(), notspace);
		string::const_iterator spaceiter = find_if(iter, s.end(), space);
		if (iter != s.end())
			words.push_back(string(iter, spaceiter));
		iter = spaceiter;
	}
	return words;

}



grammar reader(istream& cin) {
	grammar thegrammar;
	string x;
	
	while (getline(cin, x)) {
		vector<string> entry = splitter(x);
		thegrammar[entry[0]].push_back(vector<string>(entry.begin() + 1, entry.end()));

		}
	return thegrammar;
	}
	
