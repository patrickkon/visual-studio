#include "stdafx.h"
#include <vector>
#include <string>
#include <map>
#include<algorithm>
#include "grammar.h"
#include "random_num_limit.h"
#include<stdexcept>
using namespace std;
//double grammar fine? probs not
/* V1

bool brackets(const string& s) {
	string::const_iterator iter = s.begin();
	return *iter == '<' && s[s.size() - 1] == '>';
}


//so that user can have the freedom of having his own grammar choice

void gen_aux(const grammar&g, const string& s, rule& words) {
	if (!brackets(s)) {
		words.push_back(s);
	}
	else {
		grammar::const_iterator iter = g.find(s);
		if (iter == g.end()) 
			throw (domain_error) "invalid category";
		category thatcat = (*iter).second;
		rule chosenrules = thatcat[randomnum_nolim(thatcat.size())];
		for (rule::const_iterator it = chosenrules.begin(); it != chosenrules.end(); it++) {
			gen_aux(g, *it, words);
		}
	}
	
}




vector<string> sengen(const grammar& g) {
	     vector<string> words;

	gen_aux(g, "<sentence>", words);
	return words;
}
*/
