#include <iostream>
#include <stdexcept>

using namespace std;

void find_indexes_of_max_sum(int* arr_a, int* arr_b, int len, int &first_index, int &second_index);

int main()
{
	int n = 0;
	cin >> n;
	int* arr_a = new int[n];
	int* arr_b = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr_a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> arr_b[i];
	}

	int index_in_a, index_in_b;
	find_indexes_of_max_sum(arr_a, arr_b, n, index_in_a, index_in_b);
	cout << index_in_a << ' ' << index_in_b;
	delete [] arr_a;
	delete [] arr_b;
	return 0;
}

void find_indexes_of_max_sum(int* arr_a, int* arr_b, int len, int &first_index, int &second_index) {
	if (!arr_a || !arr_b) {
		throw std::invalid_argument("Null pointer to array.");
	}
	first_index = 0;
	second_index = 0;
	int index_max_in_a = 0;

	int max_first_sum = arr_a[first_index] + arr_b[second_index];

	for (int i = 1; i < len; ++i) {

		// ищем максимальный в первом массиве
		if (arr_a[i] > arr_a[index_max_in_a]) {
			index_max_in_a = i;
		}

		// если текущий во втором массиве больше, чем сохраненный, меняем
		if (arr_b[i] > arr_b[second_index]) {
			max_first_sum += -arr_b[second_index] + arr_b[i];
			second_index = i;
		}

		// если сумма максимального найденного в первом массиве и i-го во втором больше, меняем
		if(arr_a[index_max_in_a] + arr_b[i] > max_first_sum) {
			first_index = index_max_in_a;
			second_index = i;
			max_first_sum = arr_a[first_index] + arr_b[second_index];
		}
	}
}