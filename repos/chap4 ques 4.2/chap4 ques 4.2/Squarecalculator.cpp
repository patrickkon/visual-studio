#include "stdafx.h"

#include "Squarecalculator.h"

#include <stdexcept>
using std::domain_error;
double square(const double& s) {
	if (s > 100) {
		throw domain_error("The integer is more than 100");
	}
	return s * s;
	
}