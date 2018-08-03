

#include<vector>
#include<map>
#include<string>

typedef std::vector<std::string> rule;
typedef std::vector <rule> category;
typedef std::map<std::string, category> grammar;

grammar reader(std::istream&);
