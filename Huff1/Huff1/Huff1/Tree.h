#pragma once
#include "Node.h"
#include <algorithm>

class Tree {
private:
	Node * root;
	std::vector<Node*> data;
	void reform_once() {
		Node *temp;
		if (data.size() != 1) {
			temp = new Node(*data[data.size() - 1] + *data[data.size() - 2]);
//			data[data.size() - 1]->setCode("1");
//			data[data.size() - 2]->setCode("0");
			data.pop_back();
			data.pop_back();
			data.push_back(temp);
			root = data[data.size() - 1];
		}
	}
	void reorder_once() {
		Node* temp;
		for (int i = 0; i < data.size();++i){
			for (int j = i + 1; j < data.size(); ++j) {
				if ((*data[j]).getFreq() > (*data[i]).getFreq()) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
		
	}
public:
	std::vector<std::pair<char, std::string>> huff_table;
	Tree(dict input) {
		Node* temp;
		for (int i = 0; i < input.size(); ++i) {
			temp = new Node(input[i]);
			data.push_back(temp);
		}
		root = data[data.size() - 1];
	}
	void reform_all() {
		int n = data.size();
		reorder_once();
		for (int i = n; i != 1; --i) {
			reform_once();
			reorder_once();
		}
		root->setCode("0");
	}

	Node * getRoot() const {
		return root;
	}

	void down_code(Node * start, std::string s ="") {
		start->add_to_Code(s);
		if (start->getRight() == nullptr && start->getLeft() == nullptr) {
			return;
		}
		if (start->getLeft() != nullptr) down_code(start->getLeft(), s + "0");
		if (start->getRight() != nullptr) down_code(start->getRight(), s + "1");
	}

	void create_huff(const Node* start) {
		if (start->getRight() == nullptr && start->getLeft() == nullptr) {
			huff_table.push_back(std::make_pair(start->getSymb(), start->getCode()));
			return;
		}
		if (start->getLeft() != nullptr) create_huff(start->getLeft());
		if (start->getRight() != nullptr) create_huff(start->getRight());
	}

	std::vector<std::pair<char, std::string>> getHuff() {
		return huff_table;
	}

	void delete_Tree(Node * start) {
		if (start->getRight() == nullptr && start->getLeft() == nullptr) {
			delete start;
			return;
		}
		if (start->getLeft() != nullptr) delete_Tree(start->getLeft());
		if (start->getRight() != nullptr) delete_Tree(start->getRight());
		delete start;
	}

	~Tree() {
		this->delete_Tree(this->root);
	}

};