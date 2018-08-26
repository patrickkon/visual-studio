#include <vector>
#include<string>
#include"student_info.h"
struct	passfail {
	//passfail assigner/constructor
	passfail(const std::vector<student_info>&);
	//readers of stored name collection
	std::vector<std::string> passreader()const { return pass; }
	std::vector<std::string> failreader()const { return fail; }
private:
	//name collection based on pass or fail
	std::vector<std::string> pass;
	std::vector<std::string> fail;
};
