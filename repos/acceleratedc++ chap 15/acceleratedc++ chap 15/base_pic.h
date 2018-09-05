#pragma once
#ifndef GUARD_base_h
#define GUARD_base_h


#include <iostream>
#include <vector>
#include<string>
#include"ptr.h"

class picture;
struct frame_opt {
	//WHY CANT I friend just the display frame function?
	friend class frame_pic;
	friend class picture;
public:
	frame_opt(const char& t, const  char& b, const char& l, const  char&r) :tp(t), btm(b), lf(l), rh(r) {  }
	operator bool();
private:
	char tp, btm, lf, rh;

};

frame_opt::operator bool() {
	if ((tp || btm || lf || rh) != 0) return true;
}

class base_pic {
	friend std::ostream& operator<< (std::ostream&, const picture&);

	friend class string_pic;
	friend class vcat_pic;
	friend class hcat_pic;
	friend class frame_pic;
	friend class picture;
	typedef std::vector<std::string>::size_type row;
	typedef std::string::size_type length;
	
	virtual length width() const = 0;
	virtual row height() const = 0;
	//q4 attempt to add 4th argument for display to indicate reframing
	virtual void display(std::ostream&, row, bool, const ptr<frame_opt>&) const =0;
	
	// to allow pad to be used by other derived classes of base_pic, without redefinign the function each time
protected:
	static void pad(std::ostream&, length, length);
	//ATTEMPT to add a pointer for all derived classes to add frame change option
	ptr<frame_opt> framechange2;
};

void base_pic::pad(std::ostream& os, length beg, length end) {while (beg++ != end) os << " ";}


#endif
