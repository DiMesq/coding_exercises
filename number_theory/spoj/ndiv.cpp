#include <iostream>
#include <vector>

#define MAX 10000000
typedef  std::vector<int> vector;

vector p_bool(MAX+1, true);
vector p;

void gen_primes(){
	int i = 2, j=5;
	while (i*i <= MAX){
		if (p_bool[i]){
			int h=i*i;
			while (h<=MAX){
				p_bool[h] = false;
				h+=2*i;
			}
		}
		i++;
	}
	p.push_back(2);
	p.push_back(3);
	while(j<MAX){
		if (p_bool[j]) p.push_back(j);
		if (p_bool[j+2]) p.push_back(j+2);
		j+=6;
	}
}

int ndiv(unsigned long int x){

	int i=0, ans=1;

	while (x>1){
		int n = 0;
		while(x%p[i]==0){
			n++;
			x/=p[i];
		}
		ans*=(n+1);
		if (p[i]*p[i] > x){
			if (x>1) ans*=2;
			break;
		}
		i++;
	} 
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	unsigned long int a, b, cnt=0;
	std::cin >> a >> b >> n;

	gen_primes();
	for (unsigned long int i = a; i<=b; i++)
		if (ndiv(i) == n) cnt++;
	std::cout<<cnt<<std::endl;
	printf("yes: %d\n", *(--p.end()-1));

	return 0;
}