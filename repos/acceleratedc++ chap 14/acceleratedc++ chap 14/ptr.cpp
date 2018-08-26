#include "stdafx.h"
#include"ptr.h"

template<class T> ptr<T>::~ptr() {
	if (--*refptr == 0) {
		delete refptr;
		delete cp;
	}
}

template<class T>ptr<T>& ptr<T>::operator=(const ptr& s) {
	++*s.refptr;
	if (--*refptr == 0) {
		delete cp;
		delete refptr;
	}
	refptr = s.refptr;
	cp = s.cp;
	return *this;
}

template<class T> bool ptr<T>::compare(const ptr& x, const ptr& y) {
	return x->name() < y->name();
}
