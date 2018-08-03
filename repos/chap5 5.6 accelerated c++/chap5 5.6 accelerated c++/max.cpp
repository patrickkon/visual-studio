#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string::size_type maxlen(const vector<string>& collection) {
	vector<string>::const_iterator iter = collection.begin();
	string::size_type maxlen = 0;
	while (iter != collection.end()) {
		maxlen = max(maxlen, (*iter).size());
		iter++;
	}
	return maxlen;
}