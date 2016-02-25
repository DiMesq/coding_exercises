#include <iostream>

int main(int argc, char const *argv[])
{
	int x;
	std::cin >> x;
	int step = int (x/5);

	if (x - step*5 != 0) step++;
	std::cout << step <<std::endl;
	return 0;
}