#pragma once
#ifndef GUARD_pic_h
#define GUARD_pic_h

#include"ptr.h"
#include"base_pic.h"
//#include <vector>
#include "string_pic.h"
#include "frame_pic.h"
#include "hcat_pic.h"
#include "vcat_pic.h"
#include <iostream>
#include <string>
#include<stdexcept>

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
	ptr<frame_opt> framechange;
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
		try {
			if (*(pic.framechange)) pic.p->display(os, sz, false, /*pic.framechange*/0);
		}
		catch(std::runtime_error v){
			pic.p->display(os, sz, false, 0);
			
		}
		os << std::endl;
	}
	return os;
}


#endif
