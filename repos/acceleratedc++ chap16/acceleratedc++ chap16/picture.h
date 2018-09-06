#pragma once
#ifndef GUARD_pic_h
#define GUARD_pic_h

#include"ptr.h"
#include"base_pic.h"
#include <vector>
#include "string_pic.h"
#include "frame_pic.h"
#include "hcat_pic.h"
#include "vcat_pic.h"
#include <iostream>
#include <string>
#include<stdexcept>
#include"student_info.h"

using std::vector;
using std::string;
//interface class
class picture {
	friend std::ostream& operator<< (std::ostream&, const picture&);
	friend picture frame(const picture &);
	friend picture vcat(const picture&, const picture&);
	friend picture hcat(const picture&, const picture&);
public:
	picture(const std::vector<std::string>& v = std::vector<std::string>() ) : p(new string_pic(v)) { }
	void reframe(const char& t, const char& b, const char& l, const char& r) {/* framechange = new frame_opt(t, b, l, r); */(*(*this).p).framechange2 = new frame_opt(t, b, l, r); }
private:
	picture( base_pic* pic) :p(pic) { }
	ptr<base_pic> p;
	
};


picture frame(const picture & pic) {
	return  new frame_pic(pic.p);
};



picture hcat(const picture& x, const picture& y) {
	return new hcat_pic(x.p, y.p);
}

picture vcat(const picture& x, const picture& y) {
	return new vcat_pic(x.p, y.p);
}

std::ostream& operator<< (std::ostream& os, const picture& pic) {
	for (base_pic::row sz = 0; sz != pic.p->height(); sz++) {
		pic.p->display(os, sz, false, 0);
		os << std::endl;
	}
	return os;
}

picture histogram(const std::vector<student_info>& students) {
	picture names;
	picture grade_symb;

	for (vector<student_info>::const_iterator i = students.begin(); i < students.end(); i++) {
		names = vcat(names, vector<string>(1, i->findname()));
		grade_symb = vcat(grade_symb, vector<string>(1, " " + string(i->grade() / 5, '=')));
	}

	return hcat(names, grade_symb);
}

#endif
