#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <string>
//for categorizer(1,2) structure inclusion 
#include "substractor.h"
#include "charComparor.h"
#include <cctype>
using namespace std;


//takes a vector that contains vectors within it, and lists out all the vector elements within within, and then sorts them according to alphebatical order
vector<categorizer2> sorter(const vector<categorizer>& col) {
	vector<categorizer2> words;
	int i = 0;
	for (int i = 0; i < col.back().line + 1; i++) {
		vector<string>temp;
		categorizer2 temp2;

		if (i == col[i].line) {
			temp = col[i].word;

			for (int j = 0; j < temp.size(); j++) {
				temp2.word2 = temp[j];
				temp2.line2 = i;
				words.push_back(temp2);
			}
		}
	}
	sort(words.begin(), words.end(), charcomp2);
	
	// place words with lower case first char first
	stable_partition(words.begin(), words.end(),lowerchar );
	
	return words;
}