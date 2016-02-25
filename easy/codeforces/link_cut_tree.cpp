#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{	
	unsigned long long int l, r, val;
	int k;
	bool no_res = true;
	std::cin >> l >> r >> k;

	val = 1;
	while(true){
		if (val >= l){no_res = false; std::cout << val << std::endl;}
		if (val > r/k){if (no_res) std::cout<<-1<<std::endl; break;}
		else val*=k;
	}

	return 0;
}
