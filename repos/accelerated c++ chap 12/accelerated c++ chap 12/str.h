#include "vec.h"
#include <algorithm>
#include<iostream>
#include <cstring>
class str {
public:
	str()  :tempdata(0) {};
	str(const size_t& t, const char& val) : data(t, val) {};
	
	str(const char* chararray) { 
		tempdata = 0;
		if (tempdata != 0) { delete[] tempdata; tempdata = 0; }
		std::copy(chararray, chararray + strlen(chararray), std::back_inserter(data));
	}
	/* version 1
	template<typename id> str(id begin, id end) {
		if (tempdata != 0) {
			delete[] tempdata; tempdata = 0;
		}
	std::copy(begin, end, std::back_inserter(data)); }
	*/

	//version 2
	template<typename id> str(id begin, id end) {data =vec<char>(begin, end); }

	char& operator[](size_t t) {
		if (tempdata != 0) {
			delete[] tempdata; tempdata = 0;
		}
	return data[t]; }
	const char& operator[](size_t t) const { return data[t]; }

	size_t size() { return data.size(); }
	friend std::istream& operator>> (std::istream&, str&);
	
	char* begin() { return data.begin(); }
	char* end() { return data.end(); }

	// v1 according to book     str& operator+=(const str& );
	friend str operator+ (const str& , const str& );

	const char* c_str();
	std::istream& getline();
	operator bool();
private:
	vec<char> data;
	char* tempdata;
};

std::istream& operator>> (std::istream& in ,str& s) {
	//not sure if btm line works
	s.data.~vec();
	char c;
	
	while (in.get(c) && isspace(c));
	if (in) {
		do s.data.push_back(c);
		while (in.get(c) && !isspace(c));
	}
	if(in)
	in.unget();
	if (s.tempdata != 0) { delete[] s.tempdata; s.tempdata = 0; }
	return in;

};

std::ostream& operator<< (std::ostream& os, str& s) {
	// since  ostream operator << normally accepts char, but not your class str, so you define one that pushes chars within str one by one
	for (size_t t = 0; t != s.size(); t++) os << s[t];
	// this merely returns the state of os, that is.. is it cool or nay
	return os;
};

/*
str& str::operator+=(const str& s) {
	//NOT SURE IF USING *this WILL WORK

	std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
	//ASSUMING tempdata as condition works
	if (tempdata != 0) {
		delete[] tempdata; tempdata = 0;
	}
	//testing std::cout << *tempdata;
	return *this;
	
}

str operator+(const str& s, const str& s2) {
	str temp = s;
	temp += s2;
	return temp;
}
*/

//add v2 of +  for QUESTION 
 str operator+ (const str& v1, const str& v2) {
	// friend function requires <T>

	//iterator temp =  new T[v1.size()+v2.size()];
	//std::copy(v1.begin(), v1.end(), std::back_inserter(*temp));
	//std::copy(v2.begin(), v2.end(), std::back_inserter(*temp));

	// not sure if returnign ref will cause probs: yes it will
	str temp = v1;
	std::copy(v2.data.begin(), v2.data.end(), std::back_inserter(temp.data));
	return temp;
}

 const char* str::c_str() {
	size_t size = (*this).data.size();
	tempdata = new char[size+1];
	char* last = std::uninitialized_copy((*this).data.begin(), (*this).data.end(), tempdata);
	*last = '\0';
	return tempdata;
}
//reference strcmp(const char * str1, const char * str2);
bool operator < ( str& s1,  str& s2) {
	return !strcmp(s1.c_str(), s2.c_str())   ;
}
bool operator > (str& s1, str& s2) {
	return strcmp(s1.c_str(), s2.c_str());
}

 str::operator bool() {
	return !((*this).data.begin() == (*this).data.end());
}

 std::istream& str::getline() {
	 char c;
	 if (std::cin) {
		
		 while (std::cin.get(c) && c != '\n') {
			 if(std::cin)
			 (*this).data.push_back(c);
		 }
		
	 }
	 return std::cin;
 }
