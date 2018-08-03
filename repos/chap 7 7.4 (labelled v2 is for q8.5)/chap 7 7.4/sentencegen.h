#include<vector>
#include<string>
#include "grammar.h"


#include <map>
#include<algorithm>

#include "random_num_limit.h"
#include<stdexcept>

using namespace std;
std::vector<std::string> sengen(const grammar&);

// EVERYTHING PROCEEDING THIS IS V2

bool brackets(const string& s) {
	string::const_iterator iter = s.begin();
	return *iter == '<' && s[s.size() - 1] == '>';
}

template <class it>
void gen_aux(const grammar&g, const string& s, it& iter) {
	if (!brackets(s)) {
		*iter++ = s;
	}
	else {
		grammar::const_iterator iters = g.find(s);
		if (iters == g.end())
			throw (domain_error) "invalid category";
		category thatcat = (*iters).second;
		rule chosenrules = thatcat[randomnum_nolim(thatcat.size())];
		for (rule::const_iterator its = chosenrules.begin(); its != chosenrules.end(); its++) {
			gen_aux(g, *its, iter);
		}
	}

}

template <class it>
void sengen(const grammar& g, it iter) {

	gen_aux(g, "<sentence>", iter);

}