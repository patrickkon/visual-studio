#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include<stdexcept>
#include<string>
#include<iostream>
template<class g>g* clone(const g* s) {
	return s->clone();
}
//#include"core.h"
//#include "grad.h"
//DID NOT INCLUDE STRING! MIGHT CAUSE PROBLEMS? yup >> next to "is" , in this .cpp source file would not work.
template<class T> class ptr {
public:
	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			cp = cp ? clone(cp) : 0;
		}
	}

	ptr() :cp(0),refptr(new size_t(1)) {}
	
	ptr(const ptr& s) :cp(s.cp), refptr(s.refptr) { ++*refptr; }
	ptr( T* s) :cp(s), refptr(new size_t(1)) {}

	ptr& operator=(const ptr&);
	~ptr();

	operator bool() const{ return cp; }
	T& operator*() const { if (cp) return *cp;  throw std::runtime_error("unbound ptr"); }
	T* operator->() const {if (cp)return cp; throw std::runtime_error("unbound ptr");}
	
	
	//static bool compare(const ptr&, const ptr&);


private:
	T* cp;
	size_t* refptr;
};



#endif




