#define _SCL_SECURE_NO_WARNINGS

#include<iostream>
#include<memory>
#include<string>
#include"bidi_iterator.h"

using std::string;

class stringlist {
public:
	typedef bidi<string> iterator;
	typedef bidi< string const> const_iterator;
	stringlist() {create();}
	stringlist(const stringlist& s) { create(s); }
	~stringlist() { uncreate(); }
	iterator begin() { return data; }
	const_iterator begin() const{ return data; }
	const_iterator end() const { return fakelimit; }
	iterator end()  { return fakelimit; }

	void pushback(const string&);
	size_t size() const { return fakelimit - data; }

private:
	string* data;
	string* limit;
	string* fakelimit;
	std::allocator<string> alloc;
	void create();
	void create(const stringlist&);
	void uncreate();


};
