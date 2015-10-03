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

	int index_first_max_in_a = 0;
	int index_first_max_in_b = 0;
	int index_max_in_a = 0;

	int max_first_sum = arr_a[index_first_max_in_a] + arr_b[index_first_max_in_b];
	for (int i = 1; i < n; ++i) {
		int temp_sum = arr_a[i] + arr_b[i];
		if (arr_a[i] > arr_a[index_first_max_in_a]) {
			index_max_in_a = i;
		}
		if(arr_a[i] > arr_a[index_first_max_in_a] && temp_sum > max_first_sum) {
			index_first_max_in_a = i;
			index_first_max_in_b = i;
			max_first_sum = temp_sum;
		}
		else if (arr_b[i] > arr_b[index_first_max_in_b])
		{
			max_first_sum -= arr_b[index_first_max_in_b];
			index_first_max_in_b = i;
			max_first_sum += arr_b[index_first_max_in_b];
		}

		if ( i >= index_max_in_a and arr_a[index_max_in_a]+arr_b[i] > max_first_sum) {
			max_first_sum = arr_a[index_max_in_a] + arr_b[i];
			index_first_max_in_a = index_max_in_a;
			index_first_max_in_b = i;
		}
	}
	cout << index_first_max_in_a << ' ' << index_first_max_in_b;
	return 0;
}