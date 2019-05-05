#include <vector>
#include <stdio.h>
#include <iostream>
#include "fib_seq.h"

using namespace std;

vector<int> fib_seq::seq;

int read() {
	int n;
	cin >> n;
	return n;
}

int main() {
	int n = read();
	fib_seq once;
	cout << once.getValue(n) << endl;
	system("PAUSE");
	return 0;
}