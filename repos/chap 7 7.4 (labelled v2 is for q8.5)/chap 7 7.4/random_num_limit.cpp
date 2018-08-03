#include "stdafx.h"
#include <cstdlib>

using namespace std;
int randomnum(const int& s) {
	int num;
	int bucket_num = RAND_MAX / s;
	do num = rand() / bucket_num;
	while (num >= s);
	return num;
}

int randomnum_nolim(const int& s) {
	int num
		 = rand();
	int power = s;
	//convert int to double?
	static_cast <double> (power);
	int store;
	if (s > RAND_MAX) store = 1;
	else return randomnum(s);
	while (power > RAND_MAX) {
		power = power / RAND_MAX;
		store++;
	}
	
	int i = 1;
	while (i != store) {
		num = num * rand();
		i++;
	}
	return num * randomnum(power);
}