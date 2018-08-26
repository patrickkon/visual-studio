#ifndef GUARD_core_h
#define GUARD_core_h
#include <iostream>
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class core {
	 //friend class student_info;
public:
	core() :midterm(0),final(0) { /*std::cerr << "core() default constructor" << std::endl;*/ }
	core(std::istream&cin) { /*std::cerr << "core::core(istream)" << std::endl;*/ read(cin); }

	virtual ~core() {};
	

	std::string findname() const {  return name; }
	virtual std::istream& read(std::istream&);
	virtual double grade()const;
	//double showgrade()const { return finalgrade; }
	bool valid() const { return !homework.empty(); }
	
	virtual void regrade(double x, double =0) { final = x; }

	//std::string errorstate;
	//bool pass() const;
	template<class T>
	friend T* clone(T* x);
protected:
	std::string name;
	double midterm, final;
	std::vector<double> homework;
	virtual core* clone() { return new core(*this); }



	//double finalgrade;
	//std::istream& read_hw(std::istream &, std::vector<double>&);
};


#endif




