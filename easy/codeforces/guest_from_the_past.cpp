#include <iostream>

int main(int argc, char const *argv[])
{
	unsigned long long int n, a, b, c, x, res = 0;
	long long int remain;
	std::cin >> n >> a >> b >> c;

	if (a <= b-c){
		res = n/a;
	} else if (n >= b){
		x = (n-b) / (b-c);
		res = x+1;

		remain = n - (b-c)*res;
		if(remain < 0) std::cout << "bug" << std::endl;

		res += remain/a;

	} else{res=n/a;}

	std::cout << res << std::endl;

	
	return 0;
}