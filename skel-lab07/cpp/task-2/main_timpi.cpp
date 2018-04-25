#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
	}

	vector<int> get_result() {
		/*
		TODO: Faceti sortarea topologica a grafului stocat cu liste de
		adiacenta in adj.
		*******
		ATENTIE: nodurile sunt indexate de la 1 la n.
		*******
		*/
		vector<int> topsort;
		vector<int> visited(n + 1, 0);

		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				dfs(i, visited, topsort);
			}
		}

		std::reverse(topsort.begin(), topsort.end());

		return topsort;
	}

	void dfs(int node, vector<int> &visited,
			vector<int> &topsort) {
		visited[node] = 1;

		for (int v : adj[node]) {
			if (!visited[v]) {
				dfs(v, visited, topsort);
			}
		}

		topsort.push_back(node);
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i] << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
