#include <iostream>

float average(int *a, int n)
{
	int sum = 0;
	int i;
	for (i = 0; i < n; ++i)
		sum += a[i];
	return sum / (float)n;
}

void input_matrix(int m[][2], int n)
{
	
	std::cout << "Input " << n << " by " << n << "Matrix in row order ->";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> m[i][j];
	
	std::cout << std::endl;
}

void print_matrix(int m[][2], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			std::cout << m[i][j] << std::endl;
	}
}

void multiply_matrix(int m1[][2], int m2[][2], int m3[][2], int n)
{
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			m3[i][j] = 0;
			for (int k = 0; k < n; ++k)
				m3[i][j] += m1[i][k] * m2[k][j];
		}
}

int main()
{
	/*const int max = 10;
	int array[max]{};
	int array2[3][3] =
	{ { 1, 2, 3},
		{4, 5, 6},
		{7, 8, 9} };

	std::cout << "Input " << max << " integer " << std::endl;
	for (int i = 0; i < max; ++i)
		array[i] = i + 1;

	std::cout << "Average of " << max << " interger is " << average(array, max) << std::endl;

	
	std::cout << average((*array2), 4);*/

	int mat1[2][2];
	int mat2[2][2];
	int mat3[2][2];

	input_matrix(mat1, 2);
	input_matrix(mat2, 2);

	multiply_matrix(mat1, mat2, mat3, 2);

	std::cout << std::endl << "Answer : ";
	print_matrix(mat3, 2);
}