#include "stdafx.h"
#include<vector>
#include "student_info.h"
#include<algorithm>

using namespace std;

bool didallhw(const student_info& student) {
	return find(student.homework.begin(), student.homework.end(), 0)==student.homework.end() && !student.homework.empty();
}

void sorter(const vector<student_info>& students, vector<student_info>& did, vector<student_info>& didnot) {
	vector<student_info> temp = students;
	vector<student_info>::iterator iter;
	iter = stable_partition(temp.begin(), temp.end(), didallhw);
	did=vector<student_info> (temp.begin(), iter);
didnot= vector<student_info> (iter, temp.end());
	
	/* while (iter != students.end()) {
		if (find((*iter).homework.begin(), (*iter).homework.end(), 0)== (*iter).homework.end() && !((*iter).homework).empty()) {
			did.push_back(*iter);
		}
		else didnot.push_back(*iter);
		iter++;
	} */
}