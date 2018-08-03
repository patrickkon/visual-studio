#include "stdafx.h"
#include<string>
#include<algorithm>
#include<cctype>
//for noturlchar
#include"url_end.h"

//for typedef of iter
#include"url_beg.h"


using namespace std;

string::const_iterator url_beg(string::const_iterator& beg, string::const_iterator& end) {
	static const string urlswag = "://";
	typedef string::const_iterator iter;
	iter begin = beg; 
	while ((begin = search(begin, end, urlswag.begin(), urlswag.end()) )!= end) {
		iter temp = begin;
		/*
		1. iterator moved, and not stayed at beg
		2. check if after :// , it is the end of string. i.e. no char after ://
		3. check if after :// ,  it is a valid url char
		*/
		if (begin != beg && begin + urlswag.size() != end && !noturlchar(*(begin +urlswag.size())) && isalpha(*(begin - 1))) {
			//pos of start iterator
			while (begin != beg && isalpha(*(begin - 1))) {
				begin--;
			}
			return begin;
			/*if there is at least one alphanum behind ://      .UPDATE: ALREADY included in last part of above if statment
			if (begin != temp) return begin;
			*/
		}
		if (begin != end) begin += urlswag.size();

		
	}
	return end;
}
