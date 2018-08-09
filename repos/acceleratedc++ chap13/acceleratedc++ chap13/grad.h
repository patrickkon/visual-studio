#ifndef GUARD_grad_h
#define GUARD_grad_h
#include <iostream>
#include "core.h"
#include <vector>
#include <string>
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
class grad : public core{
public:
	grad() :thesis(0){};
	grad(std::istream&cin) { read(cin); }

	std::istream& read(std::istream&);
	double grade()const;

private:
	double thesis;
	virtual grad* clone() { return new grad(*this); }

};

#endif




