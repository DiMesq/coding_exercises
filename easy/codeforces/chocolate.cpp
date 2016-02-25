#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
	int n, cnt = 0, x;
	unsigned long long int res = 1;

	std::cin >>n;

	if (n==1){std::cin>>x; bool a = x==1; std::cout<< a << std::endl; return 0;}
	for (int i = 0; i<n; i++){
		std::cin >> x;

		if (x == 1){
			if (cnt!=0) res *= cnt;
			cnt = 1;
		} else if (x == 0 && cnt > 0) cnt++;
	}
	if (cnt==0) res = 0;
	std::cout << res << std::endl;
	return 0;
}