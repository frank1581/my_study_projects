#include "utilities.h"
#include "Node.h"
#include "Tree.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <set>

std::string transform_string(std::string s, std::vector<std::pair<char, std::string>> table) {
	std::string new_s = "";
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < table.size(); j++) {
			if (table[j].first == s[i]) {
				new_s += table[j].second;
				break;
			}
		}
	}
	return new_s;
}
int main() {
	std::string s;
	std::cin >> s;
	std::multiset<char> input = make_set(s);
	dict d = make_dict(input);
	Tree huff(d);
	huff.reform_all();
	huff.down_code(huff.getRoot());
	huff.create_huff(huff.getRoot());
	std::vector<std::pair<char, std::string>> table = huff.getHuff();
	int n = table.size();
	std::cout << n << " ";
	std::string new_s = transform_string(s,table);
	std::cout << new_s.size() << std::endl;
	for (int i = 0; i < table.size(); ++i) {
		std::cout << table[i].first << ":" << table[i].second << std::endl;
	}
	std::cout << new_s << std::endl;
	system("PAUSE");
}