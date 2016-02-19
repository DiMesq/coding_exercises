#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <numeric>

#define tr(v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define all(c) (c).begin(), (c).end()

class FairWorkload {

	private:
		int func(int x, std::vector<int> f, int workers);

	public:
		int getMostWork(std::vector<int> folders, int workers);
};

int FairWorkload::getMostWork(std::vector<int> folders, int workers){

	int left = 0;
	int right = std::accumulate(all(folders), 0);

	while (right - left > 1) {
		int med = (left + right) / 2;
		(this->func(med, folders, workers) ? right : left) = med;
	}

	return right;

}

int FairWorkload::func(int x, std::vector<int> f, int workers){

	int n_workers = 0, n_folders = 0;
	int N = f.size();

	for (int i = 0; i < N; i++){
		if (n_workers >= workers || f[i] > x) return false;

		n_folders += f[i];

		if (n_folders > x){
			n_workers++;
			n_folders = f[i];
		}
	}
	return n_workers < workers;
}

int main()
{	
	FairWorkload f;
	int t, n, temp, workers;
	scanf("%d", &t);
	

	while (t--){

		scanf("%d", &n);
		std::vector<int> v(n);

		tr(v){
			scanf("%d", &temp);
			*it = temp;
		}

		scanf("%d", &workers);
		std::cout << f.getMostWork(v, workers) << std::endl;
	}

	return 0;
}



