#include <iostream>
#include <vector>
#include <cmath>

#define MAX_RANK 8

bool func(int p, int m, std::vector<int>& r){
	int cnt =0;

	for (auto it=r.begin(); it!=r.end(); ++it){
		double rank=*it;

		double under = std::sqrt(pow(rank,2)/4 + 2*rank*m);
		int res = (int) std::floor((-rank/2 + under) / rank);
		cnt+=res;

		if (cnt >= p) return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int tests, p, l, r;
	scanf("%d", &tests);

	while (tests--){

		scanf("%d %d", &p, &l);
		std::vector<int> ranks;
		for (int i=0; i<l; ++i) {scanf("%d", &r); ranks.push_back(r);}

		int lo=0, hi=MAX_RANK*(p+1)*p/2;
		while (hi-lo>1){
			int mid=(lo+hi)/2;

			(func(p, mid, ranks) ? hi : lo) = mid;
		}	

		std::cout << hi << "\n";

	}
	return 0;
}