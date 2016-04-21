#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

int BFS(std::vector<int>& p, std::vector<char>& r, int n){
	int x=-1, c1 = 10%n, c2=(c1+1)%n;
	p[c1]=p[c2]=x;
	r[c1]='0'; r[c2]='1';
	if (c1==0) return c1;
	else if (c2==0) return c2;

	std::queue<int> q; q.push(c1); q.push(c2);
	while (!q.empty()){
		x=q.front(); q.pop();
		c1 = (10*x)%n; c2 = (c1+1)%n;
		if (!p[c1]){
			p[c1]=x;
			r[c1]='0';
			q.push(c1);
		} 
		if (!p[c2]){
			p[c2]=x;
			r[c2]='1';
			q.push(c2);
		}
		if (c1==0) return c1;
		else if (c2==0) return c2;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int k, n;
	scanf("%d", &k);

	for (int i=0; i<k;++i){
		scanf("%d", &n);
		if (n==1){puts("1"); continue;}
		std::vector<int> p(n);
		std::vector<char> r(n);
		int t = BFS(p, r, n);

		std::string Ans=""; Ans+=r[t];
		while (~p[t]){
			t=p[t];
			Ans+=r[t];
		}
		Ans+="1";
		std::reverse(Ans.begin(), Ans.end());
		puts(Ans.c_str());
	}
	
	return 0;
}
