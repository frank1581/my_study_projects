#include "utilities.h"

const std::multiset<char> make_set(const std::string& s) {
	std::multiset<char> str;
	for (int i = 0; i < s.size(); ++i) {
		str.insert(s[i]);
	}
	return str;
}

const dict make_dict(const std::multiset<char>& str) {
	std::multiset<char>::iterator it = ++str.begin();
	dict keys;
	char symb = *(str.begin());
	int count = 1;
	while( it != str.end()) {
		if (*it == symb) {
			++count;
			++it;
		}
		else {
			keys.push_back(std::make_pair(symb, count));
			count = 0;
			symb = *it;
		}
	}
	keys.push_back(std::make_pair(symb, count));
	return keys;
}
