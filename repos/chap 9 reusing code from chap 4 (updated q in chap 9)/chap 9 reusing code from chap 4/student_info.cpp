#include "stdafx.h"
#include "student_info.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
// NO NEED TO INCLUDE STRUCT OF STUDENT_INFO AGAIN! WOW

using std::istream;   using std::vector; using std::string;

student_info::student_info() : midterm(0), final(0) {};



istream& student_info::read(istream&is) {
	is >> name >> midterm >> final;
	read_hw(is, homework);
	//v2 following  lines are
	if(student_info::valid())finalgrade = grade();
	else {
		finalgrade = 0;
		errorstate = "invalid grade";
	}
	
	
/* v1
		try {
		finalgrade = grade();
	}
	catch (std::domain_error e) {
		errorstate = e.what();
		finalgrade = 0;
	}

*/
	return is;
}

//including read_hw in header file allows you to place read_hw below read, even though read uses read_hw 
istream& student_info::read_hw(istream &is, vector<double>& hw) {
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
	return x.findname() < y.findname();
}


