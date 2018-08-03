#include "stdafx.h"
#include<vector>
#include "student_info.h"
#include<string>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include"grade.h"
#include <numeric>
#include "median.h"
using namespace std;
//all analysers contained here
double gradecalc(const student_info& student) {
	try {
		return	grade(student);
	}
	catch (domain_error) {
		return	grade(student.midterm, student.final, 0);
	}
}


double average_gradecalc(const student_info& student) {
	if (student.homework.empty()) {
		return grade(student.midterm, student.final, 0);
	}
	double homework = accumulate(student.homework.begin(), student.homework.end(), 0.0) / student.homework.size();
	return grade(student.midterm, student.final, homework);
}

double homeworkonly(const student_info& student) {
	vector<double> homeworkonly;
	remove_copy(student.homework.begin(), student.homework.end(), back_inserter(homeworkonly), 0);
	if (homeworkonly.empty()) {
		return grade(student.midterm, student.final, 0);
	}
	else {
		return grade(student.midterm, student.final, median(homeworkonly));
	}
}
//these 3 analayszers output median of their analysis of each student
double median_analysis(const vector<student_info>& student) {
	vector<double>grade;
	//for empty student vector, e.g. when no students are in "didnot" category( i.e. zero value present in homework vector)
	// WILL REPEAT THIS FOR THE NEXT TWO FUNCTIONS
	if (student.empty()) {
		return 0;
	}
	transform(student.begin(), student.end(), back_inserter(grade), gradecalc);
	return median(grade);
}

double average_analysis(const vector<student_info>& student) {
	vector<double> grade;
	if (student.empty()) {
		return 0;
	}
	transform(student.begin(), student.end(), back_inserter(grade), average_gradecalc);
	return median(grade);
}

double medianhw_only(const vector<student_info>& student) {
	vector<double>grade;
	if (student.empty()) {
		return 0;
	}
	transform(student.begin(), student.end(), back_inserter(grade), homeworkonly);
	return median(grade);
}


// following function is an attempt to create a template function for q8.1

double analysis(const vector<student_info>& student,  double t(const student_info&) ){
	vector<double>grade;
	if (student.empty()) {
		return 0;
	}
	transform(student.begin(), student.end(), back_inserter(grade), t);
	return median(grade);
}


// sample :write_analysis("Median of all(unmarked = 0, but included in calc of hw median)", median_analysis, cout, did, didnot);

/*  vl of write_analysis WORKS

void write_analysis(const string& title, double analyser(const vector<student_info>&), ostream& cout, 
	const vector<student_info>& did, const vector<student_info>& didnot) {
	cout << title << ": median(did) = " << analyser(did) << ", median(didnot) = " << analyser(didnot) << endl;
}

*/

/* v2 of write analysis (UNTESTED)

void write_analysis(const string& title, double analyser(const student_info&), ostream& cout, 
	const vector<student_info>& did, const vector<student_info>& didnot) {
	cout << title << ": median(did) = " << analysis(did,analyser) << ", median(didnot) = " << analyser(didnot) << endl;
}

*/

//v3 of write_analysis for q8.1
/* template<class s, class os, class cont>
void write_analysis(const s& title, double analyser(const cont<student_info>&), os& cout,
	const cont<student_info>& did, const cont<student_info>& didnot) {
	cout << title << ": median(did) = " << analyser(did) << ", median(didnot) = " << analyser(didnot) << endl;
}
*/