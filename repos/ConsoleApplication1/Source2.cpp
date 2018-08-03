#include "stdafx.h"	
#include <iostream>
#include <string>

int main()
{
	{const std::string s = "a string";
	std::cout << s << std::end1;
	{const std::string s = "another string";
	std::cout << s << std::end1;
	}}
	return 0;
}
