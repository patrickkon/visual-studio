#include "stdafx.h"
#include "student_info.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "grad.h"
// NO NEED TO INCLUDE STRUCT OF STUDENT_INFO AGAIN! WOW

using std::istream;   using std::vector; using std::string;

student_info& student_info::operator=(const student_info& s) {
	if (this != &s) {
		delete cp;
		(*this).cp = (*(s.cp)).clone();
	}
	return *this;
}


istream& student_info::read(istream&is) {
	delete cp;
	char c;
	is >> c;
	if (c == 'U')
		cp = new core(is);
	else cp = new grad(is);
	
	return is;

}
double student_info::grade()const {
	if(cp)return (*cp).grade();
	else throw std::runtime_error("uninitialized student");
}

	
bool student_info::compare(const student_info& x, const student_info& y) {
	return x.findname() < y.findname();
}


