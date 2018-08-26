#include "stdafx.h"
#include "graderange.h"
#include <map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/* bool range(const int& s) {
	if (s < 60) {
		return s < 60;
	}
	
} */

char gradediscern(const int& s) {
	if (s < 60) {
		return 'F';
	}
	if (90 <= s && s <= 100) return 'A';
	if (80 <= s && s <= 89.99) return 'B';
	if (70 <= s && s <= 79.99) return 'C';
	if (60 <= s && s <= 69.99) return 'D';
	else {
		throw (domain_error) "Invalid grade";
	}
}


void store(gradestorage& col, vector<char>& c) {
	//need to use my bottom function as 3rd para? or char is fine
	sort(c.begin(), c.end());
	for (vector<char>::const_iterator iter = c.begin(); iter != c.end();iter++) {
		++col[*iter];
	}
	
	//return col;
}
void store2(vector<char>& c, const int& i) {
	c.push_back(gradediscern(i));
}


bool comparegrade(const char& x, const char& y) {
	return x < y;
}

//below is 2nd method for assigning letter grade, chap 10
string lettergrade(double grade) {
	static const double numbers[] =
	{
		90 ,80 ,70, 60, 50, 40, 0
	};
	static const char* alpha[] =
	{
		"A+", "A", "B", "C" , "D", "E", "F"
	};
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	for (size_t i = 0; i < ngrades; i++) {
		if (grade >= numbers[i]) return alpha[i];
	}
	return "\?\?\?";
}