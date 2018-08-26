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
	std::cerr << "operator =" << std::endl;
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


std::string student_info::letter_grade() {
	double grade = (*this).grade();
	static const double score[] = {97,94,90,97,84,80,77,74,70,60,0 };

	static const char* lettergrade[] = { "A+", "A","A-","B+","B", "B-","C+","C","C-","D","F" };

	static const size_t ngrades = sizeof(score) / sizeof(*score);

	for (size_t i = 0; i < ngrades; i++) {
		if (grade >= score[i])
			return lettergrade[i];
	}
	return "?\?\?"
		;
}