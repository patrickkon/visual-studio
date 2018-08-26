#include "stdafx.h"
//#include "student_info.h"
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include <stdexcept>
#include"median.h"
#include "core.h"
#include"grad.h"
using std::istream;   using std::vector; using std::string;

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

istream& core::read(istream&is) {
	is >> name >> midterm >> final;
	read_hw(is, homework);
	
	return is;
}



istream& grad::read(istream&is) {
	is >> name >> midterm >> final;
	is >> thesis;
	read_hw(is, homework);

	return is;
}

double grade(double midterm, double finals, double median) {
	return midterm * 0.2 + finals * 0.4 + median * 0.4;
}

double core::grade() const {

	double dude = median(homework);
	//std::cerr << "core::grade" << std::endl;
	return ::grade(midterm, final, dude);
}

double grad::grade() const {
	//in this case, cerr will output first. but in the case of grad(istream) constructor, it will automatically 
	//call core default constructor first before outputting cerr
	//std::cerr << "grad::grade" << std::endl;
	double dude = core::grade();
	
	return std::min(dude, thesis);
}