#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 510, MAXN2 = 250010;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int m, n, q, grid[MAXN][MAXN];
vector<array<int, 3>> edges; // {peso, a, b}

int id(int i, int j){ return n*i + j; }

namespace hld {
	vector<pair<int, int>> g[MAXN2];
	int pos[MAXN2], sz[MAXN2];
	int sobe[MAXN2], pai[MAXN2];
	int h[MAXN2], v[MAXN2], t;
	int men[MAXN2], seg[2*MAXN2];

  void add_edge(int a, int b, int c){
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			sobe[i.first] = i.second; pai[i.first] = k;
			h[i.first] = (i == g[k][0] ? h[k] : i.first);
			men[i.first] = (i == g[k][0] ? max(men[k], i.second) : i.second);
			build_hld(i.first, k, f); sz[k] += sz[i.first];

			if (sz[i.first] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}

	void build(int root = 0) {
		t = 0;
		build_hld(root);
		for (int i = 0; i < t; i++) seg[i+t] = v[i];
		for (int i = t-1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
	}

	int query_path(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] != h[b]) return max(men[a], query_path(pai[h[a]], b));
		int ans = 0, x = pos[b]+1+t, y = pos[a]+t;
		for (; x <= y; ++x/=2, --y/=2) ans = max({ans, seg[x], seg[y]});
		return ans;
	}
};

vector<int> parent, sz;

void DSU_init(){
  parent.resize(n*m);
  for(int i = 0; i < n*m; i++)
    parent[i] = i;

  sz.assign(n*m, 1);
}

int DSU_find(int x){
  if(x == parent[x]) return x;
  return parent[x] = DSU_find(parent[x]);
}

void DSU_merge(int a, int b){
  a = DSU_find(a);
  b = DSU_find(b);

  if(a == b) return;

  if(sz[a] < sz[b]) swap(a, b);

  parent[b] = a;
  sz[a] += sz[b];
}

void kruskal(){
  DSU_init();

  sort(edges.begin(), edges.end());

  for(auto [c, a, b] : edges) if(DSU_find(a) != DSU_find(b)){
    hld::add_edge(a, b, c);
    DSU_merge(a, b);
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n >> q;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      cin >> grid[i][j];

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(i < m-1) edges.push_back({max(grid[i][j], grid[i+1][j]), id(i, j), id(i+1, j)}); // vertical
      if(j < n-1) edges.push_back({max(grid[i][j], grid[i][j+1]), id(i, j), id(i, j+1)}); // horizontal
    }
  }

  kruskal();

  hld::build();

  while(q--){
    int x1, y1; cin >> x1 >> y1; x1--, y1--;
    int x2, y2; cin >> x2 >> y2; x2--, y2--;

    cout << max(grid[x1][y1], hld::query_path(id(x1, y1), id(x2, y2))) << "\n";
  }

  return 0;
}

