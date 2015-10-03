#include <iostream>
#include <assert.h>
using namespace std;

//int main()
//{
//	int maxN = 0;
//	cout << "Введите maxN:";
//	cin >> maxN;
//
//	// Заведем массив под решето и проинициализируем
//	bool* isPrime = new bool[maxN + 1];
//	for( int i = 0; i <= maxN; i++) {
//		isPrime[i] = true;
//	}
//
//	// Вычеркнем составные числа
//
//	for(int i = 2; i <= maxN; ++i) {
//		if (isPrime[i]) {
//			for (int j = 2*i; j <= maxN; j += i) {
//				isPrime[j] = false;
//			}
//		}
//	}
//
//	// Результат
//
//	for(int i = 1; i < maxN; ++i) {
//		if (isPrime[i]) {
//			cout << i << ' ';
//		}
//	}
//
//	delete[] isPrime;
//
//	return 0;
//}

bool isPrime(long long n){
	for(long long i=2; i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

int main() {

	int n = 0;
	cin >> n;
	assert(n > 0);

	for (int i = 2; i <= n; ++i)
	{
		if(isPrime(i)) {
			if (n % i == 0)
			{
				cout << i << ' ';
				n /= i;
				i = 1;
			}
		}
	}
}