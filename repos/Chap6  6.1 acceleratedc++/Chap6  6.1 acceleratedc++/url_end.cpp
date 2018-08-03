#include "stdafx.h"
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

bool noturlchar(const char& c) {
	static const string urlchar= "~;/?:@=$&-_.+!*'(),";
	return (find(urlchar.begin(), urlchar.end(), c) == urlchar.end() && !isalnum(c));
}

string::const_iterator url_end(string::const_iterator& beg, string::const_iterator& end) {
	return find_if(beg, end, noturlchar);
}