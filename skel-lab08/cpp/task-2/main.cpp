#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
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
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<int> get_result() {
		/*
		TODO: Gasiti nodurile critice ale grafului neorientat stocat cu liste
		de adiacenta in adj.
		*/
		vector<int> sol;

		int timp = 0;
		vector<int> idx(n + 1, 0), low(n + 1, 0);

		for (int i = 1; i <= n; ++i) {
			if (idx[i] == 0) {
				dfsPA(i, timp, sol, 0, idx, low);
			}
		}

		for (auto comp : low) {
			std::cerr << comp << "\n";
		}

		return sol;
	}

	void dfsPA(int node, int &timp, vector<int> &sol,
			int parent, vector<int> &idx, vector<int> &low) {
		idx[node] = low[node] = ++timp;
		vector<int> copii;

		for (auto v : adj[node]) {
			if (v != parent) {
				if (idx[v] == 0) {
					copii.push_back(v);
					dfsPA(v, timp, sol, node, idx, low);
					low[node] = min(low[node], low[v]);
				} else {
					low[node] = min(low[node], idx[v]);
				}
			}
		}

		if (parent == 0) {
			if (copii.size() >= 2) {
				sol.push_back(node);
			}
		} else {
			for (auto copil : copii) {
				if (low[copil] >= idx[node]) {
					sol.push_back(node);
					break;
				}
			}
		}
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
