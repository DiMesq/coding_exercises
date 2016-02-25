#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	std::vector<int> pos_diag(1999), neg_diag(1999);
	int n, x, y, diff, sum, res=0, pos_shift = 999, neg_shift = -2;
	std::cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d %d", &x,&y);

		diff=x-y;
		sum= x+y;

		if (pos_diag[diff+pos_shift] >0) {res+=pos_diag[diff+pos_shift];pos_diag[diff+pos_shift]+=1;}
		else pos_diag[diff+pos_shift] = 1;

		if (neg_diag[sum+neg_shift] >0) {res+=neg_diag[sum+neg_shift]; neg_diag[sum+neg_shift]+=1;}
		else neg_diag[sum+neg_shift] = 1;

	}

	std::cout << res << "\n";
	return 0;
}