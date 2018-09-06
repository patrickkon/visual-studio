#pragma once
#ifndef GUARD_vcatpic_h
#define GUARD_vcatpic_h

#include"base_pic.h"
//#include<vector>
class picture;    
#include<string>
#include"ptr.h"
#include<algorithm>
class vcat_pic : public base_pic {
	friend picture vcat(const picture&, const picture&);
	vcat_pic(const ptr<base_pic>& x, const ptr<base_pic>& y) :top(x), bottom(y) {}

	length width() const { return std::max(top->width(),bottom->width()); }
	row height() const {return top->height() + bottom->height();}
	void display(std::ostream&, row, bool, const ptr<frame_opt>& ) const;

	//ptr<frame_opt> framechange2;
	ptr<base_pic> top;
	ptr<base_pic> bottom;
};

void vcat_pic::display(std::ostream& os, row n, bool yes_pad, const ptr<frame_opt>& v = 0) const {
	base_pic::length sz = 0;

	if (n < top->height()) {
		if (framechange2) top->display(os, n, yes_pad, framechange2);
		else top->display(os, n, yes_pad,v); sz = top->width();
	}
	else if (n < height()) {
		if (framechange2)bottom->display(os, n - top->height(), yes_pad, framechange2);
		else bottom->display(os, n - top->height(), yes_pad,v); sz = bottom->width();
	}
	if (yes_pad) {
		pad(os, sz, width());
	}
}


#endif