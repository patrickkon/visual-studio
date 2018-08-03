#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "intLengthCalc.h"
using std::vector; using std::string; using std::max;

// MAYBE SHOULD INCLUDE STRING HEADER? BUT READ THAT IOSTREAM MIGHT DECLARE STRING. edit :declared

//returns maxlength amongst inputs
int reader(std::istream& s, std::vector<double>& num, vector<string>& character, vector<double>& containcrap ) {
	num.clear();
	int maxnumlength;
	maxnumlength = 0;

	string::size_type maxcharacterlength;
	maxcharacterlength = 0;

	int maxlen;
	maxlen = 0;
	//should i initialize i with 0 at same time, can its value be changed when i increment?
	int i = 0;
	while (s) {
		double x;
		string ss;
		
		
		
		if (s >> x) {
			num.push_back(x);
			maxnumlength = max(maxnumlength, intlength(x));
		}
		else {
			
			s >> ss;
			character.push_back(ss);
			maxcharacterlength = max(maxcharacterlength, ss.size());
			containcrap.push_back(i);
		}
		
		i++;

	}
	s.clear();
	if (maxcharacterlength > maxnumlength) maxlen = maxcharacterlength;
	else maxlen = maxnumlength;



	return maxlen;
}
