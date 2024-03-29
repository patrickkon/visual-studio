// acceleratedc++ chap 14.cpp : Defines the entry point for the console application.
//
// acceleratedc++ chap13.cpp : Defines the entry point for the console application.
//

// Chapter 4 accelerated c++.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "student_info.h"
#include <algorithm>
#include <iomanip>
#include<ios>
using namespace std;

using std::vector; using std::endl; using std::cout; using std::string; using std::cin; using std::max; using std::setw; using std::domain_error;
using std::left;
int main()
{
	vector<student_info> students;
	student_info record;
	string::size_type maxlen = 0;
	//core*p1 = new core;

	cout << "please enter your name,followed bty all the crap, and end of file" << endl;

	while (record.read(cin)) {
		maxlen = max(maxlen, record.findname().size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), student_info::compare);

	for (vector<student_info>::size_type i = 0; i < students.size(); i++) {
		cout << setw(maxlen + 1) << students[i].findname();
		cout << " ";
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();

			cout << setprecision(3) << final_grade << setprecision(prec) << "  ";
			//for chap13 q 4
			cout << students[i].letter_grade();
		}
		catch (std::domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}


	return 0;
}

