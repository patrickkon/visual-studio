#ifndef GUARD_grad_h
#define GUARD_grad_h
#include <iostream>
#include "core.h"
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class grad : public core{
public:
	grad() :thesis(0) { std::cerr << "grad() default constructor" << std::endl; }
	grad(std::istream&cin) { std::cerr << "grad::grad(istream) " << std::endl; read(cin); }

	std::istream& read(std::istream&);
	double grade()const;

private:
	double thesis;
	grad* clone() { return new grad(*this); }

};

#endif




