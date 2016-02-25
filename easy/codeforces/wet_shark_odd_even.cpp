#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define all(c) (c).begin(), (c).end()

int main(int argc, char const *argv[])
{
	int n, i = 0;
	unsigned long long int sum, zero = 0;
	std::cin >> n;
	std::vector<unsigned long int> v(n);

	while (i < n) {std::cin >> v[i++];}

	std::sort(all(v));

	sum = std::accumulate(v.begin(), v.end(), zero);
	i = 0;
	if (sum % 2 != 0){
		while (true){
			if(v[i] % 2 != 0){ sum -= v[i]; break;}
			i++;
		}
	}
	std::cout << sum<< std::endl;

	return 0;
}