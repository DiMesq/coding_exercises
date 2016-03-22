#include <iostream>

int func(int n){
	int k = 1;
	while (k < n){
		k*=2;
		if (k>n) {k /= 2; break;}
	}
	return k;
}

int main(int argc, char const *argv[])
{
	int n, b, p, k = 1, n_games; 
	long long int bt = 0, pt = 0;

	scanf("%d %d %d", &n, &b, &p);
	pt = n*p;
	if (n == 1) {std::cout << 0 << " " << pt << std::endl; return 0;}

	while (n > 1){
		k = func(n);
		n_games = k/2;
		bt += (2*b+1)*n_games;
		n = k/2 + n-k;
		k/=2;
	}

	std::cout << bt << " " << pt << std::endl;
	return 0;
}