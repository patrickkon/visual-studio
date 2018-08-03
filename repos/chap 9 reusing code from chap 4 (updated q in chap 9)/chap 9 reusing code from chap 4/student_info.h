#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class student_info {
public: 
	student_info();
	student_info(std::istream&cin) { read(cin); }
	
	std::string findname() const { return name; }
	std::istream& read(std::istream&);
	 double grade()const;
	double showgrade()const { return finalgrade; }
	bool valid() const { return !homework.empty(); }
	std::string errorstate;
	bool pass() const;
private:
	std::string name;
	double midterm, final;
	std::vector<double> homework;	
	double finalgrade;
	std::istream& read_hw(std::istream &, std::vector<double>&);
};




bool compare(const student_info&, const student_info&);


#endif



