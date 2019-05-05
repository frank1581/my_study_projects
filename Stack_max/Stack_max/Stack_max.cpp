#include <stack>
#include <iostream>
#include <set>
#include <string>

template <typename T>
class my_stack {
private:
	std::multiset <T, std::greater<T>> max_heap;
	std::stack <T> data;
public:
	void pop() {
		max_heap.erase(data.top());
		data.pop();
	}
	void push(const T& temp) {
		max_heap.insert(temp);
		data.push(temp);
	}
	int max() {
		return *(max_heap.begin());
	}
};

enum command { push = 0, pop = 1, max = 2 };

std::istream& operator >> (std::istream& in, command& s_enum) {
	std::string s;
	in >> s;
	if (s == "push") s_enum = push;
	if (s == "pop") s_enum = pop;
	if (s == "max") s_enum = max;
	return in;
}

int main() {

	int n, temp;
	std::cin >> n;
	command s;
	my_stack <int> data;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		switch (s) {
			case pop: {
			data.pop();
			break;
			}
			case push: {
			std::cin >> temp;
			data.push(temp);
			break;
			}
			case max: {
			std::cout << data.max() << std::endl;
			break;
			}
			default:{}
		}
	}
	system("pause");
	return 0;
}