#pragma once
#ifndef GUARD_framepic_h
#define GUARD_framepic_h
class picture;
#include <string>
#include "ptr.h"
#include "base_pic.h"
#include<stdexcept>
//#include<vector>


class frame_pic : public base_pic {
	friend picture frame(const picture&);
	frame_pic(const ptr<base_pic>& pic) :p(pic) { }

	
	length width() const {return p->width() + 4;}
	row height() const {return p->height() + 4;}
	void display(std::ostream&, row, bool, const ptr<frame_opt>& ) const;
	
	ptr<base_pic> p;
};

void frame_pic::display(std::ostream& os, row n, bool yes_pad, const ptr<frame_opt>& frame_change) const {
	 char t = '*';
	 char b = '*';
	 char l = '*';
	 char r = '*';
	 //this condition is needed because if this frame_pic wasnt the one reframed, but the 
	 // main picture that it is part of is reframed. then we can pass from main to here, and change its value
		if ((frame_change)) {
			t = frame_change->tp;
			b = frame_change->btm;
			r = frame_change->rh;
			l = frame_change->lf;
		} else if (framechange2) {
			t = framechange2->tp;
			b = framechange2->btm;
			r = framechange2->rh;
			l = framechange2->lf;
		}
	if (n >= height() &&  n >= 0) { if (yes_pad) pad(os, 0, width()); }
	else {
		
		if ((n == 0 || n == height() - 1)) { os << std::string(width(),t); }
		//not sure if os << single brackets works. ans works
		else if (n == 1 || n == height() - 2) { os << l; pad(os, 1, width() - 1); os << r; }
		else {
			os << l <<" ";
			p->display(os, n-2, true,/*frame_change*/ framechange2);
			os <<" "  <<r;
		}
	}
}


#endif
