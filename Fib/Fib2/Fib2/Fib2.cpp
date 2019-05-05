#include <cassert>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class Fibonacci {
public:
	Fibonacci(int m = 1) {
		modd = m;
		values.push_back(0);
		values.push_back(1);
		setPeriod();
	}
	void setPeriod() {
		int a1 = 0;
		int a2 = 1;
		int temp;
		int l = 1;
		while (l != 6 * modd + 1) {
			temp = a2;
			a2 = (a1 + a2) % modd;
			values.push_back(a2);
			a1 = temp;
			l++;
			if (a2 == 0) break;
		}
		period = l;
	}




	int getValue(long int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (modd == 2) return (n - 1) % 2;
		return(values[n%period]);
	}



private:
	vector<int> values;
	int modd;
	int period;
};


int read_from() {
	long int n;
	cin >> n;
	return n;
}

int main() {
	long int n = 99999999999999999;
	int m = read_from();
	Fibonacci once(m);
	cout << once.getValue(n);
	system("PAUSE");
	return 0;
}