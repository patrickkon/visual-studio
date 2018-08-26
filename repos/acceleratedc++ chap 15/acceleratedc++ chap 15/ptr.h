#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include<stdexcept>
//#include"vec.h"
#include<string>
#include<iostream>

template<class T> T* clone(const T* s) {
	return s->clone();
}
/*
template<> vec<char>* clone(const vec<char>* s) {
	return new vec<char>(*s);
}
*/
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

	ptr() :cp(0), refptr(new size_t(1)) { }

	ptr(const ptr& s) :cp(s.cp), refptr(s.refptr) { ++*refptr; }
	ptr(T* s) :cp(s), refptr(new size_t(1)) {}

	ptr& operator=(const ptr& s){
		++(*(s.refptr));
		if (--*refptr == 0) {
			delete cp;
			delete refptr;
		}
		refptr = s.refptr;
		cp = s.cp;
		return *this;
	};
	~ptr(){
		if (--*refptr == 0) {
			delete refptr;
			delete cp;
		}
	};

	operator bool() const { return cp; }
	T& operator*() const { if (cp) return *cp;  throw std::runtime_error("unbound ptr"); }
	T* operator->() const { if (cp)return cp; throw std::runtime_error("unbound ptr"); }

	static bool compare(const ptr& x, const ptr& y) {
		return (x->findname())< (y->findname());
	}
	


private:
	T* cp;
	size_t* refptr;
};



#endif




