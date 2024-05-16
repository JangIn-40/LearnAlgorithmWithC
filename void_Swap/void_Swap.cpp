#include <iostream>

void swap(void *a, void *b, int n)
{
	char *temp = new char[n];

	if (temp)
	{
		std::memcpy(temp, a, n);
		std::memcpy(a, b, n);
		std::memcpy(b, temp, n);
	}

	delete[] temp;
}

int main()
{
	char c1 = 'A', c2 = 'B';
	int i1 = 100, i2 = 200;
	float f1 = 3.14, f2 = 2.71;

	std::cout << c1 << " " << c2 << std::endl;
	swap(&c1, &c2, sizeof(char));
	std::cout << c1 << " " << c2 << std::endl;

	std::cout << i1 << " " << i2 << std::endl;
	swap(&i1, &i2, sizeof(int));
	std::cout << i1 << " " << i2 << std::endl;

	std::cout << f1 << " " << f2 << std::endl;
	swap(&f1, &f2, sizeof(float));
	std::cout << f1 << " " << f2 << std::endl;
	return 0;
}