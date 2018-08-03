#include "stdafx.h"
#include <cctype>


//for categorizer(1,2) structure inclusion 
#include "substractor.h"

using namespace std;

bool charcomp(const categorizer2& x, const categorizer2& y) {
	return x.word2.front() < y.word2.front();
}
bool lowerchar(const categorizer2& x) {
	return islower(x.word2.front());
};

bool seccharcomp(const categorizer2& x, const categorizer2& y) {
	return x.word2[1] < y.word2[1];
}


bool charcomp2(const categorizer2& x, const categorizer2& y) {
	bool checker;
	/*if (x.word2.front() != y.word2.front()) {
		checker = x.word2.front() < y.word2.front();
	}
	else {    
	*/
		int i;
		for (i = 0;  i != y.word2.size() && i!= x.word2.size() && x.word2[i] == y.word2[i]  ; i++);

		checker = x.word2[i] < y.word2[i];
	
	return checker;
}