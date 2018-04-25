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
	vector<int> inDegree;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		inDegree = vector<int>(n + 1, 0);
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			inDegree[y]++;
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
		std::queue<int> q;

		for (int i = 1; i <= n; ++i) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			topsort.push_back(currNode);

			for (auto v : adj[currNode]) {
				inDegree[v]--;
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
		}

		return topsort;
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
