#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int arr_a[n];
	int arr_b[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr_a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> arr_b[i];
	}

	int index_in_a = 0;
	int index_max_in_a = 0;
	int index_in_b = 0;

	int max_first_sum = arr_a[index_in_a] + arr_b[index_in_b];

	for (int i = 1; i < n; ++i) {

		if (arr_a[i] > arr_a[index_max_in_a]) {
			index_max_in_a = i;
		}

		if (arr_b[i] > arr_b[index_in_b]) {
			max_first_sum += -arr_b[index_in_b] + arr_b[i];
			index_in_b = i;
		}

		if(arr_a[index_max_in_a] + arr_b[i] > max_first_sum) {
			index_in_a = index_max_in_a;
			index_in_b = i;
			max_first_sum = arr_a[index_in_a] + arr_b[index_in_b];
		}
	}
	cout << index_in_a << ' ' << index_in_b;
	return 0;
}