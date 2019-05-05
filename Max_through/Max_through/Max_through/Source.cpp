#include <iostream>
#include <vector>
#include <queue>
#include <set>

int main() {
	int n, m;
	std::cin >> n;
	if (n == 0) return 0;
	std::vector <int> data(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}
	std::cin >> m;
	std::queue <int> window;
	std::multiset <int, std::greater<int>> max;
	for (int i = 0; i < n; ++i) {
		if (window.size() < m) {
			window.push(data[i]);
			max.insert(data[i]);
		}
		else {
			std::cout << *(max.begin()) << " ";
			auto it = max.find(window.front());
			max.erase(it);
			window.pop();
			window.push(data[i]);
			max.insert(data[i]);
		}
	}
	system("pause");
	return 0;
}