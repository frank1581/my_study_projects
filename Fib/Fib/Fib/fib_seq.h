#pragma once
#include <vector>

using namespace std;


class fib_seq {
public:
	fib_seq() :size(2) {
		seq.push_back(1);
		seq.push_back(1);
	}

	int getSize() const {
		return size;
	}

	int getValue(int n);
private:
	int size;
	static vector<int> seq;
	void drawNext();
};






