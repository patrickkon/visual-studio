#ifndef guard_str
#define guard_str
#include"ptr.h"
#include "vec.h"
#include <algorithm>
#include<iostream>
#include <cstring>


class str {
	friend std::istream& operator>> (std::istream&, str&);
	friend std::istream& operator>> (std::istream&, str&);

public:
	//perhaps should remove () next to char?  (next line)
	str() :data(new vec<char>) {}
	str(const size_t& t, const char& val) : data(new vec<char>(t, val)) {};
	
	str(const char* chararray) :data(new vec<char>) {
		
		std::copy(chararray, chararray + strlen(chararray), std::back_inserter(*data));
	}
	
	template<typename id> str(id begin, id end): data(new vec<char>(begin, end)) {  }

	str& operator+=(const str& s) {
		data.make_unique();
		std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));
		return *this;
	}

	char& operator[](size_t t) { data.make_unique(); return (*data)[t]; }
	const char& operator[](size_t t) const { return (*data)[t]; }

	size_t size() { return data->size(); }


	char* begin() { return data->begin(); }
	char* end() { return data->end(); }

	// v1 according to book     str& operator+=(const str& );
	friend str operator+ (const str&, const str&);

	//const char* c_str();
	//std::istream& getline();
	operator bool();

private:
	ptr<vec<char>> data;
	
};

std::istream& operator>> (std::istream& in, str& s) {
	//not sure if btm line works
	s.data->~vec();
	char c;

	while (in.get(c) && isspace(c));
	if (in) {
		do s.data->push_back(c);
		while (in.get(c) && !isspace(c));
	}
	if (in)
		in.unget();
	
	return in;

};

std::ostream& operator<< (std::ostream& os, str& s) {
	// since  ostream operator << normally accepts char, but not your class str, so you define one that pushes chars within str one by one
	for (size_t t = 0; t != s.size(); t++) os << s[t];
	// this merely returns the state of os, that is.. is it cool or nay
	return os;
};


str operator+(const str& s, const str& s2) {
str temp = s;
temp += s2;
return temp;
}


str::operator bool() {
	return !((*this).data->begin() == (*this).data->end());
}



#endif