#include <bits/stdc++.h>
using namespace std;
class graph {
	public: int s;
	public: int d;
	public: int w;
};

bool compare(graph a, graph b) {
	return a.w < b.w;
}

int findParent(int s, int *parent) {
	while(parent[s] != s) {
		s = parent[s];
	}
	return s;
}

void join(int *parent, int u, int v) {
	int uParent = findParent(u, parent);
	int vParent = findParent(v, parent);
	if(uParent < vParent)
		parent[vParent] = uParent;
	else
		parent[uParent] = vParent;
}

int main() {
	int n, m;
	cin >> n >> m;
	graph edges[m+1];
	int parent[n+1];
	int mstWt = 0;
	
	for(int i=0; i<=n; i++)
		parent[i] = i;
		
	for(int i=0; i<m; i++){
		cin >> edges[i].s >> edges[i].d >> edges[i].w ;
	}
	
	sort(edges, edges+m, compare);
	
	for(int i=0; i<m; i++) {
		int u = edges[i].s;
		int v = edges[i].d;
		if(findParent(u, parent) != findParent(v, parent)) {
			if(u < v)
				parent[v] = u;
			else
				parent[u] = v;
			mstWt = mstWt + edges[i].w;
			join(parent, u, v);
		}
	}
	
	cout << mstWt;
}
