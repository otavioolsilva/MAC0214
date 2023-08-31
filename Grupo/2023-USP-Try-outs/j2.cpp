// Complicou demais a solução na j.cpp, só a árvore da DFS
// é suficiente pra contabilizar tudo que é necessário
// (pelo menos lembrou Kruskal e DSU, vai que né)

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

int n, m, color[MAXM];
vector<pair<int, int>> adj[MAXM];
bool seen[MAXM];
set<int> ans;

void dfs(int u, int p){
  seen[u] = 1;

  if(adj[u].size() == 1 && adj[u][0].first == p){ // caso folha
    if(color[u]){
      color[p] ^= 1;
      ans.insert(adj[u][0].second);
    }

    return;
  }

  int id_p = 0;

  for(auto [v, i] : adj[u]){
    if(!seen[v])
      dfs(v, u);
    
    if(v == p)
      id_p = i;
  }

  if(color[u] && u != p){
    color[p] ^= 1;
    ans.insert(id_p);
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
  }

  for(int i = 1; i <= m; i++)
    cin >> color[i];

  memset(seen, 0, sizeof(seen));

  for(int i = 1; i <= m; i++){
    if(seen[i]) continue;

    dfs(i, i);

    if(color[i]){ // deu ímpar na componente conexa
      cout << "-1\n";
      return 0;
    }
  }

  cout << ans.size() << "\n";
  for(int i : ans)
    cout << i << " ";
  if(ans.size() != 0) cout << "\n";

  return 0;
}

