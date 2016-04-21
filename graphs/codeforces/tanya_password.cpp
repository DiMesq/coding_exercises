#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

char s[5];
const int N=128*128;
int S=-1, x, y, n, In[N];
std::vector<int> V[N]; 
std::string Ans;

int ID(char a, char b){ return 128*a + b;}

void DFS(int s){
	while (!V[s].empty()) {int n=V[s].back(); V[s].pop_back(); DFS(n);}
	Ans+=s%128;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);

	for (int i=0; i<n; ++i){
		scanf("%s", s);
		x=ID(s[0], s[1]); y=ID(s[1], s[2]);

		V[x].push_back(y); In[y]++;
	}

	for (int j=0; j<N; ++j){
		int sz=V[j].size();
		if (abs(sz-In[j]) > 1) return puts("NO"), 0;
		if (sz == In[j] + 1) if (~S) return puts("NO"), 0; else S=j;
	}
	~S ? true : S=x;
	DFS(S); Ans+=S/128;

	if (Ans.size() < n+2) return puts("NO"), 0;

	std::reverse(Ans.begin(), Ans.end());
	puts("YES"); puts(Ans.c_str());  
	return 0;
}