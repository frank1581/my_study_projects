#pragma once
#include "utilities.h"

class Node {
private:
	char symb;
	int freq;
	std::string code;
	Node* r_child;
	Node* l_child;
public:
	Node() : symb(),code(""),freq(0), r_child(nullptr), l_child(nullptr) {
	}
	Node(const std::pair<char, int>& element): code(""),symb(element.first),freq(element.second), r_child(nullptr), l_child(nullptr){
	}
	Node(Node&a, Node& b ): freq(a.freq+b.freq), r_child(&a), l_child(&b),code("") {
	}
	Node(const Node&a) : symb(a.symb),freq(a.freq), r_child(a.r_child), l_child(a.l_child),code(a.code) {
	}
	int getFreq() const {
		return freq;
	}

	char getSymb()  const {
		return symb;
	}
	std::string getCode() const {
		return code;
	}
	std::string& add_to_Code(std::string str) {
		code = str + code;
		return code;
	}
	std::string& setCode(std::string str) {
		code = str;
		return code;
	}

	Node * getLeft()  const {
		return l_child;
	}
	Node * getRight() const {
		return r_child;
	}
	Node operator+(Node& b) {
		return Node(*this, b);
	}
	Node operator =(const Node&b) {
		return Node(b);
	}
};
