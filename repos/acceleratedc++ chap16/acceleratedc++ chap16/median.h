#define _SCL_SECURE_NO_WARNINGS
#ifndef dog
#define dog

#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdexcept>
using namespace std;
double median(std::vector<double>);
//updated for q10.2,q10.3
template <class it>
double median( it begin,  it end) {
	
	 size_t	size = (end - begin);

	if (end ==begin) throw domain_error("The user did not do any homework");
	  double* temp = new double[size];
	copy(begin, end, temp);
	sort(temp,temp+size);
	double* mid = temp + size / 2;
	return (size % 2 == 0) ? ((*mid + (*(mid - 1))) / 2) : (*mid);


}
#endif