#pragma once
#ifndef GUARD_stringpic_h
#define GUARD_stringpic_h

#include"base_pic.h"
#include<vector>
//#include"picture.h"
#include<string>
#include<algorithm>
class string_pic : public base_pic {
	friend class picture;
	string_pic(const std::vector<std::string>& pic) :p(pic) { }

	length width() const ;
	row height() const { return p.size(); }
	void display(std::ostream&, row, bool, const ptr<frame_opt>& ) const;


	std::vector<std::string> p;
};

base_pic::length string_pic::width() const{
	base_pic::length n = 0;
	for (base_pic::row i = 0; i < p.size(); i++)
		n = std::max(n, p[i].size());
	return n;
}

void string_pic::display(std::ostream& os, row n, bool yes_pad, const ptr<frame_opt>& =0) const {
	base_pic::length sz = 0;
	if (n < p.size()) {
		os << p[n];
		sz = p[n].size();
	}
	if (yes_pad)
		pad(os, sz, width());
}

#endif
