#include "stdafx.h"

#include <vector>
#include <string>
#include <cctype>

using namespace std;

// for one line of input
void substractor(const string& s, vector<string>& collection) {
	typedef string::size_type dude;
	dude i = 0;
	
	while (i != s.size()) {
		string temp;
		while (i != s.size() &&  isspace(s[i])) {
			i++;
		}
		dude j = i;
		while (j != s.size() && !isspace(s[j])) {
			j++;

		}
		if (i != j) {
			temp = s.substr(i, j - i);
			collection.push_back(temp);
			i = j;
		}
	}
	
}
