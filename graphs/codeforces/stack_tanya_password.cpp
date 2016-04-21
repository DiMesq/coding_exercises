#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

char s[5];
const int N=128*128;
int S=-1, x, y, n, In[N];
std::vector<int> V[N]; 
std::string Ans;

int ID(char a, char b){ return 128*a + b;}

void DFS(){
	int n=S, s;
	std::stack<int> st; st.push(-1);
	do {
		if (!V[n].empty()) {st.push(n); s=V[n].back(); V[n].pop_back();}
		else {Ans+=n%128; s=st.top(); st.pop();}
		n=s;
	} while (!st.empty());
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
	DFS(); Ans+=S/128;

	if (Ans.size() < n+2) return puts("NO"), 0;

	std::reverse(Ans.begin(), Ans.end());
	puts("YES"); puts(Ans.c_str());  
	return 0;
}