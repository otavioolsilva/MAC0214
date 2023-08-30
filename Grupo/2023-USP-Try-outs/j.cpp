#include <bits/stdc++.h>
using namespace std;
 
void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl
 
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXM = 5e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n, m, colors[MAXM];
vector<array<int, 3>> edges; // grafo geral
vector<pair<int, int>> adj[MAXM]; // só árvore

// gerando árvore

int parent[MAXM], sz[MAXM];

void dsu_build(){
  for(int i = 1; i <= m; i++){
    parent[i] = i;
    sz[i] = 1;
  }
}

int dsu_find(int x){
  if(x == parent[x]) return x;
  return x = dsu_find(parent[x]);
}

void dsu_union(int a, int b){
  a = dsu_find(a);
  b = dsu_find(b);

  if(a == b) return;

  if(sz[a] < sz[b]) swap(a, b);
  parent[b] = a;
  sz[a] += sz[b];
}

void kruskal(){
  dsu_build();

  for(auto [a, b, i] : edges) if(dsu_find(a) != dsu_find(b)){
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
    dsu_union(a, b);
  }
}

// achando os caminhos na árvore

map<int, int> cont;
set<int> ans;

void dfs(int u, int p){
  

  for(auto [v, i] : adj[u]){
    
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  edges.resize(n);
  for(int i = 0; i < n; i++){
    cin >> edges[i][0] >> edges[i][1];
    edges[i][2] = i;
  }

  for(int i = 1; i <= m; i++)
    cin >> colors[i];

  kruskal();

  for(int i = 1; i <= m; i++)
    cont[dsu_find(i)] += colors[i];

  for(auto [k, c] : cont){
    if(c&1){
      cout << "-1\n";
      return 0;
    }

    dfs(k, k);
  }

  cout << ans.size() << "\n";
  for(int i : ans)
    cout << i << " ";
  cout << "\n";

  return 0;
}

