#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
struct student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	
};

std::istream& read(std::istream&, student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const student_info&, const student_info&);


#endif



