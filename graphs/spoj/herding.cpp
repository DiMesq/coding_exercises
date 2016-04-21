#include <vector>
#include <iostream>

int Is_new=true;
int Time=0;

void DFS(int s, std::vector<int>& adj, std::vector<int>& d, std::vector<int>& f){
	d[s]=++Time;
	int u=adj[s];
	if (!d[u]) DFS(u, adj, d, f);
	else if (f[u]) Is_new=false;
	f[s]=++Time;


}

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> adj(n*m), d(n*m), f(n*m);

	for (int i=0; i<n; ++i){
		std::string str;
		std::cin >> str;

		for (int j=0; j<m; j++){
			int v = m*i+j;
			if (str[j] == 'N') adj[v]=v-m;
			else if (str[j]=='S') adj[v]=v+m;
			else if (str[j]=='W') adj[v]=v-1;
			else if (str[j]=='E') adj[v]=v+1;
		}
	}
	int cnt=0;
	for (int i=0; i<n*m; ++i){
		Is_new=true;
		if (!d[i]){ DFS(i, adj, d, f); if (Is_new) cnt++;}
	}

	std::cout<<cnt<<"\n";

	return 0;
}