#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <vector>
#include <string>
#include"core.h"
#include "grad.h"
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class student_info {
public: 
	student_info() :cp(0) {};
	student_info(std::istream&cin) { read(cin); }
	student_info(const student_info& s) :cp(0) {if(s.cp)cp = (*(s.cp)).clone(); }
	student_info& operator=(const student_info&);
	static bool compare(const student_info&, const student_info&);
	//i THINK i can leave destructor blank since it will know how to call delete pointer?
	~student_info() {};
	
	std::string findname() const { if (cp) return (*cp).name; else throw std::runtime_error("uninitialized student"); }
	std::istream& read(std::istream&);
	double grade()const;
	//double showgrade()const { return finalgrade; }
	//bool valid() const { return !homework.empty(); }
	//std::string errorstate;
	bool pass() const;
private:
	core * cp;
};



#endif



