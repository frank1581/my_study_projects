#include <iostream>
#include <vector>


static void merge(std::vector<long int>& buf, int left, int right, int middle, int& count) //слияние
{
	if (left >= right || middle < left || middle > right) return;
	if (right == left + 1 && buf[left] > buf[right]) {
		std::swap(buf[left], buf[right]);
		++count;
		return;
	}

	std::vector<long int> tmp(&buf[left], &buf[right] + 1);

	for (int i = left, j = 0, k = middle - left + 1; i <= right; ++i) {
		if (j > middle - left) {
			buf[i] = tmp[k++];
		}
		else if (k > right - left) {
				buf[i] = tmp[j++];
		}
		else {
			if (tmp[j] <= tmp[k]) {
				buf[i] = tmp[j++];
			}
			else {
				buf[i] = tmp[k++];
				count += middle - left - j + 1;
			}
		}
	}

}


void MergeSort(std::vector<long int>& buf, int left, int right, int& count) //сортировка
{
	if (left >= right) return;

	int middle = (right + left) / 2;

	MergeSort(buf, left, middle, count);
	MergeSort(buf, middle + 1, right, count);
	merge(buf, left, right, middle, count);
}



int main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0;
	std::cin >> n;
	std::vector<long int> A(n);

	for (int i = 0; i < n; i++)
		std::cin >> A[i];
	int count = 0;
	MergeSort(A, 0, n - 1, count);
	std::cout << count << std::endl;
	system("pause");
	return 0;
}