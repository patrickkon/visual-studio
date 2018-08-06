#include <map>
#include<vector>
#include<string>
typedef std::map <  char, int> gradestorage;
void store(gradestorage&, std::vector <char>&);
char gradediscern(const int&);
void store2(std::vector<char>&, const int&);
// above is for method 1 : assigning letter grade

//below is 2nd method, chap 10
std::string lettergrade(double);