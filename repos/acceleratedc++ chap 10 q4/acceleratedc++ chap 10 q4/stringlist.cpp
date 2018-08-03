#include "stdafx.h"
#include"stringlist.h"
#include <iostream>

#include<algorithm>
#include<memory>

using std::string;

void stringlist::create() {
	
	data = limit = fakelimit = 0;

};
void stringlist::create(const stringlist& s) {
	data = new string[s.size()];
	limit=fakelimit = std::uninitialized_copy(s.begin(), s.end(), data);
};

void stringlist::uncreate() {
	// if(data)   <--- dont ned that because delete null pointer is harmless.
	delete [] data;
	data = limit = fakelimit = 0;
};


void stringlist::pushback(const string& s) {
	
	if(fakelimit==limit){
		ptrdiff_t sizes = limit - data;
		size_t size = std::max(2 * (sizes), ptrdiff_t(1));
		//char *buf = new char[sizeof(string)*size];
		string* tempstart = new string[size];
		
		if (size !=1) {
			std::copy(data, fakelimit, tempstart);
			delete[] data;
		}
		data = tempstart;
		fakelimit = data + sizes;
		limit = data + size;
	}
	alloc.construct(fakelimit++, s);
	
}

