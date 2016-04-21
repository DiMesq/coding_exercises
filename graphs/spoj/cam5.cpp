#include <iostream>
#include <unordered_map>
#include <vector>

void dfs_visit(int v, std::unordered_map<int, std::vector<int>>& adj, std::unordered_map<int, int>& vis){
	vis[v]=1;

	auto v_adj = adj[v];
	for (auto it=v_adj.begin(); it!=v_adj.end(); ++it){
		auto u=*it;
		auto iter = vis.find(u);
		if (iter==vis.end()) dfs_visit(u, adj, vis);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	int n, l, v, u;
	scanf("%d", &t);

	while (t--){
		int cnt = 0;
		scanf("%d %d", &n, &l);
		std::unordered_map<int, std::vector<int>> adj;
		std::unordered_map<int, int> vis;

		for (int i=0; i<l; ++i){

			scanf("%d %d", &v, &u);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}

		for (int i=0; i<n; ++i){

			auto it = vis.find(i);
			if (it==vis.end()){
				cnt++;
				dfs_visit(i, adj, vis);
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}


