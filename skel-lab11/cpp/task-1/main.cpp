#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int kNmax = 1005;
const int kInf = 10000000;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	int source, sink;
	vector<int> adj[kNmax];
	int C[kNmax][kNmax];
	int F[kNmax][kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;

		source = 1;
		sink = n;

		memset(C, 0, sizeof C);
		for (int i = 1, x, y, z; i <= m; i++) {
			fin >> x >> y >> z;
			adj[x].push_back(y);
			adj[y].push_back(x);
      		C[x][y] += z;
		}
		fin.close();
	}

	vector<int> BFS() {
		queue<int> q;
		q.push(source);
		vector<int> path;
		vector<int> p(n + 1, -1);
		p[source] = 0;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto neigh : adj[node]) {
				if (p[neigh] == -1 && F[node][neigh] < C[node][neigh]) {
					p[neigh] = node;
					q.push(neigh);
				}
			}
		}

		if (p[sink] == -1) {
			return path;
		}

		int curr = sink;
		while (curr != 0) {
			std::cerr << curr << " ";
			path.push_back(curr);
			curr = p[curr];
		}

		std::reverse(path.begin(), path.end());
		return path;
	}

	int get_result() {
		/*
		TODO: Calculati fluxul maxim pe graful orientat dat.
		Sursa este nodul 1.
		Destinatia este nodul n.

		In adj este stocat graful neorientat obtinut dupa ce se elimina orientarea
		arcelor, iar in C sunt stocate capacitatile arcelor.
		De exemplu, un arc (x, y) de capacitate z va fi tinut astfel:
		C[x][y] = z, adj[x] contine y, adj[y] contine x.
		*/
		int flow = 0;
		// std::cerr << "START\n";

		do {
			vector<int> path = BFS();
			if (path.empty()) {
				break;
			}

			int minFlow = kInf;
			for (int i = 0; i < path.size() - 1; ++i) {
				minFlow = min(minFlow, C[path[i]][path[i + 1]] - F[path[i]][path[i + 1]]);
			}

			if (minFlow >= 1) {
				flow += minFlow;
				for (int i = 0; i < path.size() - 1; ++i) {
					F[path[i]][path[i + 1]] += minFlow;
					F[path[i + 1]][path[i]] -= minFlow;
				}
			} else {
				break;
			}
		} while (1);

		std::cerr << flow << "\n";
		return flow;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
