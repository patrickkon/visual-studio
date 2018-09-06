#pragma once
#ifndef GUARD_hcatpic_h
#define GUARD_hcatpic_h
#include"base_pic.h"
//#include<vector>
class picture;
#include<string>
#include"ptr.h"
#include <algorithm>
class hcat_pic : public base_pic {
	friend picture hcat(const picture&, const picture&);
	hcat_pic(const ptr<base_pic>& x, const ptr<base_pic>& y) :left(x), right(y) { }

	length width() const { return left->width() + right->width(); }
	row height() const { return std::max(left->height(), right->height()); }
	void display(std::ostream&, row, bool, const ptr<frame_opt>& ) const;

	//ptr<frame_opt> framechange2;
	ptr<base_pic> left, right;
};

void hcat_pic::display(std::ostream& os, row n, bool yes_pad, const ptr<frame_opt>& v = 0) const {
	base_pic::row n2;
	base_pic::row n1;
	//base_pic::row longer;
	if (left->height() > right->height()) {
		n1 = n;
		if (n != 0) n2 = n - 1;
		else n2 = height();
	}
	else if(left->height()<right->height()){
		n2 = n;
		//if n==0 , some variable will not be initialized 
		if (n != 0)n1 = n - 1;
		else n1 = height();
	}
	else
	{
		n2 = n;
		n1 = n;
	}
		
	if (framechange2) {
		left->display(os, n1, n < right->height(), framechange2);
		right->display(os, n2, yes_pad, framechange2);
	}
	else {
		left->display(os, n1, n < right->height(), v);
		right->display(os, n2, yes_pad, v);
	}
}


#endif