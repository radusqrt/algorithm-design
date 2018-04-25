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

	struct Edge {
		int x;
		int y;
	};

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<Edge> get_result() {
		/*
		TODO: Gasiti muchiile critice ale grafului neorientat stocat cu liste
		de adiacenta in adj.
		*/

		vector<Edge> sol;

		int timp = 0;
		vector<int> idx(n + 1, 0), low(n + 1, 0);

		for (int i = 1; i <= n; ++i) {
			if (idx[i] == 0) {
				dfsPA(i, 0, timp, sol, idx, low);
			}
		}

		return sol;
	}

	void dfsPA(int node, int parent, int &timp, vector<Edge> &sol,
			vector<int> &idx, vector<int> &low) {
		idx[node] = low[node] = ++timp;

		for (auto v : adj[node]) {
			if (v != parent) {
				if (idx[v] == 0) {
					dfsPA(v, node, timp, sol, idx, low);
					low[node] = min(low[node], low[v]);
					if (low[v] > idx[node]) {
						sol.push_back({node, v});
					}
				} else {
					low[node] = min(low[node], idx[v]);
				}
			}
		}
	}

	void print_output(vector<Edge> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i].x << ' ' << result[i].y << '\n';
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
