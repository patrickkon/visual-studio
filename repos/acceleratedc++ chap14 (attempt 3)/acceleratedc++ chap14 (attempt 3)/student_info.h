#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <iostream>
#include <vector>
#include <string>
#include"ptr.h"
#include"core.h"

//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class student_info {
public: 
	student_info()  { }
	student_info(std::istream& cin) { read(cin); }
	
	static bool compare(const student_info& x, const student_info& y) { return ptr<core>::compare(x.cp, y.cp); }
	//i THINK i can leave destructor blank since it will know how to call delete pointer?

	
	std::string findname() const { if (cp) return cp->findname(); else throw std::runtime_error("uninitialized student"); }
	std::istream& read(std::istream&);
	double grade()const;
	std::string letter_grade();
	void regrade(double final, double thesis = 0) { cp.make_unique(); cp->regrade(final, thesis); }

	//double showgrade()const { return finalgrade; }
	//bool valid() const { return !homework.empty(); }
	//std::string errorstate;
	//bool pass() const;
private:
	ptr<core> cp;
};



#endif



