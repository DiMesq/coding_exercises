#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <utility>
#include <string>

#define NO_PARENT ""

void gen_primes(std::unordered_map<std::string, int>& primes){
	int max = 10000;
	std::vector<int> v;
	for (int i=0; i<max; ++i){
		int val=i;
		if (i%2==0) val=0;
		v.push_back(val);
	}

	int i=3;
	int k=i;
	while (k<max){ v[k]=0; k+=i;}

	v[1]=0;

	i=5;
	while (i*i<=max){
		int n=2;
		while (n--){
			if (v[i]!=0){
				k=i*i;
				while (k<max){ v[k]=0; k+=i;}
			}
			i+=2;
		}
		i+=2;
	}

	primes[std::to_string(2)]=1;
	primes[std::to_string(3)]=1;
	i=5;
	while (i<max){
		if (v[i]!=0) primes[std::to_string(i)]=1;
		if (v[i+2]!=0) primes[std::to_string(i+2)]=1;
		i+=6;
	}
}

void compute_adjacents(std::unordered_map<std::string, int>& primes, std::string s, std::unordered_map<std::string, std::vector<std::string>>& adj){

	for (int i=0; i<4; ++i){
		std::string str(s);
		for(int j=0; j<10; ++j){
			if (s.compare(i, 1, std::to_string(j)) == 0) continue;
			if (i==0 and j==0) continue;
			if (i==3 and j%2==0) continue;

			str.replace(i, 1, std::to_string(j));
			auto iter = primes.find(str);

			if (iter != primes.end()) adj[s].push_back(str);
		}
	}
}

int bfs(std::unordered_map<std::string, int>& primes, std::unordered_map<std::string, int>& d, std::string init, std::string goal, std::unordered_map<std::string, std::vector<std::string>>& adj, std::unordered_map<std::string, std::string>& p){

	if (init.compare(goal)==0) return 0;
	std::queue<std::string> Q;
	int t=0;
	d[init]=t;
	p[init]=NO_PARENT;
	Q.push(init);

	while (!Q.empty()){
		std::string s = Q.front();
		Q.pop();

		t = d[s]+1;
		compute_adjacents(primes, s, adj);
		std::vector<std::string> s_adj = adj[s];

		for (auto it=s_adj.begin(); it!=s_adj.end(); ++it){
			std::string u = *it;

			std::pair<std::unordered_map<std::string, int>::iterator, bool> iter = d.insert(std::make_pair(u, t));
			if (iter.second){
				p[u]=s;
				Q.push(u);
				if (u.compare(goal) == 0) return t;
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	std::unordered_map<std::string, int> primes;
	gen_primes(primes);

	char s[5], str[5];
	int test;
	scanf("%d", &test);

	for (int i=0; i<test; ++i){

		std::unordered_map<std::string, int> d;
		std::unordered_map<std::string, std::string> p;
		std::string init, goal;
		std::unordered_map<std::string, std::vector<std::string>> adj;

		scanf("%s %s", s, str);
		init = s;
		goal = str;

		int dist = bfs(primes, d, init, goal, adj, p);

		std::cout<<(dist==-1 ? "Impossible" : std::to_string(dist))<<"\n";

	}


	return 0;
}