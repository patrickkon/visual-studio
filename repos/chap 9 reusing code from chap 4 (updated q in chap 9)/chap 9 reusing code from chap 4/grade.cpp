#include "stdafx.h"
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "median.h"
#include "student_info.h"
#include <stdexcept>
using namespace std;
using std::vector; using std::istream; using std::domain_error;

double grade( double midterm,  double finals,  double median) {
	return midterm * 0.2 + finals * 0.4 + median * 0.4;
}


double student_info::grade() const {

		 double dude=median(homework);
		 return ::grade(midterm, final, dude);
}


