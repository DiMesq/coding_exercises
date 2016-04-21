#include <iostream>
#include <vector>

bool isprime(int t){

	if (t == 1) return false;
	else if (t<4) return true;

	if (t%2 == 0 || t%3 == 0) return false;

	int i = 5;
	while (i*i <= t){
		if (t%i == 0 || t%(i+2) == 0) return false;
		i+=6;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	long long int m, n;
	int t, negative = -1;

	std::cin >> t;

	for (int i = 0; i<t; i++){

		std::cin >> m >> n;

		for (int j = m; j <= n; j++){

			if (isprime(j)) v.push_back(j);
		}

		v.push_back(negative);
	}

	for (int i = 0; i < v.size(); i++){
		v[i] == negative ? printf("\n") : printf("%d\n", v[i]);
	}

	return 0;
}

