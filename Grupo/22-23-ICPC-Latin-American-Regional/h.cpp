#include <bits/stdc++.h>
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}

	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};

map<string, int> horses;
vector<string> horses_rev;

vector<int> best; // melhor posição que o cavalo pode estar
vector<vector<bool>> pos; // posições que ele pode estar considerando as corridas que ele não apareceu
vector<bool> seen; // vector auxiliar pra marcar as posições

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  horses_rev.resize(n);

  for(int i = 0; i < n; i++){
    string name; cin >> name;
    horses[name] = i;
    horses_rev[i] = name;
  }

  best.assign(n, 1);
  pos.assign(n, vector<bool>(n+1, true));

  int r; cin >> r;
  while(r--){
    int m, w; cin >> m >> w;

    seen.assign(n, false);

    for(int i = 0; i < m; i++){
      string name; cin >> name;
      int h = horses[name];

      best[h] = max(best[h], w);
      seen[h] = true;
    }

    for(int i = 0; i < n; i++)
      if(!seen[i])
        pos[i][w] = false;
  }

  // construindo grafo
  kuhn graph(n, n+1);
  for(int i = 0; i < n; i++)
    for(int j = best[i]; j <= n; j++)
      if(pos[i][j])
        graph.add(i, j);

  assert(graph.matching() == n);

  for(int i = 1; i <= n; i++)
    cout << horses_rev[graph.mb[i]] << " ";
  cout << "\n";

  return 0;
}

