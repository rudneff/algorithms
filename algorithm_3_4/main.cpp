#include <iostream>

using namespace std;

int main()
{

	int n = 0;
	cin >> n;

	int first_arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> first_arr[i];
	}

	int m = 0;
	cin >> m;

	int second_arr[m];
	for(int i = 0; i < m; ++i) {
		cin >> second_arr[i];
	}

	for (int i = 0; i < m; ++i) {
		int left_border = 0;
		int right_border = n - 1;

		// бинарным поиском ищем пару элементов, между которыми находится искомый элемент
		while((right_border - left_border) > 1) {
			if (second_arr[i] > first_arr[(right_border + left_border) / 2]) {

				left_border = (right_border + left_border) / 2;
			}
			else {
				right_border = (right_border + left_border) / 2;
			}
		}
		// необходима, если есть повторяющиеся элементы в первом массиве
		if (first_arr[left_border] == first_arr[right_border]) {
			second_arr[i] = left_border;
		}
		// выясняем, к какому элементу ближе расположен искомый
		else {
			second_arr[i] = (second_arr[i] - first_arr[left_border] <= first_arr[right_border] - second_arr[i]) ? left_border :
					right_border;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << second_arr[i] << ' ';
	}

	return 0;
}