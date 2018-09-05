// acceleratedc++ chap 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "picture.h"
#include<ostream>
#include<vector>
#include<string>

int main()
{
	 std::vector<std::string> bro;
	 bro.push_back("sir");
	 bro.push_back("mae");
	 picture p = bro;
	 //string_pic works

	 picture framed = frame(p);
	 //frame works

	 picture vcated = vcat(framed, p);
	 // vcat works

	 picture hcated = hcat(framed, p);
	 //hcat works
	 char b = 'v';
		
	 hcated.reframe(b,b,b,b);
	 //does not work.. im thinking becasue has to be applied to picture sent to cout
	//std::cout << frame(hcat(framed, vcat(hcated, vcated)));

	//will do based on above comment ...
	picture last = frame(hcat(framed, vcat(hcated, vcated)));
	//UNDO BELOW COMMENT FOR OVERRDING of previous reframe changes
	//last.reframe(b, b, b, b);
	std::cout << last;
	//YESS got it to work...
	//now have to figure out how to reframe, and apply the chars to a picture not attached to cout 
    return 0;

};

