#include <iostream>
#include <vector>
#include <stack>

using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vp = std::vector<pii>;

int DFS(int s, vp& adj, vi& vis, vi& val, int n){
	vi dfs_vis(n);
	std::stack<int> st;
	st.push(s);
	while (!st.empty()){
		int v = st.top();
		st.pop();

		dfs_vis[v]=1;
		vis[v]=1;	

		pii p = adj[v];
		int op = (val[v] ? p.second : !p.second);

		if (!dfs_vis[p.first]){ 
			st.push(p.first);
			val[p.first] = op;
		}
		else if (op != val[p.first]) return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n, v, p;

	while (1) {
		scanf("%d", &n);
		if (n==0) return 0;
		std::string str;
		vp adj(n);
		vi vis(n), val(n);
		for (int w=0; w<n; ++w){
			std::cin >> v >> str;
			adj[w]=std::make_pair(v-1, (str.compare("true") == 0) ? 1 : 0);
		}
		int is_paradox = 0;
		for (int w=0; w<n; ++w){ 
			if (!vis[w]){
				val[w]=1;
				int res = DFS(w, adj, vis, val, n);
				if (res == 0){ val[w]=0; res = DFS(w, adj, vis, val, n);}
				if (res == 0){ is_paradox=1; break;}
			}	
		}

		is_paradox ? std::cout<<"PARADOX\n" : std::cout<<"NOT PARADOX\n";

	}
	return 0;
}