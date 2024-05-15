#include <iostream>
#include <chrono>
#include <math.h>
#include <ctime>

int is_prime1(int n)
{
	int i;
	for (i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int is_prime2(int n)
{
	int i, sqrn;
	sqrn = (int)sqrt(n);
	for (i = 2; i <= sqrn; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	/*int n;
	bool r;
	while (true)
	{
		std::cin >> n;

		auto t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; ++i)
		{
			r = is_prime1(n);
		}
		auto t2 = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "Elapsed time: " << duration << "" << std::endl;

		if (r)
			std::cout << "prime " << n << std::endl;
		else
			std::cout << "not prime " << n << std::endl;

		t1 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 1000; ++i)
		{
			r = is_prime2(n);
		}
		t2 = std::chrono::high_resolution_clock::now();

		duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		std::cout << "Elapsed time: " << duration << "" << std::endl;

		if (r)
			std::cout << "prime " << n << std::endl;
		else
			std::cout << "not prime " << n << std::endl;


	}*/

	int *iptr;
	int i, j;
	int max = 1000;

	iptr = new int[max] {};

	if (iptr)
	{
		clock_t start, finish;
		double duration;

		start = clock();

		for (i = 2; i < max; ++i)
		{
			if (iptr[i] == 1)
				continue;
			j = i;
			while ((j += i) < max)
				iptr[j] = 1;
		}

		for (i = 2; i <= max; ++i)
		{
			if (iptr[i] == 0)
				std::cout << i << " ";
		}

		finish = clock();

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		std::cout << duration << "ÃÊ" << std::endl;
	}
	

	clock_t start, finish;
	double duration;

	start = clock();

	for (int i = 1; i <= 1000; i++)
	{
		bool primeNumber = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				primeNumber = false;
				break;
			}
		}

		if (primeNumber)
		{
			std::cout << i << " ";
		}
	}

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	std::cout << duration << "ÃÊ" << std::endl;

	delete[] iptr;
	iptr = nullptr;
}

