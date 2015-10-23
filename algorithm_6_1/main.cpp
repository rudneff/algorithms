#include <iostream>

unsigned long int decomposition (unsigned long int **matrix, int n);

int main()
{
	int n = 0;
	std::cin >> n;
	unsigned long int **matrix;
	matrix = new unsigned long int *[n+1];
	for(int i=0; i<=n; i++)
	{
		matrix[i] = new unsigned long int [n+1];
	}
	std::cout << decomposition(matrix, n);
	for (int i = 0; i <= n; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

unsigned long int decomposition(unsigned long int **matrix, int n) {
    //начальная инициализация именно в таком порядке
	for (int i = 0; i <= n; i++)
	{
		matrix[i][1] = 1;
		matrix[1][i] = 1;
		matrix[i][0] = 0;
		matrix[0][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (i >= j) {
				matrix[i][j] = matrix[i-j][j] + matrix[i][j-1];

			} else
                // выше главной диагонали в строке одинаковые значения
			{
				matrix[i][j] = matrix[i][i];
			}
		}
	}
	return matrix[n][n];
}