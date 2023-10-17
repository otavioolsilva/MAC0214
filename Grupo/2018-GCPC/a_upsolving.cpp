#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2010, MAXN2 = 1e6 + 10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int h, w, n;
char grid[MAXN][MAXN];
vector<int> adj[MAXN2];

int id(int i, int j){ return w*(i-1) + j/2; }

void add_edge(int a, int b){
  adj[a].push_back(b);
  adj[b].push_back(a);
}

int clk, maxl;
vector<int> tin, tout, ht;
vector<int> anc[MAXN2];

void dfs(int u, int p){
  tin[u] = clk++;

  ht[u] = ht[p]+1; anc[u][0] = p;
  for(int i = 1; i <= maxl; i++) anc[u][i] = anc[anc[u][i-1]][i-1];

  for(int v : adj[u]) if(v != p) dfs(v, u);

  tout[u] = clk++;
}

bool is_ancestor(int u, int v){ // se u é ancestral de v
  return (tin[u] <= tin[v] && tout[u] >= tin[v]);
}

int lca(int a, int b){
  if(is_ancestor(a, b)) return a;
  if(is_ancestor(b, a)) return b;

  for(int i = maxl; i >= 0; i--)
    if(!is_ancestor(anc[a][i], b))
      a = anc[a][i];

  return anc[a][0];
}

int dist(int a, int b){
  int l = lca(a, b);
  return ht[a] + ht[b] - 2*ht[l];
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> h >> w;

  n = h*w;

  string in; getline(cin, in); // ler '\n' que ficou faltando do cin
  for(int i = 0; i <= h; i++){
    getline(cin, in);

    for(int j = 0; j <= 2*w; j++)
      grid[i][j] = in[j];
  }

  for(int i = 1; i <= h; i++){
    for(int j = 1; j < 2*w; j += 2){
      if(grid[i][j] == ' ') add_edge(id(i, j), id(i+1, j)); // vertical
      if(grid[i][j+1] == ' ') add_edge(id(i, j), id(i, j+2)); // horizontal
    }
  }

  maxl = ceil(log2(n)); clk = 0;
  tin.assign(n, 0); tout.assign(n, 0); ht.assign(n, 0);

  for(int i = 0; i < n; i++)
    anc[i].resize(maxl+1);

  dfs(0, 0);

  ll ans = 0;

  int m, last_x, last_y; cin >> m;
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;

    if(i != 0) ans += dist(id(last_x, 2*last_y-1), id(x, 2*y-1));

    last_x = x; last_y = y;
  }

  cout << ans << "\n";

  return 0;
}

