#include <iostream>
#include <chrono>


int GcdMinus(int u, int v)
{
	while (u)
	{
		if (u < v)
		{
			int t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

int GcdModuls(int u, int v)
{
	while(v)
	{
		int t = u % v;
		u = v;
		v = t;
	}
	return u;
}

int GcdRecursion(int u, int v)
{
	if (v == 0)
		return u;
	else
		return GcdRecursion(v, u % v);
}

int main()
{
	auto t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; ++i)
	{
		GcdRecursion(1500, 30);
	}
	
	auto t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << "" << std::endl;

	t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; ++i)
	{
		GcdMinus(1500, 30);
	}

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << "" << std::endl;

	t1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 1000; ++i)
	{
		GcdModuls(1500, 30);
	}

	t2 = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Elapsed time: " << duration << "" << std::endl;
}