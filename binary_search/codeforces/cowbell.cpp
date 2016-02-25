#include <vector>
#include <iostream>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

bool func(std::vector<int> &v, int box_sz){

	std::vector<int>::iterator l = v.begin(), r = v.end()-1;

	while (r>l){
		if (*r + *l > box_sz) return false;
		r--; l++;
	}
	return true;
}

int bs(std::vector<int> &v, int max_ele){

	int lo = max_ele - 1;
	int hi = 2 * (lo+1);
	int mid;

	while (hi-lo>1){
		int mid = (hi+lo)/2;

		(func(v, mid) ? hi : lo) = mid;
	}
	return hi;
}

int main(int argc, char const *argv[])
{
	int n, k, full_boxes, max_ele, res;
	scanf("%d %d", &n, &k);
	full_boxes = n-k;
	std::vector<int> v(n);
	for (std::vector<int>::iterator it = v.begin(); it!=v.end(); it++) std::cin>>*it;

	max_ele = *max_element(all(v));

	if (full_boxes>0){
		std::vector<int> v1(v.begin(), v.begin()+2*full_boxes);
		res = bs(v1, max_ele);
	} else{
		res = max_ele;
	}
	std::cout<<res<<std::endl;
	return 0;
}