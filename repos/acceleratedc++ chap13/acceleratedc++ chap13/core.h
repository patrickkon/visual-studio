#ifndef GUARD_core_h
#define GUARD_core_h
#include <iostream>
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class core {
public:
	core() {};
	core(std::istream&cin) { read(cin); }

	std::string findname() const { return name; }
	virtual std::istream& read(std::istream&);
	double grade()const;
	double showgrade()const { return finalgrade; }
	bool valid() const { return !homework.empty(); }
	//std::string errorstate;
	//bool pass() const;
protected:
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	double finalgrade;
	//std::istream& read_hw(std::istream &, std::vector<double>&);
};




bool compare(const student_info&, const student_info&);


#endif




