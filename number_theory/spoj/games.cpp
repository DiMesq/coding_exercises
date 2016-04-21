#include <iostream>
#include <vector>
#include <string>

long int gcd(long int p, long int q){
	if (q) return gcd(q, p%q);
	return p;
}

int main(int argc, char const *argv[])
{
	int t, j, l, cnt;
	bool flag;
	long int p, q;
	std::string s;
	 
	std::cin >> t;
	for (int i = 0; i<t; i++){
		q=1; p=0; flag=false, cnt=0;
		std::cin >>s;
		l = s.size();
		j = l;
		while(--j>=0){
			if (s[j] == '.'){flag=true; break;}
			cnt++;
		}

		for (j=0; j<l; j++){
			if (s[j]!='.') p = p*10 + (s[j]-'0');
		}
		if (!flag) cnt=0;
		while (cnt--){
			q*=10;
		}
		std::cout << q/gcd(p,q) << std::endl;
	}

	return 0;
}

