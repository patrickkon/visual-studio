#include "stdafx.h"
#include"passfailclass q9.5-9.6.h"
#include<vector>
#include "student_info.h"
#include<algorithm>
using namespace std;
bool student_info::pass() const{
	return ((*cp).midterm + (*cp).final) / 2 > 60;
}

bool strcomp(const string& x, const string& y) {
	return x < y;
}

passfail::passfail(const std::vector<student_info>& students) {
	vector<student_info>::const_iterator iter = students.begin();
	while (iter != students.end()) {
		if ((*iter).pass()) pass.push_back((*iter++).findname());
		else fail.push_back((*iter++).findname());
	}
	sort(pass.begin(), pass.end(), strcomp);
	sort(fail.begin(), fail.end(), strcomp);
}
