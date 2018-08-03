#include "stdafx.h"
#include "student_info.h"
#include <iostream>
#include <string>
#include <vector>
// NO NEED TO INCLUDE STRUCT OF STUDENT_INFO AGAIN! WOW

using std::istream;   using std::vector; using std::string;

istream& read(istream&is, student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	
	return is;
}

//WILL USING "is" again CAUSE PROBLEMS?

 istream& read_hw(istream &is, vector<double>& hw) {
	if (is) {
		hw.clear();
		double x;
		while (is >> x) 
			hw.push_back(x);
		is.clear();
		
	}
	return is;
}

bool compare(const student_info& x, const student_info& y) {
	return x.name < y.name;
}
