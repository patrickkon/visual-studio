#ifndef babes
#define babes
#include<vector>
#include"student_info.h"
#include<string>
#include<iostream>
using namespace std;
double median_analysis(const std::vector<student_info>& );
double gradecalc(const student_info&);
double average_analysis(const std::vector<student_info>& );

double medianhw_only(const std::vector<student_info>& );


/* v1 of the code 

void write_analysis(const std::string& , double analyser(const std::vector<student_info>&), std::ostream& ,
	const std::vector<student_info>& , const std::vector<student_info>& );
	*/

// updated fpr q8.1


template<class s, class os,class cont>
void write_analysis(const s& title, double analyser(const cont&), os& cout,
	const cont& did, const cont& didnot) {
	cout << title << ": median(did) = " << analyser(did) << ", median(didnot) = " << analyser(didnot) << endl;
}
#endif
