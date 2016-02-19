#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

#define all(c) (c).begin(), (c).end()

int main(int argc, char const *argv[])
{
	long long int n, l=0, temp = 0, cnt = 0, sum = 0, i = 0;

	std::cin >> n;
	std::vector<long long int> v(n);
	while (i<n){
		std::cin >> v[i];
		sum += v[i++];
	}
	if (sum%3 != 0){std::cout << "0" << std::endl; return 0;}

	for (i = 0; i < n-1; i++){
		temp += v[i];
		if (3*temp/2 == sum) cnt += l;
		if (temp * 3 == sum) l++;
	}
	std::cout<<cnt<<std::endl;
	return 0;
}