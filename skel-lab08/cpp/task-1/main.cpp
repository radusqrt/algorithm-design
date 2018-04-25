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
	vector<int> adjt[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
		fin.close();
	}

	vector<vector<int>> get_result() {
		/*
		TODO: Gasiti componentele tare conexe ale grafului orientat cu
		n noduri, stocat in adj. Rezultatul se va returna sub forma
		unui vector, ale carui elemente sunt componentele tare conexe
		detectate. Nodurile si componentele tare conexe pot fi puse in orice
		ordine in vector.
		
		Atentie: graful transpus este stocat in adjt.
		*/
		vector<vector<int>> sol;
		vector<int> visited(n + 1, 0), topsort;

		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				dfs(i, visited, topsort);
			}
		}

		std::reverse(topsort.begin(), topsort.end());
		visited = vector<int>(n + 1, 0);

		for (auto currNode : topsort) {
			if (!visited[currNode]) {
				vector<int> currTC;
				dfsT(currNode, visited, currTC);
				sol.push_back(currTC);
			}
		}

		return sol;
	}

	void dfsT(int node, vector<int> &visited, vector<int> &currTC) {
		visited[node] = 1;
		currTC.push_back(node);

		for (auto v : adjt[node]) {
			if (!visited[v]) {
				dfsT(v, visited, currTC);
			}
		}
	}

	void dfs(int node, vector<int> &visited, vector<int> &topsort) {
		visited[node] = 1;
		for (auto v : adj[node]) {
			if (!visited[v]) {
				dfs(v, visited, topsort);
			}
		}

		topsort.push_back(node);
	}

	void print_output(vector<vector<int>> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				fout << nod << ' ';
			}
			fout << '\n';
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
