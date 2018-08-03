#include "stdafx.h"

#include <string>
#include <vector>
#include "max.h"
using namespace std;
vector<string> framer(const vector<string>& collection, string::size_type& maxlength ) {
	 maxlength = maxlen(collection);

	vector<string> top;
	string border(maxlength+4 , '*');
	top.push_back(border);
	
	vector<string>::const_iterator i = collection.begin();
	//not sure the next line will work . the line was : i=i+1 ..... YES IT WORKS. SO ITER CAN BE COMBINED WITH INTEGER;
	
	while (i != collection.end()) {
		string s;
		s = "* " + *i + string( " ", maxlength - (*i).size()) +" *";
		top.push_back(s);
		i++;
	}

	top.push_back(border);

	return top;
}