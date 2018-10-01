#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > g;
int nodes, edges;
vector<bool> visited;

void dfs(int src, int parent) {
	for(auto i: g[src]) {
		if(i == parent || visited[i]) continue;
		cout << "traversing from " << src << " to " << i << endl;
		dfs(i, src);
	}
}

int main() {
	cout << "enter number of nodes & edges: ";
	cin >> nodes >> edges;
	g.resize(nodes+1);
	visited.resize(nodes+1, 0);
	cout << "Enter edge pairs: ";
	for(int i=0;i<edges;++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for(int i=1;i<=nodes;++i) {
		if(!visited[i]) {
			dfs(i, i);
		}
	}

	return 0;
}