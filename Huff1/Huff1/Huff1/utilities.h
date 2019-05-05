#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <string>

typedef std::vector<std::pair<char, int>> dict;

const std::multiset<char> make_set(const std::string& s);

const dict make_dict(const std::multiset<char>&);

