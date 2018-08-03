#include "stdafx.h"

#include "intLengthCalc.h"
#include <cmath>
int intlength(const double& s) {
	double x =s;
	int i = 0;
	while (x != 0) {
		x = floor(x / 10);
		i++;
	}
	return i;
}