#include "fib_seq.h"

void fib_seq::drawNext() {
	seq.push_back(seq[size - 2] + seq[size - 1]);
	++size;
}

int fib_seq::getValue(int n) {
	if (size >= n) {
		return (seq[n - 1]);
	}
	else {
		for (int i = size; i < n; ++i) { drawNext(); }
	}
	return seq[size - 1];
}