#include <iostream>

using namespace std;

int find_neighbour(const int *first_arr, const int len, const int num);

int main()
{

	int n = 0;
	cin >> n;

	int* first_arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> first_arr[i];
	}

	int m = 0;
	cin >> m;

	int* second_arr = new int[m];
	for(int i = 0; i < m; ++i) {
		cin >> second_arr[i];
	}

	for (int i = 0; i < m; ++i) {
		second_arr[i] = find_neighbour(first_arr, n, second_arr[i]);
	}

	for (int i = 0; i < m; ++i) {
		cout << second_arr[i] << ' ';
	}

	return 0;
}

int find_neighbour(const int *first_arr, const int len, const int num) {
	int left_border = 0;
	int right_border = len - 1;
	for (int j = 0; j*j < len; ++j) {
		if (num < first_arr[0]) {
			right_border = 0;
			break;
		}

		if (num >= first_arr[left_border] && num <= first_arr[j*j]) {
			right_border = j*j;
			break;
		}
		else {
			left_border = j*j;
		}
	}

	// бинарным поиском ищем пару элементов, между которыми находится искомый элемент
	while((right_border - left_border) > 1) {
		if (num > first_arr[(right_border + left_border) / 2]) {

			left_border = (right_border + left_border) / 2;
		}
		else {
			right_border = (right_border + left_border) / 2;
		}
	}
	// необходима, если есть повторяющиеся элементы в первом массиве
	if (first_arr[left_border] == first_arr[right_border]) {
		return left_border;
	}
		// выясняем, к какому элементу ближе расположен искомый
	else {
		return (num - first_arr[left_border] <= first_arr[right_border] - num) ? left_border :
						right_border;
	}
}