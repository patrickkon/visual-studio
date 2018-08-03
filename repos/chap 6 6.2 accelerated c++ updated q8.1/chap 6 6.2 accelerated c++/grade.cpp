#include "stdafx.h"
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


double grade(const student_info& s) {
		 double dude=median(s.homework);
		 return grade(s.midterm, s.final, dude);
}


